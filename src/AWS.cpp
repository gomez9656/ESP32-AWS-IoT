#include "include/AWS.h"

float h;
float t;

WiFiClientSecure net = WiFiClientSecure(); // Create WiFiClientSecure object
PubSubClient client(net);                  // Create PubSubClient object

void messageHandler(char *topic, byte *payload, unsigned int length)
{
    // Deserialize JSON message
    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);
    // Get message value from JSON message
    const int message = doc["message"];
    const int message2 = doc["message2"];
    Serial.println(message);
    Serial.println(message2);

    if (message == 1)
    {
        digitalWrite(8, HIGH);
    }
    else
    {
        digitalWrite(8, LOW);
    }
}

void publishMessage()
{
    h = 15;
    t = 20;
    StaticJsonDocument<200> doc;
    doc["humidity"] = h;
    doc["temperature"] = t;
    char jsonBuffer[512];
    serializeJson(doc, jsonBuffer); // print to client

    client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

// Declare function to connect to AWS IoT
void connectAWS()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid.c_str(), pss.c_str());

    Serial.println("Connecting to Wi-Fi");

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    // Configure WiFiClientSecure to use the AWS IoT device credentials
    net.setCACert(AWS_CERT_CA);
    net.setCertificate(AWS_CERT_CRT);
    net.setPrivateKey(AWS_CERT_PRIVATE);

    // Connect to the MQTT broker on the AWS endpoint we defined earlier
    client.setServer(AWS_IOT_ENDPOINT, 8883);

    // Create a message handler
    client.setCallback(messageHandler);

    Serial.println("Connecting to AWS IOT");

    while (!client.connect(THINGNAME))
    {
        Serial.print(".");
        delay(100);
    }

    if (!client.connected())
    {
        Serial.println("AWS IoT Timeout!");
        return;
    }

    // Subscribe to a topic
    client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);

    Serial.println("AWS IoT Connected!");
}

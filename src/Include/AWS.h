#include "wifi.h"
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include "include/secrets.h"
#include "include/EEP.h"

#define AWS_IOT_PUBLISH_TOPIC "esp32c3/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32c3/sub"

extern WiFiClientSecure net; // Create WiFiClientSecure object
extern PubSubClient client;  // Create PubSubClient object

extern float h;
extern float t;

void connectAWS();
void messageHandler(char *topic, byte *payload, unsigned int length);
void publishMessage();
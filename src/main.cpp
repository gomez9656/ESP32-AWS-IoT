#include "include/EEP.h"
#include "include/smartconfig.h"
#include "include/AWS.h"

#define WiFi_rst 0                // WiFi credential reset pin (Boot button on ESP32)

unsigned long rst_millis;

void setup()
{
  Serial.begin(115200);
  pinMode(8, OUTPUT);
  pinMode(WiFi_rst, INPUT);
  
  initEEPROM();
  readEEPROM();
  startSmartConfig(); //this functions should be called only when we want to receive the WIFI credentials
  connectAWS();
}

void loop()
{  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  publishMessage();
  client.loop();
  delay(1000);
  
 /*
 This commented code is to check for a GPIO and delete wifi credentials. 
 needs to be done with interrupts
  rst_millis = millis();
  while (digitalRead(WiFi_rst) == LOW)
  {
    // Wait till boot button is pressed
  }
  // check the button press time if it is greater than 3sec clear wifi cred and restart ESP
  if (millis() - rst_millis >= 3000)
  {
    Serial.println("Reseting the WiFi credentials");
    writeStringToFlash("", 0);  // Reset the SSID
    writeStringToFlash("", 40); // Reset the Password
    Serial.println("Wifi credentials erased");
    Serial.println("Restarting the ESP");
    delay(500);
    ESP.restart(); // Restart ESP
  }
  */
}

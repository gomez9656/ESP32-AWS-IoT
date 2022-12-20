# ESP32-AWS-IoT
Use ESP32-C3 to connect to AWS IoT and publish/subscribe to topics.

This application first enters in SmartConfig mode. This allows to share the WIFI credentials from a mobile app like "ESP TOUCH".

This credentials and then stored in EEPROM memory for data storage.

Then, the application connects to AWS IoT and publish to a topic using a placeholder value for humidity and temperature. 
You can also use the AWS IoT console to send messages back to the ESP32-C3

#include "include/EEP.h"

String ssid;
String pss;

/*
Initialize EEPROM
*/
void initEEPROM()
{

    // Wait until the EEPROM initialization is complete
    while (!EEPROM.begin(EEPROM_SIZE))
    {
        Serial.println("failed to init EEPROM");
        delay(100);
    }
    // The EEPROM is now ready to be accessed
    Serial.println("EEPROM initialized");
}

/*
Read WIFI credentials stored in EEPROM.
*/
void readEEPROM()
{
    ssid = readStringFromFlash(0); // Read SSID stored at address 0
    Serial.print("SSID = ");
    Serial.println(ssid);
    pss = readStringFromFlash(40); // Read Password stored at address 40
    Serial.print("psss = ");
    Serial.println(pss);
}

void writeStringToFlash(const char *toStore, int startAddr)
{
    int i = 0;
    for (; i < LENGTH(toStore); i++)
    {
        EEPROM.write(startAddr + i, toStore[i]);
    }
    EEPROM.write(startAddr + i, '\0');
    EEPROM.commit();
}

String readStringFromFlash(int startAddr)
{
    char in[128]; // char array of size 128 for reading the stored data
    int i = 0;
    for (; i < 128; i++)
    {
        in[i] = EEPROM.read(startAddr + i);
    }
    return String(in);
}
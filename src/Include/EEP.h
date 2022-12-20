#include "EEPROM.h"

extern String ssid; // string variable to store ssid
extern String pss;  // string variable to store password


#define LENGTH(x) (strlen(x) + 1) // length of char string
#define EEPROM_SIZE 200           // EEPROM size

void initEEPROM();
void readEEPROM();
void writeStringToFlash(const char *toStore, int startAddr);
String readStringFromFlash(int startAddr);
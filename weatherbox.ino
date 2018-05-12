/*Libraries */
#include "sensors.h"
#include "config.h"
#include "transmit.h"
#include "schema.h"
#include "routine.h"
#define DEBUG 1

/*External Libraries*/
#include "SI114X.h"
#include <wire.h>
#include <XBee.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <EEPROM.h>

schema_1 Gpacket;
XBee Gxbee = XBee();

int global_count = 0;

void setup()
{
    Serial.begin(9600);
    sensor_init();
    Gxbee.begin(Serial);
    Gxbee.setSerial(Serial);
    clear_packet();
    Serial.println("Starting up...");
    //delay(1); 
}

void loop()
{
  routine(&global_count);
}


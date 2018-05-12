/*Internal Libraries*/
#include "sensors.h"
#include "config.h"
#include "SI114X.h"

/*Objects*/
//Adafruit_BME280 bme;
//Adafruit_BME280 bme(BME_CS);//hardware SPI
Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI
SI114X SI1145 = SI114X();

void sensor_init(void){
   bme.begin();
}

/*Humidity*/
long sHumidity(void){
  long val = bme.readHumidity();
  return val;
}

/*Pressure*/
long sPressure(void){
  long val = bme.readPressure();
  return val;
}

/*Temperature*/
long sTemperature(void){
  long val = bme.readTemperature();
  return val;
}

/*Solar Irradiance*/
long sSolIrrad(void){
  //long val = SI1145.ReadVisible();
  long val = SI1145.ReadIR();
  return (val); //check datasheet for this calc
}

/*Battery*/
long battStatus(void){
  long val = analogRead(PIN_BATT_V)*(5000.0/1023);
  return val;
}

/*SOLAR PANEL*/
long panelStatus(void){
  long val = 2 * (analogRead(PIN_SOLAR_V)*(5000.0/1023));
  return val;
}


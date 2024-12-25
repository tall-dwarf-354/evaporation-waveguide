//slave
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)

Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK);


float p;
float T;
float H;
float A;



void setup() {
  Wire.begin(2);                /* join i2c bus with address 2 */
  Wire.onRequest(requestEvent); /* register request event */
  Serial.begin(9600);           /* start serial comm. */
  Serial.println("I am I2C Slave");
  bme.begin();  
}

void loop() {
  delay(10000);
}

void requestEvent() {
  
  p = bme.readPressure() / 100.0F;
  T = bme.readTemperature();
  A = bme.readAltitude(SEALEVELPRESSURE_HPA);
  H = bme.readHumidity();


  char result[6];
  dtostrf(p, 6, 2, result);

  Wire.write(result);
  Serial.println(result);

  char result2[7];
  dtostrf(T, 7, 2, result2);

  Wire.write(result2);
  Serial.println(result2);

  dtostrf(A, 7, 2, result2);
  
  Wire.write(result2);
  Serial.println(result2);

  dtostrf(H, 6, 2, result);

  Wire.write(result);
  Serial.println(result);

}


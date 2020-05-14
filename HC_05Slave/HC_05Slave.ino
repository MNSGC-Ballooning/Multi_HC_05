// Author: Asif Ally
// Email: allyx004@umn.edu
// Note: If you have any questions, email me.

#include <Arduino.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <SoftwareSerial.h>

//Dallas Temperature Sensor Pin
#define ONE_WIRE_BUS 5
//LED
#define LEDPIN 3

//Interval at which we want to bluetooth to run
#define blue_INTERVAL 100
#define power 10
#define key 9
unsigned long blueStamp = 0;
SoftwareSerial blue(6, 5);

//Temp Sensor
OneWire oneWire1(ONE_WIRE_BUS);
DallasTemperature sensor1(&oneWire1);
float t1;


void setup() {
//  pinMode(power, OUTPUT);
//  pinMode(key, OUTPUT);
  pinMode(LEDPIN, OUTPUT);

//  digitalWrite(power, LOW);
//  digitalWrite(key, LOW);

//  delay(100);
//  digitalWrite(key, HIGH);
//  delay(100);
//
//  digitalWrite(power, HIGH);
  Serial.begin(9600);
  blue.begin(38400);
  delay(100);
//  blue.write("AT");
//  delay(3000);
//
//  blue.write("AT+ROLE=0\r\n");
//  Serial.write("AT+ROLE=0\r\n");
//  delay(1000);
//  blue.write("AT+CMODE=1\r\n");
//  Serial.write("AT+CMODE=1\r\n");
//  delay(1000);
//  blue.write("AT+INIT\r\n");
//  Serial.write("AT+INIT\r\n");
//  delay(3000);
//  blue.write("AT+INQ\r\n");
//  Serial.write("AT+INQ\r\n");
//  delay(3000); 
}

void loop() {
  if(blue.available()>0)
  {
    char in = blue.read();
    Serial.write(in);
    if(in == '1')
    {
      digitalWrite(LEDPIN, HIGH);
    }
    else if(in == '0')
    {
      digitalWrite(LEDPIN, LOW);
    }
  }
}

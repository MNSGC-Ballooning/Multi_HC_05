// Author: Asif Ally
// Email: allyx004@umn.edu
// Note: If you have any questions, email me.

#include <Arduino.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <SoftwareSerial.h>

//Dallas Temperature Sensor Pin
//#define ONE_WIRE_BUS 5
//LED
#define LEDPIN 30

//Interval at which we want to bluetooth to run
#define blue_INTERVAL 100
//#define power 8
//#define key 7
unsigned long blueStamp = 0;
SoftwareSerial blue(3, 2);



void setup() {
//  pinMode(power, OUTPUT);
//  pinMode(key, OUTPUT);
  pinMode(LEDPIN, OUTPUT);

  //digitalWrite(power, LOW);
  //digitalWrite(key, LOW);

  //delay(100);
  //digitalWrite(key, HIGH);
  //delay(100);

  //digitalWrite(power, HIGH);
  Serial.begin(9600);
  blue.begin(38400);
  delay(100);
  //blue.write("AT");
  //delay(3000);

  //blue.write("AT+ROLE=0\r\n");
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

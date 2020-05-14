// Author: Asif Ally
// Email: allyx004@umn.edu
// Note: If you have any questions, email me.

#include <SoftwareSerial.h>


#define power 9
#define key 3

SoftwareSerial bt(6,5);

void setup() {
  pinMode(power, OUTPUT);
  pinMode(key, OUTPUT);

  digitalWrite(power, LOW);
  digitalWrite(key, LOW);

  delay(100);

  digitalWrite(key, HIGH);

  delay(2000);

  digitalWrite(power, HIGH);

  Serial.begin(9600);
  bt.begin(38400);
  delay(1000);
//  bt.write("AT");
//  delay(3000);

  bt.write("AT+ROLE=1\r\n");
  Serial.write("AT+ROLE=1\r\n");
  delay(1000);

  bt.write("AT+CMODE=1\r\n");
  Serial.write("AT+CMODE=1\r\n");
  delay(4000);
  

}

void loop() {
  //First HC_05
  bt.write("AT+BIND=0019,07,001D38\r\n");
  Serial.write("AT+BIND=0019,07,001D38\r\n");
  delay(2000);
  bt.write("AT+INIT\r\n");
  Serial.write("AT+INIT\r\n");
  delay(3000);
  bt.write("AT+INQ\r\n");
  Serial.write("AT+INQ\r\n");
  delay(4000);
  bt.write("AT+LINK=0019,07,001D38\r\n");
  Serial.write("AT+LINK=0019,07,001D38\r\n");
  bt.write("AT+BIND?\r\n");
  digitalWrite(key, LOW);
  delay(10000);

  bt.write('1');
  delay(2000);
  bt.write('0');
  delay(8000);
  digitalWrite(power, LOW);
  //digitalWrite(key, LOW);
  delay(1000);
  digitalWrite(key, HIGH);
  delay(1000);
  digitalWrite(power, HIGH);
  Serial.write("Disconnecting...\r\n");

  //Second HC_05
  bt.write("AT+BIND=0018,91,d832ca\r\n");
  Serial.write("AT+BIND=0018,91,d832ca\r\n");
  delay(2000);
  bt.write("AT+INIT\r\n");
  Serial.write("AT+INIT\r\n");
  delay(3000);
  bt.write("AT+INQ\r\n");
  Serial.write("AT+INQ\r\n");
  delay(4000);
  bt.write("AT+LINK=0018,91,d832ca\r\n");
  Serial.write("AT+LINK=0018,91,d832ca\r\n");
  bt.write("AT+BIND?\r\n");
  digitalWrite(key, LOW);
  delay(10000);

  bt.write('1');
  delay(2000);
  bt.write('0');
  delay(8000);
  digitalWrite(power, LOW);
  //digitalWrite(key, LOW);
  delay(1000);
  digitalWrite(key, HIGH);
  delay(1000);
  digitalWrite(power, HIGH);
  Serial.write("Disconnecting...\r\n");

}

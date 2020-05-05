#include <SoftwareSerial.h>
#include <stdlib.h>

SoftwareSerial HC12(10, 11);
SoftwareSerial laser(8, 9);

void setup() {
    HC12.begin(9600);
    Serial.begin(9600);
    laser.begin(9600);
}

int token = 10;
char buffer[4];

void loop() {
    /*if (HC12.available())
  {
    token = HC12.read();
    Serial.write(itoa(token, buffer, 10));
    Serial.write("\n");
   
  }
}

#include <SoftwareSerial.h>
#include <stdlib.h>

SoftwareSerial HC12(10, 11);

void setup()
{
  HC12.begin(9600);
  Serial.begin(9600);
}

int counter;
char buffer[4];

void loop()
{
    if (HC12.available())
    {
      counter = HC12.read();
      Serial.write(itoa(counter,buffer,10));
      Serial.write("\n");
  }
}


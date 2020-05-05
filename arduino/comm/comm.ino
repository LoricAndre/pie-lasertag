#include <SoftwareSerial.h>
#include <stdlib.h>

SoftwareSerial HC12(10, 11); // ACM1

void setup()
{
  HC12.begin(9600);
  Serial.begin(9600);
}
int i = 0;
char buffer[4];
void loop()
{
  HC12.write(i++);

  /*Serial.write("Transmitter: ");
    Serial.write(itoa(i,buffer,10));
    Serial.write("\n");*/

  delay(1);
  if (i == 255)
  {
    i = 0;
  }
}
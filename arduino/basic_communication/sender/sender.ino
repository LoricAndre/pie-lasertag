#include <SoftwareSerial.h>
#include <stdlib.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 13, 5, 4, 3, 2);

SoftwareSerial HC12(10, 11);
SoftwareSerial laser(8,9);

void setup()
{
  HC12.begin(9600);
  Serial.begin(9600);
  laser.begin(9600);
  lcd.begin(16, 2);
}

char token;
int i = 0;
int cursor = 0;
char buffer[4];

void loop()
{
  HC12.write(i++);

  Serial.write("Transmitter: ");
  Serial.write(itoa(i, buffer, 10));
  Serial.write("\n");

  if (laser.available())
  {
    token = laser.read();
    Serial.write(itoa(token, buffer, 10));
    Serial.write("\n");
    lcd.setCursor(cursor, 0);
    lcd.print(token);
    cursor = (cursor + 1) % 16;
  }
  lcd.setCursor(cursor,0);
  lcd.print('o');
  

  delay(1000);
  if (i == 255)
  {
    i = 0;
  }
  lcd.clear();
  cursor = 0;
}

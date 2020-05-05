#include <SoftwareSerial.h>
#include <stdlib.h>
#include <LiquidCrystal.h>

const byte rxPinLaser = 8;
const byte txPinLaser = 9;

const byte rxPinHC12 = 10;
const byte txPinHC12 = 11;

SoftwareSerial HC12 = SoftwareSerial(rxPinHC12, txPinHC12);
SoftwareSerial laser_receiver = SoftwareSerial(rxPinLaser, txPinLaser);

LiquidCrystal lcd = LiquidCrystal(12, 13, 5, 4, 3, 2);

void setup()
{
  pinMode(rxPinLaser, INPUT);
  pinMode(txPinLaser, OUTPUT);

  pinMode(rxPinHC12, INPUT);
  pinMode(txPinHC12, OUTPUT);

  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
  Serial.println("Serial communication set up");

  HC12.begin(9600);
  laser_receiver.begin(9600);
  lcd.begin(16, 2);
}

int token = 0;
char buffer[4];
int printed = 0;

int cursor = 0;
int col;
int row;

void loop()
{ 
  HC12.print(token++); 
  while (laser_receiver.available())
   {
   HC12.print(token++); 
   token = laser_receiver.read();
   Serial.println(itoa(token, buffer, 10));
   
   col = cursor % 16;
   row = cursor / 16;
   
   lcd.setCursor(col, row);
   lcd.print(token);
   
   cursor = (cursor + 1) % 32;
   printed = 1;
   }
  if (printed == 1)
  {
    delay(1500);
    lcd.clear();
    
    cursor = 0; 
    printed = 0;
  }
  delay(500);
}


#include <SoftwareSerial.h>
#include <stdlib.h>

// Test de débit un peu compliqué quand on test le débit max
// Si on souhaite juste communiquer
// Quentin faut que t'arrives à communiquer avec la Rasp si possible ne C ou C++ plutot que cette merde de Python

SoftwareSerial HC12(10, 11); // ACM0

void setup()
{
  HC12.begin(9600);
  Serial.begin(9600);
}
int counter;
int previous = 0;
char buffer[32];
int i;

unsigned long starttime;
unsigned long endtime;

void loop()
{
  i = 0;
  starttime = micros();
  endtime = starttime;
  while (endtime - starttime <= 1000000)
  {
    if (HC12.available())
    {
      // Normal comm :
      counter = HC12.read();
      //Serial.write(itoa(counter,buffer,10));

      // Tests :
      if (counter != previous + 1 && counter != 0)
      {
        Serial.write(itoa(counter, buffer, 10));
        Serial.write(" ERROR \n");
      }

      // Normal comm :
      //Serial.write("\n");
    }
    previous = counter;
    i++;
    endtime = micros();
  }
  // Display results of max rate,
  // Je suis pas sûr de la valeur affichée
  // Pourt l'instant j'ai pas réussi à augmenter le baud-rate avec succés
  Serial.write("Quantite de donnees transmises: ");
  Serial.write(itoa(i, buffer, 10));
  Serial.write("\n");
  delay(10000);
}

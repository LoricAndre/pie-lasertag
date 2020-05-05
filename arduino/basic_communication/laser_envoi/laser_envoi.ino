#include <SendOnlySoftwareSerial.h>
#include <SoftwareSerial.h>
#include <stdlib.h>

SoftwareSerial HC12(10,11);
SendOnlySoftwareSerial laser_emitter(9);// On connecte le pin "S" du laser au pin 9 de l'arduino (le pin 10 reste vide)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC12.begin(9600);
  laser_emitter.begin(9600);
}

int input;
char buffer[4];

void loop() {
  if(HC12.available()){  //Je ne sais pas si il envoie les caractèrtes un à un ou si le type char en langage Arduino comprend les string. C'est pourtant mon hypothèse parce qu'ils s'affichent d'un coup et non un à un sur l'écran LCD, mais c'est peut etre à cause du protocol de communication...
    input = HC12.read();
    Serial.print("Received: ");
    Serial.println(itoa(input, buffer, 10));
    laser_emitter.print(input);
    //laser_emitter.print("coucou les amis !");
  }
}

#include <string.h>
#include <ctype.h>

int redpin = 9;
int greenpin = 10;
int bluepin = 11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redpin,OUTPUT);
  pinMode(greenpin,OUTPUT);
  pinMode(bluepin,OUTPUT);

  digitalWrite(redpin, HIGH);
  digitalWrite(greenpin, HIGH);
  digitalWrite(bluepin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  // digitalWrite(ledPin, HIGH);
  if (Serial.available()) {
    String text = Serial.readStringUntil('\n');
    if (text=="Red"){
      digitalWrite(redpin, LOW);
      delay(500);
      digitalWrite(redpin, HIGH);
    }

    if (text=="Green"){
      digitalWrite(greenpin, LOW);
      delay(500);
      digitalWrite(greenpin, HIGH);
    }

    if (text=="Blue"){
      digitalWrite(bluepin, LOW);
      delay(500);
      digitalWrite(bluepin, HIGH);
    }

    if (text=="Dance"){
      for(int i =0; i<10; i++){
        analogWrite(redpin, random(0,255));
        analogWrite(greenpin, random(0,255));
        analogWrite(bluepin, random(0,255));
        delay(500);
        analogWrite(redpin, 255);
        analogWrite(greenpin, 255);
        analogWrite(bluepin, 255);
      }
    }
  }
}

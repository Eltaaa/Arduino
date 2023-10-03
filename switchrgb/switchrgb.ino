int readRed = 8;
int readGreen = 9;
int readBlue = 10;

int outRed = 2;
int outGreen = 3;
int outBlue = 4;

void setup() {
  // put your setup code here, to run once:

  pinMode(readRed, INPUT_PULLUP);
  pinMode(readGreen, INPUT_PULLUP);
  pinMode(readBlue, INPUT_PULLUP);

  pinMode(outRed, OUTPUT);
  pinMode(outGreen, OUTPUT);
  pinMode(outBlue, OUTPUT);
}


void loop() {
  if (digitalRead(readBlue) == LOW){
    digitalWrite(outBlue, LOW);
  }
  else{
    digitalWrite(outBlue, HIGH);
  }

  if (digitalRead(readRed) == LOW){
    digitalWrite(outRed, LOW); 
  }
  else{
    digitalWrite(outRed, HIGH);
  }

  if (digitalRead(readGreen) == LOW){
    digitalWrite(outGreen, LOW);
  }
  else{
    digitalWrite(outGreen, HIGH);
  }

  
 
}

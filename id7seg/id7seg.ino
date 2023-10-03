int ay = 0;
int by = 1;
int dy = 3;
int ey = 4;
int fy = 5;
int gy = 6;

int ax=8;
int bx=9;
int dx=10;
int ex=11;
int fx=12;
int gx=13;

void setup() {
  pinMode(ay, OUTPUT);
  pinMode(by, OUTPUT);

  pinMode(dy, OUTPUT);
  pinMode(ey, OUTPUT);
  pinMode(fy, OUTPUT);
  pinMode(gy, OUTPUT);

  pinMode(ax, OUTPUT);
  pinMode(bx, OUTPUT);
  pinMode(dx, OUTPUT);
  pinMode(ex, OUTPUT);
  pinMode(fx, OUTPUT);
  pinMode(gx, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  //C is always active in 65070163;
  
  

  digit65();
  delay(1000);
  digit07();
  delay(1000);
  digit01();
  delay(1000);
  digit63();
  delay(1000);
  delay(1000);
  
  // digitalWrite(ay, LOW);
  // digitalWrite(by, LOW);
  // digitalWrite(dy, LOW);
  // digitalWrite(ey, LOW);
  // digitalWrite(fy, LOW);
  // digitalWrite(gy, LOW);

  // digitalWrite(ax, LOW);
  // digitalWrite(bx, LOW);
  // digitalWrite(dx, LOW);
  // digitalWrite(ex, LOW);
  // digitalWrite(fx, LOW);
  // digitalWrite(gx, LOW);
  delay(1000);
}

void digit65(){
  // 6
  digitalWrite(ax, HIGH);
  digitalWrite(by, LOW);
  digitalWrite(dx, HIGH);
  digitalWrite(ex, HIGH);
  digitalWrite(fx, HIGH);
  digitalWrite(gx, HIGH);

  // 5
  digitalWrite(ay, HIGH);
  // digitalWrite(by, HIGH);
  digitalWrite(dy, HIGH);
  // digitalWrite(ey, HIGH);
  digitalWrite(fy, HIGH);
  digitalWrite(gy, HIGH);
  
}

void digit07(){
  // 0
  digitalWrite(ax, HIGH);
  digitalWrite(bx, HIGH);
  digitalWrite(dx, HIGH);
  digitalWrite(ex, HIGH);
  digitalWrite(fx, HIGH);
  digitalWrite(gx, LOW);

  // 7
  digitalWrite(ay, HIGH);
  digitalWrite(by, HIGH);
  digitalWrite(dy, LOW);
  digitalWrite(ey, LOW);
  digitalWrite(fy, LOW);
  digitalWrite(gy, LOW);
}


void digit01(){
  // 0
  digitalWrite(ax, HIGH);
  digitalWrite(by, LOW);
  digitalWrite(dx, HIGH);
  digitalWrite(ex, HIGH);
  digitalWrite(fx, HIGH);
  digitalWrite(gx, LOW);

  // 1
  digitalWrite(ay, LOW);
  digitalWrite(by, HIGH);
  digitalWrite(dy, LOW);
  digitalWrite(ey, LOW);
  digitalWrite(fy, LOW);
  digitalWrite(gy, LOW);
}

void digit63(){
  // 6
  digitalWrite(ax, HIGH);
  digitalWrite(bx, LOW);
  digitalWrite(dx, HIGH);
  digitalWrite(ex, HIGH);
  digitalWrite(fx, HIGH);
  digitalWrite(gx, HIGH);
  // 3
  digitalWrite(ay, HIGH);
  digitalWrite(by, HIGH);
  digitalWrite(dy, HIGH);
  digitalWrite(ey, LOW);
  digitalWrite(fy, LOW);
  digitalWrite(gy, HIGH);
}

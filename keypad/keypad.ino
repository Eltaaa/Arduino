const int row_size = 4;
const int col_size = 4;
char keys[row_size][col_size] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

char row_pin[row_size] = { 9, 8, 7, 6 };
char col_pin[col_size] = { 5, 4, 3, 2 };


void setup() {
  Serial.begin(9600);
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);


  // pinMode(red, OUTPUT);
  // digitalWrite(red, HIGH);

  // pinMode(green, OUTPUT);
  // digitalWrite(green, HIGH);

  // pinMode(blue, OUTPUT);
  // digitalWrite(blue, HIGH);
}

void loop() {

  char kp = getKey();
  // kp for keyPressed;

  // digitalWrite(11,LOW);
  // delay(500);
  // digitalWrite(11,HIGH);
  // delay(500);

  if (kp != 'k') {
    Serial.println(kp);
  }
  delay(100);
  // else{
  //   Serial.println('xxx');
  // }
}


char getKey() {
  char x = 'k';


  for (int c = 0; c < col_size; c++) {
    digitalWrite(col_pin[c], LOW);  // Rapidly turn on each column
    for (int r = 0; r < row_size; r++) {
      if (digitalRead(row_pin[r]) == LOW) {
        delay(100);
        x = keys[r][c];
      }
    }
    digitalWrite(col_pin[c], HIGH);
  }

  return x;
}

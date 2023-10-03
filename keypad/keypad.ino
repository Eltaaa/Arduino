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

int red = 11;
int green = 12;
int blue = 13;

void setup() {
  
  pinMode(9, INPUT);
  pinMode(8, INPUT);
  pinMode(7, INPUT);
  pinMode(6, INPUT);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);

  pinMode(red, OUTPUT);
  digitalWrite(red, HIGH);

  pinMode(green, OUTPUT);
  digitalWrite(green, HIGH);

  pinMode(blue, OUTPUT);
  digitalWrite(blue, HIGH);
}

void loop() {

  char kp = getKey();
  // kp for keyPressed;

  if (kp != 'k') {


    if (kp == '1') {
      digitalWrite(red, LOW);
    }

    if (kp == '2') {
      digitalWrite(green, LOW);
    }

    if (kp == '3') {
      digitalWrite(blue, LOW);
    }

    if (kp == 'A') {
      for (int i = 0; i <= 2; i++) {
        digitalWrite(red, LOW);
        delay(500);
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        delay(500);
        digitalWrite(green, HIGH);
        digitalWrite(blue, LOW);
        delay(500);
        digitalWrite(blue, HIGH);
      }
    }

    if (kp == '4') {
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
    }

    if (kp == '5') {
      digitalWrite(red, LOW);
      digitalWrite(blue, LOW);
    }

    if (kp == '6') {
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }

    if (kp == 'B') {
      for (int i = 0; i <= 2; i++) {
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        delay(500);
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(blue, LOW);
        delay(500);
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
        delay(500);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
      }
    }

    if(kp == '7'){
      digitalWrite(red,0);
      digitalWrite(green,0);
      digitalWrite(blue,0);
    }
  } else {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
  }
}


char getKey() {
  char x = 'k';


  for (int c = 0; c < col_size; c++) {
    digitalWrite(col_pin[c], LOW);  // Rapidly turn on each column
    for (int r = 0; r < row_size; r++) {
      if (digitalRead(row_pin[r]) == LOW) {
        delay(50);
        x = keys[r][c];
      }
    }
    digitalWrite(col_pin[c], HIGH);
  }

  return x;
}

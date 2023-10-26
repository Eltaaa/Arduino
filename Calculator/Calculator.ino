**Arduino Keypad calculator Program* /

#include <LiquidCrystal.h>  //Header file for LCD from https://www.arduino.cc/en/Reference/LiquidCrystal
#include <Keypad.h>         //Header file for Keypad from https://github.com/Chris--A/Keypad

const byte ROWS = 4;  // Four rows
const byte COLS = 4;    // Three columns

// Define  the Keymap
char keys[ROWS][COLS] = {

  { '7', '8', '9', '/' },

  { '4', '5', '6', '*' },

  { '1', '2', '3', '-' },

  { '*', '0', '#', '+' }

};

byte rowPins[ROWS] = { 0, 1, 2, 3 };  // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = { 4, 5, 6, 7 };  // Connect keypad COL0, COL1 and COL2 to these Arduino  pins.

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);  //  Create the Keypad

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;  //Pins to which LCD is connected
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String Num1 = "", Num2 = "", Number = "";
char key, action = '.';
boolean result = false;
boolean gotNum1 = false;

void setup() {
  lcd.begin(16, 2);             //We are using a 16*2 LCD  display
  lcd.print("DIY Calculator");  //Display a intro message
  lcd.setCursor(0, 1);          // set the cursor to column 0, line 1
  lcd.print("-CircuitDigest");  //Display a intro message

  delay(2000);  //Wait for display to show info
  lcd.clear();  //Then clean it
  Serial.begin(9600);
}

void loop() {

  key = kpd.getKey();  //storing pressed key value in a char
  if (key != NO_KEY) {
    // DetectButtons();

    if (key == '+') {
      action = '+';
      gotNum1 = true;
      Serial.print("_" + Num1 + "_");
      Serial.print(action);
      Serial.print("_" + Num2 + "_");
      continue;
    } else if (key == '-') {
      action = '-';
      gotNum1 = true;
      Serial.print("_" + Num1 + "_");
      Serial.print(action);
      Serial.print("_" + Num2 + "_");
      continue;
    } else if (key == '*') {
      action = '*';
      gotNum1 = true;
      Serial.print("_" + Num1 + "_");
      Serial.print(action);
      Serial.print("_" + Num2 + "_");
      continue;
    } else if (key == '/') {
      action = '/';
      gotNum1 = true;
      Serial.print("_" + Num1 + "_");
      Serial.print(action);
      Serial.print("_" + Num2 + "_");
      continue;
    }

    if (key != '#') {
      if (Num1 != "" && Num2 != "") {
        CalculateResult();
      }
    }

    if (!gotNum1) {
      Num1 += key;
      Serial.print("_" + Num1 + "_");
      Serial.print(action);
      Serial.print("_" + Num2 + "_");
    } else {
      Num2 += key;
      Serial.print("_" + Num1 + "_");
      Serial.print(action);
      Serial.print("_" + Num2 + "_");
    }
  }

  // if (result == true) {
  //   CalculateResult();
  // }

  // DisplayResult();
}



void CalculateResult() {
  if (action == '+')
    Number = Num1 + Num2;

  if (action == '-')
    Number = Num1 - Num2;

  if (action == '*')
    Number = Num1 * Num2;

  if (action == '/')
    Number = Num1 / Num2;
}

void DisplayResult() {
  lcd.setCursor(0, 0);  // set the cursor to column 0, line 1
  lcd.print(Num1);
  lcd.print(action);
  lcd.print(Num2);

  if (result == true) {
    lcd.print(" =");
    lcd.print(Number);
  }  //Display the result

  lcd.setCursor(0, 1);  // set the cursor to column  0, line 1
  lcd.print(Number);    //Display the result
}

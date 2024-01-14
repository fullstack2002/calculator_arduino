#include <SoftwareSerial.h>

char operation;
int number1, number2, result;
 
void setup() {
  Serial.begin(9600);
  Serial.println("Calculator:");
}
 
void loop() {
  number1 = readNumber("Please, enter Number 1:");
 
  number2 = readNumber("Please, enter Number 2:");
 
  operation = readOperator("Please, enter one of the operators +, -, *, / ...");
 
  switch (operation) {
    case '+':
      result = number1 + number2;
      break;
    case '-':
      result = number1 - number2;
      break;
    case '*':
      result = number1 * number2;
      break;
    case '/':
      if (number2 != 0) {
        result = number1 / number2;
      } else {
        Serial.println("You can't divide by 0!");
        return;
      }
      break;
    default:
      Serial.println("Invalid operator!");
      return;
  }
 
  Serial.print("The result is: ");
  Serial.print(String(number1) + " " + operation + " " + String(number2) + " = " + String(result));
  Serial.println();
 
  while (true) {
  }
}
 
 
int readNumber(const char *prompt) {
  Serial.println(prompt);
  while (!Serial.available()) {}
  int number = Serial.parseInt();
  clearInputBuffer();
  return number;
}
 
char readOperator(const char *prompt) {
  Serial.println(prompt);
  while (!Serial.available()) {}
  return Serial.read();
}
 
void clearInputBuffer() {
  while (Serial.available()) {
    char c = Serial.read();
  }
}
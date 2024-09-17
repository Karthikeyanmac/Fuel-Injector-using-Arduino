#include <Servo.h>
#include <LiquidCrystal.h>

Servo myServo;
int solenoidPin = 9; // Replace with your actual solenoid pin
int ledPin = 13; // Replace with your actual LED pin
int injectorPin = 13; // Replace with your actual injector pin
int randrpm;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  myServo.attach(solenoidPin);
  pinMode(ledPin, OUTPUT);
  pinMode(injectorPin, OUTPUT);
  randomSeed(analogRead(0));
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  // Simulate the solenoid valve opening
  myServo.write(180);
  delay(2000);

  // Turn on the LED
  digitalWrite(ledPin, HIGH);

  // Simulate the solenoid valve closing
  myServo.write(0);
  delay(2000);

  // Turn off the LED
  digitalWrite(ledPin, LOW);

  // Generate random RPM and calculate injection time
  randrpm = random(1000);
  int injectingTime = map(randrpm, 0, 999, 0, 2000);

  // Inject fuel
  digitalWrite(injectorPin, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("RPM: ");
  lcd.print(randrpm);
  lcd.setCursor(0, 1);
  lcd.print("Injection: ");
  lcd.print(injectingTime);
  delay(injectingTime);
  digitalWrite(injectorPin, LOW);
  delay(200);
}
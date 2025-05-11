#include <LiquidCrystal.h>

// LCD pin connections: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(7, 11, 12, 13, A0, A1);

// Pin Definitions
const int pirPin = 8;
const int buzzerPin = 9;
const int tempPin = A2;

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);

  // Initialize LCD
lcd.begin(16, 2);
lcd.print("Welcome");
delay(1000);
lcd.clear();


  // Initialize Sensor & buzzer Pins
  pinMode(pirPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Read temperature from TMP36
  int tempReading = analogRead(tempPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float temperatureC = (voltage - 0.5) * 100;

  // Read motion from PIR
  int motionDetected = digitalRead(pirPin);
  Serial.print("PIR state: ");
  Serial.println(motionDetected);
 

  if (motionDetected == HIGH) {
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Motion Detected");

    // Send data to serial
    Serial.println("a");
  } else {
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print((char)223); // degree symbol
    lcd.print("C");

    // Send temperature to serial
    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" C");
  }

  delay(1000);

  }
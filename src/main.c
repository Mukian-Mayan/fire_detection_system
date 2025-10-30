#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define FIRE_DO 7     
#define FIRE_AO A0    
#define LED 8         
#define BUZZER 9      

LiquidCrystal_I2C lcd(0x27, 16, 2); // LCD I2C address

int analogValue = 0;
int threshold = 400; // Adjust after testing your sensor
int fireState = 0;

void setup() {
  pinMode(FIRE_DO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();

  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Fire System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  fireState = digitalRead(FIRE_AO);
  analogValue = analogRead(FIRE_DO);

  // Print readings for debugging
  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print("  Digital: ");
  Serial.println(fireState);

  // Many MH sensors are "active LOW": 0 means fire detected
  bool fireDetected = (fireState == LOW) || (analogValue > threshold);

  if (fireDetected) {
    // 🔥 Fire detected
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    lcd.setCursor(0, 0);
    lcd.print("🔥 FIRE DETECTED ");
    lcd.setCursor(0, 1);
    lcd.print("Evacuate Now!   ");
  } else {
    // 🟢 No fire detected
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);

    lcd.setCursor(0, 0);
    lcd.print("System Safe     ");
    lcd.setCursor(0, 1);
    lcd.print("Monitoring...   ");
  }

  delay(300);
}
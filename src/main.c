#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define FIRE_SENSOR 7      // Fire sensor digital output (D0)
#define SMOKE_SENSOR A0    // Smoke sensor analog output (A0)
#define FIRE_LED 8         // Red LED for fire
#define SMOKE_LED 10       // Yellow LED for smoke
#define BUZZER 9           // Buzzer pin

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD at I2C address 0x27

int smokeValue = 0;
int smokeThreshold = 60;  // Adjust this based on your MQ2 sensor readings
int fireState = HIGH;      // Default (no fire)

void setup() {
  pinMode(FIRE_SENSOR, INPUT);
  pinMode(SMOKE_SENSOR, INPUT);
  pinMode(FIRE_LED, OUTPUT);
  pinMode(SMOKE_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  Serial.println("Initializing Fire & Smoke System...");
  lcd.setCursor(0, 0);
  lcd.print("System Initializing");
  delay(2000);
  lcd.clear();
}

void loop() {
  smokeValue = analogRead(SMOKE_SENSOR);
  fireState = digitalRead(FIRE_SENSOR);

  Serial.print("Smoke Value: ");
  Serial.print(smokeValue);
  Serial.print(" | Fire State: ");
  Serial.println(fireState);

  // 🔥 FIRE detected (LOW signal from sensor)
  if (fireState == HIGH) {
    digitalWrite(FIRE_LED, HIGH);
    digitalWrite(SMOKE_LED, LOW);
    digitalWrite(BUZZER, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("🔥 FIRE DETECTED!");
    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.print(smokeValue);
    lcd.print(" F:");
    lcd.print(fireState);
    lcd.print(" ");
    Serial.println("🔥 FIRE ALERT!");

  // 💨 SMOKE detected (AO > threshold)
  } else if (smokeValue > smokeThreshold) {
    digitalWrite(SMOKE_LED, HIGH);
    digitalWrite(FIRE_LED, LOW);
    digitalWrite(BUZZER, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("💨 SMOKE DETECTED!");
    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.print(smokeValue);
    lcd.print(" F:");
    lcd.print(fireState);
    lcd.print(" ");
    Serial.println("💨 SMOKE ALERT!");

  // ✅ Safe condition
  } else {
    digitalWrite(FIRE_LED, LOW);
    digitalWrite(SMOKE_LED, LOW);
    digitalWrite(BUZZER, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("✅ Environment OK");
    lcd.setCursor(0, 1);
    lcd.print("S:");
    lcd.print(smokeValue);
    lcd.print(" F:");
    lcd.print(fireState);
    lcd.print(" ");
    Serial.println("✅ SAFE");
  }

  delay(1000);
}
#define BLYNK_TEMPLATE_ID "TMPL3jJTgX0Uo"
#define BLYNK_TEMPLATE_NAME"Soil moisture"
#define BLYNK_AUTH_TOKEN "bp2BZmoztMYbElG0yuRO2y-uRdZsJH4T"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>

// Define Pins
#define DHTPIN 4
#define DHTTYPE DHT11
#define SOIL_MOISTURE_PIN 34
#define RELAY_PIN 27

// WiFi credentials
char ssid[] = "Test123";
char pass[] = "00000000";

DHT dht(DHTPIN, DHTTYPE);

// Control variables
int manualControl = 0;

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Motor OFF initially (active LOW)
}

// Manual/Auto switch (from Blynk)
BLYNK_WRITE(V3) {
  manualControl = param.asInt();
}

void loop() {
  Blynk.run();

  // Read sensor values
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int rawSoil = analogRead(SOIL_MOISTURE_PIN);

  // Map soil moisture to 0–100%
  int moisturePercent = map(rawSoil, 4095, 1800, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  // Send sensor values to Blynk
  Blynk.virtualWrite(V0, moisturePercent);  // Soil moisture %
  Blynk.virtualWrite(V1, temperature);      // Temperature °C
  Blynk.virtualWrite(V2, humidity);         // Humidity %

  // Motor control logic
  if (manualControl == 1) {
    // Manual mode: motor always ON
    digitalWrite(RELAY_PIN, LOW);  // Relay ON (active LOW)
    Blynk.virtualWrite(V4, 1);     // LED ON
  } else {
    // Auto mode: check moisture threshold
    if (moisturePercent < 40) {
      digitalWrite(RELAY_PIN, LOW);  // Relay ON
      Blynk.virtualWrite(V4, 1);
    } else {
      digitalWrite(RELAY_PIN, HIGH); // Relay OFF
      Blynk.virtualWrite(V4, 0);
    }
  }

  delay(1000); // Delay to avoid flooding Blynk
}
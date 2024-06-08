#include <SimpleDHT.h>

SimpleDHT11 dht11;

int pinDHT11 = 2;
const int buzzer = 5;

void setup() { 
  Serial.begin(115200); 
}

void loop() {
  Serial.println("=================================");
  Serial.println("Sample DHT11...");

  byte temperature = 0;
  byte humidity = 0;

  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    Serial.println("Read DHT11 failed.");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print((int)humidity);
  Serial.println(" %");

  if (humidity <= 50) {
    digitalWrite(buzzer, HIGH); // Turn on buzzer if humidity is below 50%
  } else {
    digitalWrite(buzzer, LOW); // Turn off buzzer if humidity is 50% or above
  }

  delay(1000); // Delay for stability
}

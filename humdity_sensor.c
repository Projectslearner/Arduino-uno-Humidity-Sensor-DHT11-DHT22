/*
    Project name : Arduino Uno Humidity Sensor (DHT11)
    Modified Date: 29-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-uno-humidity-sensor
*/

#include <DHT.h>

// Define the type of sensor (DHT11)
#define DHTPIN 2        // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

// Initialize DHT sensor for normal 16 MHz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Read humidity from DHT sensor
  float humidity = dht.readHumidity();

  // Check if read failed and exit early (to try again)
  if (isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print humidity value to Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}

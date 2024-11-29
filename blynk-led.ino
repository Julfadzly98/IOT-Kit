#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_DEVICE_NAME "YourDeviceName"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// Replace with your network credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Define the LED pin
const int ledPin = 2;  // GPIO 2 (Default for onboard LED)

BLYNK_WRITE(V1) {
  int ledState = param.asInt();  // Get value from the Blynk app button
  digitalWrite(ledPin, ledState);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Ensure LED is initially off

  // Connect to Blynk IoT
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
}

void loop() {
  Blynk.run();  // Keep Blynk connected
}

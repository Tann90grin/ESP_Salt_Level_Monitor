#include <ESP8266WiFi.h>
const char* SSID;
const char* PASSWORD;
const int trigPin = 13;
const int echoPin = 12;
long duration;
float distanceCM;
#define SOUND_VELOCITY 0.034

void setup()
{
  Serial.begin(115200);
  Serial.println();
  WiFi.hostname("ESP-host");
  WiFi.begin("network-name", "pass-to-network");

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCM = duration * SOUND_VELOCITY / 2;
  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.println("cm");
  delay(1000);
}

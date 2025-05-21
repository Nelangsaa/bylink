#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_TEMPLATE_ID "TMPL6_5kNuLSY"
#define BLYNK_TEMPLATE_NAME "kendali servo"
#define BLYNK_AUTH_TOKEN "w6RbYSw5F7dEUddErBDr81GOZFxP0zCw"

#include <BlynkSimpleEsp32.h>
#include<ESP32Servo.h>

char ssid[] = "SMTI";
char pass[] = "";
char auth[] = "w6RbYSw5F7dEUddErBDr81GOZFxP0zCw";

#define SERVO_PIN 2 
#define VIRTUAL_PIN V0

Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("coneccting to wifi...");
  }
  Serial.println("coneccting to wifi");
  Blynk.begin(auth, ssid, pass);
  
  servo.attach(SERVO_PIN);
  Blynk.virtualWrite(VIRTUAL_PIN, 90);
}
BLYNK_WRITE(VIRTUAL_PIN){
  int angle = param.asInt();
  servo.write(angle);


Serial.println("Nilai Sudut : ");
Serial.println(angle);
}



void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
}

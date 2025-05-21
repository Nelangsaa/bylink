#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_TEMPLATE_ID "TMPL6t9Nv7MH6"
#define BLYNK_TEMPLATE_NAME "APIIII"
#define BLYNK_AUTH_TOKEN "SeyDJBX3eDarB0BDOK1lFX_4itCLpDzL"

#include <BlynkSimpleEsp32.h>
char ssid[] = "SMTI";
char pass[] = "";
char auth[] = "SeyDJBX3eDarB0BDOK1lFX_4itCLpDzL";

#define FLAME_SENSOR_PIN 2
#define PIN_LED1 V0
#define PIN_LED2 V1
#define PIN_LABEL V2

BlynkTimer timer;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("sabar boss");
  }

  Serial.println("wifi conect boss");

  Blynk.begin(auth, ssid, pass);
  pinMode(FLAME_SENSOR_PIN, INPUT);
  timer.setInterval(1000L, checkFlameStatus);
}

void checkFlameStatus() {
  // put your main code here, to run repeatedly:
  int flameValue = digitalRead(FLAME_SENSOR_PIN);

  if (flameValue == HIGH){
    Blynk.virtualWrite(PIN_LED1, HIGH);
    Blynk.virtualWrite(PIN_LED2, LOW);
    Blynk.virtualWrite(PIN_LABEL, "KONDISI AMAN, API TIDAK TERDETEKSI");

    Serial.print("Nilai Pembacaan Sensor");
    Serial.println(flameValue);
    Serial.println("KONDISI AMAN, API TIDAK TERDETEKSI");
    Serial.println("Menghidupkan LED 1 (VO)");
    Serial.println("");
  }else{
    Blynk.virtualWrite(PIN_LED1, LOW);
    Blynk.virtualWrite(PIN_LED2, HIGH);
    Blynk.virtualWrite(PIN_LABEL, "KONDISI BAHAYA, TERDETEKSI API");

    Serial.print("Nilai Pembacaan Sensor");
    Serial.println(flameValue);
    Serial.println("KONDISI BAHAYA, TERDETEKSI API");
    Serial.println("Menghidupkan LED 2 (V1)");
    Serial.println("");
  }

}
void loop(){
   Blynk.run();
  timer.run();
}

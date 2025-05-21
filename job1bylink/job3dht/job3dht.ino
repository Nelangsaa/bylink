#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_TEMPLATE_NAME "DHT11
#define BLYNK_TEMPLATE_ID "TMPL6t9SuNAp3"
#define BLYNK_AUTH_TOKEN "cV-iPA1lLyLQCFcmA6PHk0a5uG4Q_q0w"

#include <BlynkSimpleEsp32.h>
#include <DHT.h>

char ssid[] = "SMTI";
char pass[] = "";
char auth[] = "cV-iPA1lLyLQCFcmA6PHk0a5uG4Q_q0w";

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.print("Suhu : ");
  Serial.print(t);
  Serial.println("°C");
  Serial.print("Kelembapan : ");
  Serial.print(h);
  Serial.println("%");

  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

   WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println(".");
  }
  Serial.println("");
  Serial.println("wifi conect boss");


  Blynk.begin(auth, ssid, pass);
  dht.begin();
  timer.setInterval(2000L, sendSensor);

}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();

}

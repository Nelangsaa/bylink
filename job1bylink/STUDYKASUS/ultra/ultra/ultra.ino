#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_TEMPLATE_ID "TMPL66bOwFjNd"
#define BLYNK_TEMPLATE_NAME "ultrasonik"
#define BLYNK_AUTH_TOKEN "-t0rrSC9_OTM6G7Bz5TV1pD8wVkdj7mx"

#include <BlynkSimpleEsp32.h>


char ssid[] = "SMTI";
char pass[] = "";
char auth[] = "-t0rrSC9_OTM6G7Bz5TV1pD8wVkdj7mx";

#define triggerPin 12
#define echoPin 13

BlynkTimer timer;

void sendSensor(){
digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);


 float duration = pulseIn(echoPin, HIGH);

 float jarak = (duration/2)*0.034 ;


 
  Serial.print("Jarak: ");
  Serial.print(jarak);
  Serial.println(" cm");
    delay(500); 
  Blynk.virtualWrite(V0, jarak);



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
 
 
  pinMode(triggerPin, OUTPUT); 
  pinMode(echoPin, INPUT);
    timer.setInterval(2000L, sendSensor);


}

void loop() {
  // put your main code here, to run repeatedly:


  Blynk.run();
  timer.run();
}

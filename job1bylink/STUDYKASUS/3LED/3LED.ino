#include <WiFi.h>
#include <WiFiClient.h>
#define BLYNK_TEMPLATE_ID "TMPL6eIuxBykA"
#define BLYNK_TEMPLATE_NAME "kendali led"
#define BLYNK_AUTH_TOKEN "XYLCEPr-GHze7pjKoCPWz69d0L26O33e"


#include <BlynkSimpleEsp32.h>

char ssid[] = "SMTI";
char pass[] = "";
char auth[] = "XYLCEPr-GHze7pjKoCPWz69d0L26O33e";

#define LED_PIN1 2
#define LED_PIN2 0
#define LED_PIN3 4

BlynkTimer timer;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Conneced to WiFi");

  Blynk.begin(auth, ssid, pass);

  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  

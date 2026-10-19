
#include <Arduino.h>
#include"config.h"
#include <PubSubClient.h>

/*--------------------Project globals-------------------*/
unsigned long currentMillis = 0;
unsigned long previousMillis10ms = 0;
unsigned long previousMillis100ms = 0;
unsigned long previousMillis500ms = 0;
unsigned long previousMillis1000ms = 0;
/*--------------------------end--------------------------*/

const char *ssid = "Redmi_Note_10S";
const char *pswd = "lalima16";


bool flgDeviceReadyLedStatus = 0;

void IOT_AP_ini()
{
  pinMode(LED_DEVICE_READY, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // Start Serial monitor
  Serial.begin(115200);
  delay(1000);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Wait until connection is established
  WiFi.begin(ssid,pswd);



  // Wait until connection is established
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(LED_BUILTIN, ON);
    delay(200);
    digitalWrite(LED_BUILTIN, OFF);
    delay(200);
    Serial.print(".");
  }

  if(WiFi.status() == WL_CONNECTED)
  {
    // Once connected, print success message and local IP address
    Serial.println("");
    Serial.println("WiFi connected successfully!");
    digitalWrite(LED_BUILTIN, ON);
    delay(100);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP()); // This is your NodeMCU's local IP on your network
  }
}


void IOT_AP_500ms()
{
  Serial.println("500ms tick: System is running smoothly!");
  toggleLed(LED_DEVICE_READY);
}

void toggleLed(int led)
{
  //ledStatus?digitalWrite(led, OFF):digitalWrite(led, ON);
  if(led == LED_DEVICE_READY)
  {
    
    if(flgDeviceReadyLedStatus == 1){
      flgDeviceReadyLedStatus = 0;
      digitalWrite(led, OFF);
      Serial.println("LED_DEVICE_READY : OFF");
    }else{
      flgDeviceReadyLedStatus = 1;
      digitalWrite(led, ON);
      Serial.println("LED_DEVICE_READY : ON");
    }
  }
}
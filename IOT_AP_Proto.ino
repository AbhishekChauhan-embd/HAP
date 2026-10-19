/*
This is the program to connect the NodeMCU to the Wi-Fi
*/

#include"config.h"

void setup() {

  IOT_AP_ini();

}

void loop() {

    currentMillis = millis();
    
    if((currentMillis-previousMillis500ms) >= 500){
      previousMillis500ms = currentMillis;
      IOT_AP_500ms();
      //Serial.println("500ms tick: System is running smoothly!");
    }

    if (currentMillis - previousMillis1000ms >= 1000) {
     previousMillis1000ms = currentMillis;
     Serial.println("1-second tick: System is running smoothly!");
    }
}


#ifndef CONFIG_H
#define CONFIG_H

#include<ESP8266WiFi.h>



/*--------------------Project globals (Extern Declarations)-------------------*/
extern unsigned long currentMillis;
extern unsigned long previousMillis10ms;
extern unsigned long previousMillis100ms;
extern unsigned long previousMillis500ms;
extern unsigned long previousMillis1000ms;
/*--------------------------end--------------------------*/


/*---------------TASK Function Declaration---------------*/

void IOT_AP_ini();
void IOT_AP_500ms();

/*--------------------------end--------------------------*/

/*------------------Function Declaration-----------------*/
void toggleLed(int led);
/*--------------------------end--------------------------*/

#define LED_DEVICE_READY D0
#define ON 0x0
#define OFF 0x1

#endif
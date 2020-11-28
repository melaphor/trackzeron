/*
 * Original programming by W11cE: http://github.com/W11cE/Azeron-Simplified-Firmware-for-XIM-Apex
 * 
 * Libraries used:
 * PMW3360 Module Library for Arduino by Sunjun Kim https://www.arduino.cc/reference/en/libraries/pmw3360-module/
 */
  
#include "RefreshChecker.h"
#include <PMW3360.h>

#define ARRAY_LENGHT(type ,array)	(sizeof(array) / sizeof(type))

#define BUTTON_T4_P1  4     //index pull
#define BUTTON_T4_P2  5     //index push
#define BUTTON_T4_P3  8     //index flick 
#define BUTTON_T4_P4  9     //index high 
#define BUTTON_T4_P5  10    //index highest
#define BUTTON_T5_P1  11    //index side
#define BUTTON_T3_P1  27    //middle pull 
#define BUTTON_T3_P2  0     //middle push 
#define BUTTON_T3_P3  1     //middle flick 
#define BUTTON_T3_P4  2     //middle high 
#define BUTTON_T3_P5  3     //middle highest 
#define BUTTON_T2_P1  42     //ring pull 
#define BUTTON_T2_P2  43     //ring push 
#define BUTTON_T2_P3  44     //ring flick 
#define BUTTON_T2_P4  45     //ring high
#define BUTTON_T1_P1  38     //pinky pull 
#define BUTTON_T1_P2  39     //pinky push 
#define BUTTON_T1_P3  40     //pinky flick 
#define BUTTON_T1_P4  41     //pinky high 

const int DigitalButtons[] = {
	 BUTTON_T1_P1,
	 BUTTON_T2_P1,
	 BUTTON_T3_P1,
	 BUTTON_T4_P1,
	 BUTTON_T5_P1,
	 BUTTON_T1_P2,
	 BUTTON_T2_P2,
	 BUTTON_T3_P2,
	 BUTTON_T4_P2,
	 BUTTON_T1_P3,
	 BUTTON_T2_P3,
	 BUTTON_T3_P3,
	 BUTTON_T4_P3,
	 BUTTON_T1_P4,
	 BUTTON_T2_P4,
	 BUTTON_T3_P4,
	 BUTTON_T4_P4,
	 BUTTON_T3_P5,
	 BUTTON_T4_P5,
	};

#define SWITCH_1		14
#define SWITCH_2		13

#define LED_1			16
#define LED_2			15
#define LED_TEENSY		6

RefreshChecker Check = RefreshChecker(27);

#define SS  20 
PMW3360 sensor;

void setup()
{

Serial.begin(9600);  
  // With this line, your arduino will wait until a serial communication begin.
  // If you want your mouse application to work as soon as plug-in the USB, remove this line.
  //while(!Serial); 

  //sensor.begin(20, 1600); // to set CPI (Count per Inch), pass it as the second parameter
  if(sensor.begin(SS))  // 20 is the pin connected to SS of the module.
    Serial.println("Sensor initialization successed");
  else
    Serial.println("Sensor initialization failed");
  sensor.setCPI(1600);    // or, you can set CPI later by calling setCPI();

  Mouse.begin();
  
	Joystick.useManualSend(true);
	Joystick.hat(-1);
	Joystick.slider(512);
	Joystick.sliderLeft(0);
	Joystick.sliderRight(0);
	Joystick.Z(512);
	Joystick.Zrotate(512);

	for (int i = 0; i < ARRAY_LENGHT(int, DigitalButtons); i++)
	{
		pinMode(DigitalButtons[i], INPUT_PULLUP);
	}
	pinMode(SWITCH_1, INPUT_PULLUP);
	pinMode(SWITCH_2, INPUT_PULLUP);

	pinMode(LED_1, OUTPUT);
	pinMode(LED_2, OUTPUT);
	pinMode(LED_TEENSY, OUTPUT);

	analogWrite(LED_1, 1);
	analogWrite(LED_2, 0);
	digitalWrite(LED_TEENSY, 0);
  
}

void loop()
{
	for (int i = 0; i < ARRAY_LENGHT(int, DigitalButtons); i++)
	{
		Joystick.button(i + 1, Check.PassNew(i, !digitalReadFast(DigitalButtons[i])));
	}

	if (Check.HasNewData())
	{
		Joystick.send_now();
	}
   
   PMW3360_DATA data = sensor.readBurst();
  if(data.isOnSurface && data.isMotion)
  {
    int mdx = constrain(data.dx, -127, 127);
    int mdy = constrain(data.dy, -127, 127);

    Mouse.move(-mdx, mdy, 0);
  } 
}

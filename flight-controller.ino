#include <Arduino.h>

#include "config.h"

void pwm_setup(void);
void arm_esc_4in1(void);
void setup()
{  
    //Serial.begin(115200);

    pwm_setup();
    arm_esc_4in1();
}

void loop()
{
    for(int i = 1040; i < 1960; i+=10){
        HwPWM0.writePin(ESC_PIN_0, i, false);
        HwPWM0.writePin(ESC_PIN_1, i, false);
        HwPWM0.writePin(ESC_PIN_2, i, false);
        HwPWM0.writePin(ESC_PIN_3, i, false);    
        delay(10);
    }
    delay(1000);
    for(int i = 1960; i > 1000; i-=10){
        HwPWM0.writePin(ESC_PIN_0, i, false);
        HwPWM0.writePin(ESC_PIN_1, i, false);
        HwPWM0.writePin(ESC_PIN_2, i, false);
        HwPWM0.writePin(ESC_PIN_3, i, false); 
        delay(10);
    }
    delay(3000);
}

void pwm_setup()
{
    HwPWM0.addPin(ESC_PIN_0);
    HwPWM0.addPin(ESC_PIN_1);
    HwPWM0.addPin(ESC_PIN_2);
    HwPWM0.addPin(ESC_PIN_3);
    HwPWM0.setMaxValue(2500);
    HwPWM0.setClockDiv(PWM_PRESCALER_PRESCALER_DIV_16); // freq = 1Mhz
    HwPWM0.begin();
}

void arm_esc_4in1()
{
    HwPWM0.writePin(ESC_PIN_0, SPEED_ARM_0, false);
    HwPWM0.writePin(ESC_PIN_1, SPEED_ARM_1, false);
    HwPWM0.writePin(ESC_PIN_2, SPEED_ARM_2, false);
    HwPWM0.writePin(ESC_PIN_3, SPEED_ARM_3, false);
    delay(500);
    HwPWM0.writePin(ESC_PIN_0, SPEED_MIN_0, false);
    HwPWM0.writePin(ESC_PIN_1, SPEED_MIN_1, false);
    HwPWM0.writePin(ESC_PIN_2, SPEED_MIN_2, false);
    HwPWM0.writePin(ESC_PIN_3, SPEED_MIN_3, false);
    delay(5000);
}

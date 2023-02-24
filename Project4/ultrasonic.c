/*
 * Ultrasonic.c
 *
 *  Created on: Oct 13, 2022
 *      Author: pc
 */


#include "icu.h"
#include "gpio.h"
#include <util/delay.h>
#include "ultrasonic.h"
#include <avr/io.h>

void Ultrasonic_init(void){
	Icu_ConfigType Icu_Config = {F_CPU_8,RISING};
	Icu_init(&Icu_Config);
	Icu_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(ULTRA_SONIC_TRIGGER_PORT,ULTRA_SONIC_TRIGGER_PIN,PIN_OUTPUT);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(ULTRA_SONIC_TRIGGER_PORT,ULTRA_SONIC_TRIGGER_PIN,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRA_SONIC_TRIGGER_PORT,ULTRA_SONIC_TRIGGER_PIN,LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void){
	Ultrasonic_Trigger();
	while(g_edgeCount != 2);
	TCNT1=0;
	distance = (((float)(g_timeHigh * 0.01715))+1);
	return distance;
}

void Ultrasonic_edgeProcessing(void){
	g_edgeCount++;
	if(g_edgeCount == 1){
	Icu_clearTimerValue();
	Icu_setEdgeDetectionType(FALLING);}
	else if(g_edgeCount == 2){
	g_timeHigh = Icu_getInputCaptureValue();}
	}


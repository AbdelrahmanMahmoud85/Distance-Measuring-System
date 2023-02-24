#include "LCD.h"
#include "icu.h"
#include <avr/io.h>
#include "Ultrasonic.h"


int main(void){
	g_edgeCount = 0;
	uint16 dist;
	SREG |= (1<<7);
	Ultrasonic_init();
	LCD_init();
	LCD_displayString("Distance =    cm");
	while(1){
	dist = Ultrasonic_readDistance();
	Icu_setEdgeDetectionType(RISING);
	Icu_clearTimerValue();
	g_edgeCount = 0;
	LCD_moveCursor(0,11);
	if(dist > 99){
	LCD_intgerToString(dist);
	}
	else{
		LCD_intgerToString(dist);
		LCD_displayCharacter(' ');
		}
	}}

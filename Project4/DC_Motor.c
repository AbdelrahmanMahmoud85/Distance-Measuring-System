 /******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: DC_Motor.h
 *
 * Description: Source file for the DC Motor driver
 *
 * Author: Abdelrahman Mahmoud
 *
 *******************************************************************************/

#include "gpio.h"
#include "DC_Motor.h"
#include "Timer0.h"

void DCmotor_init(void){
	GPIO_setupPinDirection(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_LOW);
}
void DCmotor_rotate(DCMotor_State state,uint8 speed){
	PWM_Timer0_Start(speed);
	switch(state){
	case Stop:
		GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_HIGH);
		break;
	case ACW:
		GPIO_writePin(DC_MOTOR_IN1_PORT, DC_MOTOR_IN1_PIN, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_IN2_PORT, DC_MOTOR_IN2_PIN, LOGIC_LOW);
		break;
	}
}


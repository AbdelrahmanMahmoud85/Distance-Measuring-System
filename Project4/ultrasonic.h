/*
 * Ultrasonic.h
 *
 *  Created on: Oct 13, 2022
 *      Author: pc
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
uint8 g_edgeCount;
uint16 g_timeHigh;
uint16 distance;

#define ULTRA_SONIC_TRIGGER_PORT               PORTB_ID
#define ULTRA_SONIC_TRIGGER_PIN                PIN5_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Ultrasonic_edgeProcessing(void);
void Ultrasonic_init(void);
void Ultrasonic_Trigger(void);
uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */

/*
 * SAV_Sound_lib.h
 *
 *  Created on: Nov 11, 2023
 *      Author: AndrewS
 */

#ifndef INC_SAV_SOUND_LIB_H_
#define INC_SAV_SOUND_LIB_H_

#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define F_TIM_1TICK 1000000//in Hz
//
/*
#define G4 319//Sol4 - Period CNT
#define G4is 301//Sol4# - Period CNT
#define A4 284//La4 - Period CNT
#define A4s 268//La4# - Period CNT
#define H4 253//Si4 - Period CNT
#define C5 239//Do5 - Period CNT
#define C5is 225//Do5# - Period CNT
#define D5 213//Re5 - Period CNT
#define D5is 201//Re5# - Period CNT
#define E5 190//Mi5 - Period CNT
#define F5 179//Fa5 - Period CNT
#define F5is 169//Fa5# - Period CNT
#define G5 159//Sol5 - Period CNT
#define G5is 150//Sol5# - Period CNT
#define A5 142//La5 - Period CNT
#define A5s 134//La5# - Period CNT
#define H5 127//Si5 - Period CNT
*/
// Sound Notes In Hertz
#define g4	3136
#define g4is	3322.4
#define a4	3520
#define a4s	3729.3
#define h4	3951.1
#define c5	4186
#define c5is	4434.9
#define d5	4698.6
#define d5is	4978
#define e5	5274
#define f5	5587.7
#define f5is	5919.9
#define g5	6271.9
#define g5is	6644.9
#define a5	7040
#define a5is	7458.6
#define h5	7902.1
//
//
#define  TIM1_Freq_Hz		(uint32_t)(8000000)
#define  PRESCALER_VALUE    (uint32_t)(((SystemCoreClock) / TIM1_Freq_Hz) - 1)
//
//
void Play_Sound_Note (uint16_t, uint8_t, uint16_t);
void Play_Sound_Note_FADE_IN (uint16_t, uint16_t); // From 0 to Max (PWM = 50%)
void Play_Sound_Note_FADE_OUT (uint16_t, uint16_t);// From Max (PWM = 50%) to 0
void Melody1 (void);

#endif /* INC_SAV_SOUND_LIB_H_ */

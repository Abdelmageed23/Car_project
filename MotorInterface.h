/*
 * Motor.h
 *
 * Created: 1/9/2022 5:05:30 PM
 *  Author: No. 01
 */ 
/*
MOTOR 1 EN PIN 4
MOTOR 2 EN PIN 5
MOTOR 1 DIR A PIN 2
MOTOR 1 DIR B PIN 3
MOTOR 2 DIR A PIN 6
MOTOR 2 DIR B PIN 7
*/

#ifndef MOTOR_H_
#define MOTOR_H_
#include "PWM.h"


#define MOTOR_1 0
#define MOTOR_2 1

#define MOTOR_DIR_1A 2
#define MOTOR_DIR_1B 3
#define MOTOR_EN_1 4
#define MOTOR_EN_2 5
#define MOTOR_DIR_2A 6
#define MOTOR_DIR_2B 7

#define FWD HIGH
#define REV LOW

MOTORS_init(uint8_t numMotor);// numMotor (initalize Direction pins only (PWM initializes enable pins inside them))
MOTOR_speed(uint8_t dutyCycle);//  30/60/90 (Start PWM and initialize duty cycle)
MOTOR_direction(uint8_t numMotor, uint8_t DIR);//  numMotor/(FWD,REV) (Set direction of specified motor) i.e (MOTOR_1, FWD) meaning motor 1, move forward
MOTOR_off(uint8_t numMotor);// stop specified motor (writes LOW on DIR data pins)





#endif /* MOTOR_H_ */
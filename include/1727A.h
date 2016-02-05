/*
 * 1727B.h
 *
 *  Created on: Jan 29, 2016
 *      Author: Anton
 */

#ifndef _1727A_H_
#define _1727A_H_

#include <API.h>
#include "rexAPI.h"
#include "math.h"

#define R1		1
#define R2		8
#define R3		4
#define L1		2
#define L2		10
#define L3		5
#define INTAKE	3
#define LOCK	7


#define FLYWHEEL_CIRCUMFERENCE (5*3.1415926535)


typedef struct pidVars
{
	float velocity;
	float velocityRaw;
	float power;
	float powerRaw;
}pidVars;

typedef struct flywheel
{
	pidVars variables;
	pidParams parameters;
}flywheel;

void flywheelInit(flywheel aFlywheel,int (*input)(), int (*target)(), float kP, float kI, float kD, int outputs[4]);

void velocityReader(void *ignore);

void powerListener(void *params);

void driveControl(void *params);

int getRPower();

int getLPower();

int getRVel();
int getLVel();

bool twoJoysticks;

flywheel rightFlywheel;

flywheel leftFlywheel;

TaskHandle rightFlywheel_task;

TaskHandle leftFlywheel_task;

TaskHandle powerListener_task;

TaskHandle velocity_task;

TaskHandle drive_task;

TaskHandle joystick_task;

Encoder leftFlywheelEncoder;

Encoder rightFlywheelEncoder;
#endif /* _1727B_H_ */

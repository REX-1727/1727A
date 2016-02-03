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

#define R				3
#define L				8
#define LOWER_INTAKE	7
#define UPPER_INTAKE	4
#define LIFT			5
#define LIFT_2			6


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
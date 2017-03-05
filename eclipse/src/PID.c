/*
 * Proportional (P)
 * Integral (I)
 * Derivative (D)
 *
 * These 3 modes are used in different combinations:
 * P ¨C Sometimes used
 * PI - Most often used
 * PID ¨C Sometimes used
 * PD ¨C rare as hen¡¯s teeth but can be useful for controlling servomotors.
 *
 * */

#include "PID.h"


F8 UpdatePID(SPid* pid, F8 error, F8 position)
{
	F8 pTerm, dTerm, iTerm;
	F8 result;

	pTerm = pid->pGain * error;

	pid->iState += error;
	if(pid->iState > pid->iMax)
		pid->iState = pid->iMax;
	else if (pid->iState  < pid->iMin)
		pid->iState = pid->iMin;

	iTerm = pid->iGain * pid->iState;
	dTerm = pid->dGain * (position - pid->dState);
	pid->dState = position;

	result = pTerm + iTerm - dTerm;

	return result;
}

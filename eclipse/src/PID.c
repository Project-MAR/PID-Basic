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

#define F8 double	// Define Floating point 8 bytes

typedef struct SPid_TAG
{
	F8 dState;		// Last position input
	F8 iState;		// Integral state
	F8 iMax;		// Maximum allowable integrator state
	F8 iMin;		// Minimum allowable integrator state
	F8 iGain;		// integrator gain
	F8 pGain;		// proportional gain
	F8 dGain;		// derivative gain

}SPid;

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

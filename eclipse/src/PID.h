#ifndef __PID_H__
#define __PID_H__


#define F8 double

typedef struct SPid_TAG
{
	F8 dState; 		// Last position input
	F8 iState; 		// Integrator state
	F8 iMax;
	F8 iMin;	// Maximum and minimum allowable integrator state
	F8 iGain;
	F8 pGain;
	F8 dGain;
} SPid;


F8 UpdatePID(SPid* pid, F8 error, F8 position);

#endif


#include <stdio.h>
#include <stdlib.h>
#include "PID.h"

int main(void) {

	double position;		//
	double drive;			// Controller output
	double error;
	double plantCommand;	// Set point (SP)
	double ReadPlantADC[10] = {1,2,3,4,5,6,7,8,9,10};

	SPid plantPID;

	position = ReadPlantADC[0];
	error = plantCommand - position;
	drive = UpdatePID(&plantPID, error, position);

	return EXIT_SUCCESS;
}

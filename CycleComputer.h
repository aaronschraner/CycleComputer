/*=======================================================
Program name: CycleComputer.h
Author: Aaron Schraner
Date: 02/12/2015
Description: Cycle computer class and function prototypes
=========================================================*/

class CycleComputer
{
	public:
		enum 	VelocityType { current_, average_, maximum_ };
			CycleComputer(double tireDiameter);
		void 	tickSecond();
		void 	tickTireRotation();
		double 	distanceTraveled();
		double 	velocity(VelocityType vType);
		long int elapsedTime();
		long int tripTime();
		void 	resetTrip();

	private:
		long int tripSeconds;
		long int totalSeconds;
		long int totalRotations;
		long int currentRotations;
		double   tireDiameter;
		long int maxRotations;
		double   currentVelocity;
};

/*=========================================================================
Program name: CycleComputer.cpp 
Author: Aaron Schraner
Date: 02/13/2015
Description: Implements the various functions required for a cycle computer
		(as defined by CycleComputer.h)
===========================================================================*/

#include <math.h>
#include "CycleComputer.h"
#ifndef CYCLECOMPUTER_H
#define CYCLECOMPUTER_H

#define rev_to_mph(x) x * M_PI / 17.6 
//convert revolutions/second to mph

//constructor
CycleComputer::CycleComputer(double tireDiameter)
{
	this->tireDiameter=tireDiameter;
	//set tire diameter
	
	resetTrip();
	//reset everything else
}

//tell the computer a second has passed
void CycleComputer::tickSecond()
{
	totalSeconds++; 
	currentVelocity = currentRotations; 
	//save current velocity

	if(currentRotations)
		tripSeconds++;
		//increment trip timer if we are moving

	currentRotations=0;
	//reset rotation frequency counter
}

//tell the computer the tire has rotated
void CycleComputer::tickTireRotation()
{
	totalRotations++;
	currentRotations++;

	if(currentRotations > maxRotations)
		maxRotations=currentRotations;
		//keep track of the maximum speed

}

//get the total distance traveled
double CycleComputer::distanceTraveled()
{
	return totalRotations * tireDiameter;
}

//get some type of velocity
double CycleComputer::velocity(VelocityType vType)
{
	if(tripSeconds==0)
		return 0; 
		//break instantly if no seconds with movement have been counted

	switch(vType)
	{
		case current_: return rev_to_mph(currentVelocity * tireDiameter); //current velocity
		case average_: return rev_to_mph(totalRotations * tireDiameter / tripSeconds); //average velocity
		case maximum_: return rev_to_mph(maxRotations * tireDiameter); //maximum velocity

		default:
			//invalid argument
			return 0;
			break;
	}
}

//get total elapsed time
long int CycleComputer::elapsedTime()
{
	return totalSeconds;
}

//get total time that bicycle was moving
long int CycleComputer::tripTime()
{
	return tripSeconds;
}

//reset everything in the cycle computer except tire diameter
void CycleComputer::resetTrip()
{
	tripSeconds=0;
	totalSeconds=0;
	totalRotations=0;
	currentRotations=0;
	maxRotations=0;
	currentVelocity=0;
}

#endif

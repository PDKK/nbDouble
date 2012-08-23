#ifndef _INC_Kinematics
#define _INC_Kinematics

#include "CalInfo.h"

class fbReverse;

class fbReverse
{
public:
	matrix64 mult3mats(matrix64 *MRoll, matrix64 *MPitch, matrix64 *MYaw);
	matrix64 getXform(const double Roll, const double Pitch, const double Yaw);
	void Calculate();

public:
	// Cartesian Position
	double X;
	double Y;
	double Z;
	double Pitch;
	double Roll;
	double Yaw;

	// Calibration Information
	fbCalInfo calI;
        fbCalInfo finalNodePosition;

public:
	// Leg Lengths to achieve Cartesian Position
	double bottomLeg[N_AXES];
	double topLeg[N_AXES];
	
public:
	fbReverse()
	{
		X = 0.0;
		Y = 0.0;
		Z = 0.0;
		Pitch = 0.0;
		Roll = 0.0;
		Yaw = 0.0;

		int i;
		for (i=0; i<N_AXES; i++) {
                    bottomLeg[i] = topLeg[i] = 0.0;
                }
	}
};

#endif // _INC_Kinematics

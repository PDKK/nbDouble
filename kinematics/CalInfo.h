#ifndef _INC_CalInfo
#define _INC_CalInfo

// This information defines the geometry/hardware of the robot
// Essentially, it identifies the Platform and Node locations and Leg/Actuator limits

#define N_AXES (6)
#define N_LEGS (12)

#include "vector64.h"

enum tAxesOrder {
	AxesOrderUndefined = (-1),
	RollPitchYaw = 0,
	RollYawPitch,
	PitchRollYaw,
	PitchYawRoll,
	YawRollPitch,
	YawPitchRoll,
	AxesOrderLast
};

class fbCalInfo;
class fbCalInfo
{

public:
	vector64 TopBall[N_AXES];		// Platform Nodes
	vector64 TopSphere[N_AXES];		// Middle platform
	vector64 BottomBall[N_AXES];		// Middle Platform - Platform Nodes
	vector64 BottomSphere[N_AXES];	// Base Nodes

	vector64 i,j,k;				// Original Platform orientation

	double legLength[N_AXES];		// Home Leg Lengths (not used)
	double minLegLength[N_AXES];	// Min Leg Lengths
	double maxLegLength[N_AXES];	// Max Leg Lengths

	tAxesOrder RotOrder;		// determines order of multiplication of Rotational Matrices

	int n_Axes;					// number of Axes (6)

public:
	fbCalInfo()
	{
		// Platform "original" orientation
		i = vector64(1.0,0.0,0.0);
		j = vector64(0.0,1.0,0.0);
		k = vector64(0.0,0.0,1.0);

		// Order is Roll - Pitch - Yaw
		RotOrder = RollPitchYaw;

		n_Axes = N_AXES;

		// Platform Node locations (from a recently measured P-2000)
		TopBall[0] = vector64( 136.49950, -128.60920, -71.92080 );
		TopBall[1] = vector64( 179.45550, -53.92250, -72.05260 );
		TopBall[2] = vector64( 43.07670, 182.60150, -72.56360 );
		TopBall[3] = vector64( -43.02370, 182.38900, -72.51090 );
		TopBall[4] = vector64( -179.57560, -53.92250, -72.08120 );
		TopBall[5] = vector64( -136.43240, -128.53620, -71.95920 );

		// Base Node locations (from a recently measured P-2000)
		TopSphere[0] = vector64( 80.25060, -439.51770, -730.32127 );
		TopSphere[1] = vector64( 420.78770, 150.48500, -730.32107 );
		TopSphere[2] = vector64( 340.31940, 289.22580, -730.32327 );
		TopSphere[3] = vector64( -340.61570, 289.12130, -730.06687 );
		TopSphere[4] = vector64( -420.69520, 150.48500, -729.65787 );
		TopSphere[5] = vector64( -80.04690, -439.79940, -731.13167 );
                
		BottomBall[0] = vector64( 136.49950, -128.60920, -771.92080 );
		BottomBall[1] = vector64( 179.45550, -53.92250, -772.05260 );
		BottomBall[2] = vector64( 43.07670, 182.60150, -772.56360 );
		BottomBall[3] = vector64( -43.02370, 182.38900, -772.51090 );
		BottomBall[4] = vector64( -179.57560, -53.92250, -772.08120 );
		BottomBall[5] = vector64( -136.43240, -128.53620, -771.95920 );

		// Base Node locations (from a recently measured P-2000)
		BottomSphere[0] = vector64( 80.25060, -439.51770, -1430.32127 );
		BottomSphere[1] = vector64( 420.78770, 150.48500, -1430.32107 );
		BottomSphere[2] = vector64( 340.31940, 289.22580, -1430.32327 );
		BottomSphere[3] = vector64( -340.61570, 289.12130, -1430.06687 );
		BottomSphere[4] = vector64( -420.69520, 150.48500, -1429.65787 );
		BottomSphere[5] = vector64( -80.04690, -439.79940, -1431.13167 );

		// Leg lengths
		for ( int ii=0; ii<n_Axes; ii++ ) {
			legLength[ii] = 1125.0;							// Home
			minLegLength[ii] = legLength[ii];				// Min
			maxLegLength[ii] = minLegLength[ii] + 625.0;	// MaX
		}
	}
};

#endif


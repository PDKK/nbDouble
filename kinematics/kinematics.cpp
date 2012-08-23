#include "kinematics.h"

const double DTOR = PI/180.0;

// Multiply the 3 rotational matrices together
// in the specified order
matrix64 fbReverse::mult3mats(matrix64 *MRoll, matrix64 *MPitch, matrix64 *MYaw)
{
	matrix64 *mFirst,*mSecond,*mThird;

	switch ( calI.RotOrder==AxesOrderUndefined ? RollPitchYaw : calI.RotOrder ) {
		mFirst = MRoll;
		mSecond = MPitch;
		mThird = MYaw;
		break;
	case RollYawPitch:
		mFirst = MRoll;
		mSecond = MYaw;
		mThird = MPitch;
		break;
	case PitchRollYaw:
		mFirst = MPitch;
		mSecond = MRoll;
		mThird = MYaw;
		break;
	case PitchYawRoll:
		mFirst = MPitch;
		mSecond = MYaw;
		mThird = MRoll;
		break;
	case YawRollPitch:
		mFirst = MYaw;
		mSecond = MRoll;
		mThird = MPitch;
		break;
	case YawPitchRoll:
		mFirst = MYaw;
		mSecond = MPitch;
		mThird = MRoll;
		break;
	case RollPitchYaw:
	default:
		mFirst = MRoll;
		mSecond = MPitch;
		mThird = MYaw;
		break;
	}

	return (*mFirst) * (*mSecond) * (*mThird);
}

// calculate the rotational transformation matrix
matrix64 fbReverse::getXform(const double Roll, const double Pitch, const double Yaw)
{
	double rRoll = Roll*DTOR;
	double rPitch = Pitch*DTOR;
	double rYaw = Yaw*DTOR;

	// Rotation Matrices

	matrix64 MRoll;
	MRoll.row1(vector64(     1.0,           0.0,           0.0));
	MRoll.row2(vector64(     0.0,  (double)cos(rRoll), (double)sin(rRoll)));
	MRoll.row3(vector64(     0.0,  -(double)sin(rRoll),  (double)cos(rRoll)));

	matrix64 MPitch;
	MPitch.row1(vector64((double)cos(rPitch),  0.0,  -(double)sin(rPitch)));
	MPitch.row2(vector64(        0.0,  1.0,           0.0));
	MPitch.row3(vector64((double)sin(rPitch),  0.0,   (double)cos(rPitch)));

	matrix64 MYaw;
	MYaw.row1(vector64((double)cos(rYaw), (double)sin(rYaw), 0.0));
	MYaw.row2(vector64(-(double)sin(rYaw),  (double)cos(rYaw), 0.0));
	MYaw.row3(vector64(       0.0,         0.0, 1.0));


	// Original orientation

	matrix64 tA;
	tA.row1(calI.i);
	tA.row2(calI.j);
	tA.row3(calI.k);

	// Original Inverse

	matrix64 tIA;
	tIA.c1 = calI.i;
	tIA.c2 = calI.j;
	tIA.c3 = calI.k;

	// calculate Inverse * RotationalMatrix * Original

	matrix64 tX = mult3mats(&MRoll,&MPitch,&MYaw);
	return ( tIA * tX * tA );
}

/* AMC Execute from CALMATH */
void fbReverse::Calculate()
{
	int i;
	vector64 newBall;

	vector64 TopP = vector64(X,Y,Z);
	vector64 MidP = vector64(X/2,Y/2,Z/2);

	matrix64 MidRotTransform = getXform(Roll/2,Pitch/2,Yaw/2);
	matrix64 TopRotTransform = getXform(Roll,Pitch,Yaw);

        
	for ( i=0; i<calI.n_Axes; i++ ) {
		finalNodePosition.BottomBall[i] = ( calI.BottomBall[i] * MidRotTransform + MidP );
		finalNodePosition.TopSphere[i] = ( calI.TopSphere[i] * MidRotTransform + MidP );
		finalNodePosition.TopBall[i] = ( calI.TopBall[i] * TopRotTransform + TopP );
                
		bottomLeg[i] = length(finalNodePosition.BottomBall[i]-calI.BottomSphere[i]);
		topLeg[i] = length(finalNodePosition.TopBall[i]-calI.TopSphere[i]);
	}
}


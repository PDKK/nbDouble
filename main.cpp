//============================================================================
// Name        : moreSimple.cpp
// Author      : pdkk
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <unistd.h>		// usleep

#ifndef __FOR_RPi_noX__

#include  <X11/Xlib.h>
#include  <X11/Xatom.h>
#include  <X11/Xutil.h>



#endif //NOT  __FOR_RPi_noX__

#include "CalInfo.h"
#include "kinematics.h"
#include "SimpleShaderProgram.h"
#include "DrawableObject.h"
#include "Hexagon.h"
#include "MainWindow.h"
extern "C" {
#include "input.h"
#include "keys.h"
}
using namespace std;

bool *keys;
int *mouse;
struct joystick_t *joy1;


int main() {
	MainWindow * mw = new MainWindow();

	cout << "Main" << endl; // prints Hello World

    // count each frame
    int num_frames = 0;

	cout << "mw->initialise ..." << endl; // prints Hello World
    mw->initialise();
	cout << " done mw->initialise" << endl; // prints Hello World
    // set to true to leave main loop
    bool quit = false;

    // get a pointer to the key down array
    keys = getKeys();
    mouse = getMouse();
    joy1=getJoystick(0);
    //setMouseRelative(true);

    while (!quit) {		// the main loop

        doEvents();	// update mouse and key arrays
        //updateJoystick(joy1);

        if (keys[KEY_ESC])
            quit = true;	// exit if escape key pressed

        if (keys[KEY_A]) mw->camAng=mw->camAng+1;
        if (keys[KEY_S]) mw->camAng=mw->camAng-1;
//        if (keys[KEY_W]) lightAng=lightAng+1;
//        if (keys[KEY_Q]) lightAng=lightAng-1;
//        deltaMove = keys[KEY_LSHIFT] ? 0.01 : -0.01;
//        if (keys[KEY_X]) pod.topLocation.position.x += deltaMove;
//        if (keys[KEY_Y]) pod.topLocation.position.y += deltaMove;
//        if (keys[KEY_Z]) pod.topLocation.position.z += deltaMove;
//        placePlatform(&pod, &pod.topLocation.position, &pod.topLocation.position);
        mw->render();	// the render loop

        usleep(16000);	// no need to run cpu/gpu full tilt

    }

    mw->shutDown();		// tidy up
	releaseJoystick(joy1);

    return 0;
	return 0;
}

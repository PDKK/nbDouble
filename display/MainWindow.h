/*
 * MainWIndow.h
 *
 *  Created on: Aug 17, 2012
 *      Author: paul
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include "mat4.h"
#include "vec3.h"

class MainWindow {
public:
	MainWindow();
	virtual ~MainWindow();
	void initialise();
	void render();
	void shutDown();
	float lightAng, camAng;
private:
	kmVec3 pEye;
	kmVec3 pCenter;
	kmVec3 pUp, lightDir, viewDir;
	kmMat4 model, view, projection, mvp, vp, mv;
	int frame;

	Hexagon * oneHexagon;
	SimpleShaderProgram * simpleShader;
};

#endif /* MAINWINDOW_H_ */

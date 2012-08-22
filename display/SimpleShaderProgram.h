/*
 * SimpleShaderProgram.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef SIMPLESHADERPROGRAM_H_
#define SIMPLESHADERPROGRAM_H_

#include "DrawableObject.h"
#include "ShaderProgram.h"

class SimpleShaderProgram : protected ShaderProgram{
public:
	SimpleShaderProgram();
	virtual ~SimpleShaderProgram();
	void draw(DrawableObject * obj, kmMat4 * viewMatrix, kmMat4 * projectionMatrix);
};

#endif /* SIMPLESHADERPROGRAM_H_ */

/*
 * Hexagon.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef HEXAGON_H_
#define HEXAGON_H_

#include "DrawableObject.h"

class Hexagon: public DrawableObject {
public:
	Hexagon(SimpleShaderProgram *s);
	virtual ~Hexagon();
	kmMat4 * getModelMatrix();
	GLfloat * getVertexData();
	GLfloat * getColorData();
        int getNumVertices();
        void Draw(fbCalInfo *data, kmMat4 * viewMatrix, kmMat4 * projectionMatrix);
private:
	kmMat4 model;
        SimpleShaderProgram * shaderProg;
};

#endif /* HEXAGON_H_ */

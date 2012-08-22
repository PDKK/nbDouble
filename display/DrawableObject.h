/*
 * DrawableObject.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef DRAWABLEOBJECT_H_
#define DRAWABLEOBJECT_H_

#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "kazmath.h"

class DrawableObject {
public:
	DrawableObject();
	virtual ~DrawableObject();
	virtual GLfloat * getVertexData() = 0;
	virtual GLfloat * getColorData() = 0;
	virtual kmMat4 * getModelMatrix() = 0;
        virtual int getNumVertices() = 0;
protected:



};

#endif /* DRAWABLEOBJECT_H_ */

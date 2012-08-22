/*
 * DrawableObject.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */
#include <iostream>
#include <exception>
extern "C" {
#include "support.h"
}
#include "DrawableObject.h"


DrawableObject::DrawableObject() {

}

DrawableObject::~DrawableObject() {
	// TODO Auto-generated destructor stub
}
kmMat4 * DrawableObject::getModelMatrix() {
	return NULL;

}

GLfloat * DrawableObject::getVertexData() {
	return NULL;
}

GLfloat * DrawableObject::getColorData() {
	return NULL;
}

int DrawableObject::getNumVertices() {
    return 0;
}

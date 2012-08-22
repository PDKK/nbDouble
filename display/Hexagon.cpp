/*
 * Hexagon.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "kazmath.h"
#include "Hexagon.h"


float vertexData[] = {
            // X, Y, Z,
            // R, G, B, A
        0.5f,  0.866f, 0.0f, 
        1.0f, 0.0f, 0.0f,
        0.5f,  -0.866f, 0.0f, 
        -0.5f,  -0.866f, 0.0f, 
        -1.0f, 0.0f, 0.0f,
        -0.5f,  0.866f, 0.0f, 
};

float colorData[] = {
        // R, G, B, A
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 0.0f, 1.0f,
};

Hexagon::Hexagon():DrawableObject(){
	kmMat4Identity(&model);

}

Hexagon::~Hexagon() {
	// TODO Auto-generated destructor stub
}



kmMat4 * Hexagon::getModelMatrix() {
	return &model;

}

GLfloat * Hexagon::getVertexData() {
	return vertexData;
}

GLfloat * Hexagon::getColorData() {
	return colorData;
}

int Hexagon::getNumVertices() {
    return 6;
}


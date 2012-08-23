/*
 * Hexagon.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "kazmath.h"
#include "CalInfo.h"
#include "SimpleShaderProgram.h"

#include "Hexagon.h"





Hexagon::Hexagon(SimpleShaderProgram * s):DrawableObject(){
    this->shaderProg = s;
	kmMat4Identity(&model);

}

Hexagon::~Hexagon() {
	// TODO Auto-generated destructor stub
}



kmMat4 * Hexagon::getModelMatrix() {
	return &model;

}

GLfloat * Hexagon::getVertexData() {
	return NULL;
}

GLfloat * Hexagon::getColorData() {
	return NULL;
}

int Hexagon::getNumVertices() {
    return 6;
}

void Hexagon::Draw(fbCalInfo * data, kmMat4 * viewMatrix, kmMat4 * projectionMatrix) {
    kmMat4 mvpMatrix;
    float vertexData[60];
    float colorData[60];
    
    glUseProgram(shaderProg->program);
    kmMat4Multiply(&mvpMatrix, projectionMatrix, viewMatrix);
    kmMat4Multiply(&mvpMatrix, &mvpMatrix, &model);
    glUniformMatrix4fv(shaderProg->mvp_uniform, 1, GL_FALSE, mvpMatrix.mat);

    for (int i=0; i<6;i++) {
        vertexData[i*3]=data->BottomSphere[i].x;
        vertexData[1+i*3]=data->BottomSphere[i].y;
        vertexData[2+i*3]=data->BottomSphere[i].z;
        colorData[i*4] = 1.0f;
        colorData[1+i*4] = 1.0f;
        colorData[2+i*4] = 0.0f;
        colorData[3+i*4] = 1.0f;
    }
    glVertexAttribPointer(shaderProg->vert_attrib, 3, GL_FLOAT, GL_FALSE,
            0, vertexData);
    glEnableVertexAttribArray(shaderProg->vert_attrib);
    glVertexAttribPointer(shaderProg->color_attrib, 4, GL_FLOAT, GL_FALSE,
            0, colorData);
    glEnableVertexAttribArray(shaderProg->color_attrib);
    glDrawArrays(GL_LINE_LOOP, 0, 6);

    for (int i=0; i<6;i++) {
        vertexData[i*3]=data->BottomBall[i].x;
        vertexData[1+i*3]=data->BottomBall[i].y;
        vertexData[2+i*3]=data->BottomBall[i].z;
    }
    glVertexAttribPointer(shaderProg->vert_attrib, 3, GL_FLOAT, GL_FALSE,
            0, vertexData);
    glEnableVertexAttribArray(shaderProg->vert_attrib);
    glVertexAttribPointer(shaderProg->color_attrib, 4, GL_FLOAT, GL_FALSE,
            0, colorData);
    glEnableVertexAttribArray(shaderProg->color_attrib);
    glDrawArrays(GL_LINE_LOOP, 0, 6);

    for (int i=0; i<6;i++) {
        vertexData[i*3]=data->TopSphere[i].x;
        vertexData[1+i*3]=data->TopSphere[i].y;
        vertexData[2+i*3]=data->TopSphere[i].z;
    }
    glVertexAttribPointer(shaderProg->vert_attrib, 3, GL_FLOAT, GL_FALSE,
            0, vertexData);
    glEnableVertexAttribArray(shaderProg->vert_attrib);
    glVertexAttribPointer(shaderProg->color_attrib, 4, GL_FLOAT, GL_FALSE,
            0, colorData);
    glEnableVertexAttribArray(shaderProg->color_attrib);
    glDrawArrays(GL_LINE_LOOP, 0, 6);

    for (int i=0; i<6;i++) {
        vertexData[i*3]=data->TopBall[i].x;
        vertexData[1+i*3]=data->TopBall[i].y;
        vertexData[2+i*3]=data->TopBall[i].z;
    }
    glVertexAttribPointer(shaderProg->vert_attrib, 3, GL_FLOAT, GL_FALSE,
            0, vertexData);
    glEnableVertexAttribArray(shaderProg->vert_attrib);
    glVertexAttribPointer(shaderProg->color_attrib, 4, GL_FLOAT, GL_FALSE,
            0, colorData);
    glEnableVertexAttribArray(shaderProg->color_attrib);
    glDrawArrays(GL_LINE_LOOP, 0, 6);

    for (int i=0; i<6;i++) {
        vertexData[i*6]=data->BottomSphere[i].x;
        vertexData[1+i*6]=data->BottomSphere[i].y;
        vertexData[2+i*6]=data->BottomSphere[i].z;
        vertexData[3+i*6]=data->BottomBall[i].x;
        vertexData[4+i*6]=data->BottomBall[i].y;
        vertexData[5+i*6]=data->BottomBall[i].z;
        colorData[i*8] = 1.0f;
        colorData[1+i*8] = 0.0f;
        colorData[2+i*8] = 0.0f;
        colorData[3+i*8] = 1.0f;
        colorData[4+i*8] = 1.0f;
        colorData[5+i*8] = 0.0f;
        colorData[6+i*8] = 0.0f;
        colorData[7+i*8] = 1.0f;
        
    }
    glVertexAttribPointer(shaderProg->vert_attrib, 3, GL_FLOAT, GL_FALSE,
            0, vertexData);
    glEnableVertexAttribArray(shaderProg->vert_attrib);
    glVertexAttribPointer(shaderProg->color_attrib, 4, GL_FLOAT, GL_FALSE,
            0, colorData);
    glEnableVertexAttribArray(shaderProg->color_attrib);
    glDrawArrays(GL_LINES, 0, 12);
    
    for (int i=0; i<6;i++) {
        vertexData[i*6]=data->TopSphere[i].x;
        vertexData[1+i*6]=data->TopSphere[i].y;
        vertexData[2+i*6]=data->TopSphere[i].z;
        vertexData[3+i*6]=data->TopBall[i].x;
        vertexData[4+i*6]=data->TopBall[i].y;
        vertexData[5+i*6]=data->TopBall[i].z;
        colorData[i*8] = 0.0f;
        colorData[1+i*8] = 0.0f;
        colorData[2+i*8] = 1.0f;
        colorData[3+i*8] = 1.0f;
        colorData[4+i*8] = 0.0f;
        colorData[5+i*8] = 0.0f;
        colorData[6+i*8] = 1.0f;
        colorData[7+i*8] = 1.0f;
        
    }
    glVertexAttribPointer(shaderProg->vert_attrib, 3, GL_FLOAT, GL_FALSE,
            0, vertexData);
    glEnableVertexAttribArray(shaderProg->vert_attrib);
    glVertexAttribPointer(shaderProg->color_attrib, 4, GL_FLOAT, GL_FALSE,
            0, colorData);
    glEnableVertexAttribArray(shaderProg->color_attrib);
    glDrawArrays(GL_LINES, 0, 12);

}


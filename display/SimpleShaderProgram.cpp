/*
 * SimpleShaderProgram.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#include <EGL/egl.h>
#include <GLES2/gl2.h>

#include "DisplayException.h"
#include "SimpleShaderProgram.h"

const char * vertexShader =
        "uniform mat4 u_MVPMatrix;      \n" // A constant representing the combined model/view/projection matrix.

        "attribute vec4 a_Position;     \n" // Per-vertex position information we will pass in.
        "attribute vec4 a_Color;        \n" // Per-vertex color information we will pass in.

        "varying vec4 v_Color;          \n" // This will be passed into the fragment shader.

        "void main()                    \n" // The entry point for our vertex shader.
        "{                              \n"
        "   v_Color = a_Color;          \n" // Pass the color through to the fragment shader.
        // It will be interpolated across the triangle.
        "   gl_Position = u_MVPMatrix   \n" // gl_Position is a special variable used to store the final position.
        "               * a_Position;   \n" // Multiply the vertex by the matrix to get the final point in
        "}                              \n"; // normalized screen coordinates.

char * fragmentShader =
        "precision mediump float;       \n" // Set the default precision to medium. We don't need as high of a
        // precision in the fragment shader.
        "varying vec4 v_Color;          \n" // This is the color from the vertex shader interpolated across the
        // triangle per fragment.
        "void main()                    \n" // The entry point for our fragment shader.
        "{                              \n"
        "   gl_FragColor = v_Color;     \n" // Pass the color directly through the pipeline.
        "}                              \n";


GLchar vShaderStr[] =
        "attribute vec4 vPosition;    \n"
        "void main()                  \n"
        "{                            \n"
        "   gl_Position = vPosition;  \n"
        "}                            \n";

GLchar fShaderStr[] =
        "precision mediump float;\n"\
      "void main()                                  \n"
        "{                                            \n"
        "  gl_FragColor = vec4 ( 1.0, 0.0, 0.0, 1.0 );\n"
        "}                                            \n";

SimpleShaderProgram::SimpleShaderProgram() {
    // TODO Auto-generated constructor stub
    GLint link_ok = GL_FALSE;

    GLuint vs, fs;
    if ((vs = createShader(vertexShader, GL_VERTEX_SHADER)) == 0) {

        throw new DisplayException("");
    }
    if ((fs = createShader(fragmentShader, GL_FRAGMENT_SHADER)) == 0) {

        throw new DisplayException("");
    }

    program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &link_ok);
    if (!link_ok) {
        printLog(program);
        throw new DisplayException("glLinkProgram");
    }

    vert_attrib = glGetAttribLocation(program, "a_Position");
    color_attrib = glGetAttribLocation(program, "a_Color");
    mvp_uniform = glGetUniformLocation(program, "u_MVPMatrix");

}

void SimpleShaderProgram::draw(DrawableObject * obj, kmMat4 * viewMatrix, kmMat4 * projectionMatrix) {
    kmMat4 mvpMatrix;
    

    // Use the program object
    glUseProgram(program);

    // Pass in the position information

    glVertexAttribPointer(vert_attrib, 3, GL_FLOAT, GL_FALSE,
            0, obj->getVertexData());

    glEnableVertexAttribArray(vert_attrib);

    // Pass in the color information

    glVertexAttribPointer(color_attrib, 4, GL_FLOAT, GL_FALSE,
            0, obj->getColorData());

    glEnableVertexAttribArray(color_attrib);


    kmMat4Multiply(&mvpMatrix, projectionMatrix, viewMatrix);
    kmMat4Multiply(&mvpMatrix, &mvpMatrix, obj->getModelMatrix());

    glUniformMatrix4fv(mvp_uniform, 1, GL_FALSE, mvpMatrix.mat);
    glDrawArrays(GL_LINE_LOOP, 0, obj->getNumVertices());
}

SimpleShaderProgram::~SimpleShaderProgram() {
    // TODO Auto-generated destructor stub
}

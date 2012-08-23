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



SimpleShaderProgram::~SimpleShaderProgram() {
    // TODO Auto-generated destructor stub
}


/*
 * ShaderProgram.cpp
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */
#include <iostream>
#include <exception>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "ShaderProgram.h"



GLuint ShaderProgram::createShader(const GLchar* source, GLenum type) {

	GLuint res = glCreateShader(type);
	const GLchar *sources[] = {
	// Define GLSL version

			source,
#ifdef GL_ES_VERSION_2_0
			"#version 100\n"
#else
			"#version 120\n"
#endif
,			// GLES2 precision specifiers
#ifdef GL_ES_VERSION_2_0
			// Define default float precision for fragment shaders:
			(type == GL_FRAGMENT_SHADER) ?
			"#ifdef GL_FRAGMENT_PRECISION_HIGH\n"
			"precision highp float;           \n"
			"#else                            \n"
			"precision mediump float;         \n"
			"#endif                           \n" : ""
			// Note: OpenGL ES automatically defines this:
			// #define GL_ES
#else
			// Ignore GLES 2 precision specifiers:
			"#define lowp   \n" "#define mediump\n" "#define highp  \n"
#endif

		};
	glShaderSource(res, 1, &source, NULL);


	glCompileShader(res);
	GLint compile_ok = GL_FALSE;
	glGetShaderiv(res, GL_COMPILE_STATUS, &compile_ok);
	if (compile_ok == GL_FALSE) {
		printLog(res);
		glDeleteShader(res);
		return 0;
	}

	return res;
}

void ShaderProgram::printLog(GLuint object)
{
    GLint log_length = 0;
    if (glIsShader(object))
        glGetShaderiv(object, GL_INFO_LOG_LENGTH, &log_length);
    else if (glIsProgram(object))
        glGetProgramiv(object, GL_INFO_LOG_LENGTH, &log_length);
    else {
        std::cerr <<  "printlog: Not a shader or a program\n";
        return;
    }

    char *log = new char[log_length];

    if (glIsShader(object))
        glGetShaderInfoLog(object, log_length, NULL, log);
    else if (glIsProgram(object))
        glGetProgramInfoLog(object, log_length, NULL, log);

    std::cerr << log;
    delete[] log;
}


ShaderProgram::ShaderProgram() {


}

ShaderProgram::~ShaderProgram() {
	// TODO Auto-generated destructor stub
}


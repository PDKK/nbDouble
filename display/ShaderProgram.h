/*
 * ShaderProgram.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef SHADERPROGRAM_H_
#define SHADERPROGRAM_H_


class ShaderProgram {
public:
	ShaderProgram();
	virtual ~ShaderProgram();
	void draw();
    GLint program;
protected:
	GLuint createShader(const GLchar* source, GLenum type);
	void printLog(const GLuint obj);



};

#endif /* SHADERPROGRAM_H_ */

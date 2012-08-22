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
protected:
	GLuint createShader(const GLchar* source, GLenum type);
	void printLog(const GLuint obj);

    GLint program;
    GLint vert_attrib;
    GLint color_attrib;
    GLint mvp_uniform;

};

#endif /* SHADERPROGRAM_H_ */

/*
 * SimpleShaderProgram.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef SIMPLESHADERPROGRAM_H_
#define SIMPLESHADERPROGRAM_H_

#include "DrawableObject.h"
#include "ShaderProgram.h"

class SimpleShaderProgram : public ShaderProgram{
public:
	SimpleShaderProgram();
	virtual ~SimpleShaderProgram();
	
    GLint vert_attrib;
    GLint color_attrib;
    GLint mvp_uniform;        
};

#endif /* SIMPLESHADERPROGRAM_H_ */

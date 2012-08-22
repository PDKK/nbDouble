/*
 * DisplayException.h
 *
 *  Created on: Aug 21, 2012
 *      Author: paul
 */

#ifndef DISPLAYEXCEPTION_H_
#define DISPLAYEXCEPTION_H_

#include <iostream>
#include <exception>

class DisplayException : public std::exception {


	std::string extra;
public:
	DisplayException(std::string m) :
			extra(m) {
	}
	;
	~DisplayException() throw () {
	}
	;

	virtual const char* what() const throw () {
		std::string result("drawableObjectCreationException:");
		result.append(extra);
		return result.c_str();
	}
};


#endif /* DISPLAYEXCEPTION_H_ */

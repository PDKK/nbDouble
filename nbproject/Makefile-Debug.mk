#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/kazmath/mat3.o \
	${OBJECTDIR}/kazmath/GL/matrix.o \
	${OBJECTDIR}/kazmath/utility.o \
	${OBJECTDIR}/kazmath/mat4.o \
	${OBJECTDIR}/display/support.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/display/ShaderProgram.o \
	${OBJECTDIR}/kazmath/vec4.o \
	${OBJECTDIR}/display/SimpleShaderProgram.o \
	${OBJECTDIR}/kazmath/vec3.o \
	${OBJECTDIR}/display/MainWindow.o \
	${OBJECTDIR}/input/input.o \
	${OBJECTDIR}/kazmath/quaternion.o \
	${OBJECTDIR}/kazmath/GL/mat4stack.o \
	${OBJECTDIR}/kazmath/plane.o \
	${OBJECTDIR}/display/DrawableObject.o \
	${OBJECTDIR}/kazmath/vec2.o \
	${OBJECTDIR}/kazmath/ray2.o \
	${OBJECTDIR}/display/Hexagon.o \
	${OBJECTDIR}/kazmath/aabb.o


# C Compiler Flags
CFLAGS=-std=gnu99

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs egl` `pkg-config --libs libpng` `pkg-config --libs glesv2` `pkg-config --libs x11`  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nbdouble

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nbdouble: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nbdouble ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/kazmath/mat3.o: kazmath/mat3.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/mat3.o kazmath/mat3.c

${OBJECTDIR}/kazmath/GL/matrix.o: kazmath/GL/matrix.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath/GL
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/GL/matrix.o kazmath/GL/matrix.c

${OBJECTDIR}/kazmath/utility.o: kazmath/utility.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/utility.o kazmath/utility.c

${OBJECTDIR}/kazmath/mat4.o: kazmath/mat4.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/mat4.o kazmath/mat4.c

${OBJECTDIR}/display/support.o: display/support.c 
	${MKDIR} -p ${OBJECTDIR}/display
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/display/support.o display/support.c

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/display/ShaderProgram.o: display/ShaderProgram.cpp 
	${MKDIR} -p ${OBJECTDIR}/display
	${RM} $@.d
	$(COMPILE.cc) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/display/ShaderProgram.o display/ShaderProgram.cpp

${OBJECTDIR}/kazmath/vec4.o: kazmath/vec4.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/vec4.o kazmath/vec4.c

${OBJECTDIR}/display/SimpleShaderProgram.o: display/SimpleShaderProgram.cpp 
	${MKDIR} -p ${OBJECTDIR}/display
	${RM} $@.d
	$(COMPILE.cc) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/display/SimpleShaderProgram.o display/SimpleShaderProgram.cpp

${OBJECTDIR}/kazmath/vec3.o: kazmath/vec3.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/vec3.o kazmath/vec3.c

${OBJECTDIR}/display/MainWindow.o: display/MainWindow.cpp 
	${MKDIR} -p ${OBJECTDIR}/display
	${RM} $@.d
	$(COMPILE.cc) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/display/MainWindow.o display/MainWindow.cpp

${OBJECTDIR}/input/input.o: input/input.c 
	${MKDIR} -p ${OBJECTDIR}/input
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/input/input.o input/input.c

${OBJECTDIR}/kazmath/quaternion.o: kazmath/quaternion.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/quaternion.o kazmath/quaternion.c

${OBJECTDIR}/kazmath/GL/mat4stack.o: kazmath/GL/mat4stack.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath/GL
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/GL/mat4stack.o kazmath/GL/mat4stack.c

${OBJECTDIR}/kazmath/plane.o: kazmath/plane.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/plane.o kazmath/plane.c

${OBJECTDIR}/display/DrawableObject.o: display/DrawableObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/display
	${RM} $@.d
	$(COMPILE.cc) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/display/DrawableObject.o display/DrawableObject.cpp

${OBJECTDIR}/kazmath/vec2.o: kazmath/vec2.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/vec2.o kazmath/vec2.c

${OBJECTDIR}/kazmath/ray2.o: kazmath/ray2.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/ray2.o kazmath/ray2.c

${OBJECTDIR}/display/Hexagon.o: display/Hexagon.cpp 
	${MKDIR} -p ${OBJECTDIR}/display
	${RM} $@.d
	$(COMPILE.cc) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/display/Hexagon.o display/Hexagon.cpp

${OBJECTDIR}/kazmath/aabb.o: kazmath/aabb.c 
	${MKDIR} -p ${OBJECTDIR}/kazmath
	${RM} $@.d
	$(COMPILE.c) -g -D__FOR_XORG__ -Idisplay -Ikazmath -Iinput `pkg-config --cflags egl` `pkg-config --cflags libpng` `pkg-config --cflags glesv2` `pkg-config --cflags x11`    -MMD -MP -MF $@.d -o ${OBJECTDIR}/kazmath/aabb.o kazmath/aabb.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/nbdouble

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc

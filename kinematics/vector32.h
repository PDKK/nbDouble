//======================================================================*/
//                                                                      */
//      Module ....... vector32.cpp                                       */
//      Project ...... Hexel Machine Tools                              */                                                                     */
//      Author ....... Neil Jones                                       */
//      Date ......... 9th January 1995                                 */
//      Revision ..... 0.01                                             */
//                                                                      */
//----------------------------------------------------------------------*/
//                                                                      */
//            Copyright (c) 1994,95 by Neil Jones                       */
//                      24 Southsea Avenue                              */
//                         Goring-By-Sea                                */
//                            ENGLAND                                   */
//                      All rights reserved.                            */
//                                                                      */
//----------------------------------------------------------------------*/
//      Notes:                                                          */
//        This file contains the definitions of the vector32 and matrix32   */
//        classes used throughout the Hexel machine control software.   */
//        Operators and functions are inlined for speed of operation.   */
//                                                                      */
//----------------------------------------------------------------------*/
//      Revision History:                                               */
// +--------+-----------+---------------------------------------------+ */
// | Date:  | Revision: | Modifications:                              | */
// +--------+-----------+---------------------------------------------+ */
// | 9/1/95 | 0.01      | First Cut                                   | */
// |18/8/95 | A1.00     | Alpha Release                               | */
// |        |           |                                             | */
//                                                                      */
//======================================================================*/
#ifndef _INC_vector32
#define _INC_vector32
//----------------------------------------------------------------------*/
// Include Files                                                        */
//----------------------------------------------------------------------*/
#include <math.h>

#define PI 3.141592654f

class STRING;
class vector64;
class matrix64;
//----------------------------------------------------------------------*/
//   Constant Declarations ....                                         */
//----------------------------------------------------------------------*/
//#define xi vector(1.0,0,0)
//#define yi vector(0,1.0,0)
//#define zi vector(0,0,1.0)

//======================================================================*/
//   Class Name .... vector                                             */
//                                                                      */
//   Primary Data Members .......                                       */
//     float x - X Magnitude                                            */
//     float y - Y Magnitude                                            */
//     float z - Z Magnitude                                            */
//                                                                      */
//----------------------------------------------------------------------*/
//   Purpose ..........                                                 */
//     The vector class is used to encapsulate all methods relating to  */
//     the manipulation of vectors.                                     */
//                                                                      */
//======================================================================*/
class vector32
{

//----------------------------------------------------------------------*/
//   Public Data ....                                                   */
//----------------------------------------------------------------------*/
public:
   float x,y,z;

//======================================================================*/
//   Function Name .... vector::vector()                                */
//                                                                      */
//   Parameters ....... None                                            */
//   Return Value .....                                                 */
//     Returns a vector with the x,y and z magnitudes set to zero       */
//======================================================================*/
   vector32() {x=y=z=0.0f;}
   
//======================================================================*/
//   Function Name .... vector::vector()                                */
//                                                                      */
//   Parameters .......                                                 */
//     float z_x - required X Magnitude                                 */
//     float z_y - required Y Magnitude                                 */
//     float z_z - required Z Magnitude                                 */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a vector with the x,y and z magnitudes set as required.  */
//======================================================================*/
   vector32(float z_x, float z_y, float z_z)
   {
      x = z_x;
      y = z_y;
      z = z_z;
   }
   
   vector32(float v)
   {
     x=y=z=v;
   }

   vector32(double z_x, double z_y, double z_z)
   {
      x = (float)z_x;
      y = (float)z_y;
      z = (float)z_z;
   }
   
   vector32(double v)
   {
     x=y=z=(float)v;
   }

   vector32(vector64 v);
//======================================================================*/
//   IO operators ....                                                  */
//                                                                      */
//     a << b .... writes vector 'b' to output stream 'a'               */
//     a >> b ....reads b vector from input stream 'a'                  */
//                                                                      */
//======================================================================*/
   friend STRING& operator << (STRING& s, const vector32 &a);
   friend STRING& operator >> (STRING& s, vector32 &a);


//======================================================================*/
//   Comparison operators ....                                          */
//                                                                      */
//   a == b .... returns true if a is equal to b in all axes            */
//   a != b .... returns true if a is unequal to b in any axis          */
//   a > b ..... returns true if a is greater than b in all axes        */
//   a < b ..... returns true if a is less than b in all axes           */
//   a >= b .... returns true if a is greater or equal to b in all axes */
//   a <= b .... returns true if a is less or equal to b in all axes    */
//                                                                      */
//   Parameters .......                                                 */
//     const vector& a - first vector (passed by reference for speed)   */
//     const vector& b - sencond vector (passed by reference for speed) */
//                                                                      */
//======================================================================*/
   int operator == (const vector32& a) {return ((x == a.x) && (y == a.y) && (z == a.z));}
   int operator != (const vector32& a) {return !(*this == a);}
   int operator > (const vector32& a) {return ((x > a.x) && (y > a.y) && (z > a.z));}
   int operator < (const vector32& a) {return ((x < a.x) && (y < a.y) && (z < a.z));}
   int operator >= (const vector32& a) {return ((x >= a.x) && (y >= a.y) && (z >= a.z));}
   int operator <= (const vector32& a) {return ((x <= a.x) && (y <= a.y) && (z <= a.z));}


//======================================================================*/
//   Arithmetic operators ....                                          */
//                                                                      */
//   a + b ..... returns result of adding vector a to vector b          */
//   a - b ..... returns result of subtracting vector b from vector a   */
//   - a ....... returns the inverse of vector a                        */
//   a * b ..... (Scalar) if one parameter is a float, returns the      */
//               result of multiplying the vector by the scalar.        */
//   a * b ..... (Vector) if both parameters are vectors returns the    */
//               CROSS product of vector a with vector b.               */
//   a / b ..... returns result of dividing vector a by float b         */
//   dot(a,b) .. returns the DOT product of vector a and vector v       */
//   length(a) . returns the magnitude of vector a                      */
//   unit(a) ... returns a unit vector, same orientation as vector a    */
//                                                                      */
//   Parameters .......                                                 */
//     const vector& a - first vector (passed by reference for speed)   */
//     const vector& b - sencond vector (passed by reference for speed) */
//                                                                      */
//======================================================================*/
   vector32 operator + (const vector32& a) 
   {return vector32(x + a.x, y + a.y, z + a.z);}

   vector32 operator - (const vector32& a) 
   {return vector32(x - a.x, y - a.y, z - a.z);}

   friend vector32 operator - (const vector32& a) 
   {return vector32(-a.x, -a.y, -a.z);}

   vector32 operator * (float b) 
   {return vector32(x * b, y * b, z * b);}

   friend vector32 operator * (float b, const vector32& v) 
   {return vector32(v.x * b, v.y * b, v.z * b);}

 //  friend vector32 operator * (float a, const vector32 b) {return b*a;}

   vector32 operator * (const vector32& a) // CROSS product
   {return vector32(y * a.z - z * a.y,  z * a.x - x * a.z, x * a.y - y * a.x);}

   vector32 operator / (float b)  
   {return vector32(x / b, y / b, z / b);}

   float dot (const vector32& a) // DOT product
   {return (x * a.x + y * a.y + z * a.z);}

   vector32 cross (const vector32& a) // CROSS product
   {return vector32(y * a.z - z * a.y,  z * a.x - x * a.z, x * a.y - y * a.x);}

//   friend float dot (const vector32& a, const vector32& b) // DOT product
//   {return (a.x * b.x + a.y * b.y + a.z * b.z);}

   float length ()
   {return (float)sqrt((float)(x*x) + (float)(y*y) + (float)(z * z));}

   float modulus ()  {return length();}

   vector32 unit ()
   {float b; return ((b = modulus()) == 0) ? vector32() : *this / b;}

};

inline float dot (const vector32& a, const vector32& b) // DOT product
   {return (a.x * b.x + a.y * b.y + a.z * b.z);}

inline vector32 cross (const vector32&v, const vector32& a) // CROSS product
   {return vector32(v.y * a.z - v.z * a.y,  v.z * a.x - v.x * a.z, v.x * a.y - v.y * a.x);}

inline float length(const vector32& v) 
{return (float)sqrt((float)(v.x*v.x) + (float)(v.y*v.y) + (float)(v.z * v.z));}

inline vector32 unit (const vector32& v)
   {float b; return ((b = length(v)) == 0) ? vector32() : vector32(v.x/b, v.y/b, v.z/b);}

inline vector32 ABCToVector32(const vector32& a)
   {return unit(vector32((float)((cos(a.x)*sin(a.y)*cos(a.z))+(-sin(a.x)*-sin(a.z))),
                       (float)((cos(a.x)*sin(a.y)*sin(a.z))+(-sin(a.x)*cos(a.z))),
                       (float)(cos(a.x)*cos(a.y))));}

inline vector32 VectorToABC32(const vector32& v)
{
  double a, b, c;
   b = 0;
   a = acos(v.z);

   if (a > 0.0)
   {
     if (fabs(sin(a)) < 1e-11) 
       c = 0;
     else if (fabs(v.x) < fabs(v.y)) 
       c = asin(fabs(v.x) / sin(a));
     else 
       c = acos(fabs(v.y) / sin(a));
     
//---- Sort out the quadrant
     if (v.y < 0) 
       if (v.x < 0) //(-x -y)
         c = (2.0f*(float)PI) - c;
       else         //(+x -y)
         /*c = c*/;
     else 
       if (v.x < 0) //(-x +y)
         c = PI + c;
       else         //(+x +y)
         c = PI - c;
   }
   else 
     c = 0.0;

   return vector32((float)a, (float)b, (float)c);
}
   

//======================================================================*/
//   Class Name .... matrix32                                             */
//                                                                      */
//   Primary Data Members .......                                       */
//     vector32 c1 .... Column one of matrix32                              */
//     vector32 c2 .... Column two of matrix32                              */
//     vector32 c3 .... Column three of matrix32                            */
//                                                                      */
//----------------------------------------------------------------------*/
//   Purpose ..........                                                 */
//     The matrix32 class is used to encapsulate all methods relating to  */
//     the manipulation of 3x3 matrices.                                */
//                                                                      */
//======================================================================*/
class matrix32
{

//----------------------------------------------------------------------*/
//   Public Data ....                                                   */
//----------------------------------------------------------------------*/
public:
   vector32 c1;
   vector32 c2;
   vector32 c3;

//======================================================================*/
//   Function Name .... matrix32::matrix32()                                */
//                                                                      */
//   Parameters ....... None                                            */
//   Return Value .....                                                 */
//     Returns a matrix32 with the all elements set to zero               */
//======================================================================*/
   matrix32()
   {
      c1 = vector32(1.0f,0.0f,0.0f);
      c2 = vector32(0.0f,1.0f,0.0f);
      c3 = vector32(0.0f,0.0f,1.0f);
   }

//======================================================================*/
//   Function Name .... matrix32::matrix32()                                */
//                                                                      */
//   Parameters .......                                                 */
//     float x1,x2,x3 .. Fisrt row of matrix32                            */
//     float y1,y2,y3 .. Second row of matrix32                           */
//     float z1,z2,z3 .. Third row of matrix32                            */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a matrix32 with the all elements set as requested          */
//======================================================================*/
   matrix32(float x1, float x2, float x3,
      float y1, float y2, float y3,
      float z1, float z2, float z3)
   {
      c1 = vector32(x1,y1,z1);
      c2 = vector32(x2,y2,z2);
      c3 = vector32(x3,y3,z3);
   }

//======================================================================*/
//   Function Name .... matrix32::matrix32()                                */
//                                                                      */
//   Parameters .......                                                 */
//     vector32 c1_z .. Fisrt column of matrix32                            */
//     vector32 c2_z .. Second column of matrix32                           */
//     vector32 c3_z .. Third column of matrix32                            */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a matrix32 with the all elements set as requested          */
//======================================================================*/
   matrix32(vector32 c1_z, vector32 c2_z, vector32 c3_z)
   {
      c1 = c1_z;
      c2 = c2_z;
      c3 = c3_z;
   }              

   matrix32(matrix64 m);

//======================================================================*/
//   Function Name .... matrix32::matrix32()                                */
//                                                                      */
//   Parameters .......                                                 */
//     vector32 R .. A,B,C rotations of matrix32                            */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a matrix32 with the all elements set as requested          */
//======================================================================*/
   matrix32(vector32 R)
   {
      *this = matrix32();
      *this = rotateA(R.x);
      *this = rotateB(R.y);
      *this = rotateC(R.z);
   }
   
//======================================================================*/
//   IO operators ....                                                  */
//                                                                      */
//     a << b .... writes matrix32 'b' to output stream 'a'               */
//     a >> b ....reads b matrix32 from input stream 'a'                  */
//                                                                      */
//======================================================================*/
   friend STRING& operator << (STRING& os, const matrix32 &a);
   friend STRING& operator >> (STRING& is, matrix32 &a);
 
//======================================================================*/
//   Data manipulation member functions ....                            */
//                                                                      */
//     row1() ..... returns a vector32 equivalent to row 1 of this matrix32 */
//     row2() ..... returns a vector32 equivalent to row 2 of this matrix32 */
//     row3() ..... returns a vector32 equivalent to row 3 of this matrix32 */
//                                                                      */
//     row1(a) .... sets row 1 of this matrix32 to vector32 a               */
//     row2(a) .... sets row 2 of this matrix32 to vector32 a               */
//     row3(a) .... sets row 3 of this matrix32 to vector32 a               */
//                                                                      */
//     rotation_matrix32(pitch, yaw) ... returns a matrix32 with appropriate*/
//     values to provide the required rotation transformation           */
//                                                                      */
//======================================================================*/
   vector32 row1 ()
   {return vector32(c1.x, c2.x, c3.x);}

   vector32 row2 ()
   {return vector32(c1.y, c2.y, c3.y);}

   vector32 row3 ()
   {return vector32(c1.z, c2.z, c3.z);}
   
   void row1 (const vector32& v)
   {c1.x = v.x; c2.x = v.y; c3.x = v.z;}

   void row2 (const vector32& v)
   {c1.y = v.x; c2.y = v.y; c3.y = v.z;}
   
   void row3 (const vector32& v)
   {c1.z = v.x; c2.z = v.y; c3.z = v.z;}
   
  
//======================================================================*/
//   Arithmetic operators ...                                           */
//                                                                      */
//   matrix32 a + matrix32 b .... returns the result of adding matrix32 a to  */
//                            matrix b.                                 */
//                                                                      */
//   matrix a - matrix b .... returns the result of subtracting matrix b*/
//                            from matrix a.                            */
//                                                                      */
//   matrix a - matrix b .... returns the result of subtracting matrix b*/
//                            from matrix a.                            */
//                                                                      */
//   matrix a * matrix b .... returns the matrix result of multiplying  */
//                            matrix b by matrix a.                     */
//                                                                      */
//   vector32 a * matrix b .... returns the vector32 result of multiplying  */
//                            vector32 b by matrix a.                     */
//                                                                      */
//   matrix a * vector32 b .... returns the vector32 result of multiplying  */
//                            matrix b by vector32 a.                     */
//                                                                      */
//======================================================================*/
   matrix32 operator + (const matrix32& m)
   {return matrix32(c1 + m.c1, c2 + m.c2, c3 + m.c3);}

   matrix32 operator - (const matrix32& m)
   {return matrix32(c1 - m.c1, c2 - m.c2, c3 - m.c3);}

   matrix32 operator * (matrix32& m)
   {matrix32 m1;
    m1.c1 = vector32(row1().dot(m.c1),row2().dot(m.c1),row3().dot(m.c1));
    m1.c2 = vector32(row1().dot(m.c2),row2().dot(m.c2),row3().dot(m.c2));
    m1.c3 = vector32(row1().dot(m.c3),row2().dot(m.c3),row3().dot(m.c3));
    return m1;}
   //return matrix32(row1().dot(m.c1), row1().dot(m.c2), row1().dot(m.c3),
   //               row2().dot(m.c1), row2().dot(m.c2), row2().dot(m.c3),
   //               row3().dot(m.c1), row3().dot(m.c2), row3().dot(m.c3));}

   friend vector32 operator * (const vector32& v, const matrix32& m)
   {return vector32(dot(v, m.c1),dot(v, m.c2),dot(v, m.c3));}

   friend vector32 operator * (matrix32& m, const vector32& v)
   {return vector32(dot(v, m.row1()),dot(v, m.row2()),dot(v, m.row3()));}

   matrix32 rotateA(float a)
   {
	   matrix32 m = matrix32(1.0f, 0.0f,      0.0f,
                          0.0f,  (float)cos(a), (float)sin(a),
                          0.0f, (float)-sin(a), (float)cos(a));
	return *this * m;
   }
                   
   matrix32 rotateB(float a)
   {
	   matrix32 m = matrix32((float)cos(a),      0.0f,-(float)sin(a),
                                     0.0f,      1.0f,            0.0f,
                          (float)sin(a),      0.0f, (float)cos(a));
   return *this * m;
   }
                    
   matrix32 rotateC(float a)
   {
	   matrix32 m = matrix32((float)cos(a), (float)sin(a),      0.0f,
                         -(float)sin(a), (float)cos(a),      0.0f,
                            0.0f,            0.0f,      1.0f);
   return *this * m;
   }

//   matrix32 rotateA(float a)
//   {return *this * matrix32(1.0f, 0.0f,      0.0f,
//						  0.0f,  (float)cos(a), (float)sin(a),
//						  0.0f, (float)-sin(a), (float)cos(a));}
                   
//   matrix32 rotateB(float a)
//   {return *this * matrix32((float)cos(a),      0.0f,-(float)sin(a),
//									 0.0f,      1.0f,            0.0f,
//						  (float)sin(a),      0.0f, (float)cos(a));}
                    
//   matrix32 rotateC(float a)
//   {return *this * matrix32((float)cos(a), (float)sin(a),      0.0f,
//						 -(float)sin(a), (float)cos(a),      0.0f,
//									 0.0f,            0.0f,      1.0f);}

   matrix32 transpose()
   {
   		return matrix32(c1.x,c1.y,c1.z,
   					  c2.x,c2.y,c2.z,
   					  c3.x,c3.y,c3.z);
   } 
   
//   friend matrix32 rotation_matrix32(float pitch, float yaw)
//   {
//      return matrix32(
//      (float)cos(yaw), -(float)sin(yaw)*(float)cos(pitch), -(float)sin(yaw)* -(float)sin(pitch),
//      (float)sin(yaw),  (float)cos(yaw)*(float)cos(pitch),  (float)cos(yaw)* -(float)sin(pitch),
//                 0.0,             (float)sin(pitch),             (float)cos(pitch));
//   } 
 };



#endif

//======================================================================*/
//                                                                      */
//      Module ....... Vector.cpp                                       */
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
//        This file contains the definitions of the vector64 and matrix64   */
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
#ifndef vector64INCLUDED
#define vector64INCLUDED
//----------------------------------------------------------------------*/
// Include Files                                                        */
//----------------------------------------------------------------------*/
#include <math.h>
#include "vector32.h"

class STRING;
//class vector32;
class matrix32;
//----------------------------------------------------------------------*/
//   Constant Declarations ....                                         */
//----------------------------------------------------------------------*/
//#define xi vector64(1.0,0,0)
//#define yi vector64(0,1.0,0)
//#define zi vector64(0,0,1.0)

//======================================================================*/
//   Class Name .... vector64                                             */
//                                                                      */
//   Primary Data Members .......                                       */
//     double x - X Magnitude                                            */
//     double y - Y Magnitude                                            */
//     double z - Z Magnitude                                            */
//                                                                      */
//----------------------------------------------------------------------*/
//   Purpose ..........                                                 */
//     The vector64 class is used to encapsulate all methods relating to  */
//     the manipulation of vectors.                                     */
//                                                                      */
//======================================================================*/
class vector64
{

//----------------------------------------------------------------------*/
//   Public Data ....                                                   */
//----------------------------------------------------------------------*/
public:
   double x,y,z;

//======================================================================*/
//   Function Name .... vector::vector64()                                */
//                                                                      */
//   Parameters ....... None                                            */
//   Return Value .....                                                 */
//     Returns a vector64 with the x,y and z magnitudes set to zero       */
//======================================================================*/
   vector64() {x=y=z=0.0;}
   
//======================================================================*/
//   Function Name .... vector::vector64()                                */
//                                                                      */
//   Parameters .......                                                 */
//     double z_x - required X Magnitude                                 */
//     double z_y - required Y Magnitude                                 */
//     double z_z - required Z Magnitude                                 */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a vector64 with the x,y and z magnitudes set as required.  */
//======================================================================*/
   vector64(double z_x, double z_y, double z_z)
   {
      x = z_x;
      y = z_y;
      z = z_z;
   }
   
   vector64(double v)
   {
     x=y=z=v;
   }

   vector64(vector32 v)
   {
	   x=v.x;
	   y=v.y;
	   z=v.z;
   }

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
//     const vector64& a - first vector64 (passed by reference for speed)   */
//     const vector64& b - sencond vector64 (passed by reference for speed) */
//                                                                      */
//======================================================================*/
   int operator == (const vector64& a) {return ((x == a.x) && (y == a.y) && (z == a.z));}
   int operator != (const vector64& a) {return !(*this == a);}
   int operator > (const vector64& a) {return ((x > a.x) && (y > a.y) && (z > a.z));}
   int operator < (const vector64& a) {return ((x < a.x) && (y < a.y) && (z < a.z));}
   int operator >= (const vector64& a) {return ((x >= a.x) && (y >= a.y) && (z >= a.z));}
   int operator <= (const vector64& a) {return ((x <= a.x) && (y <= a.y) && (z <= a.z));}


//======================================================================*/
//   Arithmetic operators ....                                          */
//                                                                      */
//   a + b ..... returns result of adding vector64 a to vector64 b          */
//   a - b ..... returns result of subtracting vector64 b from vector64 a   */
//   - a ....... returns the inverse of vector64 a                        */
//   a * b ..... (Scalar) if one parameter is a double, returns the      */
//               result of multiplying the vector64 by the scalar.        */
//   a * b ..... (Vector) if both parameters are vectors returns the    */
//               CROSS product of vector64 a with vector64 b.               */
//   a / b ..... returns result of dividing vector64 a by double b         */
//   dot(a,b) .. returns the DOT product of vector64 a and vector64 v       */
//   length(a) . returns the magnitude of vector64 a                      */
//   unit(a) ... returns a unit vector, same orientation as vector64 a    */
//                                                                      */
//   Parameters .......                                                 */
//     const vector64& a - first vector64 (passed by reference for speed)   */
//     const vector64& b - sencond vector64 (passed by reference for speed) */
//                                                                      */
//======================================================================*/
   vector64 operator + (const vector64& a) 
   {return vector64(x + a.x, y + a.y, z + a.z);}

   vector64 operator - (const vector64& a) 
   {return vector64(x - a.x, y - a.y, z - a.z);}

   friend vector64 operator - (const vector64& a) 
   {return vector64(-a.x, -a.y, -a.z);}

   vector64 operator * (double b) 
   {return vector64(x * b, y * b, z * b);}

   friend vector64 operator * (double b, const vector64& v) 
   {return vector64(v.x * b, v.y * b, v.z * b);}

   vector64 operator * (const vector64& a) // CROSS product
   {return vector64(y * a.z - z * a.y,  z * a.x - x * a.z, x * a.y - y * a.x);}

   vector64 operator / (double b)  
   {double a=1/b; return vector64(x * a, y * a, z * a);}

   double dot (const vector64& a) // DOT product
   {return (x * a.x + y * a.y + z * a.z);}

   vector64 cross (const vector64& a) // CROSS product
   {return vector64(y * a.z - z * a.y,  z * a.x - x * a.z, x * a.y - y * a.x);}

//   friend double dot (const vector64& a, const vector64& b) // DOT product
//   {return (a.x * b.x + a.y * b.y + a.z * b.z);}

   double length ()
   {return (double)sqrt((double)(x*x) + (double)(y*y) + (double)(z * z));}

   double modulus ()  {return length();}

   vector64 unit ()
   {double b; return ((b = modulus()) == 0) ? vector64() : *this / b;}

};

inline double dot (const vector64& a, const vector64& b) // DOT product
   {return (a.x * b.x + a.y * b.y + a.z * b.z);}

inline vector64 cross (const vector64&v, const vector64& a) // CROSS product
   {return vector64(v.y * a.z - v.z * a.y,  v.z * a.x - v.x * a.z, v.x * a.y - v.y * a.x);}

inline double length(const vector64& v) 
{return (double)sqrt((double)(v.x*v.x) + (double)(v.y*v.y) + (double)(v.z * v.z));}

inline vector64 unit (const vector64& v)
   {double b; return ((b = length(v)) == 0) ? vector64() : vector64(v.x/b, v.y/b, v.z/b);}

//inline vector64 ABCTovector64(const vector64& a)
//   {return unit(vector64((float)(-sin(a.x)*-sin(a.z)),
//                       (float)(-sin(a.x)*cos(a.z)),
//                       (float)(cos(a.x)*cos(a.y))));}

//inline vector64 VectorToABC64(const vector64& v)
//{
//  double a, b, c;
//   b = 0;
//   a = acos(v.z);

//   if (a > 0.0)
//   {
//     if (fabs(sin(a)) < 1e-11)
//       c = 0;
//     else if (fabs(v.x) < fabs(v.y))
//       c = asin(fabs(v.x) / sin(a));
//     else
//       c = acos(fabs(v.y) / sin(a));
     
////---- Sort out the quadrant
//     if (v.y < 0)
//       if (v.x < 0) //(-x -y)
//         c = (2.0*(double)PI) - c;
//       else         //(+x -y)
//         c = c;
//     else
//       if (v.x < 0) //(-x +y)
//         c = PI + c;
//       else         //(+x +y)
//         c = PI - c;
//   }
//   else
//     c = 0.0;

//   return vector64((float)a, (float)b, (float)c);
//}

//======================================================================*/
//   Class Name .... matrix64                                             */
//                                                                      */
//   Primary Data Members .......                                       */
//     vector64 c1 .... Column one of matrix64                              */
//     vector64 c2 .... Column two of matrix64                              */
//     vector64 c3 .... Column three of matrix64                            */
//                                                                      */
//----------------------------------------------------------------------*/
//   Purpose ..........                                                 */
//     The matrix64 class is used to encapsulate all methods relating to  */
//     the manipulation of 3x3 matrices.                                */
//                                                                      */
//======================================================================*/
class matrix64
{

//----------------------------------------------------------------------*/
//   Public Data ....                                                   */
//----------------------------------------------------------------------*/
public:
   vector64 c1;
   vector64 c2;
   vector64 c3;

//======================================================================*/
//   Function Name .... matrix::matrix64()                                */
//                                                                      */
//   Parameters ....... None                                            */
//   Return Value .....                                                 */
//     Returns a matrix64 with the all elements set to zero               */
//======================================================================*/
   matrix64()
   {
      c1 = vector64(1.0,0.0,0.0);
      c2 = vector64(0.0,1.0,0.0);
      c3 = vector64(0.0,0.0,1.0);
   }

//======================================================================*/
//   Function Name .... matrix::matrix64()                                */
//                                                                      */
//   Parameters .......                                                 */
//     double x1,x2,x3 .. Fisrt row of matrix64                            */
//     double y1,y2,y3 .. Second row of matrix64                           */
//     double z1,z2,z3 .. Third row of matrix64                            */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a matrix64 with the all elements set as requested          */
//======================================================================*/
   matrix64(double x1, double x2, double x3,
      double y1, double y2, double y3,
      double z1, double z2, double z3)
   {
      c1 = vector64(x1,y1,z1);
      c2 = vector64(x2,y2,z2);
      c3 = vector64(x3,y3,z3);
   }

//======================================================================*/
//   Function Name .... matrix::matrix64()                                */
//                                                                      */
//   Parameters .......                                                 */
//     vector64 c1_z .. Fisrt column of matrix64                            */
//     vector64 c2_z .. Second column of matrix64                           */
//     vector64 c3_z .. Third column of matrix64                            */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a matrix64 with the all elements set as requested          */
//======================================================================*/
   matrix64(vector64 c1_z, vector64 c2_z, vector64 c3_z)
   {
      c1 = c1_z;
      c2 = c2_z;
      c3 = c3_z;
   }              

   matrix64(matrix32 m);

//======================================================================*/
//   Function Name .... matrix::matrix64()                                */
//                                                                      */
//   Parameters .......                                                 */
//     vector64 R .. A,B,C rotations of matrix64                            */
//                                                                      */
//   Return Value .....                                                 */
//     Returns a matrix64 with the all elements set as requested          */
//======================================================================*/
   matrix64(vector64 R)
   {
      *this = matrix64();
      *this = rotateA(R.x);
      *this = rotateB(R.y);
      *this = rotateC(R.z);
   }
   
//======================================================================*/
//   Data manipulation member functions ....                            */
//                                                                      */
//     row1() ..... returns a vector64 equivalent to row 1 of this matrix64 */
//     row2() ..... returns a vector64 equivalent to row 2 of this matrix64 */
//     row3() ..... returns a vector64 equivalent to row 3 of this matrix64 */
//                                                                      */
//     row1(a) .... sets row 1 of this matrix64 to vector64 a               */
//     row2(a) .... sets row 2 of this matrix64 to vector64 a               */
//     row3(a) .... sets row 3 of this matrix64 to vector64 a               */
//                                                                      */
//     rotation_matrix64(pitch, yaw) ... returns a matrix64 with appropriate*/
//     values to provide the required rotation transformation           */
//                                                                      */
//======================================================================*/
   vector64 row1 ()
   {return vector64(c1.x, c2.x, c3.x);}

   vector64 row2 ()
   {return vector64(c1.y, c2.y, c3.y);}

   vector64 row3 ()
   {return vector64(c1.z, c2.z, c3.z);}
   
   void row1 (const vector64& v)
   {c1.x = v.x; c2.x = v.y; c3.x = v.z;}

   void row2 (const vector64& v)
   {c1.y = v.x; c2.y = v.y; c3.y = v.z;}
   
   void row3 (const vector64& v)
   {c1.z = v.x; c2.z = v.y; c3.z = v.z;}
   
  
//======================================================================*/
//   Arithmetic operators ...                                           */
//                                                                      */
//   matrix64 a + matrix64 b .... returns the result of adding matrix64 a to  */
//                            matrix64 b.                                 */
//                                                                      */
//   matrix64 a - matrix64 b .... returns the result of subtracting matrix64 b*/
//                            from matrix64 a.                            */
//                                                                      */
//   matrix64 a - matrix64 b .... returns the result of subtracting matrix64 b*/
//                            from matrix64 a.                            */
//                                                                      */
//   matrix64 a * matrix64 b .... returns the matrix64 result of multiplying  */
//                            matrix64 b by matrix64 a.                     */
//                                                                      */
//   vector64 a * matrix64 b .... returns the vector64 result of multiplying  */
//                            vector64 b by matrix64 a.                     */
//                                                                      */
//   matrix64 a * vector64 b .... returns the vector64 result of multiplying  */
//                            matrix64 b by vector64 a.                     */
//                                                                      */
//======================================================================*/
   matrix64 operator + (const matrix64& m)
   {return matrix64(c1 + m.c1, c2 + m.c2, c3 + m.c3);}

   matrix64 operator - (const matrix64& m)
   {return matrix64(c1 - m.c1, c2 - m.c2, c3 - m.c3);}

   matrix64 operator * (matrix64& m)
   {matrix64 m1;
    m1.c1 = vector64(row1().dot(m.c1),row2().dot(m.c1),row3().dot(m.c1));
    m1.c2 = vector64(row1().dot(m.c2),row2().dot(m.c2),row3().dot(m.c2));
    m1.c3 = vector64(row1().dot(m.c3),row2().dot(m.c3),row3().dot(m.c3));
    return m1;}
   //return matrix64(row1().dot(m.c1), row1().dot(m.c2), row1().dot(m.c3),
   //               row2().dot(m.c1), row2().dot(m.c2), row2().dot(m.c3),
   //               row3().dot(m.c1), row3().dot(m.c2), row3().dot(m.c3));}

   friend vector64 operator * (const vector64& v, const matrix64& m)
   {return vector64(dot(v, m.c1),dot(v, m.c2),dot(v, m.c3));}

   friend vector64 operator * (matrix64& m, const vector64& v)
   {return vector64(dot(v, m.row1()),dot(v, m.row2()),dot(v, m.row3()));}

   matrix64 rotateA(double a)
   {
	   matrix64 m = matrix64(1.0, 0.0,      0.0,
                          0.0,  (double)cos(a), (double)sin(a),
                          0.0, (double)-sin(a), (double)cos(a));
   return *this * m;
   }
                   
   matrix64 rotateB(double a)
   {
	   matrix64 m = matrix64((double)cos(a),      0.0,-(double)sin(a),
                                     0.0,      1.0,            0.0,
                          (double)sin(a),      0.0, (double)cos(a));
    return *this * m;
   }
                    
   matrix64 rotateC(double a)
   {
	   matrix64 m = matrix64((double)cos(a), (double)sin(a),      0.0,
                         -(double)sin(a), (double)cos(a),      0.0,
                                     0.0,            0.0,      1.0);
    return *this * m;
   }


   matrix64 transpose()
   {
   		return matrix64(c1.x,c1.y,c1.z,
   					  c2.x,c2.y,c2.z,
   					  c3.x,c3.y,c3.z);
   } 
   
//   friend matrix64 rotation_matrix64(double pitch, double yaw)
//   {
//      return matrix64(
//      (double)cos(yaw), -(double)sin(yaw)*(double)cos(pitch), -(double)sin(yaw)* -(double)sin(pitch),
//      (double)sin(yaw),  (double)cos(yaw)*(double)cos(pitch),  (double)cos(yaw)* -(double)sin(pitch),
//                 0.0,             (double)sin(pitch),             (double)cos(pitch));
//   } 
 };

#endif  

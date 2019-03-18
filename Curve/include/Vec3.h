/// This class was written under the instruction from Jon Macey
///
/// \file Vec3.h
/// \brief encapsulates a 3d object
/// \author Ming Yan
/// \version 1.0
/// \date 17/3/19 Updated to NCCA/programming-paradigms-201819-Owlwine
/// Revision History :
/// Initial Version 11/3/19
/// \todo tidying up and code optimizations

#ifndef VEC3_H_
#define VEC3_H_

struct Vec3
{
    Vec3()=default;
    Vec3( const Vec3 & )=default;
    Vec3( float _x, float _y, float _z ) :
        x(_x), y(_y), z(_z){}

    void operator +=( const Vec3 &_rhs )
    {
        x+=_rhs.x;
        y+=_rhs.y;
        z+=_rhs.z;
    }

#define FCompare( a,b )\
    ( ( (a) -0.0000001f ) < ( b ) && ( ( a ) + 0.0000001f ) > ( b ) )

    bool operator == ( const Vec3 &_rhs )
    {
        return ( x == _rhs.x ) && ( y == _rhs.y ) && ( z == _rhs.z );
    }

    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

#endif  //  VEC3_H

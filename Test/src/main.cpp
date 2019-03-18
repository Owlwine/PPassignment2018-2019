///
/// @file main.cpp
/// @brief tests for functions


#include <gtest/gtest.h>

#include "Surface.h"

//------------------------------------------------------------------------------------------------------------------
int main( int argc, char **argv )
{
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
//------------------------------------------------------------------------------------------------------------------


//Test if default constructor works
//------------------------------------------------------------------------------------------------------------------
TEST( Vec3, defaultCtor )
{
    Vec3 a;
    EXPECT_FLOAT_EQ( a.x, 0.0f );
    EXPECT_FLOAT_EQ( a.y, 0.0f );
    EXPECT_FLOAT_EQ( a.z, 0.0f );
}
//------------------------------------------------------------------------------------------------------------------

//Test if user constructor works
//------------------------------------------------------------------------------------------------------------------
TEST( Vec3, userCtor )
{
    Vec3 b( 0.2f, 1.0f, -5.0f );
    EXPECT_FLOAT_EQ( b.x, 0.2f );
    EXPECT_FLOAT_EQ( b.y, 1.0f );
    EXPECT_FLOAT_EQ( b.z, -5.0f );
}
//------------------------------------------------------------------------------------------------------------------

//Test if operator "+=" works
//------------------------------------------------------------------------------------------------------------------
TEST( Vec3, plusEqual )
{
    Vec3 a( 1.0f, 2.0f, 3.0f );
    Vec3 b( 1.0f, 1.0f, 1.0f );
    a += b;
    EXPECT_FLOAT_EQ( a.x, 2.0f );
    EXPECT_FLOAT_EQ( a.y, 3.0f );
    EXPECT_FLOAT_EQ( a.z, 4.0f );
}
//------------------------------------------------------------------------------------------------------------------

//Test if default constructor works
//------------------------------------------------------------------------------------------------------------------
TEST( Curve, defaultCtor )
{
    Curve c;
    EXPECT_EQ( c.getControlPointsNumber(), 4 );
    EXPECT_EQ( c.getCurvePointsNumber(), 1000 );
    auto cp = c.getControlPoints();
    EXPECT_FLOAT_EQ( cp[0].x, 1.0f );
    EXPECT_FLOAT_EQ( cp[0].y, 1.0f );
    EXPECT_FLOAT_EQ( cp[0].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[1].x, 2.0f );
    EXPECT_FLOAT_EQ( cp[1].y, 2.0f );
    EXPECT_FLOAT_EQ( cp[1].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[2].x, 3.0f );
    EXPECT_FLOAT_EQ( cp[2].y, 2.0f );
    EXPECT_FLOAT_EQ( cp[2].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[3].x, 4.0f );
    EXPECT_FLOAT_EQ( cp[3].y, 1.0f );
    EXPECT_FLOAT_EQ( cp[3].z, 0.0f );
}
//------------------------------------------------------------------------------------------------------------------

//Test if user constructor works
//------------------------------------------------------------------------------------------------------------------
TEST( Curve, userCtor )
{
    Curve c( { {0.0f,3.0f,4.0f}, {0.0f,1.1f,2.0f} }, 10);
    EXPECT_EQ( c.getControlPointsNumber(), 2 );
    EXPECT_EQ( c.getCurvePointsNumber(), 10 );
    auto cp = c.getControlPoints();
    EXPECT_FLOAT_EQ( cp[0].x, 0.0f );
    EXPECT_FLOAT_EQ( cp[0].y, 3.0f );
    EXPECT_FLOAT_EQ( cp[0].z, 4.0f );
    EXPECT_FLOAT_EQ( cp[1].x, 0.0f );
    EXPECT_FLOAT_EQ( cp[1].y, 1.1f );
    EXPECT_FLOAT_EQ( cp[1].z, 2.0f );
}
//------------------------------------------------------------------------------------------------------------------

//Test if it is able to calculate binomial cofficient
//------------------------------------------------------------------------------------------------------------------
TEST( Curve, binomialCoeffs )
{
    std::vector<size_t> C( 5 );
    Curve c;
    c.binomialCoeffs( C );
    EXPECT_EQ( C[0], 1 );
    EXPECT_EQ( C[1], 4 );
    EXPECT_EQ( C[2], 6 );
    EXPECT_EQ( C[3], 4 );
    EXPECT_EQ( C[4], 1 );
}
//------------------------------------------------------------------------------------------------------------------

//Test if it is able to evaluate and generate a bezier cure, either by using default \
//values, or by using customized values(control points and the quantity of points to \
//generate the curve). If the bezier curve is generated successfully, the the first \
//and the last point will go through the first and last control points. It is acceptable \
//if the results are close enough reasonably.
//------------------------------------------------------------------------------------------------------------------
TEST( Curve, evaluateBezierCurve )
{
    Curve c;
    c.evaluateBezierCurve();
    auto cop = c.getControlPoints();
    auto cup = c.getCurvePoints();

    //comparing the first curve point and the first control point
    EXPECT_FLOAT_EQ( cup[0].x, cop[0].x );
    EXPECT_FLOAT_EQ( cup[0].y, cop[0].y );
    EXPECT_FLOAT_EQ( cup[0].z, cop[0].z );

    //comparing the last curve point and the last control point
    EXPECT_EQ( abs( cup[c.getCurvePointsNumber()-1].x - cop[c.getControlPointsNumber()-1].x ) < 0.02f, 1 );
    EXPECT_EQ( abs( cup[c.getCurvePointsNumber()-1].y - cop[c.getControlPointsNumber()-1].y ) < 0.02f, 1 );
    EXPECT_EQ( abs( cup[c.getCurvePointsNumber()-1].z - cop[c.getControlPointsNumber()-1].z ) < 0.02f, 1 );

    //test with customized values
    Curve c1( {{0.0f,3.0f,4.0f}, {0.0f,1.1f,2.0f}, {2.0f,9.1f,1.0f}}, 1000 );
    c1.evaluateBezierCurve();
    auto cop1 = c1.getControlPoints();
    auto cup1 = c1.getCurvePoints();
    EXPECT_FLOAT_EQ( cup1[0].x, cop1[0].x );
    EXPECT_FLOAT_EQ( cup1[0].y, cop1[0].y );
    EXPECT_FLOAT_EQ( cup1[0].z, cop1[0].z );
    EXPECT_EQ( abs( cup1[c1.getCurvePointsNumber()-1].x - cop1[c1.getControlPointsNumber()-1].x ) < 0.02f, 1 );
    EXPECT_EQ( abs( cup1[c1.getCurvePointsNumber()-1].y - cop1[c1.getControlPointsNumber()-1].y ) < 0.02f, 1 );
    EXPECT_EQ( abs( cup1[c1.getCurvePointsNumber()-1].z - cop1[c1.getControlPointsNumber()-1].z ) < 0.02f, 1 );
}
//------------------------------------------------------------------------------------------------------------------

//Test if default constructor works
//------------------------------------------------------------------------------------------------------------------
TEST( Surface, defaultCtor )
{
    Surface s;
    EXPECT_EQ( s.getSurfaceRow(), 4 );
    EXPECT_EQ( s.getSurfaceColumn(), 3 );
    auto cp = s.getSurfaceControlPoints();
    EXPECT_FLOAT_EQ( cp[0].x, -10.0f );
    EXPECT_FLOAT_EQ( cp[0].y, -10.0f );
    EXPECT_FLOAT_EQ( cp[0].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[1].x, 0.0f );
    EXPECT_FLOAT_EQ( cp[1].y, 20.0f );
    EXPECT_FLOAT_EQ( cp[1].z, 6.0f );
    EXPECT_FLOAT_EQ( cp[2].x, 10.0f );
    EXPECT_FLOAT_EQ( cp[2].y, 10.0f );
    EXPECT_FLOAT_EQ( cp[2].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[3].x, -7.0f );
    EXPECT_FLOAT_EQ( cp[3].y, 7.0f );
    EXPECT_FLOAT_EQ( cp[3].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[4].x, 0.0f );
    EXPECT_FLOAT_EQ( cp[4].y, 10.0f );
    EXPECT_FLOAT_EQ( cp[4].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[5].x, 10.0f );
    EXPECT_FLOAT_EQ( cp[5].y, 10.0f );
    EXPECT_FLOAT_EQ( cp[5].z, -5.0f );
    EXPECT_FLOAT_EQ( cp[6].x, 7.0f );
    EXPECT_FLOAT_EQ( cp[6].y, 10.0f );
    EXPECT_FLOAT_EQ( cp[6].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[7].x, 0.0f );
    EXPECT_FLOAT_EQ( cp[7].y, -10.0f );
    EXPECT_FLOAT_EQ( cp[7].z, -6.0f );
    EXPECT_FLOAT_EQ( cp[8].x, 10.0f );
    EXPECT_FLOAT_EQ( cp[8].y, 10.0f );
    EXPECT_FLOAT_EQ( cp[8].z, -10.0f );
    EXPECT_FLOAT_EQ( cp[9].x, 15.0f );
    EXPECT_FLOAT_EQ( cp[9].y, -5.0f );
    EXPECT_FLOAT_EQ( cp[9].z, 0.0f );
    EXPECT_FLOAT_EQ( cp[10].x, 0.0f );
    EXPECT_FLOAT_EQ( cp[10].y, -20.0f );
    EXPECT_FLOAT_EQ( cp[10].z, -12.0f );
    EXPECT_FLOAT_EQ( cp[11].x, 10.0f );
    EXPECT_FLOAT_EQ( cp[11].y, 10.0f );
    EXPECT_FLOAT_EQ( cp[11].z, -15.0f );
}
//------------------------------------------------------------------------------------------------------------------

//test if generate surface would succeed
//------------------------------------------------------------------------------------------------------------------
TEST( Surface, generateSurface )
{
    Surface s;
    s.generateSurface( 1500 );
    auto p = s.getCurves();

    size_t maxCurveNumber = s.getSurfaceColumn() + s.getSurfaceRow();
    //check if curve points amount has been updated
    for( size_t i = 0; i < ( maxCurveNumber ); ++i )
    {
        EXPECT_EQ( p[i].getCurvePointsNumber() , 1500);
    }

    for(size_t k=0.0;k<4;++k)
        std::cout<<p[0].getControlPoints()[k].x<<' '<<p[0].getControlPoints()[k].y<<' '<<p[0].getControlPoints()[k].z<<'\n';

    //check the first curve and the last curve, \
    //see if their control points are same as expected
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[0].x, -10.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[0].y, -10.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[0].z, 0.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[1].x, -7.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[1].y, 7.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[1].z, 0.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[2].x, 7.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[2].y, 10.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[2].z, 0.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[3].x, 15.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[3].y, -5.0f );
    EXPECT_FLOAT_EQ( p[0].getControlPoints()[3].z, 0.0f );

    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[0].x, 15.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[0].y, -5.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[0].z, 0.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[1].x, 0.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[1].y, -20.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[1].z, -12.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[2].x, 10.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[2].y, 10.0f );
    EXPECT_FLOAT_EQ( p[ maxCurveNumber - 1 ].getControlPoints()[2].z, -15.0f );
}
//------------------------------------------------------------------------------------------------------------------

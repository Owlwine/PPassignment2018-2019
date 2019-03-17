///
/// @file main.cpp
/// @brief tests for functions


#include <iostream>

#include <gtest/gtest.h>

#include "Curve.h"


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}


TEST(Vec3, defaultCtor)
{
    Vec3 a;
    EXPECT_FLOAT_EQ(a.x,0.0f);
    EXPECT_FLOAT_EQ(a.y,0.0f);
    EXPECT_FLOAT_EQ(a.z,0.0f);
}

TEST(Vec3, userCtor)
{
    Vec3 b(0.2f,1.0f,-5.0f);
    EXPECT_FLOAT_EQ(b.x,0.2f);
    EXPECT_FLOAT_EQ(b.y,1.0f);
    EXPECT_FLOAT_EQ(b.z,-5.0f);
}

TEST(Vec3, plusEqual)
{
    Vec3 a(1.0f,2.0f,3.0f);
    Vec3 b(1.0f,1.0f,1.0f);
    a+=b;
    EXPECT_FLOAT_EQ(a.x,2.0f);
    EXPECT_FLOAT_EQ(a.y,3.0f);
    EXPECT_FLOAT_EQ(a.z,4.0f);
}


TEST(Curve, defaultCtor)
{
    Curve c;
    EXPECT_EQ(c.getControlPointsNumber(),4);
    EXPECT_EQ(c.getCurvePointsNumber(),1000);
    auto cp=c.getControlPoints();
    EXPECT_FLOAT_EQ(cp[0].x,1.0f);
    EXPECT_FLOAT_EQ(cp[0].y,1.0f);
    EXPECT_FLOAT_EQ(cp[0].z,0.0f);
    EXPECT_FLOAT_EQ(cp[1].x,2.0f);
    EXPECT_FLOAT_EQ(cp[1].y,2.0f);
    EXPECT_FLOAT_EQ(cp[1].z,0.0f);
    EXPECT_FLOAT_EQ(cp[2].x,3.0f);
    EXPECT_FLOAT_EQ(cp[2].y,2.0f);
    EXPECT_FLOAT_EQ(cp[2].z,0.0f);
    EXPECT_FLOAT_EQ(cp[3].x,4.0f);
    EXPECT_FLOAT_EQ(cp[3].y,1.0f);
    EXPECT_FLOAT_EQ(cp[3].z,0.0f);
}


TEST(Curve, bezierCurve)
{
    Curve c;
    c.bezierCurve({{0.0f,3.0f,4.0f},{0.0f,1.1f,2.0f}},100);
    EXPECT_EQ(c.getControlPointsNumber(),2);
    EXPECT_EQ(c.getCurvePointsNumber(),100);
    auto cp=c.getControlPoints();
    EXPECT_FLOAT_EQ(cp[0].x,0.0f);
    EXPECT_FLOAT_EQ(cp[0].y,3.0f);
    EXPECT_FLOAT_EQ(cp[0].z,4.0f);
    EXPECT_FLOAT_EQ(cp[1].x,0.0f);
    EXPECT_FLOAT_EQ(cp[1].y,1.1f);
    EXPECT_FLOAT_EQ(cp[1].z,2.0f);
}

TEST(Curve,binomialCoeffs)
{
    std::vector<size_t> C(5);
    Curve c;
    c.binomialCoeffs(C);
    EXPECT_EQ(C[0],1);
    EXPECT_EQ(C[1],4);
    EXPECT_EQ(C[2],6);
    EXPECT_EQ(C[3],4);
    EXPECT_EQ(C[4],1);
}

TEST(Curve, evaluateBezierCurve)
{
    Curve c;
    c.evaluateBezierCurve();
    auto cop = c.getControlPoints();
    auto cup = c.getCurvePoints();
    EXPECT_FLOAT_EQ(cup[0].x,cop[0].x);
    EXPECT_FLOAT_EQ(cup[0].y,cop[0].y);
    EXPECT_FLOAT_EQ(cup[0].z,cop[0].z);
    EXPECT_EQ(abs(cup[c.getCurvePointsNumber()-1].x -cop[c.getControlPointsNumber()-1].x) < 0.02f,1);
    EXPECT_EQ(abs(cup[c.getCurvePointsNumber()-1].y -cop[c.getControlPointsNumber()-1].y) < 0.02f,1);
    EXPECT_EQ(abs(cup[c.getCurvePointsNumber()-1].z -cop[c.getControlPointsNumber()-1].z) < 0.02f,1);

    Curve c1;
    c1.bezierCurve({{0.0f,3.0f,4.0f},{0.0f,1.1f,2.0f},{2.0f,9.1f,1.0f}},1000);
    c1.evaluateBezierCurve();
    auto cop1 = c1.getControlPoints();
    auto cup1 = c1.getCurvePoints();
    EXPECT_FLOAT_EQ(cup1[0].x,cop1[0].x);
    EXPECT_FLOAT_EQ(cup1[0].y,cop1[0].y);
    EXPECT_FLOAT_EQ(cup1[0].z,cop1[0].z);
    EXPECT_EQ(abs(cup1[c1.getCurvePointsNumber()-1].x -cop1[c1.getControlPointsNumber()-1].x) < 0.02f,1);
    EXPECT_EQ(abs(cup1[c1.getCurvePointsNumber()-1].y -cop1[c1.getControlPointsNumber()-1].y) < 0.02f,1);
    EXPECT_EQ(abs(cup1[c1.getCurvePointsNumber()-1].z -cop1[c1.getControlPointsNumber()-1].z) < 0.02f,1);
}

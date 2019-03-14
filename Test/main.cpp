#include <iostream>
#include "ControlPoint.h"
#include "Curve.h"
#include <gtest/gtest.h>
//#include "Curve.h"
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


TEST(ControlPoint, defaultCtor)
{
    ControlPoint p;
    auto pos=p.getPosition();
    EXPECT_FLOAT_EQ(pos.x,0.0f);
    EXPECT_FLOAT_EQ(pos.y,0.0f);
    EXPECT_FLOAT_EQ(pos.z,0.0f);
}


TEST(ControlPoint, setPosition)
{
    ControlPoint p;
    p.setPosition({0.0f, -2.5,12.0004f});
    auto pos=p.getPosition();
    EXPECT_FLOAT_EQ(pos.x,0.0f);
    EXPECT_FLOAT_EQ(pos.y,-2.5f);
    EXPECT_FLOAT_EQ(pos.z,12.0004f);
}

TEST(ControlPoint, userCtor)
{
    ControlPoint p({1.0f,3.0f,4.0f});
    auto pos=p.getPosition();
    EXPECT_FLOAT_EQ(pos.x,1.0f);
    EXPECT_FLOAT_EQ(pos.y,3.0f);
    EXPECT_FLOAT_EQ(pos.z,4.0f);
}

TEST(Curve, defaultCtor)
{
    Curve c;
    EXPECT_EQ(c.getControlPointsNumber(),4);
    EXPECT_EQ(c.getCurvePointsNumber(),1000);
}


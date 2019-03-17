///
/// @file main.cpp
/// @brief generate curves without drawing


#include <iostream>
#include "Curve.h"


int main()
{
    std::cout<<"Curve main.cpp\n";   

    size_t numCurvePoints =100;
    const std::vector<Vec3> controlPoints ={{2.0,4.0,0.0}, {1.0,5.0,0.0},{3.0,6.0,0.0},{2.0,7.0,0.0}};
    Curve c;
    c.bezierCurve(controlPoints,numCurvePoints);
    c.evaluateBezierCurve();
    c.showCurvePoints();
}

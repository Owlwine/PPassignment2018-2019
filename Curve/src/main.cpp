#include <iostream>
#include "ControlPoint.h"
#include "Curve.h"
int main()
{
    std::cout<<"Curve main.cpp\n";
    /*
    ControlPoint p({1.0f,2.0f,3.0f});
    p.render();
    */
    size_t numControlPoints = 2;
    size_t numCurvePoints =2000;
    const std::vector<Vec3> ControlPoints = {{2.0,4.0,8.0}, {1.0,5.0,6.0}};
    Curve c(ControlPoints,numControlPoints,numCurvePoints);
    std::cout<<c.getControlPointsNumber()<<' '<< c.getCurvePointsNumber()<<"\n";
    c.showControlPoints();

}

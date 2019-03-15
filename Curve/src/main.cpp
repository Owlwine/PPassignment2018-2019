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

    int numControlPoints = 4;
    int numCurvePoints =10;
    const std::vector<Vec3> controlPoints = {{2.0,4.0,0.0}, {1.0,5.0,0.0},{3.0,6.0,0.0},{2.0,7.0,0.0}};
    Curve c;
    c.BezierCurve(controlPoints,numControlPoints,numCurvePoints);
    //std::cout<<c.getControlPointsNumber()<<' '<< c.getCurvePointsNumber()<<"\n";
    //c.showControlPoints();
    std::vector<size_t> C={0,0,0,0};
    std::vector<Vec3> curvePoints(10);//={{0,0,0}};
    c.binomialCoeffs(numControlPoints-1, C);
    for(auto c : C)
      std::cout<<"coef "<<c<<'\n';
    c.evaluateBezierCurve( curvePoints, numControlPoints, controlPoints, C);
}

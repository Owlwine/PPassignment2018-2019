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

    size_t numControlPoints = 4;
    size_t numCurvePoints =100;
    const std::vector<Vec3> controlPoints ={{2.0,4.0,0.0}, {1.0,5.0,0.0},{3.0,6.0,0.0},{2.0,7.0,0.0}};
    Curve c;
    c.BezierCurve(controlPoints,numControlPoints,numCurvePoints);
    //std::cout<<c.getControlPointsNumber()<<' '<< c.getCurvePointsNumber()<<"\n";
    //c.showControlPoints();
    std::vector<size_t> C(numControlPoints);
    std::vector<Vec3> curvePoints(numCurvePoints);//={{0,0,0}};
    c.binomialCoeffs(numControlPoints-1, C);
    /*
    for(auto c : C)
      std::cout<<"coef "<<c<<'\n';
      */
    c.evaluateBezierCurve( curvePoints, controlPoints, C);
    c.getCurvePoints(curvePoints);
    //for(size_t i =0; i<numCurvePoints; ++i)
    //std::cout<<curvePoints[i].x<<' '<<curvePoints[i].y<<' '<<curvePoints[i].z<<"\n";
    c.renderGL();

}

#ifndef CURVE_H_
#define CURVE_H_
#include <vector>
#include "Vec3.h"
class Curve
{
public:
    Curve()=default;
    Curve(const Curve &)=delete;
    Curve & operator=(const Curve &)=delete ;
    void BezierCurve(const std::vector<Vec3> &_ControlPoints, size_t _numCurvePoints);
    size_t getControlPointsNumber() const;
    size_t getCurvePointsNumber() const;
    std::vector<Vec3> getControlPoints() const;
    void showControlPoints() const;
    void binomialCoeffs(size_t n, std::vector<size_t> &_C);
    void evaluateBezierCurve();
    void showCurvePoints() const;
    void renderGL() const;


private:
    size_t m_numControlPoints=4;
    size_t m_numCurvePoints=1000;
    std::vector<Vec3> m_ControlPoints={{1.0f,1.0f,0.0f},{2.0f,2.0f,0.0f},{3.0f,2.0f,0.0f},{4.0f,1.0f,0.0f}};
    std::vector<Vec3> m_CurvePoints;
};
#endif

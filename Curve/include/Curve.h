#ifndef CURVE_H_
#define CURVE_H_
#include <vector>
#include "Vec3.h"
#include "ControlPoint.h"
class Curve
{
public:
    Curve()=default;
    Curve(const Curve &)=delete;
    Curve & operator=(const Curve &)=delete ;
    void BezierCurve(const std::vector<Vec3> &_ControlPoints, size_t _numControlPoints, size_t _numCurvePoints);
    size_t getControlPointsNumber() const;
    size_t getCurvePointsNumber() const;
    void showControlPoints() const;
    void binomialCoeffs(size_t n, std::vector<size_t> &_C);
    void evaluateBezierCurve(std::vector<Vec3> &_curvePoints, size_t _nControlPoints, const std::vector<Vec3> &_controlPoints, const std::vector<size_t> &_C);
    //void renderGL() const;
private:
    size_t m_numControlPoints=4;
    size_t m_numCurvePoints=1000;
    std::vector<Vec3> m_ControlPoints;
};
#endif

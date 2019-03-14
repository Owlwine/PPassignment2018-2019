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
    Curve(const std::vector<ControlPoint> &_ControlPoints, size_t _numControlPoints, size_t _numCurvePoints);
    size_t getControlPointsNumber() const;
    size_t getCurvePointsNumber() const;
    void render() const;
    //void renderGL() const;
private:
    size_t m_numControlPoints=4;
    size_t m_numCurvePoints=1000;
    std::vector<ControlPoint> m_ControlPoints;
};
#endif

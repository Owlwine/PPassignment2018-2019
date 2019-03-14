#include "Curve.h"
#include <random>

size_t Curve::getControlPointsNumber() const
{
    return m_numControlPoints;
}

size_t Curve::getCurvePointsNumber() const
{
    return m_numCurvePoints;
}


Curve::Curve(const std::vector<ControlPoint> &_ControlPoints, size_t _numControlPoints, size_t _numCurvePoints)
{
    m_numControlPoints=_numControlPoints;
    m_numCurvePoints=_numCurvePoints;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()

/*
    for(size_t i=0;i <m_numControlPoints; ++i)
    m_ControlPoints[i].setPosition(_ControlPoints[i].getPosition());
*/

}

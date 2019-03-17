/// \file Curve.h
/// \brief generate different types of curves
/// \author Ming Yan
/// \version 1.0
/// \date 17/3/19 Updated to NCCA/programming-paradigms-201819-Owlwine
/// Revision History :
/// Initial Version 11/3/19
/// \todo tidying up and code optimizations


#ifndef CURVE_H_
#define CURVE_H_


#include <cmath>
#include <cstdlib>
#include <GL/gl.h>
#include <stdlib.h>
#include <vector>

#include "Vec3.h"

class Curve
{
public:
    Curve()=default;
    Curve(const Curve &)=delete;
    Curve & operator=(const Curve &)=delete ;

    void                bezierCurve(const std::vector<Vec3> &_controlPoints, const size_t _numCurvePoints);
    size_t              getControlPointsNumber() const;
    size_t              getCurvePointsNumber() const;
    std::vector<Vec3>   getControlPoints() const;
    void                showControlPoints() const;
    void                binomialCoeffs(std::vector<size_t> &io_c);
    void                evaluateBezierCurve();
    std::vector<Vec3>   getCurvePoints() const;
    void                showCurvePoints() const;
    void                renderGL() const;


private:
    size_t              m_numControlPoints=4;
    size_t              m_numCurvePoints=1000;
    std::vector<Vec3>   m_controlPoints={{1.0f,1.0f,0.0f},{2.0f,2.0f,0.0f},{3.0f,2.0f,0.0f},{4.0f,1.0f,0.0f}};
    std::vector<Vec3>   m_curvePoints;
};
#endif  //  CURVE_H_

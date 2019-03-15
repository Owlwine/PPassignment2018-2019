#include <iostream>
#include <cmath>
#include <stdlib.h>
#include "Curve.h"


size_t Curve::getControlPointsNumber() const
{
    return m_numControlPoints;
}

size_t Curve::getCurvePointsNumber() const
{
    return m_numCurvePoints;
}


void Curve::BezierCurve(const std::vector<Vec3> &_ControlPoints, int _numControlPoints, int _numCurvePoints)
{
    m_numControlPoints=_numControlPoints;
    m_numCurvePoints=_numCurvePoints;

    for(size_t i=0;i <_numControlPoints; ++i)
    m_ControlPoints.push_back(_ControlPoints[i]);


}

void Curve::showControlPoints() const
{
    for(size_t i=0;i <m_numControlPoints; ++i)
    {
        std::cout<<m_ControlPoints[i].x<<' '<<m_ControlPoints[i].y<<' '<<m_ControlPoints[i].z<<"\n";
    }

}

void Curve::binomialCoeffs(int n,std::vector<size_t> &_C)
{
    int k,i;

    for (k = 0; k <= n ; ++k)
    {
        _C[k] = 1;

        for (i = n; i >= k+1; --i)
            _C[k] *= i;
        for (i = n-k; i >= 2; --i)
            _C[k] /= i;
       // std::cout<<_C[k];

    }

}

void Curve::evaluateBezierCurve(int _nCurvePoints, std::vector<Vec3> &_curvePoints, int _nControlPoints, const std::vector<Vec3> &_controlPoints,const std::vector<size_t> &_C)
{
    double bezierBlendingFunction;

    for(int i = 0;i <= _nCurvePoints; ++i)
        for(int j =0;j < _nControlPoints;++j)
        {
            bezierBlendingFunction = _C[j] * pow(double(i)/double(_nCurvePoints),double(j)) * pow(1-(double(i)/double(_nCurvePoints)),double(_nControlPoints -1 -j));
            std::cout<<i<<' '<<_C[j]<<' '<<pow(double(i)/double(_nCurvePoints),double(j))<<' '<<pow(1-(double(i)/double(_nCurvePoints)),double(_nControlPoints -1 -j))<<' '<<bezierBlendingFunction<<"\n";
            _curvePoints[i].x += _controlPoints[j].x * bezierBlendingFunction;
            _curvePoints[i].y += _controlPoints[j].y * bezierBlendingFunction;
            _curvePoints[i].z += _controlPoints[j].z * bezierBlendingFunction;
            std::cout<<_curvePoints[i].x<<' '<<_curvePoints[i].y<<' '<<_curvePoints[i].z<<"\n";
        }

}

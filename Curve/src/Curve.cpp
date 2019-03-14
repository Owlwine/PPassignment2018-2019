#include <iostream>
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


Curve::Curve(const std::vector<Vec3> &_ControlPoints, size_t _numControlPoints, size_t _numCurvePoints)
{
    m_numControlPoints=_numControlPoints;
    m_numCurvePoints=_numCurvePoints;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()


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
    int k,j;

    for (k = 0; k <= n ; ++k)
    {
        _C[k] = 1;

        for (j = n; j >= k+1; --j)
            _C[k] *= j;
        for (j = n-k; j >= 2; --j)
            _C[k] /= j;
        std::cout<<_C[k];

    }

}

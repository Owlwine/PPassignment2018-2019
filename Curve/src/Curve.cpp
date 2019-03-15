#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <GL/gl.h>
#include "Curve.h"


size_t Curve::getControlPointsNumber() const
{
    return m_numControlPoints;
}

size_t Curve::getCurvePointsNumber() const
{
    return m_numCurvePoints;
}


void Curve::BezierCurve(const std::vector<Vec3> &_ControlPoints, size_t _numControlPoints, size_t _numCurvePoints)
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

void Curve::binomialCoeffs(size_t n,std::vector<size_t> &_C)
{
    size_t k,i;

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

void Curve::evaluateBezierCurve(std::vector<Vec3> &_curvePoints, const std::vector<Vec3> &_controlPoints,const std::vector<size_t> &_C)
{
    float bezierBlendingFunction;
    auto _nCurvePoints=_curvePoints.size();
    auto _nControlPoints=_controlPoints.size();
    for(size_t i = 0;i <= _curvePoints.size(); ++i)
        for(size_t j =0;j < _nControlPoints;++j)
        {
//          for(auto c : _C)
//            std::cout<<"coef "<<c<<'\n';

            bezierBlendingFunction = _C[j] * powf(float(i)/float(_nCurvePoints),float(j)) * powf(1-(float(i)/float(_nCurvePoints)),float(_nControlPoints -1 -j));
            //std::cout<<i<<' '<<_C[j]<<' '<<powf(float(i)/float(_nCurvePoints),float(j))<<' '<<powf(1-(float(i)/float(_nCurvePoints)),float(_nControlPoints -1 -j))<<' '<<bezierBlendingFunction<<"\n";
            _curvePoints[i].x += _controlPoints[j].x * bezierBlendingFunction;
            _curvePoints[i].y += _controlPoints[j].y * bezierBlendingFunction;
            _curvePoints[i].z += _controlPoints[j].z * bezierBlendingFunction;
            //std::cout<<_curvePoints[i].x<<' '<<_curvePoints[i].y<<' '<<_curvePoints[i].z<<"\n";
        }    


}
void Curve::getCurvePoints(const std::vector<Vec3> &_curvePoints)
{
    for(size_t i = 0;i < _curvePoints.size(); ++i)
    {
        m_CurvePoints.push_back(_curvePoints[i]);
       // std::cout<<m_CurvePoints[i].x<<' '<<m_CurvePoints[i].y<<' '<<m_CurvePoints[i].z<<'\n';
    }

}

void Curve::renderGL() const
{

    for(size_t i = 0;i < m_numCurvePoints; ++i)
    {
        glPointSize(2.0);
        glBegin(GL_POINTS);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(m_CurvePoints[i].x,m_CurvePoints[i].y,m_CurvePoints[i].z);
        //std::cout<<m_CurvePoints[i].x<<' '<<m_CurvePoints[i].y<<' '<<m_CurvePoints[i].z<<'\n';
        glEnd();
    }

}

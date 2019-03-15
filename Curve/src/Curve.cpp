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
        std::cout<<_C[k];

    }

}

void Curve::evaluateBezierCurve( const std::vector<Vec3> &_controlPoints)
{
    float bezierBlendingFunction;
    std::vector<size_t> C(m_numControlPoints);
    std::vector<Vec3> _CurvePoints(m_numCurvePoints);


    binomialCoeffs(m_numControlPoints-1,C);
    for(size_t i = 0;i <= m_numCurvePoints; ++i)
        for(size_t j =0;j < m_numControlPoints;++j)
        {
//          for(auto c : _C)
//            std::cout<<"coef "<<c<<'\n';

            bezierBlendingFunction = C[j] * powf(float(i)/float(m_numCurvePoints),float(j)) * powf(1-(float(i)/float(m_numCurvePoints)),float((m_numControlPoints -1) -j));
            //std::cout<<i<<' '<<_C[j]<<' '<<powf(float(i)/float(m_numCurvePoints),float(j))<<' '<<powf(1-(float(i)/float(m_numCurvePoints)),float(m_numControlPoints -1 -j))<<' '<<bezierBlendingFunction<<"\n";
            _CurvePoints[i].x += _controlPoints[j].x * bezierBlendingFunction;
            _CurvePoints[i].y += _controlPoints[j].y * bezierBlendingFunction;
            _CurvePoints[i].z += _controlPoints[j].z * bezierBlendingFunction;
            //std::cout<<m_CurvePoints[i].x <<"\n";

        }

    for(size_t i = 0;i <= m_numCurvePoints; ++i)
        m_CurvePoints.push_back(_CurvePoints[i]);
}

void Curve::render()const
{
    for(size_t i = 0;i <= m_numCurvePoints; ++i)
           std::cout<<m_CurvePoints[i].x<<' '<<m_CurvePoints[i].y<<' '<<m_CurvePoints[i].z<<'\n';
}

void Curve::getCurvePoints(const std::vector<Vec3> &_curvePoints)
{
    for(size_t i = 0;i < _curvePoints.size(); ++i)
    {
        m_CurvePoints.push_back(_curvePoints[i]);
        std::cout<<m_CurvePoints[i].x<<' '<<m_CurvePoints[i].y<<' '<<m_CurvePoints[i].z<<'\n';
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

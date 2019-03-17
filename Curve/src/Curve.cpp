///
/// @file Curve.cpp
/// @brief functions for generating curves

#include <iostream>
#include "Curve.h"


size_t Curve::getControlPointsNumber() const
{
    return m_numControlPoints;
}

size_t Curve::getCurvePointsNumber() const
{
    return m_numCurvePoints;
}


void Curve::bezierCurve(const std::vector<Vec3> &_controlPoints,  const size_t _numCurvePoints)
{

    while (m_numControlPoints > 0)
    {
        m_controlPoints.pop_back();
        --m_numControlPoints;
    }

    m_numControlPoints=_controlPoints.size();
    m_numCurvePoints=_numCurvePoints;

    for(size_t i=0;i <m_numControlPoints; ++i)
    m_controlPoints.push_back(_controlPoints[i]);
}

std::vector<Vec3> Curve::getControlPoints() const
{
    return m_controlPoints;
}

void Curve::showControlPoints() const
{
    for(size_t i=0;i <m_numControlPoints; ++i)
    {
        std::cout<<m_controlPoints[i].x<<' '<<m_controlPoints[i].y<<' '<<m_controlPoints[i].z<<"\n";
    }
}

void Curve::binomialCoeffs(std::vector<size_t> &io_c)
{
    size_t i, n = io_c.size() -1;
    for (size_t k = 0; k <= n ; ++k)
    {
        io_c[k] = 1;

        for (i = n; i >= k+1; --i)
            io_c[k] *= i;
        for (i = n-k; i >= 2; --i)
            io_c[k] /= i;
    }
}

void Curve::evaluateBezierCurve( )
{
    float bezierBlendingFunction;
    std::vector<size_t> C(m_numControlPoints);
    std::vector<Vec3> CurvePoints(m_numCurvePoints);


    binomialCoeffs(C);
    for(size_t i = 0;i < m_numCurvePoints; ++i)
        for(size_t j =0;j < m_numControlPoints;++j)
        {
            bezierBlendingFunction = C[j] * powf(float(i)/float(m_numCurvePoints),float(j)) * powf(1-(float(i)/float(m_numCurvePoints)),float((m_numControlPoints -1) -j));            
            CurvePoints[i].x += m_controlPoints[j].x * bezierBlendingFunction;
            CurvePoints[i].y += m_controlPoints[j].y * bezierBlendingFunction;
            CurvePoints[i].z += m_controlPoints[j].z * bezierBlendingFunction;
        }

    for(size_t i = 0;i < m_numCurvePoints; ++i)
        m_curvePoints.push_back(CurvePoints[i]);
}

std::vector<Vec3> Curve::getCurvePoints() const
{
    return m_curvePoints;
}
void Curve::showCurvePoints()const
{
    for(size_t i = 0;i < m_numCurvePoints; ++i)
           std::cout<<m_curvePoints[i].x<<' '<<m_curvePoints[i].y<<' '<<m_curvePoints[i].z<<'\n';
}


void Curve::renderGL() const
{
    for(size_t i = 0;i < m_numCurvePoints; ++i)
    {
        glPointSize(2.0);
        glBegin(GL_POINTS);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(m_curvePoints[i].x,m_curvePoints[i].y,m_curvePoints[i].z);
        glEnd();
    }
}

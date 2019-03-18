///
/// @file Surface.cpp
/// @brief functions for generating surfaces

#include "Surface.h"


size_t Surface::getSurfaceRow() const
{
    return m_row;
}

size_t Surface::getSurfaceColumn() const
{
    return m_column;
}

std::vector<Vec3> Surface::getSurfaceControlPoints() const
{
    return m_surfaceControlPoints;
}

void Surface::generateSurface(const size_t _numCurvePoints)
{
    //allocate the control points according to the row and column values
    size_t r;
    size_t c;
    size_t i;

    std::vector<Vec3> controlPoints;

    for ( r = 0; r < m_row ; ++r)
    {
        for ( c = 0; c < m_column ; ++c)
        {
            controlPoints.push_back( Vec3(m_surfaceControlPoints[r * m_column + c].x, m_surfaceControlPoints[r * m_column + c].y, m_surfaceControlPoints[r * m_column + c].z) );
        }

        m_curves.push_back( Curve( controlPoints, _numCurvePoints) );

        for ( i = m_column; i > 0 ; --i )
        {
            controlPoints.pop_back();
        }
    }


    for ( c = 0; c < m_column ; ++c)
    {
        for ( r = 0; r < m_row ; ++r)
        {
            controlPoints.push_back( Vec3(m_surfaceControlPoints[c * m_row + r].x, m_surfaceControlPoints[c * m_row + r].y, m_surfaceControlPoints[c * m_row + r].z) );
        }

        m_curves.push_back( Curve( controlPoints, _numCurvePoints) );

        for ( i = m_column; i > 0 ; --i )
        {
            controlPoints.pop_back();
        }
    }
}

void Surface::renderSurface() const
{
    for( auto &p : m_curves)
    {
        p.renderCurve();
    }
}

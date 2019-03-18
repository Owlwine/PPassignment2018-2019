///
/// @file Surface.cpp
/// @brief functions for generating surfaces

#include "Surface.h"

//------------------------------------------------------------------------------------------------------------------
size_t Surface::getSurfaceRow() const
{
    return m_row;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
size_t Surface::getSurfaceColumn() const
{
    return m_column;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
std::vector<Vec3> Surface::getSurfaceControlPoints() const
{
    return m_surfaceControlPoints;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
void Surface::generateSurface(const size_t _numCurvePoints)
{
    //allocate the control points according to the row and column values
    size_t r = 0;
    size_t c = 0;

    size_t i;

    //a temporary Vec3 type vector which will store the control points for a curve
    std::vector<Vec3> controlPoints;

    //generate curves in column
    for ( c = 0; c < m_column ; ++c )
    {
        for ( r = 0; r < m_row ; ++r )
        {
            controlPoints.push_back( Vec3(m_surfaceControlPoints[ r * m_column + c ].x,
                                     m_surfaceControlPoints[ r * m_column + c ].y, m_surfaceControlPoints[ r * m_column + c ].z) );
        }       

        m_curves.push_back( Curve( controlPoints, _numCurvePoints) );

        //empty the temporary vector, in order to store control points for next curve
        for ( i = m_row; i > 0 ; --i )
        {
            controlPoints.pop_back();
        }
    }

    //generate curves in row
    for ( r = 0; r < m_row ; ++r )
    {
        for ( c = 0; c < m_column ; ++c )
        {
            controlPoints.push_back( Vec3(m_surfaceControlPoints[ r * m_column + c ].x,
                                     m_surfaceControlPoints[ r * m_column + c ].y, m_surfaceControlPoints[ r * m_column + c ].z) );
        }

        m_curves.push_back( Curve( controlPoints, _numCurvePoints) );

        for ( i = m_column; i > 0 ; --i )
        {
            controlPoints.pop_back();
        }
    }
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
std::vector<Curve> Surface::getCurves() const
{
    return m_curves;
}
//------------------------------------------------------------------------------------------------------------------

//render the surface consists of bezier curves
//------------------------------------------------------------------------------------------------------------------
void Surface::renderSurface() const
{
    auto p = getCurves();
    for( size_t i = 0; i< m_curves.size(); ++i)
    {
        p[i].evaluateBezierCurve();
        p[i].renderCurve();
    }
}
//------------------------------------------------------------------------------------------------------------------

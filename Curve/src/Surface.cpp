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
size_t Surface::getSurfacePointsNumber() const
{
    return m_surfacePoints.size();
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
std::vector<Vec3> Surface::getSurfacePoints() const
{
    return m_surfacePoints;
}
//------------------------------------------------------------------------------------------------------------------

void Surface::setSurfacePointsNumber( const size_t _numCurvePoints )
{
    m_surfacePointsNumber = _numCurvePoints * _numCurvePoints;
}

//might need to abandon it
//------------------------------------------------------------------------------------------------------------------
void Surface::storeSurfaceControlPoints(const size_t _numCurvePoints)
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

void Surface::evaluateSurfacePoints( const size_t _numCurvePoints )
{

    float columnBezierBlendingFunction;
    float rowBezierBlendingFunction;
    float surfaceBezierBlendingFunction;
    size_t surfacePointMark;
    size_t controlPointMark;

    std::vector<size_t> cColumn( m_row );
    std::vector<size_t> cRow( m_column );
    std::vector<Vec3> surfacePoints( _numCurvePoints * _numCurvePoints );


    /// The following section is modified from :-
    /// Donald Hearn, M.Pauline Baker, Warren R.Carithers (2014). Computer Graphics with OpenGL, Fourth Edition.
    //attention, might error, or just use curve type?
    m_curves[0].binomialCoeffs( cRow );
    for(size_t q=0;q<m_column;++q)
//        std::cout<<cRow[q]<<' ';
//    std::cout<<'\n';

    m_curves[0].binomialCoeffs( cColumn);
//    for(auto p1 : cColumn)
//        std::cout<<p1<<' ';

    size_t dd=0;

    for( size_t l = 0; l < _numCurvePoints; ++l )
    {
        for( size_t i = 0; i < _numCurvePoints; ++i )
        {
            for( size_t j = 0; j < m_column; ++j )
            {
                for( size_t k = 0; k < m_row; ++k )
                {
                    surfacePointMark = l * _numCurvePoints + i;
                    controlPointMark = j * m_row + k;

                    columnBezierBlendingFunction = cColumn[k] * powf( float(i) / float(_numCurvePoints), float(k) ) *
                                             powf( 1 - ( float(i) / float(_numCurvePoints) ),
                                                   float( ( m_row - 1 ) - k ) );

                    rowBezierBlendingFunction = cRow[j] * powf( float(l) / float(_numCurvePoints), float(j) ) *
                                             powf( 1 - ( float(l) / float(_numCurvePoints) ),
                                                   float( ( m_column - 1 ) - j ) );

                    surfaceBezierBlendingFunction = columnBezierBlendingFunction * rowBezierBlendingFunction;

                    //When evaluating points on a bezier curve, a curve point is equal to \                    //a control point multiply the bezier blending function


                    surfacePoints[ surfacePointMark ].x += m_surfaceControlPoints[ controlPointMark ].x * surfaceBezierBlendingFunction;
                    surfacePoints[ surfacePointMark ].y += m_surfaceControlPoints[ controlPointMark ].y * surfaceBezierBlendingFunction;
                    surfacePoints[ surfacePointMark ].z += m_surfaceControlPoints[ controlPointMark ].z * surfaceBezierBlendingFunction;
                    //std::cout<<"dd "<<dd<<" surfacePointMark "<<surfacePointMark<<" controlPointMark "<<controlPointMark<<'\n';
                    ++dd;
                }
            }
        }
    }

//    for(auto p : m_surfaceControlPoints)
//        std::cout<<p.x<<' '<<p.y<<' '<<p.z<<'\n';
    /// end of Citation

    //Store the calculated points into the member of the curve type object
    for( size_t i = 0;i < _numCurvePoints * _numCurvePoints; ++i )
    {
        m_surfacePoints.push_back( surfacePoints[i] );
    }
}
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
//    auto p = getCurves();
//    for( size_t i = 0; i< m_curves.size(); ++i)
//    {
//        p[i].evaluateBezierCurve();
//        p[i].renderCurve();
//    }
    double_t r = 0.0 ;
    double_t g = 0.0 ;
    double_t b = 0.0 ;

    for( size_t i = 0;i < m_surfacePoints.size(); ++i )
    {
        //set the point size to 2
        glPointSize( 2.0 );

        glBegin( GL_POINTS );

        //set the points colours according to the position, using mod() function and getting \
        //the absolute values
        r = abs( fmod( m_surfacePoints[i].x , 255.0f ) );
        g = abs( fmod( m_surfacePoints[i].y , 255.0f ) );
        b = abs( fmod( m_surfacePoints[i].z , 255.0f ) );

        glColor3f( r, g, b );

        //draw the points on the curve
        glVertex3f( m_surfacePoints[i].x, m_surfacePoints[i].y, m_surfacePoints[i].z );
        glEnd();
    }
}
//------------------------------------------------------------------------------------------------------------------

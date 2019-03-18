///
/// @file Surface.cpp
/// @brief functions for generating surfaces

#include "Surface.h"

//user constructor
//------------------------------------------------------------------------------------------------------------------
Surface::Surface( const size_t _nRow, const size_t _nColumn, const size_t _numCurvePoints,
                  const std::vector<Vec3> &_controlPoints ):
    m_row( _nRow ),
    m_column( _nColumn ),
    m_edgePointsNumber( _numCurvePoints ),
    m_surfaceControlPoints( _controlPoints )
{
    m_surfacePointsNumber = _numCurvePoints * _numCurvePoints;
}
//------------------------------------------------------------------------------------------------------------------


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
size_t Surface::getEdgePointsNumber() const
{
    return m_edgePointsNumber;
}
//------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------
size_t Surface::getSurfacePointsNumber() const
{
    return m_surfacePointsNumber;
}
//------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------
std::vector<Vec3> Surface::getSurfaceControlPoints() const
{
    return m_surfaceControlPoints;
}
//------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------
std::vector<Vec3>   Surface::getSurfacePoints() const
{
    return m_surfacePoints;
}
//------------------------------------------------------------------------------------------------------------------


//The bezier blending function is Bernstein polynomial. The expression is \
//C( n , k ) * u^k * ( 1 - u )^( n - k ), 0 <= u <= 1. C( n , k ) is binomial coefficient , \
//while n euqals to control points' amount minus 1.
//To evaluate the points on the surface, we use tensor product in direction row and column.
//The amount of surface points depend on the curve points. In another word, it depends on the \
//points's amount on the edge.
//------------------------------------------------------------------------------------------------------------------
void Surface::evaluateSurfacePoints()
{

    float columnBezierBlendingFunction;
    float rowBezierBlendingFunction;
    float surfaceBezierBlendingFunction;
    size_t surfacePointMark;
    size_t controlPointMark;

    std::vector<size_t> cColumn( m_row );
    std::vector<size_t> cRow( m_column );
    std::vector<Vec3> surfacePoints( m_surfacePointsNumber );


    /// The following section is modified from :-
    /// Donald Hearn, M.Pauline Baker, Warren R.Carithers (2014). Computer Graphics with OpenGL, Fourth Edition.

    //calculate the binomial coefficients in direction row and column
    m_curves[0].binomialCoeffs( cRow );
    m_curves[0].binomialCoeffs( cColumn);

    for( size_t l = 0; l < m_edgePointsNumber; ++l )
    {
        for( size_t i = 0; i < m_edgePointsNumber; ++i )
        {
            for( size_t j = 0; j < m_column; ++j )
            {
                for( size_t k = 0; k < m_row; ++k )
                {
                    surfacePointMark = l * m_edgePointsNumber + i;
                    controlPointMark = j * m_row + k;

                    columnBezierBlendingFunction = cColumn[k] * powf( float(i) / float(m_edgePointsNumber), float(k) ) *
                                             powf( 1 - ( float(i) / float(m_edgePointsNumber) ),
                                                   float( ( m_row - 1 ) - k ) );

                    rowBezierBlendingFunction = cRow[j] * powf( float(l) / float(m_edgePointsNumber), float(j) ) *
                                             powf( 1 - ( float(l) / float(m_edgePointsNumber) ),
                                                   float( ( m_column - 1 ) - j ) );

                    surfaceBezierBlendingFunction = columnBezierBlendingFunction * rowBezierBlendingFunction;

                    //When evaluating points on a bezier curve, a curve point is equal to
                    //a control point multiply the bezier blending function
                    //The process of generating points on the surface is similar
                    surfacePoints[ surfacePointMark ].x += m_surfaceControlPoints[ controlPointMark ].x * surfaceBezierBlendingFunction;
                    surfacePoints[ surfacePointMark ].y += m_surfaceControlPoints[ controlPointMark ].y * surfaceBezierBlendingFunction;
                    surfacePoints[ surfacePointMark ].z += m_surfaceControlPoints[ controlPointMark ].z * surfaceBezierBlendingFunction;
                }
            }
        }
    }
    /// end of Citation

    //Store the calculated points into the member m_surfacePoints
    for( size_t i = 0;i < m_surfacePointsNumber ; ++i )
    {
        m_surfacePoints.push_back( surfacePoints[i] );
    }
}
//------------------------------------------------------------------------------------------------------------------


//render the surface points
//------------------------------------------------------------------------------------------------------------------
void Surface::renderSurface() const
{
    //in order to view more colours, the colour is generated based on points' positions
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

///
/// @file Curve.cpp
/// @brief functions for generating curves

#include "Curve.h"
#include "Surface.h"

//------------------------------------------------------------------------------------------------------------------
Curve::Curve(const std::vector<Vec3> &_controlPoints , const size_t _numCurvePoints)
{
    //empty default control points vector
    while ( m_numControlPoints > 0 )
    {
        m_controlPoints.pop_back();
        --m_numControlPoints;
    }

    m_numControlPoints = _controlPoints.size();
    m_numCurvePoints = _numCurvePoints;


    for( size_t i=0; i < m_numControlPoints; ++i )
    {
        m_controlPoints.push_back( _controlPoints[i] );
    }
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
size_t Curve::getControlPointsNumber() const
{
    return m_numControlPoints;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
size_t Curve::getCurvePointsNumber() const
{
    return m_numCurvePoints;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
std::vector<Vec3> Curve::getControlPoints() const
{
    return m_controlPoints;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
void Curve::showControlPoints() const
{
    for( size_t i = 0; i < m_numControlPoints; ++i )
    {
        std::cout<< m_controlPoints[i].x <<' '<< m_controlPoints[i].y <<' '<< m_controlPoints[i].z <<'\n';
    }
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
/// The following function is modified from :-
/// Donald Hearn, M.Pauline Baker, Warren R.Carithers (2014). Computer Graphics with OpenGL, Fourth Edition.
// Compute n! / ( k! * ( n - k )! )
void Curve::binomialCoeffs( std::vector<size_t> &io_c )
{
    size_t i;

    //When computing binomial coefficient in a bezier curve, n = (control points amount - 1)
    size_t n = io_c.size() -1;

    for ( size_t k = 0; k <= n ; ++k )
    {
        io_c[k] = 1;

        for ( i = n; i >= k+1; --i )
        {
            io_c[k] *= i;
        }

        for ( i = n-k; i >= 2; --i )
        {
            io_c[k] /= i;
        }
    }
}
/// end of Citation
//------------------------------------------------------------------------------------------------------------------


//Evaluate and generate the points on a bezier curve
//----------------------------------------------------------------------------------------------------------------
void Curve::evaluateBezierCurve( )
{
    //The bezier blending function is Bernstein polynomial. The expression is \
    //C( n , k ) * u^k * ( 1 - u )^( n - k ), 0 <= u <= 1. C( n , k ) is binomial coefficient , \
    //while n euqals to control points' amount minus 1.
    float bezierBlendingFunction;

    std::vector<size_t> C( m_numControlPoints );
    std::vector<Vec3> CurvePoints( m_numCurvePoints );


    /// The following section is modified from :-
    /// Donald Hearn, M.Pauline Baker, Warren R.Carithers (2014). Computer Graphics with OpenGL, Fourth Edition.
    binomialCoeffs(C);

    for( size_t i = 0; i < m_numCurvePoints; ++i )
    {
        for( size_t k = 0; k < m_numControlPoints; ++k )
        {
            bezierBlendingFunction = C[k] * powf( float(i) / float(m_numCurvePoints), float(k) ) *
                                     powf( 1 - ( float(i) / float(m_numCurvePoints) ),
                                           float( ( m_numControlPoints - 1 ) - k ) );

            //When evaluating points on a bezier curve, a curve point is equal to \
            //a control point multiply the bezier blending function
            CurvePoints[i].x += m_controlPoints[k].x * bezierBlendingFunction;
            CurvePoints[i].y += m_controlPoints[k].y * bezierBlendingFunction;
            CurvePoints[i].z += m_controlPoints[k].z * bezierBlendingFunction;
        }
    }
    /// end of Citation

    //Store the calculated points into the member of the curve type object
    for( size_t i = 0;i < m_numCurvePoints; ++i )
    {
        m_curvePoints.push_back( CurvePoints[i] );
    }
}
//------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------
std::vector<Vec3> Curve::getCurvePoints() const
{
    return m_curvePoints;
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
void Curve::showCurvePoints()const
{
    for( size_t i = 0;i < m_numCurvePoints; ++i )
    {
        std::cout<< m_curvePoints[i].x <<' '<< m_curvePoints[i].y <<' '<< m_curvePoints[i].z <<'\n';
    }
}
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
void Curve::renderCurve() const
{
    double_t r = 0.0 ;
    double_t g = 0.0 ;
    double_t b = 0.0 ;

    for( size_t j = 0; j < m_numControlPoints; ++j)
    {
        //set the point size to 4
        glPointSize( 6.0 );

        glBegin( GL_POINTS );

        //set the colour to red
        glColor3f( 1.0, 0.0, 0.0 );

        //draw the control points
        glVertex3f( m_controlPoints[j].x, m_controlPoints[j].y, m_controlPoints[j].z );
        glEnd();
    }


   //draw control point hall
    GLfloat lineVertices[m_numControlPoints * 3];
    size_t m = 0;

    for(size_t l = 0; l< m_numControlPoints * 3 ; l+=3)
    {
        lineVertices[l]   = m_controlPoints[m].x;
        lineVertices[l+1] = m_controlPoints[m].y;
        lineVertices[l+2] = m_controlPoints[m].z;
        ++m;
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0,lineVertices);
    glDrawArrays(GL_LINE_STRIP, 0 ,m_numControlPoints);
    glDisableClientState(GL_VERTEX_ARRAY);




    for( size_t i = 0;i < m_numCurvePoints; ++i )
    {
        //set the point size to 2
        glPointSize( 2.0 );

        glBegin( GL_POINTS );

        //set the points colours according to the position, using mod() function and getting \
        //the absolute values
        r = abs( fmod( m_curvePoints[i].x , 255.0f ) );
        g = abs( fmod( m_curvePoints[i].y , 255.0f ) );
        b = abs( fmod( m_curvePoints[i].z , 255.0f ) );

        glColor3f( r, g, b );

        //draw the points on the curve
        glVertex3f( m_curvePoints[i].x, m_curvePoints[i].y, m_curvePoints[i].z );
        glEnd();


    }
}
//------------------------------------------------------------------------------------------------------------------

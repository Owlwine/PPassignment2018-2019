/// \file Surface.h
/// \brief generate different types of surfaces with \
///        different algrithm (currently only using bezier curve)
/// \author Ming Yan
/// \version 1.0
/// \date 18/3/19 Updated to NCCA/programming-paradigms-201819-Owlwine
/// Revision History :
/// Initial Version 17/3/19
/// \todo produce this file


#ifndef SURFACE_H_
#define SURFACE_H_


#include "Curve.h"

class Surface
{
public:
    Surface()=default;
    Surface( const Surface & ) = default;
    Surface( Surface && ) = default;

    size_t              getSurfaceRow() const;
    size_t              getSurfaceColumn() const;
    std::vector<Vec3>   getSurfaceControlPoints() const;
    void                generateSurface( const size_t _numCurvePoints);
    void                renderSurface() const;


private:
    size_t              m_row = 4;
    size_t              m_column = 3;
    std::vector<Vec3>   m_surfaceControlPoints = { { -10.0f, -10.0f, 5.0f }, { 0.0f, 20.0f, 6.0f }, { 10.0f,10.0f, 0.0f },
                                                 { -10.0f, -10.0f, 0.0f }, { 0.0f, 20.0f, 0.0f }, { 10.0f,10.0f, -5.0f },
                                                 { -10.0f, -10.0f, -5.0f }, { 0.0f, 20.0f, -6.0f }, { 10.0f,10.0f, -10.0f },
                                                 { -10.0f, -10.0f, -10.0f }, { 0.0f, 20.0f, -12.0f }, {10.0f,10.0f, -15.0f } };

    //Store the curves for generate the surface
    std::vector<Curve>  m_curves;
};


#endif

/// \file Surface.h
/// \class Surface
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

    //need to passing the amount of points on generated curve, while generating the surface
    void                generateSurface( const size_t _numCurvePoints);

    std::vector<Curve>  getCurves() const;
    void                renderSurface() const;



private:
    size_t              m_row = 4;
    size_t              m_column = 3;
    std::vector<Vec3>   m_surfaceControlPoints = { { -10.0f, -10.0f,13.0f }, { -5.0f, -9.0f, 10.0f }, { -12.0f,-11.0f, 5.0f },
                                                 { -7.0f, 7.0f, 14.0f }, { -8.0f, 10.0f, 9.0f }, { -10.0f, 13.0f, 4.0f },
                                                 { 7.0f, 10.0f, 15.0f }, { 5.0f, 10.0f, 8.0f }, { 10.0f, 10.0f, 3.0f },
                                                 { 15.0f, -5.0f, 16.0f }, { 7.0f, -7.0f, 7.0f }, { 10.0f, -10.0f, 2.0f } };

    //Store the curves for generate the surface
    std::vector<Curve>  m_curves;
};


#endif  //  SURFACE_H_


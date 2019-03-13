#include "ControlPoint.h"
#include "Curve.h"
#include <iostream>
#include <GL/gl.h>
#include <random>

Vec3 ControlPoint::getPosition() const
{
    return m_position;
}

void ControlPoint::setPosition(const Vec3 &_pos)
{
    m_position=_pos;
}

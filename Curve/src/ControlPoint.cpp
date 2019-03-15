#include "ControlPoint.h"
#include <iostream>
//#include <OpenGL/gl.h>
#include <random>

ControlPoint::ControlPoint(const Vec3 &_pos)
{
    m_position=_pos;
}

Vec3 ControlPoint::getPosition() const
{
    return m_position;
}

void ControlPoint::setPosition(const Vec3 &_pos)
{
    m_position=_pos;
}

void ControlPoint::render() const
{
    std::cout<<m_position.x<<' '<<m_position.y<<' '<<m_position.z<<'\n';
}

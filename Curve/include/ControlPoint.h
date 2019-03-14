#ifndef CONTROLPOINT_H_
#define CONTROLPOINT_H_
#include "Vec3.h"

class ControlPoint
{
public:
    ControlPoint()=default;
    ControlPoint(const ControlPoint &)=default;
    ControlPoint(ControlPoint &&)=default; //move ctor
    ControlPoint(const Vec3 &_pos);
    Vec3 getPosition() const;
    void setPosition(const Vec3 &_pos);
    void render() const;
private:
    Vec3 m_position;
};

#endif

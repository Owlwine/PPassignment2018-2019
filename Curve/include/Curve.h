#ifndef CURVE_H_
#define CURVE_H_
#include <vector>
#include "Vec3.h"
#include "ControlPoint.h"
class Curve
{
public:
    Curve()=default;
    Curve(const Curve &)=delete;
    Curve & operator=(const Curve &)=delete ;
    Curve(size_t _numControlPoints);
    /*
    void setPos(const Vec3 &_pos);
    Vec3 getPos() const;
    size_t getNumControlPoints() const;
    void update();
    void updatePos(float _dx,float _dy, float _dz);
    */
    void render() const;
    //void renderGL() const;
private:
    size_t m_numControlPoints=0;
    Vec3 m_pos;
    std::vector<ControlPoint> m_ControlPoints;
};
#endif

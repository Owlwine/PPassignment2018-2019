#ifndef VEC3_H_
#define VEC3_H_

struct Vec3
{
    Vec3()=default;
    Vec3(const Vec3 &)=default;
    Vec3(float _x, float _y, float _z) :
        x(_x), y(_y), z(_z){}
    void operator +=(const Vec3 &_rhs)
    {
        x+=_rhs.x;
        y+=_rhs.y;
        z+=_rhs.z;
    }

#define FCompare(a,b)\
    ( ((a)-0.0000001f)<(b) && ((a)+0.0000001f)>(b) )

    bool operator == (const Vec3 &_rhs)
    {
        return (x==_rhs.x) && (y==_rhs.y) && (z==_rhs.z);
    }

    float x=0.0f;
    float y=0.0f;
    float z=0.0f;
};

#endif

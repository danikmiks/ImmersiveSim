#ifndef VECTOR3_HPP
#define VECTOR3_HPP

struct Vector3 {
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}
};

#endif 

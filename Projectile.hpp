#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "Vector3.hpp"

struct Projectile {
    Vector3 position;
    Vector3 direction;
    float speed;
    float damage;
    bool active;

    Projectile()
        : position(), direction(0, 0, 1), speed(20.0f), damage(10.0f), active(false) {}
};

#endif 
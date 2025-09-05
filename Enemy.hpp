#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Transform.hpp"

struct Enemy {
    Transform transform;
    float health;
    float damage;
    float moveSpeed;

    Enemy()
        : health(50.0f), damage(10.0f), moveSpeed(2.0f) {}
};

#endif 

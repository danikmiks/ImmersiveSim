#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Transform.hpp"

struct Player {
    Transform transform;
    float health;
    float movementSpeed;    
    float lookSensitivity;

    Player()
        : health(100.0f), movementSpeed(5.0f), lookSensitivity(1.0f) {}
};

#endif 
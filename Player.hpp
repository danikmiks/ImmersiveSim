#pragma once
#include <iostream>
#include "Transform.hpp"

class Player {
private:
    Transform transform;
    float health;
    float movementSpeed;
    float lookSensitivity;

public:
    Player();
    Player(const Transform& t, float h, float ms, float ls);
    Player(const Player& other);

    Player& operator=(const Player& other);

    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Player& p);
    friend std::istream& operator>>(std::istream& in, Player& p);
};

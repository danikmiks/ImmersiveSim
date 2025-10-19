#pragma once
#include <iostream>

class Enemy {
private:
    float health;
    float damage;
    float moveSpeed;

public:
    Enemy();
    Enemy(float h, float d, float s);
    Enemy(const Enemy& other);

    Enemy& operator=(const Enemy& other);

    bool operator==(const Enemy& other) const;
    bool operator!=(const Enemy& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Enemy& e);
    friend std::istream& operator>>(std::istream& in, Enemy& e);
};

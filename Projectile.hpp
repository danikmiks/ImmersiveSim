#pragma once
#include <iostream>
#include "Vector3.hpp"

class Projectile {
private:
    Vector3 position;
    Vector3 direction;
    float speed;
    float damage;
    bool active;

public:
    Projectile();
    Projectile(const Vector3& pos, const Vector3& dir, float spd, float dmg, bool act);
    Projectile(const Projectile& other);

    Projectile& operator=(const Projectile& other);

    bool operator==(const Projectile& other) const;
    bool operator!=(const Projectile& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Projectile& p);
    friend std::istream& operator>>(std::istream& in, Projectile& p);
};

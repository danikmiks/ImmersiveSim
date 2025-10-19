#include "Projectile.hpp"

Projectile::Projectile()
    : position(), direction(0.0f, 0.0f, 1.0f),
      speed(20.0f), damage(10.0f), active(false) {}

Projectile::Projectile(const Vector3& pos, const Vector3& dir, float spd, float dmg, bool act)
    : position(pos), direction(dir), speed(spd), damage(dmg), active(act) {}

Projectile::Projectile(const Projectile& other)
    : position(other.position), direction(other.direction),
      speed(other.speed), damage(other.damage), active(other.active) {}

Projectile& Projectile::operator=(const Projectile& other) {
    if (this != &other) {
        position = other.position;
        direction = other.direction;
        speed = other.speed;
        damage = other.damage;
        active = other.active;
    }
    return *this;
}

bool Projectile::operator==(const Projectile& other) const {
    return position == other.position &&
           direction == other.direction &&
           speed == other.speed &&
           damage == other.damage &&
           active == other.active;
}

bool Projectile::operator!=(const Projectile& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Projectile& p) {
    out << "Projectile(Position: [" << p.position.x << ", " << p.position.y << ", " << p.position.z
        << "], Direction: [" << p.direction.x << ", " << p.direction.y << ", " << p.direction.z
        << "], Speed: " << p.speed << ", Damage: " << p.damage
        << ", Active: " << (p.active ? "true" : "false") << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Projectile& p) {
    in >> p.position.x >> p.position.y >> p.position.z
       >> p.direction.x >> p.direction.y >> p.direction.z
       >> p.speed >> p.damage >> p.active;
    return in;
}

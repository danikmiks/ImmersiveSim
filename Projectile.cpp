#include "Projectile.hpp"

Projectile::Projectile()
    : position(), direction(0.0f, 0.0f, 1.0f),
    speed(20.0f), damage(10.0f), active(false) {
}

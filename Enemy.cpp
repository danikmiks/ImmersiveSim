#include "Enemy.hpp"

Enemy::Enemy()
    : health(50.0f), damage(10.0f), moveSpeed(2.0f) {
}

Enemy::Enemy(float h, float d, float s)
    : health(h), damage(d), moveSpeed(s) {
}

Enemy::Enemy(const Enemy& other)
    : health(other.health), damage(other.damage), moveSpeed(other.moveSpeed) {
}

Enemy& Enemy::operator=(const Enemy& other) {
    if (this != &other) {
        health = other.health;
        damage = other.damage;
        moveSpeed = other.moveSpeed;
    }
    return *this;
}

bool Enemy::operator==(const Enemy& other) const {
    return health == other.health &&
        damage == other.damage &&
        moveSpeed == other.moveSpeed;
}

bool Enemy::operator!=(const Enemy& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Enemy& e) {
    out << "Enemy(Health: " << e.health
        << ", Damage: " << e.damage
        << ", Speed: " << e.moveSpeed << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Enemy& e) {
    in >> e.health >> e.damage >> e.moveSpeed;
    return in;
}

void Enemy::SaveToDB(Database& db) const {
    db.execute(
        "INSERT INTO Enemy (health, damage, speed) VALUES (?, ?, ?);",
        health, damage, moveSpeed
    );
}

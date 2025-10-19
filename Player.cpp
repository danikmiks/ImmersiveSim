#include "Player.hpp"

Player::Player()
    : transform(), health(100.0f), movementSpeed(5.0f), lookSensitivity(1.0f) {
}

Player::Player(const Transform& t, float h, float ms, float ls)
    : transform(t), health(h), movementSpeed(ms), lookSensitivity(ls) {
}

Player::Player(const Player& other)
    : transform(other.transform), health(other.health),
    movementSpeed(other.movementSpeed), lookSensitivity(other.lookSensitivity) {
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        transform = other.transform;
        health = other.health;
        movementSpeed = other.movementSpeed;
        lookSensitivity = other.lookSensitivity;
    }
    return *this;
}

bool Player::operator==(const Player& other) const {
    return transform == other.transform &&
        health == other.health &&
        movementSpeed == other.movementSpeed &&
        lookSensitivity == other.lookSensitivity;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Player& p) {
    out << "Player(" << p.transform
        << ", Health: " << p.health
        << ", MoveSpeed: " << p.movementSpeed
        << ", Sensitivity: " << p.lookSensitivity << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Player& p) {
    in >> p.transform >> p.health >> p.movementSpeed >> p.lookSensitivity;
    return in;
}
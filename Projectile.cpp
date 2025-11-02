#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Vector3.hpp"  
class Projectile {
private:
    Vector3 position;
    Vector3 direction;
    float speed;
    float damage;
    bool active;
    std::vector<std::string> effects; 

public:
   
    Projectile()
        : position(), direction(0.0f, 0.0f, 1.0f),
        speed(20.0f), damage(10.0f), active(false), effects({ "default" }) {
    }

    Projectile(const Vector3& pos, const Vector3& dir, float spd, float dmg, bool act)
        : position(pos), direction(dir), speed(spd), damage(dmg), active(act) {
    }

    Projectile(const Projectile& other) = default;
    Projectile& operator=(const Projectile& other) = default;

    bool operator==(const Projectile& other) const {
        return position == other.position &&
            direction == other.direction &&
            speed == other.speed &&
            damage == other.damage &&
            active == other.active &&
            effects == other.effects;
    }

    bool operator!=(const Projectile& other) const { return !(*this == other); }

   
    void AddEffect(const std::string& e) {
        effects.push_back(e);
    }

    void SortEffects() {
        std::sort(effects.begin(), effects.end());
    }

    void DisplayEffects() const {
        std::cout << "Effects: ";
        std::for_each(effects.begin(), effects.end(),
            [](const std::string& e) { std::cout << e << " "; });
        std::cout << "\n";
    }

    
    friend std::ostream& operator<<(std::ostream& out, const Projectile& p) {
        out << "Projectile(Position: [" << p.position.x << ", " << p.position.y << ", " << p.position.z
            << "], Direction: [" << p.direction.x << ", " << p.direction.y << ", " << p.direction.z
            << "], Speed: " << p.speed
            << ", Damage: " << p.damage
            << ", Active: " << (p.active ? "true" : "false")
            << ", Effects: [";

        std::for_each(p.effects.begin(), p.effects.end(),
            [&](const std::string& e) { out << e << " "; });
        out << "])";
        return out;
    }

    
    friend std::istream& operator>>(std::istream& in, Projectile& p) {
        std::cout << "Enter position (x y z): ";
        in >> p.position.x >> p.position.y >> p.position.z;
        std::cout << "Enter direction (x y z): ";
        in >> p.direction.x >> p.direction.y >> p.direction.z;
        std::cout << "Enter speed, damage, active (0/1): ";
        in >> p.speed >> p.damage >> p.active;
        return in;
    }
};

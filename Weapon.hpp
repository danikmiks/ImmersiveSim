#pragma once
#include <iostream>
#include <string>
#include "Database.hpp"

class Weapon {
private:
    std::string name;
    int ammo;
    int maxAmmo;
    float fireRate;
    float damage;

public:
    Weapon();
    Weapon(const std::string& n, int a, int m, float f, float d);
    Weapon(const Weapon& other);

    Weapon& operator=(const Weapon& other);

    bool operator==(const Weapon& other) const;
    bool operator!=(const Weapon& other) const;

    void SaveToDB(Database& db) const;

    friend std::ostream& operator<<(std::ostream& out, const Weapon& w);
    friend std::istream& operator>>(std::istream& in, Weapon& w);
};

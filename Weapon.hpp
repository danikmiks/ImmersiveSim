#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

struct Weapon {
    std::string name;
    int ammo;
    int maxAmmo;
    float fireRate;      
    float damage;

    Weapon()
        : name("Pistol"), ammo(12), maxAmmo(12), fireRate(2.0f), damage(10.0f) {}
};

#endif 

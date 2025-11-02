#include "Weapon.hpp"

Weapon::Weapon()
    : name("Pistol"), ammo(12), maxAmmo(12), fireRate(2.0f), damage(10.0f) {
}

Weapon::Weapon(const std::string& n, int a, int m, float f, float d)
    : name(n), ammo(a), maxAmmo(m), fireRate(f), damage(d) {
}

Weapon::Weapon(const Weapon& other)
    : name(other.name), ammo(other.ammo), maxAmmo(other.maxAmmo),
    fireRate(other.fireRate), damage(other.damage) {
}

Weapon& Weapon::operator=(const Weapon& other) {
    if (this != &other) {
        name = other.name;
        ammo = other.ammo;
        maxAmmo = other.maxAmmo;
        fireRate = other.fireRate;
        damage = other.damage;
    }
    return *this;
}

bool Weapon::operator==(const Weapon& other) const {
    return name == other.name &&
        ammo == other.ammo &&
        maxAmmo == other.maxAmmo &&
        fireRate == other.fireRate &&
        damage == other.damage;
}

bool Weapon::operator!=(const Weapon& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Weapon& w) {
    out << "Weapon(Name: " << w.name
        << ", Ammo: " << w.ammo << "/" << w.maxAmmo
        << ", FireRate: " << w.fireRate
        << ", Damage: " << w.damage << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Weapon& w) {
    in >> w.name >> w.ammo >> w.maxAmmo >> w.fireRate >> w.damage;
    return in;
}


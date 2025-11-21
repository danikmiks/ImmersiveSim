#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "Transform.hpp"
#include "Database.hpp"

class Player {
private:
    Transform transform;
    std::string name;
    float health;
    float movementSpeed;
    float lookSensitivity;
    std::vector<std::string> inventory;

public:
    Player()
        : transform(), name("Unknown"), health(100.0f), movementSpeed(5.0f), lookSensitivity(1.0f) {
    }

    Player(const Transform& t, const std::string& n, float h, float ms, float ls)
        : transform(t), name(n), health(h), movementSpeed(ms), lookSensitivity(ls) {
    }

    Player(const Player& other) = default;
    Player& operator=(const Player& other) = default;

    bool operator==(const Player& other) const {
        return transform == other.transform &&
            name == other.name &&
            health == other.health &&
            movementSpeed == other.movementSpeed &&
            lookSensitivity == other.lookSensitivity &&
            inventory == other.inventory;
    }

    bool operator!=(const Player& other) const { return !(*this == other); }

    const std::string& GetName() const { return name; }
    void SetName(const std::string& newName) { name = newName; }

    void AddItem(const std::string& item) { inventory.push_back(item); }

    void SortInventory() {
        std::sort(inventory.begin(), inventory.end());
    }

    void DisplayInventory() const {
        std::cout << "Inventory of " << name << ": ";
        for (const auto& item : inventory)
            std::cout << item << " ";
        std::cout << '\n';
    }

    void SaveToDB(Database& db) const;

    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        out << "Player(" << p.name
            << ", Health: " << p.health
            << ", MoveSpeed: " << p.movementSpeed
            << ", Sensitivity: " << p.lookSensitivity
            << ", Items: [";
        for (const auto& item : p.inventory)
            out << item << " ";
        out << "])";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Player& p) {
        in >> p.name;
        in >> p.health >> p.movementSpeed >> p.lookSensitivity;
        return in;
    }
};

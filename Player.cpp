#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>   
#include "Transform.hpp"

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

  
    friend std::ostream& operator<<(std::ostream& out, const Player& p) {
        out << "Player(" << p.name
            << ", Health: " << p.health
            << ", MoveSpeed: " << p.movementSpeed
            << ", Sensitivity: " << p.lookSensitivity
            << ", Items: [";
        std::for_each(p.inventory.begin(), p.inventory.end(),
            [&](const std::string& item) { out << item << " "; });
        out << "])";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Player& p) {
        std::cout << "Enter name: ";
        in >> p.name;
        std::cout << "Enter health, move speed, sensitivity: ";
        in >> p.health >> p.movementSpeed >> p.lookSensitivity;
        return in;
    }
};

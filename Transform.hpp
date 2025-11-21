#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <memory>
#include <string>
#include "Vector3.hpp"
#include "Database.hpp"

class Transform {
private:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    std::array<std::string, 3> tags;

public:
    Transform()
        : position(), rotation(), scale(1.0f, 1.0f, 1.0f), tags({ "default", "active", "none" }) {
    }

    Transform(const Vector3& pos, const Vector3& rot, const Vector3& scl)
        : position(pos), rotation(rot), scale(scl), tags({ "custom", "active", "none" }) {
    }

    Transform(const Transform& other) = default;
    Transform& operator=(const Transform& other) = default;

    bool operator==(const Transform& other) const {
        return position == other.position &&
            rotation == other.rotation &&
            scale == other.scale &&
            tags == other.tags;
    }

    bool operator!=(const Transform& other) const {
        return !(*this == other);
    }

    void SortTags();
    void DisplayTags() const;

    void SaveToDB(Database& db) const;

    friend std::ostream& operator<<(std::ostream& out, const Transform& t);
    friend std::istream& operator>>(std::istream& in, Transform& t);
};

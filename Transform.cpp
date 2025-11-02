#pragma once
#include <iostream>
#include <array>
#include <algorithm>
#include <memory>
#include <string>
#include "Vector3.hpp"

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

    void SortTags() {
        std::sort(tags.begin(), tags.end());
    }

    void DisplayTags() const {
        std::for_each(tags.begin(), tags.end(), [](const std::string& tag) {
            std::cout << tag << " ";
            });
        std::cout << '\n';
    }

    friend std::ostream& operator<<(std::ostream& out, const Transform& t) {
        out << "Transform(Position: [" << t.position.x << ", " << t.position.y << ", " << t.position.z
            << "], Rotation: [" << t.rotation.x << ", " << t.rotation.y << ", " << t.rotation.z
            << "], Scale: [" << t.scale.x << ", " << t.scale.y << ", " << t.scale.z << "], Tags: [";
        std::for_each(t.tags.begin(), t.tags.end(), [&](const std::string& tag) {
            out << tag << " ";
            });
        out << "])";
        return out;
    }

    friend std::istream& operator>>(std::istream& in, Transform& t) {
        std::cout << "Enter position (x y z): ";
        in >> t.position.x >> t.position.y >> t.position.z;
        std::cout << "Enter rotation (x y z): ";
        in >> t.rotation.x >> t.rotation.y >> t.rotation.z;
        std::cout << "Enter scale (x y z): ";
        in >> t.scale.x >> t.scale.y >> t.scale.z;
        return in;
    }
};

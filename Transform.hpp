#pragma once
#include <iostream>
#include "Vector3.hpp"

class Transform {
private:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

public:
    Transform();
    Transform(const Vector3& pos, const Vector3& rot, const Vector3& scl);
    Transform(const Transform& other);

    Transform& operator=(const Transform& other);

    bool operator==(const Transform& other) const;
    bool operator!=(const Transform& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Transform& t);
    friend std::istream& operator>>(std::istream& in, Transform& t);
};

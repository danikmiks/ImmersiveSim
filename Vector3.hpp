#pragma once
#include <iostream>
#include "Database.hpp"

class Vector3 {
public:
    float x, y, z;

    Vector3();
    Vector3(float xx, float yy, float zz);
    Vector3(const Vector3& other);

    Vector3& operator=(const Vector3& other);

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    void SaveToDB(Database& db) const;

    friend std::ostream& operator<<(std::ostream& out, const Vector3& v);
    friend std::istream& operator>>(std::istream& in, Vector3& v);
};

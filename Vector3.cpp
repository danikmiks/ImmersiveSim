#include "Vector3.hpp"

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(float xx, float yy, float zz)
    : x(xx), y(yy), z(zz) {}

Vector3::Vector3(const Vector3& other)
    : x(other.x), y(other.y), z(other.z) {}

Vector3& Vector3::operator=(const Vector3& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }
    return *this;
}

bool Vector3::operator==(const Vector3& other) const {
    return x == other.x && y == other.y && z == other.z;
}

bool Vector3::operator!=(const Vector3& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Vector3& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

std::istream& operator>>(std::istream& in, Vector3& v) {
    in >> v.x >> v.y >> v.z;
    return in;
}

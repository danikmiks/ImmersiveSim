#include "Transform.hpp"

Transform::Transform()
    : position(), rotation(), scale(1.0f, 1.0f, 1.0f) {}

Transform::Transform(const Vector3& pos, const Vector3& rot, const Vector3& scl)
    : position(pos), rotation(rot), scale(scl) {}

Transform::Transform(const Transform& other)
    : position(other.position), rotation(other.rotation), scale(other.scale) {}

Transform& Transform::operator=(const Transform& other) {
    if (this != &other) {
        position = other.position;
        rotation = other.rotation;
        scale = other.scale;
    }
    return *this;
}

bool Transform::operator==(const Transform& other) const {
    return position == other.position &&
           rotation == other.rotation &&
           scale == other.scale;
}

bool Transform::operator!=(const Transform& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Transform& t) {
    out << "Transform(Position: [" << t.position.x << ", " << t.position.y << ", " << t.position.z
        << "], Rotation: [" << t.rotation.x << ", " << t.rotation.y << ", " << t.rotation.z
        << "], Scale: [" << t.scale.x << ", " << t.scale.y << ", " << t.scale.z << "])";
    return out;
}

std::istream& operator>>(std::istream& in, Transform& t) {
    in >> t.position.x >> t.position.y >> t.position.z
       >> t.rotation.x >> t.rotation.y >> t.rotation.z
       >> t.scale.x >> t.scale.y >> t.scale.z;
    return in;
}

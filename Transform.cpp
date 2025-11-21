#include "Transform.hpp"

void Transform::SortTags() {
    std::sort(tags.begin(), tags.end());
}

void Transform::DisplayTags() const {
    std::for_each(tags.begin(), tags.end(), [](const std::string& tag) {
        std::cout << tag << " ";
        });
    std::cout << '\n';
}

std::ostream& operator<<(std::ostream& out, const Transform& t) {
    out << "Transform(Position: [" << t.position.x << ", " << t.position.y << ", " << t.position.z
        << "], Rotation: [" << t.rotation.x << ", " << t.rotation.y << ", " << t.rotation.z
        << "], Scale: [" << t.scale.x << ", " << t.scale.y << ", " << t.scale.z << "], Tags: [";
    std::for_each(t.tags.begin(), t.tags.end(), [&](const std::string& tag) {
        out << tag << " ";
        });
    out << "])";
    return out;
}

std::istream& operator>>(std::istream& in, Transform& t) {
    in >> t.position.x >> t.position.y >> t.position.z;
    in >> t.rotation.x >> t.rotation.y >> t.rotation.z;
    in >> t.scale.x >> t.scale.y >> t.scale.z;
    return in;
}

void Transform::SaveToDB(Database& db) const {
    db.execute(
        "INSERT INTO Transform (posX, posY, posZ, rotX, rotY, rotZ, scaleX, scaleY, scaleZ, tag1, tag2, tag3) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);",
        position.x, position.y, position.z,
        rotation.x, rotation.y, rotation.z,
        scale.x, scale.y, scale.z,
        tags[0], tags[1], tags[2]
    );
}

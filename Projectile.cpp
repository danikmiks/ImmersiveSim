#include "Projectile.hpp"

void Projectile::SaveToDB(Database& db) const {
    std::string combinedEffects;
    for (const auto& e : effects) {
        combinedEffects += e + ",";
    }

    db.execute(
        "INSERT INTO Projectile (posX, posY, posZ, dirX, dirY, dirZ, speed, damage, active, effects) "
        "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?);",
        position.x, position.y, position.z,
        direction.x, direction.y, direction.z,
        speed, damage, active ? 1 : 0,
        combinedEffects
    );
}

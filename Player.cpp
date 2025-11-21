#include "Player.hpp"

void Player::SaveToDB(Database& db) const {
    std::string inv;
    for (const auto& item : inventory)
        inv += item + ",";

    db.execute(
        "INSERT INTO Player (name, health, moveSpeed, lookSensitivity, inventory) "
        "VALUES (?, ?, ?, ?, ?);",
        name, health, movementSpeed, lookSensitivity, inv
    );
}

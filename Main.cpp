#include "GameEngine.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Projectile.hpp"
#include "Weapon.hpp"
#include "Transform.hpp"
#include "Vector3.hpp"
#include "Database.hpp"

int main() {
    Database db("game.db");

    db.execute("CREATE TABLE IF NOT EXISTS GameEngine (time REAL);");

    db.execute("CREATE TABLE IF NOT EXISTS Player ("
        "name TEXT, health REAL, moveSpeed REAL, "
        "lookSensitivity REAL, inventory TEXT);");

    db.execute("CREATE TABLE IF NOT EXISTS Enemy ("
        "health REAL, damage REAL, speed REAL);");

    db.execute("CREATE TABLE IF NOT EXISTS Projectile ("
        "posX REAL, posY REAL, posZ REAL,"
        "dirX REAL, dirY REAL, dirZ REAL,"
        "speed REAL, damage REAL, active INTEGER, "
        "effects TEXT);");

    db.execute("CREATE TABLE IF NOT EXISTS Weapon ("
        "name TEXT, ammo INTEGER, maxAmmo INTEGER, "
        "fireRate REAL, damage REAL);");

    db.execute("CREATE TABLE IF NOT EXISTS Transform ("
        "posX REAL, posY REAL, posZ REAL,"
        "rotX REAL, rotY REAL, rotZ REAL,"
        "scaleX REAL, scaleY REAL, scaleZ REAL,"
        "tag1 TEXT, tag2 TEXT, tag3 TEXT);");

    db.execute("CREATE TABLE IF NOT EXISTS Vector3 (x REAL, y REAL, z REAL);");

    GameEngine engine;
    engine.Init();
    engine.Update(0.1f);
    engine.SaveToDB(db);

    Player player(Transform(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(1, 1, 1)),
        "Hero", 100.0f, 5.0f, 1.2f);
    player.AddItem("Sword");
    player.AddItem("Shield");
    player.SortInventory();
    player.SaveToDB(db);

    Enemy enemy(50.0f, 15.0f, 3.0f);
    enemy.SaveToDB(db);

    Projectile proj(Vector3(1, 2, 3), Vector3(0, 1, 0), 20.0f, 12.0f, true);
    proj.AddEffect("fire");
    proj.AddEffect("burn");
    proj.SaveToDB(db);

    Weapon weapon("Rifle", 30, 30, 6.0f, 25.0f);
    weapon.SaveToDB(db);

    Transform tr(Vector3(3, 4, 5), Vector3(10, 0, 0), Vector3(1, 2, 1));
    tr.SaveToDB(db);

    Vector3 pos(5, 6, 7);
    pos.SaveToDB(db);

    return 0;
}

#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine() : m_time(0.0f) {}

GameEngine::GameEngine(float time) : m_time(time) {}

GameEngine::GameEngine(const GameEngine& other) : m_time(other.m_time) {}

GameEngine& GameEngine::operator=(const GameEngine& other) {
    if (this != &other) {
        m_time = other.m_time;
    }
    return *this;
}

bool GameEngine::operator==(const GameEngine& other) const {
    return m_time == other.m_time;
}

bool GameEngine::operator!=(const GameEngine& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const GameEngine& g) {
    out << "GameEngine(Time: " << g.m_time << ")";
    return out;
}

std::istream& operator>>(std::istream& in, GameEngine& g) {
    in >> g.m_time;
    return in;
}

void GameEngine::Init() {
    m_time = 0.0f;
    std::cout << "Game initialized.\n";
}

void GameEngine::Run() {
    std::cout << "Game running...\n";
}

void GameEngine::Update(float dt) {
    m_time += dt;
    std::cout << "Game updated. Time = " << m_time << "\n";
}

void GameEngine::SaveToDB(Database& db) const {
    db.execute(
        "INSERT INTO GameEngine (time) VALUES (?);",
        m_time
    );
}

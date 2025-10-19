#pragma once
#include <iostream>

class GameEngine {
private:
    float m_time;

public:
    GameEngine();
    GameEngine(float time);
    GameEngine(const GameEngine& other);

    GameEngine& operator=(const GameEngine& other);

    bool operator==(const GameEngine& other) const;
    bool operator!=(const GameEngine& other) const;

    friend std::ostream& operator<<(std::ostream& out, const GameEngine& g);
    friend std::istream& operator>>(std::istream& in, GameEngine& g);

    void Init();
    void Run();
    void Update(float dt);
};

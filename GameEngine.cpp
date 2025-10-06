#include "GameEngine.hpp"
#include <iostream>

GameEngine::GameEngine() {
    m_state = GameState::Menu;
    std::cout << "GameEngine initialized.\n";
}

void GameEngine::start() {
    m_state = GameState::Playing;
    std::cout << "Game started.\n";
}

void GameEngine::update(float dt) {
    
}

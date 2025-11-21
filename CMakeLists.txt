cmake_minimum_required(VERSION 3.16)
project(GameEngineProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Activăm warning-uri bune
if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Include folder SRC
include_directories(${CMAKE_SOURCE_DIR}/src)

# SQLite3 (MSYS2/UCRT64)
find_library(SQLITE3_LIB sqlite3 HINTS "C:/msys64/ucrt64/lib")
find_path(SQLITE3_INCLUDE sqlite3.h HINTS "C:/msys64/ucrt64/include")

include_directories(${SQLITE3_INCLUDE})

# Toate sursele pentru biblioteca ta
set(ENGINE_SOURCES
    src/GameEngine.cpp
    src/Database.cpp
    src/Vector3.cpp
    src/Transform.cpp
    src/Player.cpp
    src/Weapon.cpp
    src/Projectile.cpp
    src/Enemy.cpp
)

set(ENGINE_HEADERS
    src/GameEngine.hpp
    src/Database.hpp
    src/Vector3.hpp
    src/Transform.hpp
    src/Player.hpp
    src/Weapon.hpp
    src/Projectile.hpp
    src/Enemy.hpp
)

# Creăm biblioteca — statică sau dinamică (alegere ta)
add_library(GameEngineLib STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

# Linkăm biblioteca cu SQLite3
target_link_libraries(GameEngineLib PRIVATE ${SQLITE3_LIB})

# Creăm executabilul principal
add_executable(GameApp src/Main.cpp)

# Aplicatia folosește biblioteca
target_link_libraries(GameApp PRIVATE GameEngineLib ${SQLITE3_LIB})

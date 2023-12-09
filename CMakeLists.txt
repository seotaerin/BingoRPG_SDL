cmake_minimum_required(VERSION 3.26)
project(BingoRPG)

set(CMAKE_CXX_STANDARD 23)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(BingoRPG
        src/WinMain.cpp
        src/Window.cpp
        src/Player.cpp
        src/Map.cpp
        src/Monster.cpp
        src/Fight.cpp
        src/Text.cpp
        src/Shop.cpp
        src/Keyboard.cpp
        src/Pointer.cpp
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

target_include_directories(BingoRPG PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(BingoRPG PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(BingoRPG PRIVATE ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)


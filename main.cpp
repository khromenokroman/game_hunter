
#include <iostream>

#include "src/game.hpp"

int main() {
    std::unique_ptr<hunter::game::Game> game = nullptr;
    try{
        game = std::make_unique<hunter::game::Game>();
        game->run();
    }catch(std::exception const& ex) {
        std::cout << "Error: " << ex.what() << std::endl;
        return -1;
    }
    return 0;
}

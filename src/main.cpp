#include <iostream>
#include "Controller.h"

int main() {
    HumanPlayer p1{'X'};
    HumanPlayer p2{'O'};
    Renderer renderer;
    Board board;
    Controller controller{p1, p2, renderer, board};

    while(true) {
        controller.PlayGame();
    }
}
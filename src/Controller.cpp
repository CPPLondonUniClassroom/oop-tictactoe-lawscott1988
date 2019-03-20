#include <iostream>
#include <stdlib.h>
#include "Controller.h"


Controller::Controller(IPlayer& p1, IPlayer& p2, IRenderer& r, Board& b)
    :   player1(p1),
        player2(p2),
        renderer(r),
        board(b)
{}

void Controller::PlayGame() {
    renderer.RenderBoard(board.CurrentState());
    std::cout << "Player 1 take their turn..." << "\n";
    BoardPosition bp = player1.TakeTurn(board.FreePositions());
    board.OccupyPosition(bp, player1);

    if(this->CheckGameState(player1) == true) {
        std::cout << "Player 1 Wins!" << "\n";
    }
    if(this->CheckDraw(board) == true) {
        std::cout << "Game is a Draw!";
    }

    renderer.RenderBoard(board.CurrentState());
    std::cout << "Player 2 take their turn..." << "\n";
    bp = player2.TakeTurn(board.FreePositions());
    board.OccupyPosition(bp, player2);

    if(this->CheckGameState(player1) == true) {
        std::cout << "Player 2 Wins!" << "\n";
    }
    if(this->CheckDraw(board) == true) {
        std::cout << "Game is a Draw!" << "\n";
    }
}

bool Controller::CheckGameState(IPlayer& player) const {
    std::vector<char> state = board.CurrentState();

    //FIRST ROW
    if(state[0] == player.Symbol() && state[1] == player.Symbol() && state[2] == player.Symbol()) {
        return true;
    }

    //SECOND ROW
    if(state[3] == player.Symbol() && state[4] == player.Symbol() && state[5] == player.Symbol()) {
        return true;
    }

    //THIRD ROW
    if(state[6] == player.Symbol() && state[7] == player.Symbol() && state[8] == player.Symbol()) {
        return true;
    }

    //FIRST COLUMN
    if(state[0] == player.Symbol() && state[3] == player.Symbol() && state[6] == player.Symbol()) {
        return true;
    }

    //SECOND COLUMN
    if(state[1] == player.Symbol() && state[4] == player.Symbol() && state[7] == player.Symbol()) {
        return true;
    }

    //THIRD COLUMN
    if(state[2] == player.Symbol() && state[5] == player.Symbol() && state[8] == player.Symbol()) {
        return true;
    }

    //DIAGONAL TOP LEFT to BOTTOM RIGHT
    if(state[0] == player.Symbol() && state[4] == player.Symbol() && state[8] == player.Symbol()) {
        return true;
    }

    //DIAGONAL TOP RIGHT to BOTTOM LEFT
    if(state[2] == player.Symbol() && state[4] == player.Symbol() && state[6] == player.Symbol()) {
        return true;
    }

    //NO WIN STATE FOUND
    return false;
}

bool Controller::CheckDraw(Board &board) const {
    std::vector<char> state = board.CurrentState();
    int countState = 0;
    for(char& c : state) {
        if(c == 'X' || c == 'O') {
            countState++;
        }
    }

    if(countState == 9) {
        return true;
    }

    return false;
}
#include <iostream>
#include "Board.h"

Board::Board() {
    //'u' is for unoccupied
    boardState.insert(std::pair(BoardPosition::TOP_LEFT, 'u'));
    boardState.insert(std::pair(BoardPosition::TOP_MIDDLE, 'u'));
    boardState.insert(std::pair(BoardPosition::TOP_RIGHT, 'u'));
    boardState.insert(std::pair(BoardPosition::MIDDLE_LEFT, 'u'));
    boardState.insert(std::pair(BoardPosition::CENTER, 'u'));
    boardState.insert(std::pair(BoardPosition::MIDDLE_RIGHT, 'u'));
    boardState.insert(std::pair(BoardPosition::BOTTOM_LEFT, 'u'));
    boardState.insert(std::pair(BoardPosition::BOTTOM_MIDDLE, 'u'));
    boardState.insert(std::pair(BoardPosition::BOTTOM_RIGHT, 'u'));
}

std::vector<BoardPosition> Board::FreePositions() const {
    std::vector<BoardPosition> freePositions;
    for(const auto& pos : boardState) {
        if(pos.second == 'u') {
            freePositions.push_back(pos.first);
        }
    }
    return freePositions;
}

void Board::OccupyPosition(const BoardPosition& bp, const IPlayer& player) {
    const auto& it = boardState.find(bp);
    if(it->second == 'u') {
        it->second = player.Symbol();
    }
    else {
        std::cout << "Position is occupied and reads: " << it->second << "\n"
            << ". Please choose another Board position." << "\n";
    }
}

std::vector<char> Board::CurrentState() const {
    std::vector<char> state{};
    for(auto& c : boardState) {
        switch(c.second) {
            case 'X':
                state.push_back('X');
                break;
            case 'O':
                state.push_back('O');
                break;
            case 'u':
                state.push_back('0');
                break;
        }
    }
    return state;
}

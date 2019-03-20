#pragma once
#include<map>
#include"BoardPosition.h"
#include"interface/IPlayer.h"

class Board {
    std::map<BoardPosition, char> boardState;
public:
    Board();

    std::vector<BoardPosition> FreePositions() const;
    void OccupyPosition(const BoardPosition& bp, const IPlayer& player);
    std::vector<char> CurrentState() const;

};
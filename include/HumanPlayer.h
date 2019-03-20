#pragma once
#include "interface/IPlayer.h"

class HumanPlayer : public IPlayer {
    char symbol;

    //helper function
    std::string numToPosition(int pos);

public:

    HumanPlayer(const char& sym);

    char Symbol() const override;
    BoardPosition TakeTurn(const std::vector<BoardPosition>& board) override;
};
#include "HumanPlayer.h"
#include "utility.h"
#include "Renderer.h"

HumanPlayer::HumanPlayer(const char& sym)
    :   symbol(sym)
{}

char HumanPlayer::Symbol() const {
    return symbol;
}

BoardPosition HumanPlayer::TakeTurn(const std::vector<BoardPosition>& boardPos) {
    int pos{};
    while(true) {
        std::cout << "Free Positions: " << "\n";
        for (auto p : boardPos) {
            std::cout << BoardPositionToInt(p) << ": " << numToPosition(BoardPositionToInt(p)) << "\n";
        }
        pos = ReadNumber(0, 8);

        //NEED TO REFACTOR THIS LOOP. WORKING INCORRECTLY
        //update: actually have no idea what I mean by the above
        for(auto p : boardPos) {
            if(pos == BoardPositionToInt(p)) {
                return NumberToBoardPosition(pos);
            }
        }
        std::cout << "Position is taken. Please choose another position" << "\n";
    }
}

std::string HumanPlayer::numToPosition(int pos) {
        switch (pos) {
            case 0:
                return "TOP LEFT";
            case 1:
                return "TOP MIDDLE";
            case 2:
                return "TOP RIGHT";
            case 3:
                return "MIDDLE LEFT";
            case 4:
                return "CENTRE";
            case 5:
                return "MIDDLE RIGHT";
            case 6:
                return "BOTTOM LEFT";
            case 7:
                return "BOTTOM MIDDLE";
            case 8:
                return "BOTTOM RIGHT";
        }
}
#pragma once
#include "interface/IPlayer.h"
#include "interface/IRenderer.h"
#include "Board.h"
#include "HumanPlayer.h"
#include "Renderer.h"


class Controller {
    IPlayer& player1;
    IPlayer& player2;
    IRenderer& renderer;
    Board& board;

public:

    Controller(IPlayer& p1, IPlayer& p2, IRenderer& r, Board& b);

    void PlayGame();
    bool CheckGameState(IPlayer& player) const;
    bool CheckDraw(Board& board) const;
};
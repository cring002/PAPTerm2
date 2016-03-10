//
//  Game.hpp
//  papTermTwoCourseWork
//
//  Created by Charles Ringer on 15/02/2016.
//
//

#ifndef Game_hpp
#define Game_hpp
#include <stdio.h>
#include <vector>
using namespace std;

#include "GiraffePiece.hpp"
#include "LionPiece.hpp"
#include "ElephantPiece.hpp"
#include "BlankPiece.hpp"
#include "ChickPiece.hpp"
#include "HenPiece.hpp"
#include "State.hpp"
#include "AIBrain.hpp"


class Game
{
private:
    ofImage* background;
    vector<GamePiecePtr> gameboard;
    GamePiecePtr playerSelectedPiece;
    shared_ptr<ImageBank> imgBank;
    HumanPlayer* player;
    AIPlayer* ai;
    AIBrain brain;
    int pieceWidth;
    int pieceHeight;
    int xOffset;
    int yOffset;
    State* state;
    
    void movePiece(GamePiecePtr selectedPiece, int x, int y);
    void promotePiece(GamePiecePtr piece);
    void handleDroppedPiece(int x,int y);
    bool playersTurn = false;
    
public:
    Game(State& _state, shared_ptr<ImageBank> _imgBank);
    ~Game();
    
    
    void drawGame();
    void handlePlayerClick(int x, int y);
    void checkEnd();
    void takeAITurn();
    
};

#endif /* Game_hpp */

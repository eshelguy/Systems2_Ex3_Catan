#ifndef CATAN_HPP
#define CATAN_HPP

#include <vector>
#include "Board.hpp"
#include "Player.hpp"
//guyes134@gmail.com

class Board;

class Catan {

public:
    Catan(Player& p1, Player& p2, Player& p3);

    void nextTurn();
    void ChooseStartingPlayer();
    void printWinner();

    Board* getBoard();  // Method to get the Board
    std::vector<Player*>& getAllPlayers();  // Method to get all players


private:
    std::vector<Player*> allPlayers;
    int currentPlayerIndex;
    Board* gameBoard;  // Add a Board object as a member of the Catan class
};

#endif // CATAN_HPP

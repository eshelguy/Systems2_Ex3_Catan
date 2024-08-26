//guyes134@gmail.com

#include "Catan.hpp"
#include <iostream>

Catan::Catan(Player& p1, Player& p2, Player& p3) : currentPlayerIndex(0){
    allPlayers.push_back(&p1);
    allPlayers.push_back(&p2);
    allPlayers.push_back(&p3);
    gameBoard = new Board();
}


Board* Catan::getBoard() {
    return gameBoard;
}

void Catan::printWinner() {
    for (Player* player: allPlayers) {
        if (player->getPoints() >= 10){
            std::cout << player->getName() << " is the winner!" << std::endl;
            return;
        }
    }
    std::cout << "No player has won yet." << std::endl;
}

void Catan::ChooseStartingPlayer() {
    currentPlayerIndex = 0;
    allPlayers[currentPlayerIndex]->setIsMyTurn(true);
    std::cout << allPlayers.at(currentPlayerIndex)->getName() << std::endl;
}

void Catan::nextTurn() {
    allPlayers[currentPlayerIndex]->setIsMyTurn(false);
    currentPlayerIndex = (currentPlayerIndex + 1) % allPlayers.size(); //3 in our case
    allPlayers[currentPlayerIndex]->setIsMyTurn(true);
}

std::vector<Player*>& Catan::getAllPlayers() {
    return allPlayers;
}
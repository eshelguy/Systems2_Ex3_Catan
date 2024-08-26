//guyes134@gmail.com

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()
#include <string>
#include "Settlement.hpp"
#include "City.hpp"
#include "Road.hpp"
#include "DevelopmentCard.hpp"
#include "Board.hpp"
#include "Catan.hpp"
#include "Hexagon.hpp"
#include "Port.hpp"

class Settlement;
class Road;
class City;
class Board;
class Port;

class Player {
public:
    Player(std::string name);

    void rollDice(Board& board, Catan& catan);
    void printPlayerDetails() const;
    void addVictoryPoints(int num);
    bool placeRoad(int edgeIndex, Board& board);
    bool placeSettlement(int vertexIndex, Board& board);
    bool upgradeSettlementToCity(int vertexIndex, Board& board);  // Method to upgrade a settlement to a city
    void addResource(ResourceType resource, int amount);
    int takeAllResourcesOfType(ResourceType resource);    // Take all resources of a given type
    int getTotalResourceCount() const;  // Method to get the total number of resource cards
    void discardResources(int count);   // Method to discard a specified number of resources
    void tradeResources(Player& p2, ResourceType offer, int offerNum, ResourceType get, int getNum);
    void incrementKnightCount();  // Increments the Knight count
    int chooseNewRobberLocation() const;
    ResourceType getLargestResource();
    void tradeAtPort(int vertexIndex, ResourceType offerResource, ResourceType desiredResource, Board& board);
    void buyDevelopmentCard(Board& board, Catan& catan);  // Method to buy a development card

    int getPoints() const;
    int getKnightCount() const;  // Getter for the Knight count
    void awardLargestArmy();      // Awards the Largest Army bonus
    bool hasLargestArmy() const;  // Checks if the player has the Largest Army bonus

    std::string getName() const;
    std::vector<Road*>& getRoads();
    std::vector<City*>& getCities();
    std::vector<Settlement*>& getSettlement();
    std::map<ResourceType, int>& getResources();
    std::vector<std::shared_ptr<DevelopmentCard>>& getDevelopmentCards();  // Method to get development cards

    void setIsMyTurn(bool isTurn);  // Set if it's this player's turn
    bool getIsMyTurn() const;        // Check if it's this player's turn

private:
    bool isMyTurn;
    bool largestArmy;
    std::string name;
    int knightCount;  // Tracks the number of Knight cards played
    int victoryPoints;
    std::vector<Road*> roads;
    std::vector<City*> cities;
    std::vector<Settlement*> settlements;
    std::map<ResourceType, int> resources;
    std::vector<std::shared_ptr<DevelopmentCard>> developmentCards;
};

#endif // PLAYER_HPP

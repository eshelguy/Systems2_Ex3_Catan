//guyes134@gmail.com

#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Vertex.hpp"
#include "Hexagon.hpp"
#include "Edge.hpp"
#include "DevelopmentCard.hpp"
#include "Port.hpp"

enum class ResourceType;
class Hexagon;
class Edge;
class DevelopmentCard;

class Board {
public:
    Board();
    ~Board();

    void printBoard();
    static std::string resourceToString(ResourceType resource);
    void distributeResources(int rolledNumber);
    int getLastRoll() const;
    void setLastRoll(int roll);  // Setter for lastRoll
    void moveRobber(int newHexLocation);  // Move the robber to a new hex
    void checkAndAwardLargestArmy(Player& player);


    int getRobberLocation() const;  // Get the current location of the robber
    const std::vector<Vertex>& getVertices() const;  // Returns a constant reference to vertices
    const std::vector<Edge>& getEdges() const;       // Returns a constant reference to edges
    const std::vector<Hexagon>& getHexagons() const; // Returns a constant reference to hexagons
    std::vector<std::shared_ptr<DevelopmentCard>>& getDevelopmentDeck();  // Getter for the deck

private:
    void initializeVertices();
    void initializeEdges();
    void initializeHexagons();
    void initialPorts();
    void initializeDevelopmentDeck();  // Initialize the deck with all cards

    Player* largestArmyHolder;  // Tracks who holds the Largest Army
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<Hexagon> hexagons;
    std::vector<std::shared_ptr<DevelopmentCard>> developmentDeck;  // The deck of development cards
    int robberLocation;  // Index of the hexagon where the robber is located
    int lastRoll;


};

#endif // BOARD_HPP
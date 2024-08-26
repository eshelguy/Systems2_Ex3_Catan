//guyes134@gmail.com

#ifndef ROAD_HPP
#define ROAD_HPP

#include <string>
#include "Player.hpp"

class Player;

class Road {
public:
    // Constructor that initializes a road with start and end hex IDs and the player's name
    Road(int edge, Player& owner);
    ~Road();

    // Getters for the road properties
    int getEdge() const;
    Player& getOwner() const;
    void setEdge(int road);

    // Equality operator to compare two roads (useful for removing roads, etc.)
    bool operator==(const Road &other) const;
    friend std::ostream& operator<<(std::ostream& os, const Road& road);


private:
    int edge;  // Pointer to the first vertex
    Player& owner;    // Pointer to the player who owns this road
};

#endif // ROAD_HPP

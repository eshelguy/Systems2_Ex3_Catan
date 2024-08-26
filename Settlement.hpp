//guyes134@gmail.com

#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

#include "Vertex.hpp"
#include "Player.hpp"

class Player;

class Settlement {
public:
    Settlement(int location, Player& owner);
    ~Settlement();

    bool operator==(const Settlement& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Settlement& settlement);

    // Getters
    int getLocation() const;
    Player& getOwner() const;
    void setLocation(int vertexLocation);

private:
    int location;  // Location of the settlement
    Player& owner;     // Player who owns this settlement
};

#endif // SETTLEMENT_HPP

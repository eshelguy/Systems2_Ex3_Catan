//guyes134@gmail.com

#ifndef CITY_HPP
#define CITY_HPP

#include "Vertex.hpp"
#include "Player.hpp"

class Player;

class City {
public:
    City(int location, Player& owner);

    int getLocation() const;
    Player& getOwner() const;
    friend std::ostream& operator<<(std::ostream& os, const City& city);


private:
    int location;
    Player& owner;
};

#endif // CITY_HPP
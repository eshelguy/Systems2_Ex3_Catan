//guyes134@gmail.com

#include "City.hpp"

City::City(int location, Player& owner)
        : location(location), owner(owner) {}

int City::getLocation() const {
    return location;
}

Player& City::getOwner() const {
    return owner;
}

std::ostream& operator<<(std::ostream& os, const City& city) {
    os << "City at vertex: " << city.getLocation();
    return os;
}

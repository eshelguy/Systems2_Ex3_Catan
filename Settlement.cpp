//guyes134@gmail.com

#include "Settlement.hpp"

Settlement::Settlement(int location, Player& owner)
        : location(location), owner(owner) {}

Settlement::~Settlement() {}

int Settlement::getLocation() const {
    return location;
}

void Settlement::setLocation(int vertexLocation) {
    this->location = vertexLocation;
}

Player& Settlement::getOwner() const {
    return owner;
}

bool Settlement::operator==(const Settlement& other) const {
    return location == other.location && owner.getName() == other.owner.getName();
}

std::ostream& operator<<(std::ostream& os, const Settlement& settlement) {
    os << "Settlement at vertex: " << settlement.getLocation();
    return os;
}



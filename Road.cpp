//guyes134@gmail.com

#include "Road.hpp"

// Constructor implementation
Road::Road(int edge, Player& owner)
        : edge(edge), owner(owner) {
}

Road::~Road() {}

int Road::getEdge() const {
    return edge;
}

// Getter for the owner of the road
Player& Road::getOwner() const {
    return owner;
}

void Road::setEdge(int road){
    edge = road;
}
std::ostream& operator<<(std::ostream& os, const Road& road) {
    os << "Road at Road: " << road.getEdge();
    return os;
}



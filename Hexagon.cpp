//guyes134@gmail.com

#include "Hexagon.hpp"

Hexagon::Hexagon(const ResourceType resourceType, int id, int diceNumber) : resource(resourceType), id(id),
                                diceNumber(diceNumber), robberPresent(0) {}

Hexagon::~Hexagon() {}

// Getter for vertices
std::vector<Vertex*>& Hexagon::getVertices() {
    return vertices;
}

void Hexagon::setVertices(const std::vector<Vertex*>& sixVertices) {
    vertices = sixVertices;
}

int Hexagon::getDiceNumber() const{
    return diceNumber;
}

int Hexagon::getId() const{
    return id;
}


ResourceType Hexagon::getResource() {
    return resource;
}

bool Hexagon::hasRobber() const {
    return robberPresent;
}

void Hexagon::setRobber(bool robber) {
    robberPresent = robber;
}

std::string resourceToString1(ResourceType resource) {
    switch (resource) {
        case ResourceType::Wood:
            return "Wood";
        case ResourceType::Brick:
            return "Brick";
        case ResourceType::Grain:
            return "Grain";
        case ResourceType::Wool:
            return "Wool";
        case ResourceType::Ore:
            return "Ore";
        case ResourceType::Desert:
            return "Desert";
        default:
            return "Unknown";
    }
}


std::ostream& operator<<(std::ostream& os, const Hexagon& hexagon){
    std::string hexagonToString;
    hexagonToString = resourceToString1(hexagon.resource);
    os << hexagonToString << " " << hexagon.diceNumber;
    return os;
}
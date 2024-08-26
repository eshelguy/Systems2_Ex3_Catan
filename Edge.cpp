//guyes134@gmail.com

#include "Edge.hpp"
#include <string>

Edge::Edge(Vertex* v1, Vertex* v2, int id, int symbol) : id(id), symbol(symbol), road(nullptr){
    vertices[0] = v1;
    vertices[1] = v2;
}

int Edge::getId(){
    return id;
}


Vertex* Edge::getV1() const {
    return vertices[0];
}

Vertex* Edge::getV2() const {
    return vertices[1];
}

bool Edge::hasRoad() const{
    return road != nullptr;
}

std::shared_ptr<Road> Edge::getRoad(){
    return road;
}

void Edge::setRoad(std::shared_ptr<Road> newRoad) {
    road = newRoad;  // Assign the smart pointer to the road
}

std::ostream& operator<<(std::ostream& os, const Edge& edge){
    std::string edgeToString;
    if(edge.symbol == 0){
        edgeToString = "/";
    }
    else if(edge.symbol == 2){
        edgeToString = "\\";
    }
    else{
        edgeToString = "|";
    }
    os << edgeToString;
    return os;
}


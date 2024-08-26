//guyes134@gmail.com

#include <memory>
#include "Edge.hpp"
#include "Vertex.hpp"

Vertex::Vertex(int id) : id(id){
    settlement = nullptr;
    city = nullptr;
    port = nullptr;
}

int Vertex::getId() {
    return id;
}

std::vector<Edge*> Vertex::getAdjacentEdges() {
    return adjacent_edges;
}

std::vector<Vertex*> Vertex::getAdjacentVertices() {
    return adjacent_vertices;
}

void Vertex::setAdjacentVertices(const std::vector<Vertex*>& vertices) {
    adjacent_vertices = vertices;
}

void Vertex::setAdjacentEdges(const std::vector<Edge*>& edges){
    adjacent_edges = edges;
}

std::shared_ptr<Settlement> Vertex::getSettlement() const{
    return settlement;
}

std::shared_ptr<City> Vertex::getCity() const{
    return city;
}

void Vertex::setPort(std::shared_ptr<Port> port) {
    this->port = port;
}

bool Vertex::hasPort() const {
    return port != nullptr;
}

std::shared_ptr<Port> Vertex::getPort() const {
    return port;
}

bool Vertex::hasSettlement() const{
    return settlement != nullptr;
}

bool Vertex::hasCity() const{
    return city != nullptr;
}

void Vertex::setSettlement(std::shared_ptr<Settlement> newSettlement) {
    if (city == nullptr) {  // Only allow setting a Settlement if there's no City
        settlement = newSettlement;
    }
}

void Vertex::upgradeToCity(std::shared_ptr<City> newCity) {
    settlement.reset();  // Remove the Settlement when upgrading to a City
    city = newCity;
}



std::ostream& operator<<(std::ostream& os, const Vertex& vertex){
    os << vertex.id;
    return os;
}

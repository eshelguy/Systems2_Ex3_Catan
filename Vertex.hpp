//guyes134@gmail.com

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
#include <memory>
#include "Settlement.hpp"
#include "Edge.hpp"
#include "City.hpp"
#include "Port.hpp"

class Settlement;
class Port;

class Vertex {
public:
    Vertex(int id);

    // Getters
    int getId();
    bool hasCity() const;
    bool hasSettlement() const;
    std::shared_ptr<City> getCity() const;
    std::shared_ptr<Settlement> getSettlement() const;
    std::vector<Edge*> getAdjacentEdges();
    std::vector<Vertex*> getAdjacentVertices();

    // Setters
    void setAdjacentVertices(const std::vector<Vertex*>& vertices);  // Method to set adjacent vertices
    void setAdjacentEdges(const std::vector<Edge*>& edges);  // Method to set adjacent vertices
    void setPort(std::shared_ptr<Port> port);  // Set the port for this vertex

    // Port-related methods
    bool hasPort() const;  // Check if this vertex has a port
    std::shared_ptr<Port> getPort() const;  // Get the port associated with this vertex

    // Methods for upgrading and setting settlements/cities
    void upgradeToCity(std::shared_ptr<City> newCity);
    void setSettlement(std::shared_ptr<Settlement> newSettlement);

    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex);

private:
    int id;
    std::shared_ptr<Settlement> settlement;  // Smart pointer to manage the Settlement
    std::shared_ptr<City> city;              // Smart pointer to manage the City
    std::vector<Edge*> adjacent_edges;
    std::vector<Vertex*> adjacent_vertices;
    std::shared_ptr<Port> port;              // Smart pointer to manage the Port (optional)
};

#endif // VERTEX_H

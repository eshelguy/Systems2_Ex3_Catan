//guyes134@gmail.com

#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include <array>
#include <string>
#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"

class Vertex;

enum class ResourceType {
    Wood,
    Brick,
    Grain,
    Wool,
    Ore,
    Desert
};

class Hexagon {
public:
    Hexagon(ResourceType resourceType, int id, int diceNum);
    ~Hexagon();

    void setRobber(bool robber);      // Set the robber's presence on this hex

    int getId() const;
    bool hasRobber() const; // Check if the robber is on this hex
    int getDiceNumber() const;
    ResourceType getResource();
    std::vector<Vertex*>& getVertices();  // Return vertices as pointers
    void setVertices(const std::vector<Vertex*>& sixVertices);  // Set vertices

    friend std::ostream& operator<<(std::ostream& os, const Hexagon& hexagon);

private:
    int id;
    ResourceType resource;
    int diceNumber;
    bool robberPresent;
    std::vector<Vertex*> vertices;  // Store pointers to vertices
};

#endif // HEXAGON_HPP

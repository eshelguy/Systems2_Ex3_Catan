//guyes134@gmail.com

#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Vertex.hpp"
#include "Road.hpp"

class Vertex;
class Road;

class Edge {
public:
    Edge(Vertex* v1, Vertex* v2, int id, int symbol);


    Vertex* getV1() const;  // Getter for vertices by index
    Vertex* getV2() const;
    int getId();
    bool hasRoad() const;
    std::shared_ptr<Road> getRoad();
    void setRoad(std::shared_ptr<Road> newRoad);

    friend std::ostream& operator<<(std::ostream& os, const Edge& edge);

    private:
    int symbol; //  0 = '/' , 1 = '|' , 2 = '\'
    int id;
    Vertex* vertices[2];
    std::shared_ptr<Road> road;  // Smart pointer to manage the Road
};

#endif // EDGE_H

//guyes134@gmail.com

#ifndef PORT_H
#define PORT_H

#include "Hexagon.hpp"
#include "Vertex.hpp"

enum class ResourceType;

class Port {
public:
    // Constructor to initialize the Port with a specific ratio and resource
    Port(int tradeRatio, ResourceType resourceType);

    // Getter methods
    int getTradeRatio() const;
    bool isGenericPort() const;
    ResourceType getResourceType() const;

private:
    int tradeRatio;                // The ratio required to trade at this port
    ResourceType resourceType;     // The specific resource this port deals with, or a generic indicator
};

#endif // PORT_H

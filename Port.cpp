//guyes134@gmail.com

#include "Port.hpp"

Port::Port(int tradeRatio, ResourceType resourceType)
        : tradeRatio(tradeRatio), resourceType(resourceType) {}

int Port::getTradeRatio() const {
    return tradeRatio;
}

ResourceType Port::getResourceType() const {
    return resourceType;
}

bool Port::isGenericPort() const {
    return tradeRatio == 3 && resourceType == ResourceType::Desert;
}

//guyes134@gmail.com

#include "Player.hpp"
#include <memory>
#include <random>


Player::Player(std::string name)
        : name(name), victoryPoints(0) , isMyTurn(false), largestArmy(false), knightCount(0){
    resources[ResourceType::Wood] = 4;
    resources[ResourceType::Brick] = 4;
    resources[ResourceType::Wool] = 2;
    resources[ResourceType::Ore] = 2;
    resources[ResourceType::Grain] = 0;
}

void Player::setIsMyTurn(bool isTurn) {
    isMyTurn = isTurn;
}

bool Player::getIsMyTurn() const {
    return isMyTurn;
}

std::map<ResourceType, int>& Player::getResources() {
    return resources;
}

std::vector<Settlement*>& Player::getSettlement() {
    return settlements;
}

std::vector<City*>& Player::getCities() {
    return cities;
}

std::vector<Road*>& Player::getRoads() {
    return roads;
}


std::vector<std::shared_ptr<DevelopmentCard>>& Player::getDevelopmentCards() {
    return developmentCards;
}

std::string resourceToString(ResourceType resource) {
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


std::string Player::getName() const {
    return name;
}

void Player::incrementKnightCount() {
    knightCount++;
}

int Player::getKnightCount() const {
    return knightCount;
}

void Player::awardLargestArmy() {
    if (!largestArmy && knightCount >= 3) {
        largestArmy = true;
        victoryPoints += 2;
        std::cout << getName() << " has been awarded the Largest Army and gains 2 victory points!\n";
    }
}

bool Player::hasLargestArmy() const {
    return largestArmy;
}


int Player::getPoints() const{
    return victoryPoints;
}

void Player::addResource(ResourceType resource, int amount) {
    resources[resource] += amount;
}

void Player::addVictoryPoints(int num){
    victoryPoints = victoryPoints + num;
}

int Player::takeAllResourcesOfType(ResourceType resource) {
    int amount = resources[resource];
    resources[resource] = 0;  // Remove all resources of the specified type
    return amount;
}

int Player::getTotalResourceCount() const {
    int total = 0;
    for (const auto& resource : resources) {
        total += resource.second;
    }
    return total;
}

ResourceType Player::getLargestResource(){
    int max = 0;
    ResourceType maxResourceType;
    for (const auto& resource: resources) {
        if (resource.second > max){
            max = resource.second;
            maxResourceType = resource.first;
        }
    }
    return maxResourceType;
}

void Player::discardResources(int count) {
    for (int i = 0; i < count; ++i) {
        ResourceType maxResourceType = getLargestResource();
        resources[maxResourceType]--;
    }
}

bool Player::placeSettlement(int vertexIndex, Board& board) {
    if (!getIsMyTurn()) {
        std::cout << "It's not " << name << "'s turn!" << std::endl;
        return false;
    }
    if (resources[ResourceType::Brick] < 1 || resources[ResourceType::Wood] < 1
        || resources[ResourceType::Ore] < 1 || resources[ResourceType::Wool] < 1){
        std::cout << "Not enough Brick or Wood to build a road.\n";
        return false;
    }

    // Access the vertex directly from the board
    Vertex& vertex = const_cast<Vertex &>(board.getVertices().at(vertexIndex));

    // Check if the vertex is available for settlement
    if (vertex.hasSettlement()) {
        std::cout << "Cannot place settlement at vertex " << vertexIndex << " as it's already occupied.\n";
        return false;
    }

    // Check if any neighboring vertex has a settlement or a city
    const std::vector<Vertex*>& neighbors = vertex.getAdjacentVertices();
    for (Vertex* neighbor : neighbors) {
        if (neighbor->hasSettlement() || neighbor->hasCity()) {
            std::cout << "Cannot place settlement at vertex " << vertexIndex << " because a neighboring vertex is already occupied.\n";
            return false;
        }
    }

    // Check if any neighboring edge has a road
    const std::vector<Edge*>& EdgesNeighbors = vertex.getAdjacentEdges();
    bool roadConnected = false;
    for (Edge* neighbor : EdgesNeighbors) {
        if (neighbor->hasRoad()) {
            roadConnected = true;
            break;
        }
    }

    if (!roadConnected) {
        std::cout << "Cannot place settlement at vertex " << vertexIndex << " because there is no road connected to this vertex.\n";
        return false;
    }

    resources[ResourceType::Brick]--;
    resources[ResourceType::Ore]--;
    resources[ResourceType::Wood]--;
    resources[ResourceType::Wool]--;
    auto settlement = std::make_shared<Settlement>(vertexIndex, *this);

    // Add the new Settlement to the player's list of settlements
    settlements.push_back(settlement.get());

    // Update the vertex to point to this settlement
    vertex.setSettlement(settlement);

    victoryPoints++;

    std::cout << name << " placed a settlement at vertex " << vertexIndex << ".\n";
    return true;
}

bool Player::placeRoad(int edgeIndex, Board& board) {
    if (!getIsMyTurn()) {
        std::cout << "It's not " << name << "'s turn!" << std::endl;
        return false;
    }

    // Check if the player has enough resources
    if (resources[ResourceType::Brick] < 1 || resources[ResourceType::Wood] < 1) {
        std::cout << "Not enough resources to build a road.\n";
        return false;
    }

    // Access the edge directly from the board
    Edge& edge = const_cast<Edge &>(board.getEdges().at(edgeIndex)); // No need for const_cast if getEdges() returns non-const reference

    // Check if the edge is available for a road
    if (edge.hasRoad()) {
        std::cout << "Cannot place road at edge " << edgeIndex << " as it's already occupied.\n";
        return false;
    }

    // Deduct the resources
    resources[ResourceType::Brick]--;
    resources[ResourceType::Wood]--;

    // Create a new Road object using a smart pointer
    auto road = std::make_shared<Road>(edgeIndex, *this);

    // Add the new Road to the player's list of roads
    roads.push_back(road.get());

    // Update the edge to point to this road
    edge.setRoad(road);

    std::cout << name << " placed a road at edge " << edgeIndex << ".\n";
    return true;
}

bool Player::upgradeSettlementToCity(int vertexIndex, Board& board) {
    if (!getIsMyTurn()) {
        std::cout << "It's not " << name << "'s turn!" << std::endl;
        return false;
    }

    Vertex& vertex = const_cast<Vertex &>(board.getVertices().at(vertexIndex));

    if (!vertex.hasSettlement() || vertex.hasCity()) {
        std::cout << "No settlement to upgrade at vertex " << vertexIndex << " or city already exists.\n";
        return false;
    }

    // Check if there is a settlement at the vertex and if this player is the owner
    if (!vertex.hasSettlement() || &vertex.getSettlement()->getOwner() != this) {
        std::cout << "You do not own the settlement at vertex " << vertexIndex << " or there is no settlement to upgrade.\n";
        return false;
    }

    // Check if the player has enough resources (assuming you need 3 Ore and 2 Grain)
    if (resources[ResourceType::Ore] < 3 || resources[ResourceType::Grain] < 2) {
        std::cout << "Not enough resources to upgrade to a city.\n";
        return false;
    }

    // Deduct the resources
    resources[ResourceType::Ore] -= 3;
    resources[ResourceType::Grain] -= 2;

    // Upgrade the settlement to a city
    auto city = std::make_shared<City>(vertexIndex, *this);
    vertex.upgradeToCity(city);  // Set the city on the vertex
    cities.push_back(city.get());  // Add the city to the player's list of cities

    std::cout << name << " upgraded a settlement to a city at vertex " << vertexIndex << ".\n";
    return true;
}


void Player::tradeResources(Player& p2, ResourceType offer, int offerNum, ResourceType get, int getNum) {
    // Check if the current player has enough of the offered resource
    if (resources[offer] < offerNum) {
        std::cout << name << " does not have enough " << resourceToString(offer) << " to trade.\n";
        return;
    }

    // Check if the second player has enough of the requested resource
    if (p2.resources[get] < getNum) {
        std::cout << p2.getName() << " does not have enough " << resourceToString(get) << " to trade.\n";
        return;
    }

    // Ask the second player if they agree to the trade
    char response;
    std::cout << p2.getName() << ", do you agree to trade " << getNum << " " << resourceToString(get)
              << " for " << offerNum << " " << resourceToString(offer) << "? (y/n): ";
    std::cin >> response;

    if (response == 'y' || response == 'Y') {
        // Perform the trade
        resources[offer] -= offerNum;
        p2.resources[offer] += offerNum;

        p2.resources[get] -= getNum;
        resources[get] += getNum;

        std::cout << name << " traded " << offerNum << " " << resourceToString(offer)
                  << " with " << p2.getName() << " for " << getNum << " " << resourceToString(get) << ".\n";
    } else {
        std::cout << p2.getName() << " declined the trade.\n";
    }
}

int Player::chooseNewRobberLocation() const {
    int newHexIndex;

    do {
        std::cout << getName() << ", choose a hex to move the robber to (0-"
                  << 18 << "): ";
        std::cin >> newHexIndex;

        if (newHexIndex < 0 || newHexIndex >= 19) {
            std::cout << "Invalid hexagon index. Please choose a valid hex.\n";
        }
    } while (newHexIndex < 0 || newHexIndex >= 19);

    return newHexIndex;
}

void Player::tradeAtPort(int vertexIndex, ResourceType offerResource, ResourceType desiredResource, Board& board) {
    // Access the vertex from the board
    Vertex& vertex = const_cast<Vertex&>(board.getVertices().at(vertexIndex));

    // Check if the vertex has a port
    if (!vertex.hasPort()) {
        std::cout << "Vertex " << vertexIndex << " does not have a port. Trade cannot be performed." << std::endl;
        return;
    }

    // Check if the player has a settlement or city on the vertex
    if (!vertex.hasSettlement() || vertex.getSettlement()->getOwner().getName() != this->getName()) {
        if (!vertex.hasCity() || vertex.getCity()->getOwner().getName() != this->getName()) {
            std::cout << "You don't have a settlement or city on vertex " << vertexIndex << ". Trade cannot be performed." << std::endl;
            return;
        }
    }

    // Get the port from the vertex
    std::shared_ptr<Port> port = vertex.getPort();

    // Determine the type of port and perform the trade
    if (port->isGenericPort()) {
        // Generic 3:1 port, can trade any resource type
        if (resources[offerResource] >= 3) {
            resources[offerResource] -= 3;
            resources[desiredResource] += 1;
            std::cout << name << " traded 3 " << resourceToString(offerResource)
                      << " for 1 " << resourceToString(desiredResource)
                      << " using a 3:1 port at vertex " << vertexIndex << ".\n";
        } else {
            std::cout << name << " does not have enough " << resourceToString(offerResource)
                      << " to trade at the 3:1 port at vertex " << vertexIndex << ".\n";
        }
    } else {
        // Specific 2:1 port, can only trade the specific resource
        if (port->getResourceType() == offerResource && resources[offerResource] >= 2) {
            resources[offerResource] -= 2;
            resources[desiredResource] += 1;
            std::cout << name << " traded 2 " << resourceToString(offerResource)
                      << " for 1 " << resourceToString(desiredResource)
                      << " using a 2:1 port at vertex " << vertexIndex << ".\n";
        } else {
            std::cout << name << " does not have enough " << resourceToString(offerResource)
                      << " to trade at the 2:1 port at vertex " << vertexIndex << ".\n";
        }
    }
}


void Player::rollDice(Board& board, Catan& catan) {
    // Create a random number generator
    std::random_device rd;  // Seed
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);

    // Roll two dice
    int die1 = dis(gen);
    int die2 = dis(gen);
    int rollResult = die1 + die2;

    // Set the last roll in the Board
    board.setLastRoll(rollResult);

    std::cout << name << " rolled: " << board.getLastRoll() << " (" << die1 << " + " << die2 << ")" << std::endl;

    // If the roll is 7, handle the robber and resource discarding
    if (rollResult == 7) {
        std::cout << "You rolled a 7! All players with more than 7 resource cards must discard half." << std::endl;

        // Get all players in the game
        for (Player* p : catan.getAllPlayers()) {
            int totalResources = p->getTotalResourceCount();

            if (totalResources > 7) {
                int resourcesToDiscard = totalResources / 2;
                std::cout << p->getName() << "  discard " << resourcesToDiscard << " resource cards." << std::endl;
                p->discardResources(resourcesToDiscard);
            }
        }

        // Move the robber
        std::cout << "Please choose a new hexagon to move the robber to (0-18): ";
        int currentRobberPosition = board.getRobberLocation();
        int newHexIndex;

        do {
            newHexIndex = chooseNewRobberLocation();

            if (newHexIndex == currentRobberPosition) {
                std::cout << "The robber is already on that hexagon. Please choose a different one." << std::endl;
            }
        } while (newHexIndex == currentRobberPosition);

        board.moveRobber(newHexIndex);
    } else {
        board.distributeResources(rollResult);
    }
}

void Player::buyDevelopmentCard(Board& board, Catan& catan) {
    if (!getIsMyTurn()) {
        std::cout << "It's not " << name << "'s turn!" << std::endl;
        return;
    }
    // Draw a development card from the deck
    if (board.getDevelopmentDeck().empty()) {
        std::cout << "No more development cards available!" << std::endl;
        return;
    }

    // Check if the player has enough resources
    if (resources[ResourceType::Wool] < 1 || resources[ResourceType::Grain] < 1 || resources[ResourceType::Ore] < 1) {
        std::cout << name << " does not have enough resources to buy a development card." << std::endl;
        return;
    }

    resources[ResourceType::Wool]--;
    resources[ResourceType::Grain]--;
    resources[ResourceType::Ore]--;

    // Draw the card from the deck
    std::shared_ptr<DevelopmentCard> drawnCard = board.getDevelopmentDeck().back();
    board.getDevelopmentDeck().pop_back();  // Remove the card from the deck
    developmentCards.push_back(drawnCard);

    std::cout << name << " bought a development card: " << drawnCard->getName() << std::endl;
    drawnCard->playCard(*this, board, catan);
}


void Player::printPlayerDetails() const {
    std::cout << "Player: " << this->getName() << std::endl;
    std::cout << "  Victory Points: " << this->victoryPoints << std::endl;

    std::cout << "  Settlements: " << std::endl;
    for (const auto& settlement : settlements) {
        if (settlement) {
            std::cout << "    - " << *settlement << std::endl;
        }
    }

    std::cout << "  Roads: " << std::endl;
    for (const auto& road : roads) {
        if (road) {
            std::cout << "    - " << *road << std::endl;
        }
    }

    std::cout << "  Cities: " << std::endl;
    for (const auto& city : cities) {
        if (city) {
            std::cout << "    - " << *city << std::endl;
        }
    }

    std::cout << "  Resources: " << std::endl;
    // Explicitly list all resource types to ensure they are displayed in a specific order
    std::vector<ResourceType> allResources = {
            ResourceType::Wood,
            ResourceType::Brick,
            ResourceType::Grain,
            ResourceType::Wool,
            ResourceType::Ore
    };

    for (const auto& resourceType : allResources) {
        int count = 0;
        if (resources.find(resourceType) != resources.end()) {
            count = resources.at(resourceType);
        }
        std::cout << "    - " << resourceToString(resourceType) << ": " << count << std::endl;
    }

    std::cout << "  Development Cards: " << std::endl;
    for (const auto& devCard : developmentCards) {
        std::cout << "    - " << devCard->getName() << std::endl;
    }

    std::cout << std::endl;
}

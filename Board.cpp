//guyes134@gmail.com

#include "Board.hpp"
#include <iostream>
#include <random>

using namespace std;

Board::Board() : robberLocation(10), largestArmyHolder(nullptr) {
    initializeVertices();
    initializeEdges();
    initializeHexagons();
    initialPorts();
    initializeDevelopmentDeck();
}

Board::~Board(){}

int Board::getLastRoll() const {
    return lastRoll;
}

void Board::setLastRoll(int roll) {
    lastRoll = roll;
}

// Getter for vertices
const std::vector<Vertex>& Board::getVertices() const {
    return vertices;
}

// Getter for edges
const std::vector<Edge>& Board::getEdges() const {
    return edges;
}

// Getter for hexagons
const std::vector<Hexagon>& Board::getHexagons() const {
    return hexagons;
}

std::vector<std::shared_ptr<DevelopmentCard>>& Board::getDevelopmentDeck() {
    return developmentDeck;
}


void Board::checkAndAwardLargestArmy(Player& player) {
    // If there is no current holder and the player has at least 3 Knights
    if (largestArmyHolder == nullptr && player.getKnightCount() >= 3) {
        largestArmyHolder = &player;
        player.awardLargestArmy();  // Permanently award the title
        std::cout << player.getName() << " has claimed the Largest Army title!\n";
    }
}

void Board::initializeVertices() {
    for (int i = 0; i < 54; ++i) {
        vertices.emplace_back(i);
    }

    vertices[0].setAdjacentVertices({&vertices[1], &vertices[8]});
    vertices[1].setAdjacentVertices({&vertices[0], &vertices[2]});
    vertices[2].setAdjacentVertices({&vertices[1], &vertices[3], &vertices[10]});
    vertices[3].setAdjacentVertices({&vertices[2], &vertices[4]});
    vertices[4].setAdjacentVertices({&vertices[3], &vertices[5], &vertices[12]});
    vertices[5].setAdjacentVertices({&vertices[4], &vertices[6]});
    vertices[6].setAdjacentVertices({&vertices[5], &vertices[14]});

    vertices[7].setAdjacentVertices({&vertices[8], &vertices[17]});
    vertices[8].setAdjacentVertices({&vertices[0], &vertices[7], &vertices[9]});
    vertices[9].setAdjacentVertices({&vertices[19], &vertices[8], &vertices[10]});
    vertices[10].setAdjacentVertices({&vertices[9], &vertices[11], &vertices[2]});
    vertices[11].setAdjacentVertices({&vertices[10], &vertices[12], &vertices[21]});
    vertices[12].setAdjacentVertices({&vertices[11], &vertices[13], &vertices[4]});
    vertices[13].setAdjacentVertices({&vertices[12], &vertices[14], &vertices[23]});
    vertices[14].setAdjacentVertices({&vertices[13], &vertices[15], &vertices[6]});
    vertices[15].setAdjacentVertices({&vertices[25], &vertices[14]});

    vertices[16].setAdjacentVertices({&vertices[17], &vertices[27]});
    vertices[17].setAdjacentVertices({&vertices[16], &vertices[18], &vertices[7]});
    vertices[18].setAdjacentVertices({&vertices[17], &vertices[19], &vertices[29]});
    vertices[19].setAdjacentVertices({&vertices[18], &vertices[20], &vertices[9]});
    vertices[20].setAdjacentVertices({&vertices[19], &vertices[21], &vertices[31]});
    vertices[21].setAdjacentVertices({&vertices[20], &vertices[22], &vertices[11]});
    vertices[22].setAdjacentVertices({&vertices[21], &vertices[23], &vertices[33]});
    vertices[23].setAdjacentVertices({&vertices[22], &vertices[24], &vertices[13]});
    vertices[24].setAdjacentVertices({&vertices[23], &vertices[25], &vertices[35]});
    vertices[25].setAdjacentVertices({&vertices[24], &vertices[26], &vertices[15]});
    vertices[26].setAdjacentVertices({&vertices[25], &vertices[37]});

    vertices[27].setAdjacentVertices({&vertices[16], &vertices[28]});
    vertices[28].setAdjacentVertices({&vertices[27], &vertices[29], &vertices[38]});
    vertices[29].setAdjacentVertices({&vertices[28], &vertices[30], &vertices[18]});
    vertices[30].setAdjacentVertices({&vertices[29], &vertices[31], &vertices[40]});
    vertices[31].setAdjacentVertices({&vertices[30], &vertices[32], &vertices[20]});
    vertices[32].setAdjacentVertices({&vertices[31], &vertices[33], &vertices[42]});
    vertices[33].setAdjacentVertices({&vertices[32], &vertices[34], &vertices[22]});
    vertices[34].setAdjacentVertices({&vertices[33], &vertices[35], &vertices[13]});
    vertices[35].setAdjacentVertices({&vertices[34], &vertices[36], &vertices[24]});
    vertices[36].setAdjacentVertices({&vertices[35], &vertices[37], &vertices[15]});
    vertices[37].setAdjacentVertices({&vertices[26], &vertices[36]});

    vertices[38].setAdjacentVertices({&vertices[28], &vertices[39]});
    vertices[39].setAdjacentVertices({&vertices[38], &vertices[40], &vertices[47]});
    vertices[40].setAdjacentVertices({&vertices[40], &vertices[41], &vertices[30]});
    vertices[41].setAdjacentVertices({&vertices[41], &vertices[42], &vertices[49]});
    vertices[42].setAdjacentVertices({&vertices[42], &vertices[43], &vertices[32]});
    vertices[43].setAdjacentVertices({&vertices[43], &vertices[44], &vertices[51]});
    vertices[44].setAdjacentVertices({&vertices[44], &vertices[45], &vertices[34]});
    vertices[45].setAdjacentVertices({&vertices[45], &vertices[46], &vertices[53]});
    vertices[46].setAdjacentVertices({&vertices[36], &vertices[45]});

    vertices[47].setAdjacentVertices({&vertices[39], &vertices[48]});
    vertices[48].setAdjacentVertices({&vertices[47], &vertices[49]});
    vertices[49].setAdjacentVertices({&vertices[48], &vertices[50], &vertices[41]});
    vertices[50].setAdjacentVertices({&vertices[49], &vertices[51]});
    vertices[51].setAdjacentVertices({&vertices[50], &vertices[52], &vertices[43]});
    vertices[52].setAdjacentVertices({&vertices[51], &vertices[53]});
    vertices[53].setAdjacentVertices({&vertices[52], &vertices[45]});
}

void Board::initializeEdges() {
    edges.emplace_back(&vertices[0], &vertices[1], 0, 0);
    edges.emplace_back(&vertices[1], &vertices[2], 1, 2);
    edges.emplace_back(&vertices[2], &vertices[3], 2, 0);
    edges.emplace_back(&vertices[3], &vertices[4], 3, 2);
    edges.emplace_back(&vertices[4], &vertices[5], 4, 0);
    edges.emplace_back(&vertices[5], &vertices[6], 5, 2);

    edges.emplace_back(&vertices[0], &vertices[8], 6, 1);
    edges.emplace_back(&vertices[2], &vertices[10], 7, 1);
    edges.emplace_back(&vertices[4], &vertices[12], 8, 1);
    edges.emplace_back(&vertices[6], &vertices[14], 9, 1);

    edges.emplace_back(&vertices[7], &vertices[8], 10, 0);
    edges.emplace_back(&vertices[8], &vertices[9], 11, 2);
    edges.emplace_back(&vertices[9], &vertices[10], 12, 0);
    edges.emplace_back(&vertices[10], &vertices[11], 13, 2);
    edges.emplace_back(&vertices[11], &vertices[12], 14, 0);
    edges.emplace_back(&vertices[12], &vertices[13], 15, 2);
    edges.emplace_back(&vertices[13], &vertices[14], 16, 0);
    edges.emplace_back(&vertices[14], &vertices[15], 17, 2);

    edges.emplace_back(&vertices[7], &vertices[17], 18, 1);
    edges.emplace_back(&vertices[9], &vertices[19], 19, 1);
    edges.emplace_back(&vertices[11], &vertices[21], 20, 1);
    edges.emplace_back(&vertices[13], &vertices[23], 21, 1);
    edges.emplace_back(&vertices[15], &vertices[25], 22, 1);

    edges.emplace_back(&vertices[16], &vertices[17], 23, 0);
    edges.emplace_back(&vertices[17], &vertices[18], 24, 2);
    edges.emplace_back(&vertices[18], &vertices[19], 25, 0);
    edges.emplace_back(&vertices[19], &vertices[20], 26, 2);
    edges.emplace_back(&vertices[20], &vertices[21], 27, 0);
    edges.emplace_back(&vertices[21], &vertices[22], 28, 2);
    edges.emplace_back(&vertices[22], &vertices[23], 29, 0);
    edges.emplace_back(&vertices[23], &vertices[24], 30, 2);
    edges.emplace_back(&vertices[24], &vertices[25], 31, 0);
    edges.emplace_back(&vertices[25], &vertices[26], 32, 2);

    edges.emplace_back(&vertices[16], &vertices[27], 33, 1);
    edges.emplace_back(&vertices[18], &vertices[29], 34, 1);
    edges.emplace_back(&vertices[20], &vertices[31], 35, 1);
    edges.emplace_back(&vertices[22], &vertices[33], 36, 1);
    edges.emplace_back(&vertices[24], &vertices[35], 37, 1);
    edges.emplace_back(&vertices[26], &vertices[37], 38, 1);

    edges.emplace_back(&vertices[27], &vertices[28], 39, 2);
    edges.emplace_back(&vertices[28], &vertices[29], 40, 0);
    edges.emplace_back(&vertices[29], &vertices[30], 41, 2);
    edges.emplace_back(&vertices[30], &vertices[31], 42, 0);
    edges.emplace_back(&vertices[31], &vertices[32], 43, 2);
    edges.emplace_back(&vertices[32], &vertices[33], 44, 0);
    edges.emplace_back(&vertices[33], &vertices[34], 45, 2);
    edges.emplace_back(&vertices[34], &vertices[35], 46, 0);
    edges.emplace_back(&vertices[35], &vertices[36], 47, 2);
    edges.emplace_back(&vertices[36], &vertices[37], 48, 0);

    edges.emplace_back(&vertices[28], &vertices[38], 49, 1);
    edges.emplace_back(&vertices[30], &vertices[40], 50, 1);
    edges.emplace_back(&vertices[32], &vertices[42], 51, 1);
    edges.emplace_back(&vertices[34], &vertices[44], 52, 1);
    edges.emplace_back(&vertices[36], &vertices[46], 53, 1);

    edges.emplace_back(&vertices[38], &vertices[39], 54, 2);
    edges.emplace_back(&vertices[39], &vertices[40], 55, 0);
    edges.emplace_back(&vertices[40], &vertices[41], 56, 2);
    edges.emplace_back(&vertices[41], &vertices[42], 57, 0);
    edges.emplace_back(&vertices[42], &vertices[43], 58, 2);
    edges.emplace_back(&vertices[43], &vertices[44], 59, 0);
    edges.emplace_back(&vertices[44], &vertices[45], 60, 2);
    edges.emplace_back(&vertices[45], &vertices[46], 61, 0);

    edges.emplace_back(&vertices[39], &vertices[47], 62, 1);
    edges.emplace_back(&vertices[41], &vertices[49], 63, 1);
    edges.emplace_back(&vertices[43], &vertices[51], 64, 1);
    edges.emplace_back(&vertices[45], &vertices[53], 65, 1);

    edges.emplace_back(&vertices[47], &vertices[48], 66, 2);
    edges.emplace_back(&vertices[48], &vertices[49], 67, 0);
    edges.emplace_back(&vertices[49], &vertices[50], 68, 2);
    edges.emplace_back(&vertices[50], &vertices[51], 69, 0);
    edges.emplace_back(&vertices[51], &vertices[52], 70, 2);
    edges.emplace_back(&vertices[52], &vertices[53], 71, 0);

    vertices[0].setAdjacentEdges({&edges[0], &edges[6]});
    vertices[1].setAdjacentEdges({&edges[0], &edges[1]});
    vertices[2].setAdjacentEdges({&edges[2], &edges[1], &edges[7]});
    vertices[3].setAdjacentEdges({&edges[2], &edges[3]});
    vertices[4].setAdjacentEdges({&edges[3], &edges[4], &edges[8]});
    vertices[5].setAdjacentEdges({&edges[2], &edges[3]});
    vertices[6].setAdjacentEdges({&edges[5], &edges[9]});

    vertices[7].setAdjacentEdges({&edges[10], &edges[18]});
    vertices[8].setAdjacentEdges({&edges[6], &edges[10], &edges[11]});
    vertices[9].setAdjacentEdges({&edges[19], &edges[11], &edges[12]});
    vertices[10].setAdjacentEdges({&edges[7], &edges[12], &edges[13]});
    vertices[11].setAdjacentEdges({&edges[20], &edges[13], &edges[14]});
    vertices[12].setAdjacentEdges({&edges[8], &edges[14], &edges[15]});
    vertices[13].setAdjacentEdges({&edges[21], &edges[15], &edges[16]});
    vertices[14].setAdjacentEdges({&edges[9], &edges[16], &edges[17]});
    vertices[15].setAdjacentEdges({&edges[22], &edges[17]});

    vertices[16].setAdjacentEdges({&edges[23], &edges[33]});
    vertices[17].setAdjacentEdges({&edges[23], &edges[24], &edges[18]});
    vertices[18].setAdjacentEdges({&edges[24], &edges[25], &edges[34]});
    vertices[19].setAdjacentEdges({&edges[25], &edges[26], &edges[19]});
    vertices[20].setAdjacentEdges({&edges[26], &edges[27], &edges[35]});
    vertices[21].setAdjacentEdges({&edges[27], &edges[28], &edges[20]});
    vertices[22].setAdjacentEdges({&edges[28], &edges[29], &edges[36]});
    vertices[23].setAdjacentEdges({&edges[29], &edges[30], &edges[21]});
    vertices[24].setAdjacentEdges({&edges[30], &edges[31], &edges[37]});
    vertices[25].setAdjacentEdges({&edges[31], &edges[32], &edges[22]});
    vertices[26].setAdjacentEdges({&edges[32], &edges[38]});

    vertices[27].setAdjacentEdges({&edges[39], &edges[33]});
    vertices[28].setAdjacentEdges({&edges[39], &edges[40], &edges[49]});
    vertices[29].setAdjacentEdges({&edges[40], &edges[41], &edges[34]});
    vertices[30].setAdjacentEdges({&edges[41], &edges[42], &edges[50]});
    vertices[31].setAdjacentEdges({&edges[42], &edges[43], &edges[35]});
    vertices[32].setAdjacentEdges({&edges[43], &edges[44], &edges[51]});
    vertices[33].setAdjacentEdges({&edges[44], &edges[45], &edges[36]});
    vertices[34].setAdjacentEdges({&edges[45], &edges[46], &edges[52]});
    vertices[35].setAdjacentEdges({&edges[46], &edges[47], &edges[37]});
    vertices[36].setAdjacentEdges({&edges[47], &edges[48], &edges[53]});
    vertices[37].setAdjacentEdges({&edges[48], &edges[38]});

    vertices[38].setAdjacentEdges({&edges[49], &edges[54]});
    vertices[39].setAdjacentEdges({&edges[54], &edges[50], &edges[62]});
    vertices[40].setAdjacentEdges({&edges[55], &edges[51], &edges[50]});
    vertices[41].setAdjacentEdges({&edges[56], &edges[52], &edges[63]});
    vertices[42].setAdjacentEdges({&edges[57], &edges[53], &edges[51]});
    vertices[43].setAdjacentEdges({&edges[58], &edges[54], &edges[64]});
    vertices[44].setAdjacentEdges({&edges[59], &edges[55], &edges[52]});
    vertices[45].setAdjacentEdges({&edges[60], &edges[56], &edges[65]});
    vertices[46].setAdjacentEdges({&edges[61], &edges[53]});

    vertices[47].setAdjacentEdges({&edges[62], &edges[66]});
    vertices[48].setAdjacentEdges({&edges[66], &edges[67]});
    vertices[49].setAdjacentEdges({&edges[67], &edges[68], &edges[63]});
    vertices[50].setAdjacentEdges({&edges[68], &edges[69]});
    vertices[51].setAdjacentEdges({&edges[69], &edges[70], &edges[64]});
    vertices[52].setAdjacentEdges({&edges[70], &edges[71]});
    vertices[53].setAdjacentEdges({&edges[71], &edges[65]});
}

void Board::initializeHexagons() {
    hexagons.emplace_back(ResourceType::Ore, 0, 10);
    hexagons.emplace_back(ResourceType::Wool, 1, 2);
    hexagons.emplace_back(ResourceType::Wood, 2, 9);
    hexagons.emplace_back(ResourceType::Grain, 3, 12);
    hexagons.emplace_back(ResourceType::Brick, 4, 6);
    hexagons.emplace_back(ResourceType::Wool, 5, 4);
    hexagons.emplace_back(ResourceType::Brick, 6, 10);
    hexagons.emplace_back(ResourceType::Grain, 7, 9);
    hexagons.emplace_back(ResourceType::Wood, 8, 11);
    hexagons.emplace_back(ResourceType::Desert, 9, 7);
    hexagons.emplace_back(ResourceType::Wood, 10, 3);
    hexagons.emplace_back(ResourceType::Ore, 11, 8);
    hexagons.emplace_back(ResourceType::Wood, 12, 8);
    hexagons.emplace_back(ResourceType::Ore, 13, 3);
    hexagons.emplace_back(ResourceType::Grain, 14, 4);
    hexagons.emplace_back(ResourceType::Wool, 15, 5);
    hexagons.emplace_back(ResourceType::Brick, 16, 5);
    hexagons.emplace_back(ResourceType::Grain, 17, 6);
    hexagons.emplace_back(ResourceType::Wool, 18, 11);

    hexagons[0].setVertices({&vertices[0],  &vertices[1], &vertices[2], &vertices[10], &vertices[9], &vertices[8]});
    hexagons[1].setVertices({&vertices[2], &vertices[3], &vertices[4], &vertices[12], &vertices[11], &vertices[10]});
    hexagons[2].setVertices({&vertices[3], &vertices[4], &vertices[5], &vertices[14], &vertices[12], &vertices[13]});
    hexagons[3].setVertices({&vertices[7], &vertices[8], &vertices[9], &vertices[19], &vertices[18], &vertices[17]});
    hexagons[4].setVertices({&vertices[9], &vertices[10], &vertices[11], &vertices[21], &vertices[20], &vertices[19]});
    hexagons[5].setVertices({&vertices[11], &vertices[12], &vertices[13], &vertices[23], &vertices[22], &vertices[21]});
    hexagons[6].setVertices({&vertices[13], &vertices[14], &vertices[15], &vertices[25], &vertices[24], &vertices[23]});
    hexagons[7].setVertices({&vertices[16], &vertices[17], &vertices[18], &vertices[29], &vertices[28], &vertices[27]});
    hexagons[8].setVertices({&vertices[18], &vertices[19], &vertices[20], &vertices[31], &vertices[30], &vertices[29]});
    hexagons[9].setVertices({&vertices[20], &vertices[21], &vertices[22], &vertices[33], &vertices[32], &vertices[31]});
    hexagons[10].setVertices({&vertices[22], &vertices[23], &vertices[24], &vertices[35], &vertices[34], &vertices[33]});
    hexagons[11].setVertices({&vertices[24], &vertices[25], &vertices[26], &vertices[37], &vertices[36], &vertices[35]});
    hexagons[12].setVertices({&vertices[28], &vertices[29], &vertices[30], &vertices[40], &vertices[39], &vertices[38]});
    hexagons[13].setVertices({&vertices[30], &vertices[31], &vertices[32], &vertices[42], &vertices[41], &vertices[40]});
    hexagons[14].setVertices({&vertices[32], &vertices[33], &vertices[34], &vertices[44], &vertices[43], &vertices[42]});
    hexagons[15].setVertices({&vertices[34], &vertices[35], &vertices[36], &vertices[46], &vertices[45], &vertices[44]});
    hexagons[16].setVertices({&vertices[39], &vertices[40], &vertices[41], &vertices[49], &vertices[48], &vertices[47]});
    hexagons[17].setVertices({&vertices[41], &vertices[42], &vertices[43], &vertices[51], &vertices[50], &vertices[49]});
    hexagons[18].setVertices({&vertices[43], &vertices[44], &vertices[45], &vertices[53], &vertices[52], &vertices[51]});
}

void Board::initialPorts() {
    // Directly associate each port with its vertices
    vertices[0].setPort(std::make_shared<Port>(3, ResourceType::Desert));  // 3:1 Generic Port
    vertices[1].setPort(vertices[0].getPort());

    vertices[3].setPort(std::make_shared<Port>(2, ResourceType::Grain));  // 3:1 Generic Port
    vertices[4].setPort(vertices[2].getPort());

    vertices[7].setPort(std::make_shared<Port>(2, ResourceType::Wood));  // 3:1 Generic Port
    vertices[17].setPort(vertices[4].getPort());

    vertices[14].setPort(std::make_shared<Port>(2, ResourceType::Ore));  // 3:1 Generic Port
    vertices[15].setPort(vertices[6].getPort());

    vertices[28].setPort(std::make_shared<Port>(2, ResourceType::Brick));  // 2:1 Wood Port
    vertices[38].setPort(vertices[8].getPort());

    vertices[45].setPort(std::make_shared<Port>(2, ResourceType::Wool));  // 2:1 Brick Port
    vertices[46].setPort(vertices[10].getPort());

    vertices[26].setPort(std::make_shared<Port>(3, ResourceType::Desert));  // 2:1 Grain Port
    vertices[37].setPort(vertices[12].getPort());

    vertices[50].setPort(std::make_shared<Port>(3, ResourceType::Desert));  // 2:1 Wool Port
    vertices[21].setPort(vertices[14].getPort());

    vertices[47].setPort(std::make_shared<Port>(3, ResourceType::Desert));  // 2:1 Ore Port
    vertices[48].setPort(vertices[16].getPort());
}

void Board::initializeDevelopmentDeck() {
    // Add 14 Knight Cards
    for (int i = 0; i < 14; ++i) {
        developmentDeck.push_back(std::make_shared<KnightCard>());
    }

    // Add 5 Victory Point Cards
    for (int i = 0; i < 5; ++i) {
        developmentDeck.push_back(std::make_shared<VictoryPointCard>());
    }

    // Add 2 Road Building Cards
    for (int i = 0; i < 2; ++i) {
        developmentDeck.push_back(std::make_shared<RoadBuildingCard>());
    }

    // Add 2 Year of Plenty Cards
    for (int i = 0; i < 2; ++i) {
        developmentDeck.push_back(std::make_shared<YearOfPlentyCard>());
    }

    // Add 2 Monopoly Cards
    for (int i = 0; i < 2; ++i) {
        developmentDeck.push_back(std::make_shared<MonopolyCard>());
    }

    // Shuffle the deck after all cards have been added
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(developmentDeck.begin(), developmentDeck.end(), g);
}



void Board::distributeResources(int rolledNumber) {
    for (Hexagon& hexagon : hexagons) {
        if (hexagon.getDiceNumber() == rolledNumber) {
            ResourceType resourceType = hexagon.getResource();
            for (const auto& vertex : hexagon.getVertices()) {  // Use a const reference to shared_ptr<Vertex>
                if (vertex->hasSettlement()) {
                    Player& owner = vertex->getSettlement()->getOwner();
                    owner.addResource(resourceType, 1);
                    std::cout << owner.getName() << " received 1 " << resourceToString(resourceType) << std::endl;
                }
                if (vertex->hasCity()) {
                    Player& owner = vertex->getCity()->getOwner();
                    owner.addResource(resourceType, 2);
                    std::cout << owner.getName() << " received 2 " << resourceToString(resourceType) << std::endl;
                }
            }
        }
    }
}


std::string Board::resourceToString(ResourceType resource) {
    switch (resource) {
        case ResourceType::Wood: return "Wood";
        case ResourceType::Brick: return "Brick";
        case ResourceType::Wool: return "Wool";
        case ResourceType::Grain: return "Grain";
        case ResourceType::Ore: return "Ore";
        case ResourceType::Desert: return "Desert";
        default: return "Unknown";
    }
}

void Board::moveRobber(int newHexLocation) {
    if (newHexLocation >= 0 && newHexLocation < (int)hexagons.size()) {
        // Remove the robber from the current location
        hexagons[robberLocation].setRobber(false);

        // Update the robber location
        robberLocation = newHexLocation;

        // Place the robber on the location
        hexagons[robberLocation].setRobber(true);

        std::cout << "Robber moved to hex " << newHexLocation << ".\n";
    } else {
        std::cout << "Invalid hex location.\n";
    }
}

int Board::getRobberLocation() const {
    return robberLocation;
}

void Board::printBoard() {
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;


    // display the board:
    cout<<"                                                                 "<<this->vertices[1]<<"          "<<this->vertices[3]<<"          "<<this->vertices[5]<<endl;
    cout<<"                                                             "<<this->edges[0]<<"       "<<this->edges[1]<<" "<<this->edges[2]<<"        "<<this->edges[3]<<" "<<this->edges[4]<<"        "<<this->edges[5]<<endl;
    cout<<"                                                           "<<this->vertices[0]<<"          "<<this->vertices[2]<<"          "<<this->vertices[4]<<"          "<<this->vertices[6]<<endl;
    cout<<"                                                           "<<this->edges[6]<<"  "<<this->hexagons[0]<<"  "<<this->edges[7]<<"  "<<this->hexagons[1]<<"  "<<this->edges[8]<<"   "<<this->hexagons[2]<<"  "<<this->edges[9]<<endl;
    cout<<"                                                           "<<this->vertices[8]<<"          "<<this->vertices[10]<<"         "<<this->vertices[12]<<"         "<<this->vertices[14]<<endl;
    cout<<"                                                       "<<this->edges[10]<<"        "<<this->edges[11]<<" "<<this->edges[12]<<"        "<<this->edges[13]<<" "<<this->edges[14]<<"        "<<this->edges[15]<<" "<<this->edges[16]<<"        "<<this->edges[17]<<endl;
    cout<<"                                                      "<<this->vertices[7]<<"          "<<this->vertices[9]<<"          "<<this->vertices[11]<<"         "<<this->vertices[13]<<"         "<<this->vertices[15]<<endl;
    cout<<"                                                      "<<this->edges[18]<<" "<<this->hexagons[3]<<" "<<this->edges[19]<<"  "<<this->hexagons[4]<<"  "<<this->edges[20]<<" "<<this->hexagons[5]<<"  "<<this->edges[21]<<"  "<<this->hexagons[6]<<" "<<this->edges[22]<<endl;
    cout<<"                                                     "<<this->vertices[17]<<"          "<<this->vertices[19]<<"         "<<this->vertices[21]<<"         "<<this->vertices[23]<<"          "<<this->vertices[25]<<endl;
    cout<<"                                                 "<<this->edges[23]<<"        "<<this->edges[24]<<" "<<this->edges[25]<<"         "<<this->edges[26]<<" "<<this->edges[27]<<"        "<<this->edges[28]<<" "<<this->edges[29]<<"         "<<this->edges[30]<<" "<<this->edges[31]<<"        "<<this->edges[32]<<endl;
    cout<<"                                                "<<this->vertices[16]<<"         "<<this->vertices[18]<<"          "<<this->vertices[20]<<"         "<<this->vertices[22]<<"          "<<this->vertices[24]<<"         "<<this->vertices[26]<<endl;
    cout<<"                                                "<<this->edges[33]<<"  "<<this->hexagons[7]<<" "<<this->edges[34]<<"  "<<this->hexagons[8]<<"  "<<this->edges[35]<<" "<<this->hexagons[9]<<"  "<<this->edges[36]<<"  "<<this->hexagons[10]<<"  "<<this->edges[37]<<"   "<<this->hexagons[11]<<"  "<<this->edges[38]<<endl;
    cout<<"                                                "<<this->vertices[27]<<"         "<<this->vertices[29]<<"          "<<this->vertices[31]<<"         "<<this->vertices[33]<<"          "<<this->vertices[35]<<"         "<<this->vertices[37]<<endl;
    cout<<"                                                 "<<this->edges[39]<<"        "<<this->edges[40]<<" "<<this->edges[41]<<"         "<<this->edges[42]<<" "<<this->edges[43]<<"        "<<this->edges[44]<<" "<<this->edges[45]<<"         "<<this->edges[46]<<" "<<this->edges[47]<<"         "<<this->edges[48]<<endl;
    cout<<"                                                     "<<this->vertices[28]<<"          "<<this->vertices[30]<<"         "<<this->vertices[32]<<"         "<<this->vertices[34]<<"          "<<this->vertices[36]<<endl;
    cout<<"                                                      "<<this->edges[49]<<"  "<<this->hexagons[12]<<"  "<<this->edges[50]<<"   "<<this->hexagons[13]<<"   "<<this->edges[51]<<"  "<<this->hexagons[14]<<" "<<this->edges[52]<<"   "<<this->hexagons[15]<<"  "<<this->edges[53]<<endl;
    cout<<"                                                     "<<this->vertices[38]<<"          "<<this->vertices[40]<<"         "<<this->vertices[42]<<"         "<<this->vertices[44]<<"          "<<this->vertices[46]<<endl;
    cout<<"                                                       "<<this->edges[54]<<"        "<<this->edges[55]<<" "<<this->edges[56]<<"         "<<this->edges[57]<<" "<<this->edges[58]<<"        "<<this->edges[59]<<" "<<this->edges[60]<<"         "<<this->edges[61]<<endl;
    cout<<"                                                           "<<this->vertices[39]<<"          "<<this->vertices[41]<<"         "<<this->vertices[43]<<"          "<<this->vertices[45]<<endl;
    cout<<"                                                           "<<this->edges[62]<<"  "<<this->hexagons[16]<<"  "<<this->edges[63]<<"  "<<this->hexagons[17]<<"  "<<this->edges[64]<<"  "<<this->hexagons[18]<<" "<<this->edges[65]<<endl;
    cout<<"                                                           "<<this->vertices[47]<<"          "<<this->vertices[49]<<"         "<<this->vertices[51]<<"          "<<this->vertices[53]<<endl;
    cout<<"                                                             "<<this->edges[66]<<"        "<<this->edges[67]<<" "<<this->edges[68]<<"         "<<this->edges[69]<<" "<<this->edges[70]<<"        "<<this->edges[71]<<endl;
    cout<<"                                                                 "<<this->vertices[48]<<"         "<<this->vertices[50]<<"          "<<this->vertices[52]<<endl;

    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
}
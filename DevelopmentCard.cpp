//guyes134@gmail.com

#include "DevelopmentCard.hpp"
#include <iostream>

KnightCard::KnightCard() {};

std::string KnightCard::getName() const {
    return "Knight";
}

void KnightCard::playCard(Player& player, Board& board, Catan &catan) {
    std::cout << player.getName() << " played a Knight card!\n";

    // Choose a new location for the robber
    int newHexLocation = player.chooseNewRobberLocation();

    // Move the robber to the chosen location
    board.moveRobber(newHexLocation);

    // Increment the player's Knight count
    player.incrementKnightCount();

    // Check if the player should now hold the Largest Army title
    board.checkAndAwardLargestArmy(player);
}

/**-------------------------------------------------------------------------------**/

VictoryPointCard::VictoryPointCard() {};

std::string VictoryPointCard::getName() const {
    return "Victory Point";
}

void VictoryPointCard::playCard(Player& player, Board& board, Catan &catan) {
    std::cout << player.getName() << " revealed a Victory Point card!\n";
    player.addVictoryPoints(1);
}


/**-------------------------------------------------------------------------------**/


RoadBuildingCard::RoadBuildingCard() {};


std::string RoadBuildingCard::getName() const {
    return "Road Building";
}

void RoadBuildingCard::playCard(Player& player, Board& board, Catan &catan) {
    std::cout << player.getName() << " played a Road Building card!\n";

    // The player places two roads on the board
    for (int i = 0; i < 2; ++i) {
        int edgeIndex;

        // Prompt the player to choose an edge for the new road
        std::cout << "Choose the location for road " << (i + 1) << " (edge index): ";
        std::cin >> edgeIndex;

        // Attempt to place the road, and handle invalid placements
        while (!player.placeRoad(edgeIndex, board)) {
            std::cout << "Invalid road placement. Please choose a different location.\n";
            std::cin >> edgeIndex;
        }

        std::cout << "Road " << (i + 1) << " placed at edge " << edgeIndex << ".\n";
    }
}

/**-------------------------------------------------------------------------------**/

YearOfPlentyCard::YearOfPlentyCard() {};


std::string YearOfPlentyCard::getName() const {
    return "Year of Plenty";
}

void YearOfPlentyCard::playCard(Player& player, Board& board, Catan &catan) {
    std::cout << player.getName() << " played a Year of Plenty card!\n";

    // Prompt the player to choose two resources
    for (int i = 0; i < 2; ++i) {
        std::cout << "Choose resource " << (i + 1) << " (Wood, Brick, Grain, Wool, Ore): ";
        std::string resourceChoice;
        std::cin >> resourceChoice;

        ResourceType resource;
        if (resourceChoice == "Wood") resource = ResourceType::Wood;
        else if (resourceChoice == "Brick") resource = ResourceType::Brick;
        else if (resourceChoice == "Grain") resource = ResourceType::Grain;
        else if (resourceChoice == "Wool") resource = ResourceType::Wool;
        else if (resourceChoice == "Ore") resource = ResourceType::Ore;
        else {
            std::cout << "Invalid resource type. Please try again.\n";
            --i;
            continue;
        }

        player.addResource(resource, 1);
        std::cout << player.getName() << " received 1 " << resourceChoice << ".\n";
    }
}


/**-------------------------------------------------------------------------------**/


MonopolyCard::MonopolyCard() {};


std::string MonopolyCard::getName() const {
    return "Monopoly";
}

void MonopolyCard::playCard(Player& player, Board& board, Catan &catan) {
    std::cout << player.getName() << " played a Monopoly card!\n";

    // Prompt the player to choose a resource type
    std::cout << "Choose a resource type to monopolize (Wood, Brick, Grain, Wool, Ore): ";
    std::string resourceChoice;
    std::cin >> resourceChoice;

    ResourceType resource;
    if (resourceChoice == "Wood") resource = ResourceType::Wood;
    else if (resourceChoice == "Brick") resource = ResourceType::Brick;
    else if (resourceChoice == "Grain") resource = ResourceType::Grain;
    else if (resourceChoice == "Wool") resource = ResourceType::Wool;
    else if (resourceChoice == "Ore") resource = ResourceType::Ore;
    else {
        std::cout << "Invalid resource type. The Monopoly card was wasted.\n";
        return; // Invalid choice, card is wasted
    }

    // Collect all the chosen resources from other players
    int totalResourcesCollected = 0;
    for (Player* p : catan.getAllPlayers()) {  // Assuming Board has a method to get all players
        if (p != &player) {
            int resourcesTaken = p->takeAllResourcesOfType(resource);
            player.addResource(resource, resourcesTaken);
            totalResourcesCollected += resourcesTaken;

            std::cout << p->getName() << " gave " << resourcesTaken << " " << resourceChoice << "(s) to " << player.getName() << ".\n";
        }
    }

    if (totalResourcesCollected > 0) {
        std::cout << player.getName() << " monopolized " << totalResourcesCollected << " " << resourceChoice << "(s).\n";
    } else {
        std::cout << "No resources were collected. The Monopoly card had no effect.\n";
    }
}



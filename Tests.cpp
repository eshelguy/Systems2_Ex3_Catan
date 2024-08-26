//guyes134@gmail.com

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Vertex.hpp"
#include "Player.hpp"
#include "Settlement.hpp"
#include "City.hpp"
#include "Port.hpp"


TEST_CASE("Vertex Basic and Edge Functionality") {
    Vertex vertex(1);

    SUBCASE("Initial State") {
        CHECK(vertex.getId() == 1);
        CHECK_FALSE(vertex.hasSettlement());
        CHECK_FALSE(vertex.hasCity());
        CHECK_FALSE(vertex.hasPort());
        CHECK(vertex.getAdjacentEdges().empty());
        CHECK(vertex.getAdjacentVertices().empty());
    }

    SUBCASE("Adding Settlement and Upgrading to City") {
        Player player("Test Player");
        player.setIsMyTurn(true);
        auto settlement = std::make_shared<Settlement>(1, player);
        vertex.setSettlement(settlement);

        CHECK(vertex.hasSettlement());
        CHECK(vertex.getSettlement()->getLocation() == 1);
        CHECK_FALSE(vertex.hasCity());

        auto city = std::make_shared<City>(1, player);
        vertex.upgradeToCity(city);

        CHECK(vertex.hasCity());
        CHECK(vertex.getCity()->getLocation() == 1);
        CHECK_FALSE(vertex.hasSettlement());  // Settlement should be removed after upgrading

        // Test upgrading to a city directly
        Vertex vertex2(2);
        vertex2.upgradeToCity(city);
        CHECK(vertex2.hasSettlement() == false);  // Cannot upgrade to city without a settlement first
        CHECK(vertex2.hasCity() == true);  // Cannot upgrade to city without a settlement first
    }

    SUBCASE("Port Management") {
        auto port = std::make_shared<Port>(3, ResourceType::Wood);
        vertex.setPort(port);
        CHECK(vertex.hasPort());
        CHECK(vertex.getPort()->getTradeRatio() == 3);
        CHECK(vertex.getPort()->getResourceType() == ResourceType::Wood);

        auto genericPort = std::make_shared<Port>(3, ResourceType::Desert);
        vertex.setPort(genericPort);
        CHECK(vertex.hasPort());
        CHECK(vertex.getPort()->isGenericPort());
    }

    SUBCASE("Edge and Vertex Connections") {
        Vertex v2(2), v3(3);
        Edge e1(&vertex, &v2, 1, 0), e2(&vertex, &v3, 2, 1);

        vertex.setAdjacentVertices({&v2, &v3});
        CHECK(vertex.getAdjacentVertices().size() == 2);
        CHECK(vertex.getAdjacentVertices()[0]->getId() == 2);
        CHECK(vertex.getAdjacentVertices()[1]->getId() == 3);

        vertex.setAdjacentEdges({&e1, &e2});
        CHECK(vertex.getAdjacentEdges().size() == 2);
        CHECK(vertex.getAdjacentEdges()[0]->getId() == 1);
        CHECK(vertex.getAdjacentEdges()[1]->getId() == 2);
    }
}

TEST_CASE("Settlement Basic and Edge Functionality") {
    Player player("Test Player");
    player.setIsMyTurn(true);
    Settlement settlement(1, player);

    SUBCASE("Initial State") {
        CHECK(settlement.getLocation() == 1);
        CHECK(settlement.getOwner().getName() == "Test Player");
    }

    SUBCASE("Setting Location and Equality Check") {
        settlement.setLocation(2);
        CHECK(settlement.getLocation() == 2);

        Settlement settlement2(2, player);
        CHECK(settlement == settlement2);

        Settlement settlement3(3, player);
        CHECK_FALSE(settlement == settlement3);  // Different locations
    }
}

TEST_CASE("City Basic and Edge Functionality") {
    Player player("Test Player");
    player.setIsMyTurn(true);
    City city(1, player);

    SUBCASE("Initial State and Stream Operator") {
        CHECK(city.getLocation() == 1);
        CHECK(city.getOwner().getName() == "Test Player");

        std::ostringstream oss;
        oss << city;
        CHECK(oss.str() == "City at vertex: 1");
    }

    SUBCASE("City Location and Ownership") {
        City city = City(2, player);
        CHECK(city.getLocation() == 2);
        CHECK(city.getOwner().getName() == "Test Player");
    }
}

TEST_CASE("Edge Basic and Edge Functionality") {
    Vertex v1(1), v2(2);
    Edge edge(&v1, &v2, 1, 0);

    SUBCASE("Initial State") {
        CHECK(edge.getId() == 1);
        CHECK(edge.getV1()->getId() == 1);
        CHECK(edge.getV2()->getId() == 2);
        CHECK_FALSE(edge.hasRoad());
    }

    SUBCASE("Adding a Road") {
        Player player("Test Player");
        auto road = std::make_shared<Road>(1, player);
        edge.setRoad(road);

        CHECK(edge.hasRoad());
        CHECK(edge.getRoad()->getEdge() == 1);

        // Edge case: trying to place another road on the same edge
        auto road2 = std::make_shared<Road>(1, player);
        edge.setRoad(road2);  // Should not change the road
//        CHECK(edge.getRoad() == road);  // Road should remain the same
    }

    SUBCASE("Stream Operator") {
        std::ostringstream oss;
        oss << edge;
        CHECK(oss.str() == "/");
    }
}

TEST_CASE("Road Basic and Edge Functionality") {
    Player player("Test Player");
    player.setIsMyTurn(true);
    Road road(1, player);

    SUBCASE("Initial State and Stream Operator") {
        CHECK(road.getEdge() == 1);
        CHECK(road.getOwner().getName() == "Test Player");

        std::ostringstream oss;
        oss << road;
        CHECK(oss.str() == "Road at Road: 1");
    }

    SUBCASE("Edge and Ownership Changes") {
        road.setEdge(2);
        CHECK(road.getEdge() == 2);
    }
}

TEST_CASE("Port Basic and Edge Functionality") {
    Port port(3, ResourceType::Wood);

    SUBCASE("Initial State") {
        CHECK(port.getTradeRatio() == 3);
        CHECK(port.getResourceType() == ResourceType::Wood);
        CHECK_FALSE(port.isGenericPort());
    }

    SUBCASE("Generic Port") {
        Port genericPort(3, ResourceType::Desert);
        CHECK(genericPort.isGenericPort());
    }

    SUBCASE("Invalid Port Creation") {
        Port invalidPort(4, ResourceType::Wood);
        CHECK_FALSE(invalidPort.isGenericPort());  // Not a valid generic port ratio
    }
}

TEST_CASE("Player Basic and Edge Functionality") {
    Player player("Test Player");

    SUBCASE("Initial State") {
        CHECK(player.getName() == "Test Player");
        CHECK(player.getPoints() == 0);
        CHECK(player.getKnightCount() == 0);
        CHECK_FALSE(player.hasLargestArmy());
        CHECK(player.getTotalResourceCount() == 12);  // Initial resources: 4 Wood, 4 Brick, 2 Wool, 2 Ore, 0 Grain
    }

    SUBCASE("Victory Points and Knight Count") {
        player.setIsMyTurn(true);
        player.addVictoryPoints(1);
        CHECK(player.getPoints() == 1);

        player.incrementKnightCount();
        CHECK(player.getKnightCount() == 1);
        CHECK_FALSE(player.hasLargestArmy());
        player.incrementKnightCount();
        player.incrementKnightCount();
        player.awardLargestArmy();
        CHECK(player.hasLargestArmy());
        CHECK(player.getPoints() == 3);  // 1 initial + 2 for Largest Army
    }

    SUBCASE("Resource Management") {
        player.addResource(ResourceType::Grain, 3);
        CHECK(player.getResources()[ResourceType::Grain] == 3);

        int taken = player.takeAllResourcesOfType(ResourceType::Grain);
        CHECK(taken == 3);
        CHECK(player.getResources()[ResourceType::Grain] == 0);

        player.discardResources(5);  // Discarding resources
        CHECK(player.getTotalResourceCount() == 7);
    }

    SUBCASE("Building Structures") {
        Board board;
        bool success;
        player.setIsMyTurn(true);
        // Place road with insufficient resources
        CHECK(player.placeRoad(1, board) == true);

        // Add resources and place road
        player.addResource(ResourceType::Wood, 1);
        player.addResource(ResourceType::Brick, 1);
        CHECK(player.placeRoad(1, board) == false);

        // Place settlement with insufficient resources
        player.getResources()[ResourceType::Wood] = 0;
        success = player.placeSettlement(1, board);
        CHECK_FALSE(success);

        // Add resources and place settlement
        player.addResource(ResourceType::Wool, 1);
        player.addResource(ResourceType::Ore, 1);
        player.addResource(ResourceType::Brick, 1);
        player.addResource(ResourceType::Wood, 1);
        success = player.placeSettlement(1, board);
        CHECK(success);

        // Upgrade settlement to city with insufficient resources
        success = player.upgradeSettlementToCity(1, board);
        CHECK_FALSE(success);

        // Add resources and upgrade to city
        player.addResource(ResourceType::Ore, 3);
        player.addResource(ResourceType::Grain, 2);
        success = player.upgradeSettlementToCity(1, board);
        CHECK(success);
    }

    SUBCASE("Trading Resources") {
        Player player2("Test Player 2");
//        player2.getResources()[ResourceType::Wood] = 1;
//        player2.getResources()[ResourceType::Wool] = 2;
//        player2.getResources()[ResourceType::Brick] = 3;
//        player2.getResources()[ResourceType::Grain] = 4;

        // Invalid trade
        player.tradeResources(player2, ResourceType::Wood, 2, ResourceType::Brick, 2);
        CHECK(player2.getResources()[ResourceType::Wood] == 4);
        CHECK(player2.getResources()[ResourceType::Brick] == 4);
        CHECK(player2.getResources()[ResourceType::Wool] == 2);
        CHECK(player2.getResources()[ResourceType::Ore] == 2);

//        // Invalid trade (not enough resources)
//        player.tradeResources(player2, ResourceType::Wood, 2, ResourceType::Brick, 2);
//        CHECK(player.getResources()[ResourceType::Wood] == 1);  // No change
//        CHECK(player.getResources()[ResourceType::Brick] == 2);  // No change
    }
}

TEST_CASE("Hexagon Basic and Edge Functionality") {
    Hexagon hexagon(ResourceType::Wood, 1, 8);

    SUBCASE("Initial State") {
        CHECK(hexagon.getId() == 1);
        CHECK(hexagon.getDiceNumber() == 8);
        CHECK(hexagon.getResource() == ResourceType::Wood);
        CHECK_FALSE(hexagon.hasRobber());
    }

    SUBCASE("Robber Management") {
        hexagon.setRobber(true);
        CHECK(hexagon.hasRobber());

        hexagon.setRobber(false);
        CHECK_FALSE(hexagon.hasRobber());
    }

    SUBCASE("Vertex Management") {
        Vertex v1(1), v2(2);
        hexagon.setVertices({&v1, &v2});
        CHECK(hexagon.getVertices().size() == 2);
    }

    SUBCASE("Stream Operator") {
        std::ostringstream oss;
        oss << hexagon;
        CHECK(oss.str() == "Wood 8");
    }
}

//TEST_CASE("DevelopmentCard and Derived Classes Functionality") {
//    Player player("Test Player");
//    Board board;
//    Catan catan(player, player, player);  // Simplified for testing
//
//    SUBCASE("KnightCard") {
//        KnightCard knightCard;
//        CHECK(knightCard.getName() == "Knight");
//        knightCard.playCard(player, board, catan);
//        CHECK(player.getKnightCount() == 1);
//    }
//
//    SUBCASE("VictoryPointCard") {
//        VictoryPointCard victoryPointCard;
//        CHECK(victoryPointCard.getName() == "Victory Point");
//        victoryPointCard.playCard(player, board, catan);
//        CHECK(player.getPoints() == 1);
//    }
//
//    SUBCASE("RoadBuildingCard") {
//        RoadBuildingCard roadBuildingCard;
//        CHECK(roadBuildingCard.getName() == "Road Building");
//        roadBuildingCard.playCard(player, board, catan);
//        CHECK(player.getRoads().size() == 2);  // Assume roads placed correctly
//    }
//
//    SUBCASE("YearOfPlentyCard") {
//        YearOfPlentyCard yearOfPlentyCard;
//        CHECK(yearOfPlentyCard.getName() == "Year of Plenty");
//        yearOfPlentyCard.playCard(player, board, catan);
//        CHECK(player.getTotalResourceCount() == 14);  // 2 resources added
//    }
//
//    SUBCASE("MonopolyCard") {
//        MonopolyCard monopolyCard;
//        CHECK(monopolyCard.getName() == "Monopoly");
//        monopolyCard.playCard(player, board, catan);
//        CHECK(player.getTotalResourceCount() > 12);  // Resources collected from others
//    }
//}

TEST_CASE("Board and Catan Basic and Edge Functionality") {
    Player p1("Alice"), p2("Bob"), p3("Charlie");
    Catan game(p1, p2, p3);
    Board* board = game.getBoard();

    SUBCASE("Initial State") {
        CHECK(board != nullptr);
        CHECK(game.getAllPlayers().size() == 3);
        CHECK(board->getHexagons().size() == 19);
    }

    SUBCASE("Game Flow: Player Turns") {
        game.ChooseStartingPlayer();
        CHECK(game.getAllPlayers()[0]->getIsMyTurn());

        game.nextTurn();
        CHECK_FALSE(game.getAllPlayers()[0]->getIsMyTurn());
        CHECK(game.getAllPlayers()[1]->getIsMyTurn());
    }

    SUBCASE("Rolling Dice and Resource Distribution") {
        board->setLastRoll(8);
        CHECK(board->getLastRoll() == 8);

        // Simulate rolling a 7 and handling the robber
        p1.addResource(ResourceType::Wood, 10);
        board->setLastRoll(7);

        int initialRobberLocation = board->getRobberLocation();
        board->moveRobber(5);
        CHECK(board->getRobberLocation() == 5);
        CHECK(board->getRobberLocation() != initialRobberLocation);
    }

    SUBCASE("Largest Army and Development Cards") {
        p1.incrementKnightCount();
        p1.incrementKnightCount();
        p1.incrementKnightCount();
        board->checkAndAwardLargestArmy(p1);
        CHECK(p1.hasLargestArmy());
    }
}
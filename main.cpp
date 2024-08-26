//guyes134@gmail.com

#include <random>
#include "Board.hpp"
#include "Catan.hpp"
#include "Player.hpp"

using namespace std;

int main(){

    Player p1("Amit");
    Player p2("Yossi");
    Player p3("Dana");

    Catan catan(p1, p2, p3);
    catan.ChooseStartingPlayer();   // should print the name of the starting player, assume it is Amit.
    Board* board = catan.getBoard(); // get the board of the game.
    board->printBoard();

    // Place first settlements and roads for p1
    p1.placeRoad(31, *board);
    p1.placeSettlement(25, *board);
    catan.nextTurn();

    // Attempt to place first settlements and roads for p2
    p2.placeRoad(31, *board);
    p2.placeSettlement(25, *board);


    // Place first settlements and roads for p2 at different locations
    p2.placeRoad(19, *board);
    p2.placeSettlement(9, *board);
    catan.nextTurn();

    // Place first settlements and roads for p3 at different locations
    p3.placeRoad(57, *board);
    p3.placeSettlement(42, *board);
    catan.nextTurn();

    // Place second settlements and roads for p1 at different locations
    p1.placeRoad(26, *board);
    p1.placeSettlement(20, *board);
    catan.nextTurn();

    // Attempt to place second settlement for p2
    p2.placeRoad(41, *board);
    p2.placeSettlement(29, *board);
    catan.nextTurn();

    // Place second settlements and roads for p1 in a different location
    p3.placeRoad(46, *board);
    p3.placeSettlement(35, *board);
    catan.nextTurn();


    catan.nextTurn();
    /**end of the start position**/
    board->distributeResources(3);
    catan.nextTurn();

    board->distributeResources(5);
    catan.nextTurn();

    board->distributeResources(6);
    catan.nextTurn();

    board->distributeResources(11);
    catan.nextTurn();

    board->distributeResources(9);
    catan.nextTurn();

    // Players start upgrading settlements to cities and buying development cards

    // P1 upgrades a settlement to a city
    board->distributeResources(3);
    p1.upgradeSettlementToCity(25, *board);
    catan.nextTurn();

    // P2 builds another road and buys a development card
    board->distributeResources(5);
    p2.placeRoad(13, *board);
    catan.nextTurn();

    // P3 upgrades a settlement to a city and buys a development card
    board->distributeResources(8);
    p3.upgradeSettlementToCity(42, *board);
    catan.nextTurn();

    // P1 builds another road and settlement
    p1.placeRoad(12, *board);
    p1.placeSettlement(8, *board);
    catan.nextTurn();

    // P2 upgrades another settlement to a city
    board->distributeResources(6);
    p2.upgradeSettlementToCity(9, *board);
    catan.nextTurn();

    // P3 builds another road and buys a development card
    board->distributeResources(6);
    p3.placeRoad(15, *board);
    catan.nextTurn();

    // Simulate more resource distribution
    board->distributeResources(8);
    catan.nextTurn();

    board->distributeResources(4);
    catan.nextTurn();

    board->distributeResources(10);
    catan.nextTurn();

    board->distributeResources(9);
    catan.nextTurn();

    board->distributeResources(11);
    catan.nextTurn();

    board->distributeResources(3);
    catan.nextTurn();
    // Continue with more actions

    // P1 buys another development card
    p1.buyDevelopmentCard(*board, catan);
    catan.nextTurn();

    // P2 builds a road and another settlement
    p2.placeRoad(16, *board);
    p2.placeSettlement(10, *board);
    catan.nextTurn();

    // P3 upgrades another settlement to a city
    p3.upgradeSettlementToCity(35, *board);
    catan.nextTurn();

    p1.tradeAtPort(1, ResourceType::Brick, ResourceType::Wool, *board);


    p1.printPlayerDetails();
    p2.printPlayerDetails();
    p3.printPlayerDetails();

    catan.printWinner();





    return 1;
}
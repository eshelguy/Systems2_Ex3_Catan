//guyes134@gmail.com

#ifndef DEVELOPMENTCARD_HPP
#define DEVELOPMENTCARD_HPP

#include <string>
#include "DevelopmentCard.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Catan.hpp"


class Player;
class Board;
class Catan;

class DevelopmentCard {
public:

    virtual ~DevelopmentCard() = default;

    virtual std::string getName() const = 0;  // Get the name of the card
    virtual void playCard(Player& player, Board& board, Catan &catan) = 0;  // Play the card

    bool isPlayable() const { return playable; }  // Check if the card is playable
    void setPlayable(bool value) { playable = value; }  // Set if the card is playable

protected:
    bool playable = false;  // Determines if the card can be played immediately
};


/**-------------------------------------------------------------------------------**/



class KnightCard : public DevelopmentCard {
public:
    KnightCard();  // Constructor
    std::string getName() const override;
    void playCard(Player& player, Board& board, Catan &catan) override;
};


/**-------------------------------------------------------------------------------**/


class VictoryPointCard : public DevelopmentCard {
public:
    VictoryPointCard();
    std::string getName() const override;
    void playCard(Player& player, Board& board, Catan &catan) override;
};


/**-------------------------------------------------------------------------------**/


class RoadBuildingCard : public DevelopmentCard {
public:
    RoadBuildingCard();
    std::string getName() const override;
    void playCard(Player& player, Board& board, Catan &catan) ;
};


/**-------------------------------------------------------------------------------**/



class YearOfPlentyCard : public DevelopmentCard {
public:
    YearOfPlentyCard();
    std::string getName() const override;
    void playCard(Player& player, Board& board, Catan &catan) override;
};


/**-------------------------------------------------------------------------------**/



class MonopolyCard : public DevelopmentCard {
public:
    MonopolyCard();
    std::string getName() const override;
    void playCard(Player& player, Board& board, Catan &catan);
};


#endif // DEVELOPMENTCARD_HPP


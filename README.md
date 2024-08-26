### Detailed README (English)

# Catan Game Implementation

## Overview

This project is a C++ implementation of the popular board game **Catan**. The implementation simulates the core mechanics of the game, allowing players to engage in strategic gameplay involving resource management, trading, and building. The game is structured using various classes to represent the key elements such as players, the game board, hexagons, roads, settlements, cities, and development cards. This document provides an overview of the project, instructions on how to compile and run the game, as well as how to run the included unit tests.

## Features

- **Player Management**: Each player can manage resources, build roads, settlements, and cities, and use development cards.
- **Game Board Representation**: The board consists of hexagons that produce resources, vertices where settlements and cities can be placed, and edges where roads can be built.
- **Resource Distribution**: Resources are distributed based on dice rolls, and players can trade resources with each other or through ports.
- **Development Cards**: Various development cards can be used to gain advantages, such as building roads, gaining victory points, or moving the robber.
- **Victory Conditions**: The game tracks player progress towards victory, with conditions such as accumulating a certain number of victory points.

## Project Structure

- **Catan.hpp / Catan.cpp**: Manages the overall game flow, including player turns, resource distribution, and determining the winner.
- **Board.hpp / Board.cpp**: Represents the game board, including hexagons, vertices, edges, ports, and the robber. Handles resource distribution and game state updates.
- **Player.hpp / Player.cpp**: Manages individual player data, including resources, roads, settlements, cities, and development cards. Contains methods for player actions such as rolling dice, building, and trading.
- **Hexagon.hpp / Hexagon.cpp**: Represents hexagons on the board, which produce resources based on dice rolls. Handles the placement of the robber.
- **Edge.hpp / Edge.cpp**: Represents edges between vertices where roads can be built.
- **Vertex.hpp / Vertex.cpp**: Represents vertices on the board where settlements and cities are placed. Manages connections to adjacent vertices and edges.
- **Settlement.hpp / Settlement.cpp**: Represents a player's settlement on the board, which can later be upgraded to a city.
- **City.hpp / City.cpp**: Represents a city, which is an upgraded version of a settlement, providing more resources.
- **Road.hpp / Road.cpp**: Represents roads that players build between vertices.
- **Port.hpp / Port.cpp**: Represents ports on the board, allowing players to trade resources at advantageous rates.
- **DevelopmentCard.hpp / DevelopmentCard.cpp**: Base class for development cards with derived classes representing specific types of cards such as Knight, Victory Point, Road Building, Year of Plenty, and Monopoly.


### Basic Rules

1. **Game Setup**: Each player begins with two settlements and two roads placed on the game board. Players start with specific resources depending on the placement of their initial settlements.
   
2. **Turns**: During a player's turn, they roll two dice to determine which hexagons produce resources. Players collect resources from hexagons adjacent to their settlements and cities.
   
3. **Building**: Players can use their resources to build roads, settlements, and cities, or buy development cards. Building settlements requires specific resources, and upgrading to cities requires additional resources.

4. **Trading**: Players can trade resources with each other or use ports to trade at favorable rates.

5. **Development Cards**: Players can play development cards to gain advantages, such as moving the robber, gaining victory points, or building additional roads.

6. **Winning the Game**: The first player to reach 10 victory points wins the game. Victory points are earned through building settlements, upgrading to cities, and playing certain development cards.

### Additional Features

- **Robber**: The robber is a game mechanic that can block resource production on a hexagon. It is moved when a player rolls a 7 or plays a Knight card.

- **Largest Army**: The player who plays the most Knight cards can earn the Largest Army bonus, which provides additional victory points.

## Future Improvements

This implementation covers the basic rules and mechanics of Catan. Future improvements could include:

- **Graphical User Interface (GUI)**: Developing a GUI to make the game more user-friendly and visually appealing.
- **Network Play**: Allowing players to play against each other over a network.
- **AI Opponents**: Adding AI players with different difficulty levels to provide single-player gameplay.

## Author

This project was developed by [Your Name]. Contributions, suggestions, and bug reports are welcome. Feel free to open an issue or submit a pull request on the project’s repository.

## License

This project is licensed under the MIT License - see the LICENSE file for details.

---


---

These detailed README files provide in-depth information about the project, including instructions for compiling and running the game, a breakdown of the project's structure, game rules, and future improvement suggestions. If you need further customization or additional sections, feel free to ask!

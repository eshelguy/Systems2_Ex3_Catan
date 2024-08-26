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

## Installation and Dependencies

### Prerequisites

To build and run this project, you'll need the following:

- A C++ compiler that supports C++11 or later (e.g., GCC, Clang, MSVC).
- The `doctest` library for unit testing.

### Installing `doctest`

You can install `doctest` by downloading the header file from the official repository and including it in your project directory. Alternatively, you can install it using your system's package manager if available.

```bash
# Example for Ubuntu-based systems
sudo apt-get install doctest-dev
```

## Compilation

### Compiling the Game

To compile the main game, use the following command:

```bash
g++ -std=c++11 -o catan_game main.cpp Catan.cpp Board.cpp Player.cpp Hexagon.cpp Edge.cpp Vertex.cpp Settlement.cpp City.cpp Road.cpp Port.cpp DevelopmentCard.cpp -I.
```

This command compiles all the necessary source files and links them into an executable named `catan_game`.

### Compiling the Tests

To compile the unit tests, use the following command:

```bash
g++ -std=c++11 -o tests test_main.cpp Catan.cpp Board.cpp Player.cpp Hexagon.cpp Edge.cpp Vertex.cpp Settlement.cpp City.cpp Road.cpp Port.cpp DevelopmentCard.cpp -I. -ldoctest
```

This command compiles the test suite along with the game files and links them into an executable named `tests`.

## Running the Game

After compiling the project, you can start the game by running the following command:

```bash
./catan_game
```

This will launch the game in the terminal, where you can play Catan by following the on-screen prompts.

## Running the Tests

To run the unit tests, execute the following command:

```bash
./tests
```

The test suite will run, providing output on the success or failure of each test case. This ensures that the game logic is functioning correctly and helps catch any potential bugs or issues.

## Game Rules and Instructions

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

### README (Hebrew)

# מימוש משחק קטאן

## סקירה כללית

הפרויקט הזה הוא מימוש בשפת C++ של משחק הלוח הפופולרי **קטאן**. המימוש מדמה את המכניקה המרכזית של המשחק, ומאפשר לשחקנים להשתתף במשחק אסטרטגי הכולל ניהול משאבים, מסחר ובנייה. המשחק בנוי באמצעות מחלקות שונות המייצגות את האלמנטים המרכזיים כמו שחקנים, לוח המשחק, משושים, דרכים, יישובים, ערים וקלפי פיתוח. מסמך זה מספק סקירה כללית של הפרויקט, הוראות כיצד לקמפל ולהריץ את המשחק, וכיצד להריץ את בדיקות היחידה הכלולות.

## תכונות

- **ניהול שחקנים**: כל שחקן יכול לנהל משאבים, לבנות דרכים, יישובים וערים, ולהשתמש בקלפי פיתוח.
- **ייצוג לוח המשחק**: הלוח מורכב ממשושים המייצרים משאבים, צמתים שבהם ניתן למקם יישובים וערים, וקצוות שבהם ניתן לבנות דרכים.
- **חלוקת משאבים**: משאבים מחולקים לפי תוצאות זריקת קוביות, והשחקנים יכולים לסחור במשאבים זה עם זה או דרך נמלים.
- **קלפי פיתוח**: קלפי פיתוח שונים מאפשרים לשחקנים להשיג יתרונות, כמו בניית דרכים, השגת נקודות ניצחון, או הזזת השודד.
- **תנאי ניצחון**: המשחק עוקב אחר ההתקדמות של השחקנים לעבר הניצחון, עם תנאים כמו צבירת מספר מסוים של נקודות ניצחון.

## מבנה הפרויקט

- **Catan.hpp / Catan.cpp**: מנהל את מהלך המשחק הכולל, כולל תורות השחקנים, חלוקת משאבים, וקביעת המנצח.
- **Board.hpp / Board.cpp**: מייצג את לוח המשחק, כולל משושים, צמתים, קצוות, נמלים והשודד. מטפל בחלוקת משאבים ובעדכוני מצב המשחק.
- **Player.hpp / Player.cpp**: מנהל את הנתונים של כל שחקן, כולל משאבים, דרכים, יישובים, ערים וקלפי פיתוח. מכיל שיטות לפעולות שחקן כמו זריקת קוביות, בנייה ומסחר.
- **Hexagon.hpp / Hexagon.cpp**: מייצג משושים על הלוח, שמייצרים משאבים בהתאם לזריקות הקוביות. מטפל במיקום השודד.
- **Edge.hpp / Edge.cpp**: מייצ

ג קצוות בין צמתים שבהם ניתן לבנות דרכים.
- **Vertex.hpp / Vertex.cpp**: מייצג צמתים על הלוח שבהם ממוקמים יישובים וערים. מנהל חיבורים לצמתים וקצוות סמוכים.
- **Settlement.hpp / Settlement.cpp**: מייצג יישוב של שחקן על הלוח, שיכול לשדרג בהמשך לעיר.
- **City.hpp / City.cpp**: מייצג עיר, שהיא גרסה משודרגת של יישוב, המספקת יותר משאבים.
- **Road.hpp / Road.cpp**: מייצג דרכים ששחקנים בונים בין צמתים.
- **Port.hpp / Port.cpp**: מייצג נמלים על הלוח, המאפשרים לשחקנים לסחור במשאבים בתנאים מיטביים.
- **DevelopmentCard.hpp / DevelopmentCard.cpp**: מחלקה בסיסית לקלפי הפיתוח עם מחלקות נגזרות המייצגות סוגי קלפים ספציפיים כמו אביר, נקודת ניצחון, בניית דרך, שנת שפע ומונופול.

## התקנה ותלויות

### דרישות מקדימות

כדי לבנות ולהריץ את הפרויקט, תצטרכו את הדברים הבאים:

- מהדר C++ התומך ב-C++11 או מאוחר יותר (לדוגמה, GCC, Clang, MSVC).
- ספריית `doctest` לבדיקות יחידה.

### התקנת `doctest`

ניתן להתקין את `doctest` על ידי הורדת קובץ הכותרת מהמאגר הרשמי והכנסתו לתיקיית הפרויקט שלכם. לחלופין, ניתן להתקין את הספרייה באמצעות מנהל החבילות של המערכת אם הוא זמין.

```bash
# דוגמה למערכות מבוססות אובונטו
sudo apt-get install doctest-dev
```

## קומפילציה

### קומפילציה של המשחק

כדי לקמפל את המשחק הראשי, השתמשו בפקודה הבאה:

```bash
g++ -std=c++11 -o catan_game main.cpp Catan.cpp Board.cpp Player.cpp Hexagon.cpp Edge.cpp Vertex.cpp Settlement.cpp City.cpp Road.cpp Port.cpp DevelopmentCard.cpp -I.
```

פקודה זו מקמפלת את כל קבצי המקור הנדרשים ומקשרת אותם לקובץ הרצה בשם `catan_game`.

### קומפילציה של הבדיקות

כדי לקמפל את בדיקות היחידה, השתמשו בפקודה הבאה:

```bash
g++ -std=c++11 -o tests test_main.cpp Catan.cpp Board.cpp Player.cpp Hexagon.cpp Edge.cpp Vertex.cpp Settlement.cpp City.cpp Road.cpp Port.cpp DevelopmentCard.cpp -I. -ldoctest
```

פקודה זו מקמפלת את חבילת הבדיקות יחד עם קבצי המשחק ומקשרת אותם לקובץ הרצה בשם `tests`.

## הרצת המשחק

לאחר הקומפילציה של הפרויקט, תוכלו להפעיל את המשחק באמצעות הפקודה הבאה:

```bash
./catan_game
```

הפקודה תפעיל את המשחק במסוף, שבו תוכלו לשחק קטאן על ידי ביצוע ההנחיות המופיעות על המסך.

## הרצת הבדיקות

כדי להריץ את בדיקות היחידה, השתמשו בפקודה הבאה:

```bash
./tests
```

חבילת הבדיקות תופעל ותציג את תוצאות כל בדיקה. זה מבטיח שהלוגיקה של המשחק פועלת כראוי ועוזר לזהות באגים או בעיות פוטנציאליות.

## חוקי המשחק והוראות

### כללים בסיסיים

1. **הגדרת המשחק**: כל שחקן מתחיל עם שני יישובים ושתי דרכים הממוקמות על לוח המשחק. השחקנים מתחילים עם משאבים ספציפיים בהתאם למיקום היישובים ההתחלתיים שלהם.
   
2. **תורות**: במהלך תורו של שחקן, הוא זורק שתי קוביות כדי לקבוע אילו משושים ייצרו משאבים. השחקנים אוספים משאבים ממשושים סמוכים ליישובים ולערים שלהם.
   
3. **בנייה**: השחקנים יכולים להשתמש במשאביהם כדי לבנות דרכים, יישובים וערים, או לקנות קלפי פיתוח. בניית יישובים דורשת משאבים ספציפיים, ושדרוג לערים דורש משאבים נוספים.

4. **מסחר**: השחקנים יכולים לסחור במשאבים זה עם זה או להשתמש בנמלים כדי לסחור בתנאים מועדפים.

5. **קלפי פיתוח**: השחקנים יכולים לשחק בקלפי פיתוח כדי להשיג יתרונות, כגון הזזת השודד, קבלת נקודות ניצחון, או בניית דרכים נוספות.

6. **ניצחון במשחק**: השחקן הראשון שמגיע ל-10 נקודות ניצחון מנצח במשחק. נקודות ניצחון נצברות באמצעות בניית יישובים, שדרוג לערים, ושימוש בקלפי פיתוח מסוימים.

### תכונות נוספות

- **השודד**: השודד הוא מנגנון במשחק שיכול לחסום ייצור משאבים על משושה. הוא מוזז כאשר שחקן מגלגל 7 או משחק קלף אביר.

- **הצבא הגדול ביותר**: השחקן שמשחק את מספר קלפי האביר הגדול ביותר יכול לזכות בבונוס הצבא הגדול ביותר, המספק נקודות ניצחון נוספות.

## שיפורים עתידיים

מימוש זה מכסה את הכללים והמכניקות הבסיסיים של קטאן. שיפורים עתידיים עשויים לכלול:

- **ממשק משתמש גרפי (GUI)**: פיתוח ממשק גרפי כדי להפוך את המשחק לידידותי למשתמש וויזואלית מושך יותר.
- **משחק רשת**: אפשרות לשחקנים לשחק אחד נגד השני דרך הרשת.
- **יריבים מבוססי בינה מלאכותית (AI)**: הוספת שחקני AI ברמות קושי שונות כדי לספק אפשרות למשחק יחיד.

## מחבר

הפרויקט הזה פותח על ידי [Your Name]. תרומות, הצעות ודיווחי באגים מתקבלים בברכה. מוזמנים לפתוח דיווח בעיה או להגיש בקשת מיזוג במאגר הפרויקט.

## רישיון

הפרויקט הזה מוגן ברישיון MIT - ראו את קובץ ה-LICENSE לפרטים נוספים.

---

These detailed README files provide in-depth information about the project, including instructions for compiling and running the game, a breakdown of the project's structure, game rules, and future improvement suggestions. If you need further customization or additional sections, feel free to ask!

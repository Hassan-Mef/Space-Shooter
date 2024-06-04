// Console.h
#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

// Forward declaration of Game_Manager
class Game_Manager;

class Console {
    // Declare Game_Manager as a friend of Console
    friend class Game_Manager;

private:
    // Private member
    std::string consoleName = "Game Console";

public:
    // Function to clear the console
    void clearConsole() {
        // This will print 100 newline characters
        for (int i = 0; i < 100; i++)
            std::cout << "\n";
    }
};

#endif // CONSOLE_H

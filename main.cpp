#include "engine/Parser.h"
#include <iostream>

int main()
{
    std::string command;
    std::cout << "Welcome to MiniRelationalDB (type EXIT to quit)\n\n";
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (command == "EXIT")
            break;
        Parser::execute(command);
    }
    return 0;
}
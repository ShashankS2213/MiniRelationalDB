#include "Parser.h"
#include "Table.h"
#include "Utils.h"
#include <sstream>
#include <iostream>
#include <filesystem>

namespace Parser
{
    void execute(const std::string &cmd)
    {
        std::string command = Utils::trim(cmd);
        if (command.find("CREATE TABLE") == 0)
        {
            size_t start = command.find(" ", 13);
            size_t paren = command.find("(");
            std::string name = Utils::trim(command.substr(13, paren - 13));
            std::string colsStr = command.substr(paren + 1, command.find(")") - paren - 1);
            auto cols = Utils::split(colsStr, ',');
            for (auto &col : cols)
                col = Utils::trim(col);
            Table t(name, cols);
            t.saveToFile();
            std::cout << "Table " << name << " created.\n";
        }
        else if (command.find("INSERT INTO") == 0)
        {
            size_t valIdx = command.find("VALUES");
            std::string name = Utils::trim(command.substr(11, valIdx - 11));
            std::string vals = command.substr(command.find("(", valIdx) + 1);
            vals = vals.substr(0, vals.find(")"));
            auto values = Utils::split(vals, ',');
            for (auto &v : values)
                v = Utils::trim(v);
            Table t = Table::loadFromFile(name);
            t.insertRow(values);
        }
        else if (command.find("SELECT * FROM") == 0)
        {
            std::string name = Utils::trim(command.substr(14));
            Table t = Table::loadFromFile(name);
            t.selectAll();
        }
        else
        {
            std::cout << "Invalid command.\n";
        }
    }
}

#include "Table.h"
#include <iostream>
#include <fstream>
#include <filesystem>

Table::Table(const std::string &name, const std::vector<std::string> &cols)
    : tableName(name), columns(cols) {}

void Table::insertRow(const std::vector<std::string> &row)
{
    if (row.size() != columns.size())
    {
        std::cout << "Column count mismatch.\n";
        return;
    }
    rows.push_back(row);
    saveToFile();
    std::cout << "Row inserted.\n";
}

void Table::selectAll() const
{
    for (const auto &col : columns)
        std::cout << col << "\t";
    std::cout << "\n";
    for (const auto &row : rows)
    {
        for (const auto &val : row)
            std::cout << val << "\t";
        std::cout << "\n";
    }
}

void Table::saveToFile() const
{
    std::ofstream out("db/" + tableName + ".tbl");
    for (const auto &col : columns)
        out << col << ",";
    out << "\n";
    for (const auto &row : rows)
    {
        for (const auto &val : row)
            out << val << ",";
        out << "\n";
    }
}

Table Table::loadFromFile(const std::string &name)
{
    std::ifstream in("db/" + name + ".tbl");
    std::string line;
    std::vector<std::string> cols;
    std::vector<std::vector<std::string>> rows;

    if (std::getline(in, line))
    {
        size_t start = 0, end;
        while ((end = line.find(',', start)) != std::string::npos)
        {
            cols.push_back(line.substr(start, end - start));
            start = end + 1;
        }
    }
    while (std::getline(in, line))
    {
        std::vector<std::string> row;
        size_t start = 0, end;
        while ((end = line.find(',', start)) != std::string::npos)
        {
            row.push_back(line.substr(start, end - start));
            start = end + 1;
        }
        rows.push_back(row);
    }
    Table t(name, cols);
    t.insertRow({}); // force init
    t = Table(name, cols);
    t.rows = rows;
    return t;
}
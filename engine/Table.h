#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include <unordered_map>

class Table
{
public:
    Table(const std::string &name, const std::vector<std::string> &columns);
    void insertRow(const std::vector<std::string> &row);
    void selectAll() const;
    void saveToFile() const;
    static Table loadFromFile(const std::string &name);

private:
    std::string tableName;
    std::vector<std::string> columns;
    std::vector<std::vector<std::string>> rows;
};

#endif

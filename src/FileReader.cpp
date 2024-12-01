#include "FileReader.hpp"

HistorianHysteria::FileReader::FileReader(const std::string &fileName)
{
    input.open(fileName);
    if (!input.is_open())
    {
        throw std::runtime_error("Error: could not open file " + fileName);
    }
}

std::vector<std::pair<int, int>> HistorianHysteria::FileReader::readPairs()
{
    std::vector<std::pair<int, int>> pairs;
    std::string line;

    while (std::getline(input, line))
    {
        size_t pos = line.find(' ');
        if (pos == std::string::npos)
        {
            throw std::runtime_error("Error: invalid input file format");
        }

        int num1 = std::stoi(line.substr(0, pos));
        int num2 = std::stoi(line.substr(pos + 1));
        pairs.emplace_back(num1, num2);
    }

    return (pairs);
}

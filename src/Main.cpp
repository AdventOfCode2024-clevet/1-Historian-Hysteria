#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <input>" << std::endl;
        return (1);
    }

    // We need to read the input file
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cerr << "Error: could not open file " << argv[1] << std::endl;
        return (1);
    }

    // Read the input file
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(input, line)) {
        lines.push_back(line);
    }

    // Each line has two numbers, we need to create two separate vectors to store them
    std::vector<int> numbers1;
    std::vector<int> numbers2;

    // Parse the lines
    for (const auto& l : lines) {
        size_t pos = l.find(' ');
        if (pos == std::string::npos) {
            std::cerr << "Error: invalid input file" << std::endl;
            return (1);
        }

        numbers1.push_back(std::stoi(l.substr(0, pos)));
        numbers2.push_back(std::stoi(l.substr(pos + 1)));
    }

    // We need to determine how many times the numbers in the first vector appear in the second vector using a map
    std::map<int, int> count;
    for (const auto& n : numbers1) {
        count[n] = std::count(numbers2.begin(), numbers2.end(), n);
    }

    // Now we need to sum key times value
    int sum = 0;
    for (const auto& c : count) {
        sum += c.first * c.second;
    }

    // Print the result
    std::cout << sum << std::endl;

    return (0);
}

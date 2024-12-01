#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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

    // Now we must order the numbers in ascending order in both vectors
    std::sort(numbers1.begin(), numbers1.end());
    std::sort(numbers2.begin(), numbers2.end());

    // Now we sum the distances between the numbers in both vectors
    int sum = 0;
    for (size_t i = 0; i < numbers1.size(); ++i) {
        sum += std::abs(numbers1[i] - numbers2[i]);
    }

    // Print the result
    std::cout << sum << std::endl;

    return (0);
}

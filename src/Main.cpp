#include <iostream>

#include "ArgumentParser.hpp"
#include "Calculator.hpp"
#include "FileReader.hpp"

int main(int argc, char* argv[]) {
    try {
        HistorianHysteria::ArgumentParser parser(argc, argv);

        HistorianHysteria::FileReader reader(parser.getInputFile());
        auto pairs = reader.readPairs();

        int result = 0;
        switch (parser.getPart()) {
            case 1:
                result = HistorianHysteria::Calculator::calculatePartOne(pairs);
                std::cout << "Result (part 1): " << result << std::endl;
                break;
            case 2:
                result = HistorianHysteria::Calculator::calculatePartTwo(pairs);
                std::cout << "Result (part 2): " << result << std::endl;
                break;
            default:
                throw std::invalid_argument("Error: part must be 1 or 2");
        }
    } catch (const std::exception &ex) {
        std::cerr << ex.what() << std::endl;
        return (1);
    }

    return (0);
}

#pragma once

#ifndef CALCULATOR_HPP
    #define CALCULATOR_HPP

    #include <algorithm>
    #include <map>
    #include <utility>
    #include <vector>

    namespace HistorianHysteria
    {
        class Calculator
        {
            public:
                static int calculatePartOne(const std::vector<std::pair<int, int>> &pairs)
                {
                    std::vector<int> numbers1, numbers2;
                    for (const auto &pair : pairs)
                    {
                        numbers1.push_back(pair.first);
                        numbers2.push_back(pair.second);
                    }

                    std::sort(numbers1.begin(), numbers1.end());
                    std::sort(numbers2.begin(), numbers2.end());

                    int sum = 0;
                    for (size_t i = 0; i < numbers1.size(); ++i)
                    {
                        sum += std::abs(numbers1[i] - numbers2[i]);
                    }
                    return (sum);
                }

                static int calculatePartTwo(const std::vector<std::pair<int, int>> &pairs)
                {
                    std::vector<int> numbers1, numbers2;
                    for (const auto &pair : pairs)
                    {
                        numbers1.push_back(pair.first);
                        numbers2.push_back(pair.second);
                    }

                    std::map<int, int> count;
                    for (const auto &n : numbers1)
                    {
                        count[n] = std::count(numbers2.begin(), numbers2.end(), n);
                    }

                    int sum = 0;
                    for (const auto &c : count)
                    {
                        sum += c.first * c.second;
                    }
                    return (sum);
                }
        };
    }

#endif /* CALCULATOR_HPP */
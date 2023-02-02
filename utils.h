#pragma once
#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& data)
{
    std::cout << "(";
    for(size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i] << ((i == data.size()-1) ? "" : ", ");
    }
    std::cout << ")";
    return os;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<std::vector<T>>& data)
{
    for(size_t j = 0; j < data.size(); ++j) {
        std::cout << "|";
        for(size_t i = 0; i < data[j].size(); ++i) {
            std::cout << data[j][i] << ((i == data[j].size()-1) ? "" : ", ");
        }
        std::cout << "|" << ((j == data.size()-1)? "" : "\n");
    }
    return os;
}
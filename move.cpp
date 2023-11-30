// Move.cpp
#include "move.hpp"
#include <iostream>

int move::getIndex() const {
    //converting char columns to an integer
    int columnIndex = std::toupper(column) - 'A';

    return row * 20 + columnIndex;
}

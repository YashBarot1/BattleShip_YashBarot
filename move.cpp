// Move.cpp
#include "move.hpp"
#include <iostream>

int move::getIndex() const {
    //converting char columns to an integer
    int columnIndex = std::toupper(column) - 'A';

    return (row * 10 + columnIndex) - 10 ;

    /*row * 10 + columnIndex gives me 100 unique indexes from 10 to 119,
    *  (row*10 + columnIndex) - 10 gives me 400 unique indexes from 0 to 99
    */
}

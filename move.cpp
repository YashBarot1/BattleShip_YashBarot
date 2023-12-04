// Move.cpp
#include "move.hpp"
#include <iostream>

int move::getIndex() const {
    //converting char columns to an integer
    int columnIndex = std::toupper(column) - 'A';

    return (row * 20 + columnIndex) - 20 ;

    /*row * 20 + columnIndex gives me 400 unique indexes from 20 to 419,
    *  (row*20 + columnIndex) - 20 gives me 400 unique indexes from 0 to 400
    */
}

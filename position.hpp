#ifndef _POSITION_H
#define _POSITION_H
#include "utils.hpp"
#include <exception>
#include <stdexcept>
#include <cmath>

/**
Class Position: represents one board field.
Fields:
    - column - a colunm symbol (a - h)
    - row - a row number (1 - 8)
Methods:
    - inLine - checks if two positions are in the same row or column
    - inDiagonal - checks if two positions are in the same diagonal
    - inL - checks if two positions create a L-shape (knight's move)
    - isNeighbour - checks if two positions are neighbours
    - isForward - checks if the other position is forward of the current; color dependent
    - toInt - returns an int representation of the field
*/
class Position{
private:
    char column;
    int row;
public:
    Position(const char column_, const int row_);

    bool inLine(const Position& other) const;
    bool inDiagonal(const Position& other) const;
    bool inL(const Position& other) const;
    bool isNeighbour(const Position& other) const;
    bool isForward(const Position& other, const bool color) const;

    bool operator==(const Position& other) const;
    bool operator!=(const Position& other) const;

    int toInt() const;
};

Position::Position(const char column_, const int row_){
    if(column_ < 'a' || column_ > 'h')
        throw std::out_of_range("Only a-h columns are accepted");
    if(row_ < 1 || row_ > 8)
        throw std::out_of_range("Only 1-8 rows are accepted");
    column = column_;
    row = row_;
}


bool Position::inLine(const Position& other) const{
    return (row == other.row || column == other.column);
}

bool Position::inDiagonal(const Position& other) const{
    return (abs(row - other.row) == abs(column - other.column));
}


bool Position::inL(const Position& other) const{
    return(abs(row- other.row) == 2 && abs(column-other.column) == 1) ||
    (abs(row-other.row) == 1 && abs(column-other.column) == 2);
}


bool Position::isNeighbour(const Position& other) const{
    return (abs(row - other.row) <= 1 && abs(column - other.column) <=1 && (*this) != other);
}

bool Position::isForward(const Position& other, const bool color) const{
    return color == WHITE ? other.row >= row : other.row <= row;
}

bool Position::operator==(const Position& other) const{
    return row == other.row && column == other.column;
}

bool Position::operator!=(const Position& other) const{
    return !operator==(other);
}

int Position::toInt() const{
    return (row-1)*8 + int(column - 'a');
}

#endif // _POSITION_H

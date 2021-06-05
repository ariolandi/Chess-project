#ifndef _PIECE_H
#define _PIECE_H
#include "position.hpp"
#include "utils.hpp"


/**
Class Piece: represents one chess piece in the game.
Fields:
    - current position
    - color (black or white)
    - symbol representation (capital letter for the black ones)
Methods:
    - move - virtual method; moves the piece to a new spare board field if this is possible
    - attack - virtual method; moves the piece to a board field with an enemy piece is this is possible
    - get methods for all fields
*/
class Piece{
protected:
    Position position;
    bool color;
    char symbol;
public:
    Piece(const Position& position_, const bool color_, const char symbol_);
    virtual void move(const Position& toPosition) = 0;
    virtual void attack(const Position& toPosition) = 0;
    Position getPosition() const { return position; }
    bool getColor() const { return color; }
    char getSymbol() const { return symbol; }
};

Piece::Piece(const Position& position_, const bool color_, const char symbol_): position(position_){
    color = color_;
    symbol = symbol_;
}

///---------------------------------------

/**
Class Pawn
*/
class Pawn: public Piece{
    public:
        Pawn(const Position& position_, const bool color_):Piece(position_, color_, (color_ == WHITE ? PAWN_WHITE : PAWN_BLACK)){}
        void move(const Position& toPosition);
        void attack(const Position& toPosition);
};


void Pawn::move(const Position& toPosition){
    if(!position.isNeighbour(toPosition) || !position.inLine(toPosition) || !position.isForward(toPosition, color))
        throw std::logic_error("Invalid position");
    position = toPosition;
}

void Pawn::attack(const Position& toPosition){
    if(!position.isNeighbour(toPosition) || !position.inDiagonal(toPosition) || !position.isForward(toPosition, color))
        throw std::logic_error("Invalid position");
    position = toPosition;
}

///---------------------------------------

/**
Class Knight
*/
class Knight: public Piece{
    public:
        Knight(const Position& position_, const bool color_):Piece(position_, color_, (color_ == WHITE ? KNIGHT_WHITE : KNIGHT_BLACK)){}
        void move(const Position& toPosition);
        void attack(const Position& toPosition);
};


void Knight::move(const Position& toPosition){
    if(!position.inL(toPosition))
        throw std::logic_error("Invalid position");
    position = toPosition;
}

void Knight::attack(const Position& toPosition){
    move(toPosition);
}


///---------------------------------------

/**
Class Bishop
*/
class Bishop: public Piece{
    public:
        Bishop(const Position& position_, const bool color_):Piece(position_, color_, (color_ == WHITE ? BISHOP_WHITE : BISHOP_BLACK)){}
        void move(const Position& toPosition);
        void attack(const Position& toPosition);
};


void Bishop::move(const Position& toPosition){
    if(!position.inDiagonal(toPosition))
        throw std::logic_error("Invalid position");
    position = toPosition;
}

void Bishop::attack(const Position& toPosition){
    move(toPosition);
}

///---------------------------------------

/**
Class Rook
*/
class Rook: public Piece{
    public:
        Rook(const Position& position_, const bool color_):Piece(position_, color_, (color_ == WHITE ? ROOK_WHITE : ROOK_BLACK)){}
        void move(const Position& toPosition);
        void attack(const Position& toPosition);
};


void Rook::move(const Position& toPosition){
    if(!position.inLine(toPosition))
        throw std::logic_error("Invalid position");
    position = toPosition;
}

void Rook::attack(const Position& toPosition){
    move(toPosition);
}

///---------------------------------------

/**
Class Queen
*/
class Queen: public Piece{
    public:
        Queen(const Position& position_, const bool color_):Piece(position_, color_, (color_ == WHITE ? QUEEN_WHITE : QUEEN_BLACK)){}
        void move(const Position& toPosition);
        void attack(const Position& toPosition);
};


void Queen::move(const Position& toPosition){
    if(!position.inLine(toPosition) && !position.inDiagonal(toPosition))
        throw std::logic_error("Invalid position");
    position = toPosition;
}

void Queen::attack(const Position& toPosition){
    move(toPosition);
}

///---------------------------------------

/**
Class King
*/
class King: public Piece{
    public:
        King(const Position& position_, const bool color_):Piece(position_, color_, (color_ == WHITE ? KING_WHITE : KING_BLACK)){}
        void move(const Position& toPosition);
        void attack(const Position& toPosition);
};


void King::move(const Position& toPosition){
    if((!position.inLine(toPosition) && !position.inDiagonal(toPosition)) || !position.isNeighbour(toPosition))
        throw std::logic_error("Invalid position");
    position = toPosition;
}

void King::attack(const Position& toPosition){
    move(toPosition);
}

#endif // _PIECE_h

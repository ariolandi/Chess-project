#ifndef _BOARD_H
#define _BOARD_H
#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include "position.hpp"
#include "piece.hpp"
#include "utils.hpp"


class Board{
private:
    std::vector<Piece*> chess_piecess;
public:
    Board();
    void add_piece(Piece* piece);
    bool empty_position(const Position& position) const;
    void move(const Position& from, const Position& to);

    friend std::ostream& operator<<(std::ostream& os, const Board& board);
};

Board::Board(){
    chess_piecess.assign(BOARD_SIZE*BOARD_SIZE, nullptr);
}

void Board::add_piece(Piece* piece){
    Position position = piece->getPosition();
    if(!empty_position(position))
        throw std::logic_error("Not an empty position - cannot add a piece.");
    chess_piecess[position.toInt()] = piece;
}

bool Board::empty_position(const Position& position) const {
    return chess_piecess[position.toInt()] == nullptr;
}

void Board::move(const Position& from, const Position& to){
    if(empty_position(from))
        throw std::logic_error("An empty position - cannot move the piece.");
    Piece* p = chess_piecess[from.toInt()];
    if(!empty_position(to)){
        if(p->getColor() == chess_piecess[to.toInt()]->getColor())
            throw std::logic_error("Cannot move - there is a piece of the same color in this position.");
        p->attack(to);
    } else {
        p->move(to);
    }
    chess_piecess[to.toInt()] = p;
    chess_piecess[from.toInt()] = nullptr;
}


std::ostream& operator<<(std::ostream& os, const Board& board){
    for(int i=0; i<BOARD_SIZE; i++){
        os << i+1 << "| ";
        for(int j=0; j<BOARD_SIZE; j++){
            Piece* p = board.chess_piecess[i*BOARD_SIZE + j];
            os << (p == nullptr ? '.' : p->getSymbol()) << " ";
        }
        os << std::endl;
    }
    os << "   _______________" << std::endl;
    os << "   a b c d e f g h" << std::endl;

    return os;
}

#endif // _BOARD_H

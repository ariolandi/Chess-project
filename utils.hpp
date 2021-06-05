#ifndef _UTILS_H
#define _UTILS_H
#include <string>

const bool WHITE = 0;
const bool BLACK = 1;


const char PAWN_WHITE = 'p';
const char PAWN_BLACK = 'P';
const char KNIGHT_WHITE = 'n';
const char KNIGHT_BLACK = 'N';
const char BISHOP_WHITE = 'b';
const char BISHOP_BLACK = 'B';
const char ROOK_WHITE = 'r';
const char ROOK_BLACK = 'R';
const char QUEEN_WHITE = 'q';
const char QUEEN_BLACK = 'Q';
const char KING_WHITE = 'k';
const char KING_BLACK = 'K';

const int BOARD_SIZE = 8;



bool color(std::string str){
    return str == "white" ? WHITE : BLACK;
}

#endif //_UTILS_H

#ifndef _GAME_H
#define _GAME_H
#include <vector>
#include <iostream>
#include <string>
#include "utils.hpp"
#include "board.hpp"
#include "position.hpp"
#include "piece.hpp"
#include "player.hpp"

class ChessGame{
private:
    Board board;
    Player player1;
    Player player2;
    std::vector<Piece*> pieces;

    void generate_chess_set(const bool color);
public:
    ChessGame(const std::string& p1, const std::string& p2);

    friend std::ostream& operator<<(std::ostream& os, const ChessGame& game);
};

void ChessGame::generate_chess_set(const bool color){
    const int row = (color == WHITE ? 1 : BOARD_SIZE);

    pieces.push_back(new Rook(Position('a', row), color));
    pieces.push_back(new Knight(Position('b', row), color));
    pieces.push_back(new Bishop(Position('c', row), color));
    pieces.push_back(new Queen(Position('d', row), color));
    pieces.push_back(new King(Position('e', row), color));
    pieces.push_back(new Bishop(Position('f', row), color));
    pieces.push_back(new Knight(Position('g', row), color));
    pieces.push_back(new Rook(Position('h', row), color));

    const int second_row = (color == WHITE ? row + 1 : row - 1);
    for(char i='a'; i<='h'; i++){
        pieces.push_back(new Pawn(Position(i, second_row), color));
    }
}

ChessGame::ChessGame(const std::string& p1, const std::string& p2): player1(p1, WHITE), player2(p2, BLACK){
    generate_chess_set(WHITE);
    generate_chess_set(BLACK);
    for(int i=0; i<pieces.size(); i++)
        board.add_piece(pieces[i]);
}

std::ostream& operator<<(std::ostream& os, const ChessGame& game){
    os << game.board << std::endl;
    return os;
}

#endif //_GAME_H

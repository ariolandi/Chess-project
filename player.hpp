#ifndef _PLAYER_H
#define _PLAYER_H
#include <string>

/**
Class PLayer: represents a player in the game of chess.
Fields:
    - nickname
    - color of the pieces (black or white)
Methods:
    - get methods for all fields
*/
class Player{
private:
    std::string nickname;
    bool color;
public:
    Player(const std::string nickname_, const bool color_);
    std::string getNickname() const { return nickname; }
    bool getColor() const { return color; }
};

Player::Player(const std::string nickname_, const bool color_){
    nickname = nickname_;
    color = color_;
}



#endif // _PLAYER_H

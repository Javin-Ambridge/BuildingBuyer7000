#ifndef PLAYER_H
#define PLAYER_H
#include <string>


class Tile;

class Player{
  std::string name;
  std::string piece;
  int money;
  int netWorth;
  bool rollUpCup;
  Tile * pos;
  Tile *properties[];
  public:

    //CTOR
    Player(std::string name, std::string piece);
    //DTOR
    ~Player();

    //getters
    std::string getName();
    std::string getPiece();
    int getMoney();
    int getNetWorth();

    //Player moves
    void roll();
    void displayAssets();
    void bankrupt();

    //Property functions
    void improve(Tile * t);
    void unimprove(Tile * t);
    void mortgage(Tile * t);
    void unmortage(Tile * t);
    bool hasProperty(Tile & t);
    void removeProperty(Tile & t);
    void addProperty(Tile & t);


};

#endif

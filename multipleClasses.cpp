#include <iostream>
#include <string>
#include <bits/unique_ptr.h>

using namespace std;

class Location;
class Piece;

class Coordinate{
  char row;
  int column;
public:
  Coordinate(){};
  Coordinate(char row,int column):row{row},column{column}{};
};


class Piece{
  string name;
  unique_ptr<Location> l;
public:
  Piece(){}
  Piece(string name):name{name}{}
  string toString() const;
};

class Location{
  Coordinate *coordinate;
  Piece *piece;
public:
  Location();
  Location(Coordinate& c, Piece& p):coordinate{&c},piece{&p}{}
};

string Piece::toString() const{
  return name;
}


  
int main(int argc,char **argv){

  Coordinate* coordinate=new Coordinate{'a',3};
  Piece* piece=new Piece{"pieCeName"};
  
  Location l{*coordinate,*piece};
  return 0;

}

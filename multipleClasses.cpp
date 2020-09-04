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
  Coordinate(char row,int column);
};


class Piece{
  string name;
  unique_ptr<Location> l;
public:
  Piece(string name);
  string toString() const;
};

class Location{
  Coordinate c;
  Piece p;
};

Piece::Piece(string name){
  this->name=name;
}

string Piece::toString() const{
  return name;
}


  
int main(int argc,char **argv){

  return 0;

}

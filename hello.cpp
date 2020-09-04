#include <iostream>
#include <string>
#include <bits/unique_ptr.h>

using namespace std;

class Piece{
  string name;
public:
  Piece(string name);
  string toString() const;
};

Piece::Piece(string name){
  this->name=name;
}

string Piece::toString() const{
  return name;
}
  
int main(int argc,char **argv){

  string s;

  while(true){
    cout << "Enter Text:";
    cin >> s;
    cout << s + '\n';
    Piece p {s};
    cout << "Piece: " << p.toString() << '\n';

    unique_ptr<Piece> piece_ptr{new Piece{s}};
    cout << "PiecePointer: " << piece_ptr->toString() << '\n';
  }
  
  return 0;
}

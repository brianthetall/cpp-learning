#include <iostream>

using namespace std;

class tea{
  string teaType;
  
public:

  tea(string name):teaType{name}{}
  ~tea(){}
  string getType(){return teaType;}

  friend ostream &operator<<(ostream& stream,tea& t){
    stream << t.getType();
    return stream;
  }
  
};

int main(void){

  tea gt{"green"};
  tea bt{"black"};

  cout << gt << endl;
  cout << bt << endl;

  return 0;
}

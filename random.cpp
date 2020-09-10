#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

class Vect{
  double *elem;
  int elements;
  std::string str;
public:
  //Vect(){};
  Vect(int s,std::string st);
  double& operator[](int i);
  int size() const;
};


Vect::Vect(int s=0,std::string st=""):elements{s},str{st}{}

double& Vect::operator[](int i){ return elem[i]; }
int Vect::size() const{ return elements; }

int main(){
  Vect v{10};
  string s="asdf";
  if("asdf"==s)
    cout<<"easy string compare\a\n";

  while(true){
    cout<<".\a"<<endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  
  return 0;
}

#include <iostream>

using namespace std;

int main(void){

  cout << "Content-type:text/html\r\n\r\n";
  cout<<"<html><head><title>C++ from CGI</title></head>"<<endl;
  cout<<"<body><h1>Hello from C++</h1>";
  cout<<"<br>LoadModule cgid_module libexec/apache24/mod_cgid.so"<<endl;
  cout<<"</body></html>"<<endl;
  
  return 0;
}

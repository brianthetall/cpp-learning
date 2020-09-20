#include "ezSql.h"

using namespace std;

int main (){

  EzSql sql{"user","passwd"};
  string input{""};
  
  sql.createDb("opc");

  cout<<"Ready to drop table?"<<endl;
  cin>>input;

  sql.dropDb("opc");
  
  sql.close();
  
  return 0;
}

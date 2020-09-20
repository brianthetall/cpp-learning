#include "ezSql.h"

using namespace std;

int main (){

  EzSql sql{"user","passwd"};
  string input{""};
  
  sql.createDb("hat");

  cout<<"Ready to drop table?"<<endl;
  cin>>input;

  sql.dropDb("hat");
  
  sql.close();
  
  return 0;
}

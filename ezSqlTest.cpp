#include "ezSql.h"

using namespace std;

int main (){

  EzSql sql{"user","passwd"};
  string input{""};
  
  sql.createDb("opc");
  cout<<sql.status()<<endl;
  sql.createTable("opc","partsTable");
  sql.insertJsonFile("ezSql.json");
  cout<<sql.selectElement("rtd0")<<endl;
  cout<<sql.selectElement("vfd0")<<endl;
  cout<<sql.selectElement("levelSensor0")<<endl;

  cout<<"Ready to drop table?"<<endl;
  cin>>input;

  sql.dropTable("partsTable");

  cout<<"Ready to drop DB opc?"<<endl;
  cin>>input;

  sql.dropDb("opc");
  
  sql.close();
  
  return 0;
}

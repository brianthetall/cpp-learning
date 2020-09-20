#include "ezSql.h"

void EzSql::createDb(string dbName){
  
  stringstream ss{""};
  ss<<"CREATE DATABASE "<<dbName;
  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }
}

void EzSql::dropDb(string dbName){
  
  stringstream ss{""};
  ss<<"DROP DATABASE "<<dbName;
  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }
}

void EzSql::close(void){
  mysql_close(connector);
}

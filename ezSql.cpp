#include "ezSql.h"

void EzSql::createDb(string dbName){

  verifyConnection();
  stringstream ss{""};
  ss<<"CREATE DATABASE "<<dbName;
  cout<<ss.str().data()<<endl;
  if (mysql_query(connector, ss.str().data() )){
    cout<<mysql_error(connector)<<endl;
  }
}

void EzSql::dropDb(string dbName){

  verifyConnection();
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

string EzSql::status(void){
  string retval{ mysql_stat(connector) };
  return retval;
}

void EzSql::verifyConnection(void){
  //ping the db, if fail, reconnect
  if(mysql_ping(connector))
    mariadb_reconnect(connector);
}

/*

https://mariadb.com/kb/en/mysql_query/

*/

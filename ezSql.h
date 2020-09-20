#include <mariadb/mysql.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class EzSql{

  MYSQL *connector;
  string user,passwd;

 public:
  EzSql(string username,string password):user{username},passwd{password}{

    connector = mysql_init(NULL);

    if (connector == NULL){
      cout<<mysql_error(connector)<<endl;
    }

    if (mysql_real_connect(connector, "localhost", "user", "passwd", NULL, 0, NULL, 0) == NULL) {
      cout<<mysql_error(connector)<<endl;
      mysql_close(connector);
    }  

  };

  void createDb(string dbName);
  void dropDb(string dbName);
  void close(void);

};

#include <httplib.h>
#include <iostream>
#include <string>
#include <memory>

#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

namespace influx{

  class InfluxConnector{

    string address;
    int port;
    unique_ptr<httplib::Client> client;

  public:

    InfluxConnector(string addr,int port):address{addr},port{port}{
      client=unique_ptr<httplib::Client>(new httplib::Client{addr,port});
      
    }
    ~InfluxConnector(){}
    
    int createDatabase(string name);
    int dropDatabase(string name);
    

  };

};

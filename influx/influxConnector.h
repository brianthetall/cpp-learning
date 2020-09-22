#include <httplib.h>
#include <iostream>
#include <string>

#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

namespace influx{

  class InfluxConnector{

    string address;
    int port;
    httplib::Client client;

  public:

    InfluxConnector(string addr,int port):address{addr},this->port{port}{
      client=httplib::Client{addr,port};
      
    }
    ~InfluxConnector(){}
    
    int createDatabase(string name);
    int dropDatabase(string name);
    

  };

};

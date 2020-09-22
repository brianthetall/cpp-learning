#include <httplib.h>
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <utility>

#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

namespace influx{

  class InfluxConnector{

    string address;
    int port;
    unique_ptr<httplib::Client> client;

  public:

    InfluxConnector(string addr,int port):address{addr},port{port}{
      client=unique_ptr<httplib::Client>(new httplib::Client{addr,this->port});
      
    }
    ~InfluxConnector(){}
    
    int createDatabase(string name);
    int dropDatabase(string name);
    //set retention policy

    //write to database
    template <typename T>
    int write(const string db,const string measurement,const T data){

      int returnCode;
      string cmd="/write?db="+db;
      stringstream ss{""};
      ss<<measurement<<",value="<<data;

      try{
	auto res=client->Post(cmd.data(),ss.str(),"application/octet-stream");
	cout << res->status << endl;
	cout << res->get_header_value("Content-Type") << endl;
	cout << res->body << endl;
	returnCode=res->status;
    
      }catch(...){
	cout<<"Error Writing to Database: "<<endl;
	return 1;
      }
  
      return returnCode;

    }

  };

};

#include <httplib.h>
#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <utility>
#include <map>

#define CA_CERT_FILE "./ca-bundle.crt"

using namespace std;

namespace influx{

  enum class Units{HOUR,DAY};

  class InfluxConnector{

  private:
    
    string address;
    int port;
    unique_ptr<httplib::Client> client;

    bool pingConnection(void);//true if connected
    void reconnect(void);

    
  public:

    InfluxConnector(string addr,int port):address{addr},port{port}{
      client=unique_ptr<httplib::Client>(new httplib::Client{addr,this->port});
      
    }
    ~InfluxConnector(){}
    
    int createDatabase(string name,int duration,Units unit,string policyName);
    int dropDatabase(string name);
    void ensureConnection(void);

    //-----------------write to database--------------------------
    template <typename T>
    int write(const string db,const string measurement,const map<string,string> metadata,const T data){

      int returnCode;
      string cmd="/write?db="+db;
      stringstream ss{""};
      ss<<measurement;
      for(auto& param : metadata){
	ss<<","<<param.first<<"="<<param.second;
      }
      ss<<" value="<<data;

      try{
	ensureConnection();
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
    //------------end write to database--------------------------

  };

};

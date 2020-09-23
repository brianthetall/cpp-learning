#include <influxConnector.h>

//curl -i -XPOST http://localhost:8086/query --data-urlencode "q=CREATE DATABASE mydb"
int influx::InfluxConnector::createDatabase(string name,int duration,Units unit,string policyName){

  int returnCode;
  stringstream ss{""};
  ss<<"CREATE DATABASE "<<name<<" WITH DURATION "<<duration;
  if(unit==Units::HOUR)
    ss<<"h ";
  else
    ss<<"d ";
  
  ss<<"name "<<policyName;
  string command=ss.str();
  httplib::Params p;
  p.emplace("q" , command);
  try{
    ensureConnection();
    auto res=client->Post("/query",p);
    cout << res->status << endl;
    cout << res->get_header_value("Content-Type") << endl;
    cout << res->body << endl;
    returnCode=res->status;
    
  }catch(...){
    cout<<"Error Creating Database: "<<name<<endl;
    return 1;
  }
  
  return returnCode;//return the http success code
}
//CREATE DATABASE "bar" WITH DURATION 1d NAME "myrp"

int influx::InfluxConnector::dropDatabase(string name){

  int returnCode;
  string command="DROP DATABASE "+name;
  httplib::Params p;
  p.emplace("q" , command);
  try{
    ensureConnection();
    auto res=client->Post("/query",p);
    cout << res->status << endl;
    cout << res->get_header_value("Content-Type") << endl;
    cout << res->body << endl;
    returnCode=res->status;
    
  }catch(...){
    cout<<"Error Dropping Database: "<<name<<endl;
    return 1;
  }
  
  return returnCode;
  
}

bool influx::InfluxConnector::pingConnection(void){

  try{
    
    auto res=client->Get("/ping");
    if(res==nullptr)
      return false;
    
    return true;
    
  }catch(...){
    cout<<"Error Pinging Influx Connection."<<endl;
    return false;
  }
  
  return false;
}

inline void influx::InfluxConnector::reconnect(void){
  client=unique_ptr<httplib::Client>(new httplib::Client{address,port});
}

void influx::InfluxConnector::ensureConnection(void){
    while(!pingConnection()){//see if server is still up
    cout<<"Attempting Reconnection"<<endl;
    reconnect();//reconnect
  }
}

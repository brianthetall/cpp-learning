#include <influxConnector.h>

int influx::InfluxConnector::createDatabase(string name){

  string command="CREATE DATABASE "+name;
  httplib::Params p;
  p.emplace("q" , command);
  try{
    auto res=client->Post("/query",p);
    cout << res->status << endl;
    cout << res->get_header_value("Content-Type") << endl;
    cout << res->body << endl;
    
  }catch(...){
    cout<<"Error Creating Database: "<<name<<endl;
    return 1;
  }
  
  return 0;
}

int influx::InfluxConnector::dropDatabase(string name){

  string command="DROP DATABASE "+name;
  httplib::Params p;
  p.emplace("q" , command);
  try{
    auto res=client->Post("/query",p);
    cout << res->status << endl;
    cout << res->get_header_value("Content-Type") << endl;
    cout << res->body << endl;
    
  }catch(...){
    cout<<"Error Dropping Database: "<<name<<endl;
    return 1;
  }
  
  return 0;
  
}

//InfluxConnector::

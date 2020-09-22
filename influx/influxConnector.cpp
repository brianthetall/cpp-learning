#include <influxConnector.h>

int InfluxConnector::createDatabase(string name){

  string command="CREATE DATABASE "+name;
  httplib::Params p;
  p.emplace("q" , command);
  try{
    auto res=client.Post("/query",p);
    cout << result->status << endl;
    cout << result->get_header_value("Content-Type") << endl;
    cout << result->body << endl;
    
  }catch(...){
    cout<<"Error Creating Database: "<<name<<endl;
    return 1;
  }
  
  return 0;
}

int InfluxConnector::dropDatabase(string name){
  
}

//InfluxConnector::

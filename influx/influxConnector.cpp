#include <influxConnector.h>

//curl -i -XPOST http://localhost:8086/query --data-urlencode "q=CREATE DATABASE mydb"
int influx::InfluxConnector::createDatabase(string name){

  int returnCode;
  string command="CREATE DATABASE "+name;
  httplib::Params p;
  p.emplace("q" , command);
  try{
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

int influx::InfluxConnector::dropDatabase(string name){

  int returnCode;
  string command="DROP DATABASE "+name;
  httplib::Params p;
  p.emplace("q" , command);
  try{
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

/*
curl -i -XPOST 'http://localhost:8086/write?db=mydb' --data-binary 'cpu_load_short,host=server01,region=us-west value=0.64 1434055562000000000'

res = cli.Post("/person", "name=john1&note=coder", "application/x-www-form-urlencoded");
"application/octet-stream" 
*/

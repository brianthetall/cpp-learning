#include <iostream>
#include <utility>
#include <map>
#include <influxConnector.h>

using namespace std;

int main(int argc,char **argv){

  string serverAddress,input;
  int port;
  
  if ( argc == 2 ){
    port=8086;
    serverAddress=*++argv;
  }else if ( argc == 3 ){
    serverAddress=*++argv;
    port = atoi ( *++argv );
  }else{
    cout << "address [port]" << endl;
    return -1;
  }
  
  influx::InfluxConnector con{serverAddress,port};
  con.createDatabase("generatedDB",1,influx::Units::DAY,"oneDay");
  
  //add some things
  map<string,string> params{
			    {"one","1"},
			    {"two","2"}
  };
  con.write("generatedDB","levelSensor",params,100);
  con.write("generatedDB","temperatureSensor",params,69);

  
  cout<<"Press any key to drop DB"<<endl;
  cin>>input;

  con.dropDatabase("generatedDB");
  
  return 0;
}

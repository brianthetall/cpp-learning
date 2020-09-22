#include <iostream>
#include <utility>
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
  con.createDatabase("generatedDB");


  //  con.f("generatedDB","shit",69);
  
  
  //add some things
  //pair<string,string> pair1{string{"levelSensor"},string{"high"}};
  con.write<string>(string{"generatedDB"},string{"levelSensor"},string{"high"});
  
  //pair<string,int> pair2={string{"temperatureSensor"},int{69}};
  con.write<int>(string{"generatedDB"},string{"temperatureSensor"},int{69});
  
  cout<<"Press any key to drop DB"<<endl;
  cin>>input;

  con.dropDatabase("generatedDB");
  
  return 0;
}

#include <iostream>
#include "mySocket.h"

#define BUFFER 100

using namespace std;

int main(int argc,char **argv){

  MySocket socket;
  Type type;
  string sendString{""};
  
  if ( argc == 3 ){//ip,port,bufferSize
    //setup as client
    type=Type::CLIENT;
    string ip{ *++argv };
    int port = atoi( *++argv );
    socket=MySocket{ ip,port,BUFFER };
    
  }
  else if ( argc == 2 ){//port,bufferSize
    //setup as server
    type=Type::SERVER;
    int port = atoi( *++argv );
    socket=MySocket{ port,BUFFER };
    
  }

  if (type == Type::SERVER){

    while(true){
      cout<<socket.readString()<<endl;
      getline(cin,sendString);
      socket.sendString(sendString);
    }

  }

  if (type == Type::CLIENT){
  
    while(true){
      getline(cin,sendString);
      socket.sendString(sendString);
      cout<<socket.readString()<<endl;
    }

  }

  return 0;

}

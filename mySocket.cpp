#include <iostream>
#include "mySocket.h"

#define BUFFER 1024

using namespace std;

int main(int argc,char **argv){

  MySocket socket;
  Type type;
  string sendString{""};
  
  if ( argc == 3 ){//ip,port
    //setup as client
    type=Type::CLIENT;
    string ip{ *++argv };
    int port = atoi( *++argv );
    socket=MySocket{ ip,port,BUFFER };
    
  }
  else if ( argc == 2 ){//port
    //setup as server
    type=Type::SERVER;
    int port = atoi( *++argv );
    socket=MySocket{ port,BUFFER };
    
  }

  if (type == Type::SERVER){

    while(true){
      cout<<socket.readString()<<endl;
      cin>>sendString;
      socket.sendString(sendString);
    }

  }

  if (type == Type::CLIENT){
  
    while(true){
      cin>>sendString;
      socket.sendString(sendString);
      cout<<socket.readString()<<endl;
    }

  }

  return 0;

}

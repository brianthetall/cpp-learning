#include <iostream>
#include <vector>  
#include <string>  
#include <stdio.h>  
#include <stdlib.h> 
#include <fstream>
#include <sstream>

#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  

using namespace std;
using namespace cgicc;

int main () {

  stringstream ss{""};

  ifstream dropdown;
  dropdown.open("/usr/home/user/gitRepos/cpp-learning/cgi/dropdown.html");
  string line;

  ofstream log;
  log.open("/home/user/logs/log");
  
  Cgicc formData;
  
  cout << "Content-type:text/html\r\n\r\n";
  cout << "<html>\n";
  cout << "<head>\n";
  cout << "<title>Using GET and POST Methods</title>\n";
  cout << "</head>\n";
  cout << "<body>\n";

  while(getline(dropdown,line)){
    log << line<<endl;
    cout << line;
  }

   form_iterator fi = formData.getElement("startRow");  
   if( !fi->isEmpty() && fi != (*formData).end()) {  
     //cout << "Start Row: " << **fi << endl;
     ss<<**fi;
   }
   
   fi = formData.getElement("startCol");  
   if( !fi->isEmpty() &&fi != (*formData).end()) {  
     //cout << "Start Column: " << **fi << endl;
     ss<<**fi;
   }
   ss<<",";
   fi = formData.getElement("destRow");  
   if( !fi->isEmpty() &&fi != (*formData).end()) {  
     //cout << "Destination Row: " << **fi << endl;
     ss<<**fi;
   }

   fi = formData.getElement("destCol");  
   if( !fi->isEmpty() &&fi != (*formData).end()) {  
     //cout << "Destination Column: " << **fi << endl;
     ss<<**fi;
   }

   log << ss.str()<<endl;
   cout<<"<br>";
   cout<<"Coordinates: "<<ss.str()<<endl;
   
   cout << "<br/>\n";
   cout << "</body>\n";
   cout << "</html>\n";

   log.close();
   return 0;
}

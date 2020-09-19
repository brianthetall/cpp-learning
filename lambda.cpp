#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

  vector<double> vd{1.0,3.3,88.3,66.};
  for_each(vd.begin(),vd.end(),
	   [](double& d){ cout << d++ << endl; }
	   );

  for(auto d : vd)
    cout << d << endl;
	     


  return 0;
}

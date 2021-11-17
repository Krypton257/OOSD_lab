//code just to extracting string from input file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () 
{
  string str;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    getline (myfile,str);
    myfile.close();
  }

  int n = str.length();
  
  cout<<str<<endl;

  return 0;
}
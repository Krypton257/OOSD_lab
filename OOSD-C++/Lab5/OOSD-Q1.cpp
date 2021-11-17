//Code to eliminate spaces in the string

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print_without_spaces(string str)
{
    int n=str.length();
    for (int i = 0; i<n; i++){
        if (str[i] == ' '){
            while(str[i]==' '){
              i++;
            }
        }
          cout<<str[i];
    }
}
 
int main () 
{
  string str;
  int i,j,end=0;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    getline (myfile,str);
    myfile.close();
  }

  int n=str.length();

  print_without_spaces(str);

  return 0;
}
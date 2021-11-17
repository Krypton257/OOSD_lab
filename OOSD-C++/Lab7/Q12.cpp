// not complete code as per question
// code for segregating terms 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () 
{
  string str;
  ifstream myfile ("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input.txt");
  if (myfile.is_open())
  {
    getline (myfile,str);
    myfile.close();
  }
  
  cout<<endl;
  cout<<"Original Expression - "<<str<<endl;

  int n = str.length();
  int r,l;

  for(int i=0;i<n;i++){
    if(str[i]=='('){
        cout<<endl;
        r=i+1;
        while(str[i]!=')'){
          i++;
        }
        l=i-1;
        for(int k=r;k<=l;k++){
          cout<<str[k];
        }
        if(str[i+1]!='(')
          cout<<endl;
    }
    else
    cout<<str[i];
  }

  cout<<endl;

  return 0;
}
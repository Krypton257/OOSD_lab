//code to simplifying expression and getting final string for further operations

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
   cout<<endl;
   cout<<"Original Expression - "<<str<<endl;

  int n = str.length();
  int r,l,x;
  string str1;

  for(int i=0;i<n;i++){
    if(str[i]=='('){
        cout<<endl;
        r=i+1;
        while(str[i]!=')'){
          i++;
        }
        l=i-1;

        str1=str.substr(r,l);

        for(int k=r;k<=l;k++){
          //cout<<str[k];
        }
          //cout<<endl;
    }
    if(str[i]=='^'){
      i=i+2;
      x=0;
               while(str[i] !=')') {
                x = 10*x + str[i]-'0';
                i++;
              }
              //cout<<x<<endl;
    }
  }
  string str2;      //new string that will be used for further work

  while(x--){
       str2 += "(";
       str2 += str1;
       str2 += ")";
  }
  cout<<"Simplified expression - "<<str2<<endl;

  return 0;
}
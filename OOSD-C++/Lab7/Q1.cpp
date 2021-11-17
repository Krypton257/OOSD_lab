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

  cout<<"Simplified Expression - ";

  for(int i=2;i<n;i++){
    
    while(str[i]!=')'){

      int arr[26]={0};
      int z = str[0]-'a';
      arr[z]++;

      if(str[i]!='+'  &&  str[i]!='^'  &&  str[i]!='*'  &&  str[i]!='-'){
        int x = str[i]-'a';
        arr[x]++;
          
          for(int j=0; j<26; j++) {
            if (arr[j]){
            cout << (char)('a'+j);
            if (arr[j] > 1) 
              cout << "^(" << arr[j] << ")";
        }
    }

      i++;

      }
      else{
        cout<<str[i];
        i++;
      }

    }

  }

  cout<<endl;

  return 0;
}
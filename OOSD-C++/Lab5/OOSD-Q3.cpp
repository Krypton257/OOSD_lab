#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

  int arr[27];

int main () 
{
  string str;
  int i,j,end=0;
  ifstream myfile ("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input.txt");
  if (myfile.is_open())
  {
    getline (myfile,str);
    myfile.close();
  }
  int n = str.length();

  for(int i=0;i<n;i++){

    if(str[i]=='a')
      arr[1]++;
    else if(str[i]=='b')
      arr[2]++;
    else if(str[i]=='c')
      arr[3]++;
    else if(str[i]=='d')
      arr[4]++;
    else if(str[i]=='e')
      arr[5]++;
    else if(str[i]=='f')
      arr[6]++;
    else if(str[i]=='g')
      arr[7]++;
    else if(str[i]=='h')
      arr[8]++;
    else if(str[i]=='i')
      arr[9]++;
    else if(str[i]=='j')
      arr[10]++;
    else if(str[i]=='k')
      arr[11]++;
    else if(str[i]=='l')
      arr[12]++;
    else if(str[i]=='m')
      arr[13]++;
    else if(str[i]=='n')
      arr[14]++;
    else if(str[i]=='o')
      arr[15]++;
    else if(str[i]=='p')
      arr[16]++;
    else if(str[i]=='q')
      arr[17]++;
    else if(str[i]=='r')
      arr[18]++;
    else if(str[i]=='s')
      arr[19]++;
    else if(str[i]=='t')
      arr[20]++;
    else if(str[i]=='u')
      arr[21]++;
    else if(str[i]=='v')
      arr[22]++;
    else if(str[i]=='w')
      arr[23]++;
    else if(str[i]=='x')
      arr[24]++;
    else if(str[i]=='y')
      arr[25]++;
    else if(str[i]=='z')
      arr[26]++;
  }
  for(int i=1;i<27;i++){
    if(arr[i]!=0){
      char temp= 'a'+i-1;
      cout<<temp<<"^("<<arr[i]<<")";
    }
  }
  cout<<endl;
  return 0;
}
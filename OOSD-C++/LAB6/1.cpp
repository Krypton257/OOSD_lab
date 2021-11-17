#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

void expr(string s){

    int cnt[26]={0};

    int val = 0, n = s.size();  

    for(int i=0; i<n;i++){
        val = 1;
        int ind = s[i] - 'a';
        if (i+1 < n && s[i+1] == '^') {
            string num = "";
            i+=3;
            int x=0;
               while(s[i] !=')') 
                  {x = 10*x + s[i]-'0';i++;}
            val += x - 1;
        }
        cnt[ind] += val;
    }
    
    for(int i=0; i<26; i++) {
        if (cnt[i]){
            cout << (char)('a'+i);
            if (cnt[i] > 1) cout << "^(" << cnt[i] << ")";
        }
    } cout << "\n";

}
int main () 
{
  string s;
  int i,j;
  ifstream myfile ("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input.txt");
  if (myfile.is_open())
  {
    getline (myfile,s);

    myfile.close();
  }

  i=0;

  while(i<s.length()){
    for(int j=i;j<s.length();j++){
        if(s[j]=='+' || s[j]=='-' || s[j]=='*' || s[j]=='/'){
            string a = s.substr(i,j-1);
            expr(a);
        }
    }
    i += j+1;
  }
    
    return 0;
}
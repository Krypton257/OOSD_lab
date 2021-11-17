//code for multiplication when coefficients are positive

#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

string str;
int mul=1;

void expr(string s){

    int cnt[26]={0};

    int val = 0,val1 ,sum1=0, n = s.size();  

    for(int i=0;i<s.length();i++){
        val1 = 0;
        if(i==0){
            while(s[i]>='0' && s[i]<='9'){
                int x = s[i]-'0';
                sum1 = 10*sum1 + x;
                val1++;
                i++;
            }
        }
    }

    cout<<"coefficient = "<<"{"<<sum1<<"}"<<endl;
    mul *= sum1;

    for(int i=val1; i<n;i++){
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

   // for(int i=0;i<cnt)

}
int main () 
{
  string s,s1;
  int i,j,sum1=0,sum2=0;
  ifstream myfile ("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input.txt");
  if (myfile.is_open())
  {
    getline (myfile,s);
    getline (myfile,s1);
    myfile.close();
  }
    cout<<s<<endl;
    cout<<s1<<endl;
    expr(s);
    expr(s1);

   

    cout<<"Multiplied Final exp ="<<mul<<endl;

    return 0;
}
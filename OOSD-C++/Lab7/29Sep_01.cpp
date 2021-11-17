//Roll No:- 19MA20016
//Name :- Gaurav Jain
//NOT CONSIDERING "/" AS AN OPERATOR BECAUSE IT WAS QUESTION STATED ONLY +,-,*,^ 
//AS SAID IN CLASS BY SIR ALL POWER FUNCTIONS SHOULD BE PROVIDED IN BRACKETS
//Lexicographic sort was no clear on coefficient based sorting so if coefficient based sorting is required decomment the code in compare function.
#include <iostream>

#include <fstream>
#include <string>
using namespace std;

int string_length(string s) {
   int c = 0;
   while (s[c] != '\0')
      c++;

   return c;
}

int power_add(string s,int j)
{
    int power=0;
    bool flag=0;
    if(s[j]=='-')
    {
        j++;
        flag=1;
    }
    while(s[j]!=')')
    {
        
        power *= 10;
        power+=s[j]-'0';
        j++;
    }
    if(flag) power*=-1;
    return power;
}

string sorted_power(string a)
{
    int i = 0, power, n, frequency[26] = {0};
    char c;
    string answer;

    n = string_length(a);
    while(i < n)
    {
        c = a[i];
        
        power = 1;
        if(i < n)
        {
            if(a[i]=='(')
            {
                
                i++;
                string b;
                while(a[i]!=')')
                {
                    b.push_back(a[i]);
                    i++;
                }
                i++;
                if(a[i] == '^')
                {
                    i += 2;
                    power=power_add(a,i);
                    
                    while(a[i]!=')') i++;
                }
                for(int k=0;k<string_length(b);k++)
                {
                    frequency[b[k]-'a']+=power;
                }
                continue;

            }
            i++;
            if(a[i] == '^')
            {
                i += 2;
                cout<<i;
                power=power_add(a,i);
                while(a[i]!=')') i++;
            }
            
        }
        frequency[c-'a'] += power;
        
    }
    for (i = 0; i < 26; i++)
    {
        if(frequency[i] != 0)
        {
            c = 'a' + i;
            answer = answer + c;
            if (frequency[i] != 1)
            {
                answer = answer + "^(";
                int t = frequency[i];
                string number;
                int flag = 0;
                while(t != 0)
                {
                    if(t < 0)
                    {
                        t *= -1;
                        flag = 1;
                    }
                    number = (char)(t%10 + '0') + number;
                    t /= 10;
                }
                if(flag) number = '-' + number;
                answer = answer + number + ')';
            }
        }
    }
    return answer;
}

void product(string a,string a1)
{
    int fa[27]={0},fa1[27]={0};
    if(a[0]=='-') fa[26]=1;
    if(a1[0]=='-') fa1[26]=1;
    int n = string_length(a),power,i=0;
    char c;
    while(i < n)
    {
        c = a[i];
        power = 1;
        if(i < n)
        {
            if(a[i]=='(')
            {
                
                i++;
                string b;
                while(a[i]!=')')
                {
                    b.push_back(a[i]);
                    i++;
                }
                i++;
                if(a[i] == '^')
                {
                    i += 2;
                    power=power_add(a,i);
                    
                    while(a[i]!=')') i++;
                }
                for(int k=0;k<string_length(b);k++)
                {
                    fa[b[k]-'a']+=power;
                }
                continue;
            }
            i++;
            if(a[i] == '^')
            {
                i += 2;
                power=power_add(a,i);
                while(a[i]!=')') i++;
            }   
        }
        fa[c-'a'] += power;
    }
    n = string_length(a1);i=0;
    while(i < n)
    {
        c = a1[i];
        power = 1;
        if(i < n)
        {
            if(a1[i]=='(')
            {
                
                i++;
                string b1;
                while(a1[i]!=')')
                {
                    b1.push_back(a1[i]);
                    i++;
                }
                i++;
                if(a1[i] == '^')
                {
                    i += 2;
                    power=power_add(a1,i);
                    while(a1[i]!=')') i++;
                }
                for(int k=0;k<string_length(b1);k++)
                {
                    fa1[b1[k]-'a']+=power;
                }
                continue;
            }
            i++;
            if(a1[i] == '^')
            {
                i += 2;
                power=power_add(a1,i);
                while(a1[i]!=')') i++;
            }            
        }
        fa1[c-'a'] += power; 
    }
    for(i=0;i<27;i++)
    {
        fa[i]+=fa1[i];
    }
    fa[26]%=2;
    
    string answer;
    for (i = 0; i < 26; i++)
    {
        if(fa[i] != 0)
        {
            c = 'a' + i;
            answer = answer + c;
            if (fa[i] != 1 )
            {
                answer = answer + "^(";
                int t = fa[i];
                string number;
                int flag = 0;
                
                while(t != 0)
                {
                    if(t < 0)
                    {
                        t *= -1;
                        flag = 1;
                    }
                    number = (char)(t%10 + '0') + number;
                    t /= 10;
                }
                if(flag) number = '-' + number;
                answer = answer + number + ')';
            }
        }
    }
    //
    int x=0,y=0,j=0;
    //cout<<x;
    while(j<string_length(a))
    {
        //cout<<"hi\n";
        if(a[j]=='-') {j++;continue;}
        else if((a[j]-'0')>=0 && a[j]-'0'<10)
        {
            x+=int(a[j]-'0');
            x*=10;
        }
        else break;
        j++;
        
    }
    x/=10;
    j=0;
    while(j<string_length(a1))
    {
        if(a1[j]=='-') {j++;continue;}
        else if(a1[j]-'0'>=0 && a1[j]-'0'<10)
        {
            y+=int(a1[j]-'0');
            y*=10;
        }
        else break;
        j++;
    }
    y/=10;
    if(x && y) x*=y;
    else if(y) x=y;
    if(fa[26]) cout<<'-';
    if(x!=1) cout<<x; 
    cout<<answer;
}

int freq(string a,string b)
{
    int ans=0;
    int i=0;
    while(i<string_length(a))
    {
        if(a[i]==b[0])
        {
            int j=0;
            while(a[i+j]==b[j]) j++;
            if(j==string_length(b))
            {
                int k=i,temp=0;
                k--;
                while(a[k]=='-' || (a[k]-'0'>=0 && a[k]-'0'<10))
                {
                    temp+=int(a[k]-'0');
                    temp*=10;
                    if(k=='-') {temp*=-1; break;}
                    k--;
                }
                temp/=10;
                ans+=temp;
            }
            
        }
        i++;
    }
    return ans;
}

string conv_to_string(int x){
    string ans = "";
    while(x){
        int rem = x%10;
        ans += char(rem+'0');
        x /= 10;
    }

    // Rerversing the string
    for(int i=0; i<((int)ans.length())/2; i++){
        char c = ans[i];
        ans[i] = ans[(int)ans.length()-i-1];
        ans[(int)ans.length()-i-1] = c;
    }

    if(ans == "") ans += '0';

    return ans;
}

string remove_spaces(string s){
    string ans = "";

    for(int i=0; i<(int)s.size(); i++){
        if(s[i] == ' ') continue;
        ans.push_back(s[i]);
    }

    return ans;
}

string string_of_string(string s, int inx){
    string ans = "";
    if(s[inx] == '-'){
        ans += '-';
        inx++;
    }

    else if(s[inx] == '+'){
        ans += '+';
        inx++;
    }

    for(int i=inx; i<(int)s.size(); i++){
        if(s[i] == '+' || s[i] == '-') break;
        ans += s[i];
    }

    return ans;
}

string sorted(string s){
    string ans = "";
    int k = 0;
    while(s[k] < 97 || s[k] > 122){
        ans += s[k++];
    }

    int power[26]; 

    for(int i=0; i<26; i++){
        int temp = 0; 

        for(int j = k; j<(int)s.size(); j++){
            int temp1 = 0, temp2;
            if(s[j] == '(' && s[j+1]-'a' >=0 && s[j+1]-'a' <= 25){
                j++;
                temp2 = 0;
                while(s[j]!=')'){
                    if(s[j]-'a' == i) temp2++;
                    j++;
                }

                j += 3;

                while(s[j] != ')' && temp2 != 0){
                    temp1 = temp1*10 + (s[j]-'0');
                    j++;
                }

                temp += temp1*temp2;
            }

            else if(s[j] == '^' && s[j-1]-'a' == i){
                j += 2;
                while(s[j] != ')'){
                    temp1 = temp1*10 + (s[j]-'0');
                    j++;
                }
                temp += temp1;
            }

            else if(s[j]-'a' == i && s[j+1] != '^') temp++;
        }

        power[i] = temp;
    }

    for(int i=0; i<26; i++){
        if(power[i] == 0) continue;
        else if(power[i] == 1) ans += (char)('a'+i);
        else{
            ans += (char)('a'+i);
            ans += "^(";
            ans += conv_to_string(power[i]);
            ans += ')';
        }
    }

    return ans;
}

int total_power(string s)
{
    int j=1;
    int power=0,total_power=0,n=string_length(s);
    bool flag=0;
    while(j<n)
    {
        power=0;
        if(s[j+1]=='^')
        {
            j+=3;
            if(s[j]=='-')
            {
                j++;
                flag=1;
            }
            while(s[j]!=')')
            {
                
                power *= 10;
                power+=s[j]-'0';
                j++;
            }
            if(flag) power*=-1;
        }
        else if(s[j]-'a'>=0 && s[j]-'a'<26) power=1;
        total_power+=power;
        j++;
    }
    return total_power;
}

int compare(string A, string B){
    int n1 = (int)A.size(), n2 = (int)B.size();

    int i=1, j=1,ca=0,cb=0,p1=total_power(A),p2=total_power(B);
    if(p2>p1) return 0;
    else if(p1>p2) return 1;
    /*if(A[i]-'a'>=0 && A[i]-'a'<26)  ca=1;
    else if(A[i]-'0'>=0 && A[i]-'0'<10)
    {
        while(A[i]-'0'>=0 && A[i]-'0'<10)
        {
            ca+=int(A[i]-'0');
            ca*=10;
            i++;
        }
    }
    if(B[j]-'a'>=0 && B[j]-'a'<26)  cb=1;
    else if(B[j]-'0'>=0 && B[j]-'0'<10)
    {
        while(B[j]-'0'>=0 && B[j]-'0'<10)
        {
            cb+=int(B[j]-'0');
            cb*=10;
            j++;
        }
    }
    if(cb>ca) return false;
    else if(ca>cb) return true;*/
    i=1;j=1;
    while(i<n1 && j<n2)
    {
        if(A[i] == '^')
        {
            while(A[i] != ')') i++;
            i++;
        }

        if(B[j] == '^')
        {
            while(B[j] != ')') j++;
            j++;
        }
        while((A[i]=='+' || A[i]=='-') || (A[i]-'0'>=0 && A[i]-'0'<10)) i++;
        while((B[j]=='+' || B[j]=='-') || (B[j]-'0'>=0 && B[j]-'0'<10)) j++;
        if(A[i]-B[j]>0) return 1;
        else if(A[i]-B[j]<0) return 0;
        //cout<<i<<endl;
        i++;
        j++;
    }
    i=0;j=0;
    while((A[i]=='+' || A[i]=='-') || (A[i]-'0'>=0 && A[i]-'0'<10)) i++;
    while((B[j]=='+' || B[j]=='-') || (B[j]-'0'>=0 && B[j]-'0'<10)) j++;
    string a=A.substr(i);
    string b=B.substr(j);
    if(a==b) return 2;
    return 1;
}

string sum(string A,string B)
{
    int ca=0,cb=0,i=0,j=0,sa=1,sb=1,ans;
    if(A[i]=='-') 
    {
        sa=-1;
        i++;
    }
    else i++;
    if(B[j]=='-') 
    {
        sb=-1;
        j++;
    }
    else j++;
    if(A[i]-'a'>=0 && A[i]-'a'<26)  ca=10;
    else if(A[i]-'0'>=0 && A[i]-'0'<10)
    {
        while(A[i]-'0'>=0 && A[i]-'0'<10)
        {
            ca+=int(A[i]-'0');
            ca*=10;
            i++;
        }
    }
    
    if(B[j]-'a'>=0 && B[j]-'a'<26)  cb=10;
    else if(B[j]-'0'>=0 && B[j]-'0'<10)
    {
        while(B[j]-'0'>=0 && B[j]-'0'<10)
        {
            cb+=int(B[j]-'0');
            cb*=10;
            j++;
        }
    }
    //cout<<ca<<endl;
    //cout<<cb<<endl;
    ca/=10;
    cb/=10;
    ca*=sa;
    cb*=sb;
    ans=ca+cb;
    string answer;
    if(ans<0)
    {
        answer+='-';
        ans*=-1;
    }
    else if(ans==0)
    {
        answer=' ';
        return answer;
    }
    else answer+='+';
    answer+=conv_to_string(ans);
    //cout<<answer<<endl;
    int k=0;
    while((A[k]=='+' || A[k]=='-') || (A[k]-'0'>=0 && A[k]-'0'<10))
    k++;
    while(k<string_length(A))
    {answer+=A[k];k++;}
    //cout<<answer<<endl;
    return answer;
}

string multiply(string A,string B)
{
    int ca=0,cb=0,i=0,j=0,sa=1,sb=1,ans;
    if(A[i]=='-') 
    {
        sa=-1;
        i++;
    }
    else i++;
    if(B[j]=='-') 
    {
        sb=-1;
        j++;
    }
    else j++;
    if(A[i]-'a'>=0 && A[i]-'a'<26)  ca=10;
    else if(A[i]-'0'>=0 && A[i]-'0'<10)
    {
        while(A[i]-'0'>=0 && A[i]-'0'<10)
        {
            ca+=int(A[i]-'0');
            ca*=10;
            i++;
        }
    }
    
    if(B[j]-'a'>=0 && B[j]-'a'<26)  cb=10;
    else if(B[j]-'0'>=0 && B[j]-'0'<10)
    {
        while(B[j]-'0'>=0 && B[j]-'0'<10)
        {
            cb+=int(B[j]-'0');
            cb*=10;
            j++;
        }
    }
    //cout<<ca<<endl;
    //cout<<cb<<endl;
    ca/=10;
    cb/=10;
    ca*=sa;
    cb*=sb;
    ans=ca*cb;
    string answer;
    if(ans<0)
    {
        answer+='-';
        ans*=-1;
    }
    else if(ans==0)
    {
        answer=' ';
        return answer;
    }
    else answer+='+';
    answer+=conv_to_string(ans);
    //cout<<answer<<endl;
    int k=0;
    while((A[k]=='+' || A[k]=='-') || (A[k]-'0'>=0 && A[k]-'0'<10))
    k++;
    while(k<string_length(A))
    {answer+=A[k];k++;}
    
    int k1=0;
    while((B[k1]=='+' || B[k1]=='-') || (B[k1]-'0'>=0 && B[k1]-'0'<10))
    k1++;
    while(k1<string_length(B))
    {answer+=B[k1];k1++;}
    return answer;
}

int main()
{
    fstream my_file;
    my_file.open("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input1.txt"); 
    string s1,s2,s3,s4;
    getline(my_file,s1);
    getline(my_file,s2);
    cout<<"The given expression is\n("<<s1 <<")*("<<s2<<")"<<endl;
    s1=remove_spaces(s1);
    s2=remove_spaces(s2);
    
    my_file.close();
    string s= s2;
    s=remove_spaces(s);
    cout << s<<endl;
    if((s[0] >= 97 && s[0] <= 122) || (s[0]>=48 && s[0]<=57)) s = '+' + s;
    if((s1[0] >= 97 && s1[0] <= 122) || (s1[0]>=48 && s1[0]<=57)) s1 = '+' + s1;
    int n = 0; 

    for(int i=0; i<(int)s.size(); i++){
        string temp = string_of_string(s, i);
        i = i + (int)temp.length();
        n++;
    }

    string arr[n];

    int j = 0;
    for(int i=0; i<(int)s.size();){
        string temp = string_of_string(s, i);
        i = i + (int)temp.length();
        arr[j] = temp;
        j++;
    }


    for(int i=0; i<n; i++)
    {
        //cout<<arr[i]<<endl;
        arr[i] = sorted(arr[i]);
        //cout<<arr[i]<<endl;
    }
    s1=sorted(s1);
    //cout<<s1<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i]=multiply(arr[i],s1);
    }

    for(int i=0; i<n; i++)
    {
        //cout<<arr[i]<<endl;
        arr[i] = sorted(arr[i]);
        //cout<<arr[i]<<endl;
    }

    bool spd;
    for(int i=0; i<n; i++)
    {
        
        spd = false;
        
        for(j=0; j<n-1; j++)
        {
            if(compare(arr[j],arr[j+1])==1)
            {
                swap(arr[j],arr[j+1]);
                spd = true;
            }
            else if(compare(arr[j],arr[j+1])==2)
            {
                
                arr[j]=sum(arr[j],arr[j+1]);
                arr[j+1]=' ';
                //cout<<arr[j]<<endl;
            }
        }

        if(spd == false) break;
    }

    string temp = "";
    for(int i=0; i<(int)arr[0].size(); i++){
        if(arr[0][i] == '+') continue;
        temp += arr[0][i];
    }

    arr[0] = temp;
    string answer;
    cout << "Polynomial after sort is: ";
    //string t=' ';
    for(int i=0;i<n;i++) 
    {
        //if(arr[i]==st)continue;
        answer+= arr[i];
    }
    //cout<<answer<<endl;
    answer=remove_spaces(answer);
    if(answer[0]=='+') answer[0]=' ';
    answer=remove_spaces(answer);
    if(answer.empty()) 
    {
        cout<<"0\n";
        return 0;
    }
    cout<<answer;
    cout << '\n';

    return 0;
}
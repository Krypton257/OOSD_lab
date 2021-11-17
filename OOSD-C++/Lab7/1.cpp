#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

string int_to_string(int n) 
{
    string str="";
    int m=n;
    if(n<0)
        n=-n;
    while(n>0)
    {
        int i=n%10;
        str+='0'+i;
        n=n/10;
    }
    if(m<0)
        str+="-";
    int l=0,r=str.length()-1;
    while(l<r)
    {
        char temp=str[l];
        str[l]=str[r];
        str[r]=temp;
        l++;
        r--;
    }
    return str;
}

string remove_spaces(string str)
{
    string s="";
    for(int i=0;i<str.length();i++)
    {
        if(str[i]!=' ')
            s+=str[i];
    }

    return s;
}

int find_coeff(string str)
{
    int n=str.length();
    int coeff;
    int i=1;
   
    if(str[i]>='a' && str[i]<='z')
    {
        if(str[0]=='+')
            return 1;
        else
            return -1;
    }
    int k=0;
    while(str[i]>='0' && str[i]<='9')
    {
        k=k*10 + (str[i]-'0');
        i++;
    }
    coeff=k;
    if(str[0]=='+')
        return coeff;
    else
        return -coeff;
}

string find_variable(string str)
{
    int n=str.length();
    string s="";
    int i=1;
    while(str[i]>='0' && str[i]<='9')
        i++;
    while(i<n)
        s+=str[i++];

    return s;
}

string product_variable(string str1,string str2)
{
    int power[26];
    for(int i=0;i<26;i++)
        power[i]=0;

    int n=str1.length();                               
    int i=0;
    while(i<n)
    {
        if(str1[i]>='a' and str1[i]<='z')
        {
            if(str1[i+1]!='^')
            {
                power[str1[i]-'a']+=1;
                i++;
            }
            else
            {
                int l = str1[i] - 'a' ; 
                i = i+3 ;
                int k = 0;
                while ( str1[i] != ')') 
                {
                    k = k*10 + (str1[i]-'0') ;
                    i++ ; 
                }
                power[l] += k;
                i++ ;
            }
        }
    }

    n=str2.length();
    i=0;
    while(i<n)
    {
        if(str2[i]>='a' and str2[i]<='z')
        {
            if(str2[i+1]!='^')
            {
                power[str2[i]-'a']+=1;
                i++;
            }
            else
            {
                int l = str2[i] - 'a' ; 
                i = i+3 ;
                int k = 0;
                while ( str2[i] != ')') 
                {
                    k = k*10 + (str2[i]-'0') ;
                    i++ ; 
                }
                power[l] += k;
                i++ ;
            }
        }
    }
    string str="";
    for(i=0;i<26;i++)
    {
        if(power[i]==0)
            continue;
        else if(power[i]==1)
        {
            char ch='a'+i;
            str+=ch;
        }
        else
        {
            char ch='a'+i;
            str+=ch;
            str+="^(";
            str+=int_to_string(power[i]);
            str+=')';
        }
    }

    return str;

}

void product_terms(string *s,string term,int terms)
{
    int coeff1,coeff2;
    coeff2=find_coeff(term);
    //cout<<"findcoeffworks"<<endl;
    string str1,str2;
    str2=find_variable(term);
    //cout<<"findvar works"<<endl;

    string m[terms];
    for(int i=0;i<terms;i++)
        m[i]="";
    
    for(int i=0;i<terms;i++)
    {
        coeff1=find_coeff(s[i]);
        str1=find_variable(s[i]);
        int p=coeff1*coeff2;

        string str=product_variable(str1,str2);
        if(p!=1)
            m[i]+=int_to_string(p);
        m[i]+=str;
        if(p>0)
            s[i]='+';
        else
            s[i]="";
        s[i]+=m[i];
    }

}

void sort_terms(string m[],int terms)
{
    string n[terms];
    for(int i=0;i<terms;i++)
    {
        n[i]=m[i].substr(1);
    }

    for(int i=0;i<terms-1;i++)
    {
        for(int j=i+1;j<terms;j++)
        {
            if(n[i]>n[j])
            {
                string temp=n[i];
                n[i]=n[j];
                n[j]=temp;

                temp=m[i];
                m[i]=m[j];
                m[j]=temp;
            }
        }
    }
}


int main()
{
    fstream file;
    file.open("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input.txt");
    string a;
    getline(file,a);
    file.close();
    cout<<"Given Equation:"<<endl;
    cout<<a<<endl;
    string term="";
    string poly="";
    int n=a.length();
    int i=0;
    if(a[0]!='-')
        term+='+';
    while(1)
    {
        if(a[i]=='(' && a[i-1]!='^')
            break;
        term+=a[i++];
    }
    i++;
    while(i<n-1)
        poly+=a[i++];
    //cout<<term<<endl;
    //cout<<poly<<endl;

    string str=remove_spaces(poly);

    int count=0;
    n=str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='+' || str[i]=='-')
            count++;
    }
    if(str[0]=='-')
        count--;
    
    int terms=count+1;

    string s[terms];
    for(int i=0;i<terms;i++)
    {
        s[i]="";
    }
    int j=0;
    if(str[0]!='-')
        s[0]+='+';
    for(int i=0;i<n;i++)
    {
        if((str[i]=='+' || str[i]=='-') && i>0)
        {
            j++;
        }

        s[j]+=str[i];    
    }

    product_terms(s,term,terms);

    /*for(int i=0;i<terms;i++)
        cout<<s[i]<<endl;*/


    ///////////////////////////////////////////////////////////////
    //sorting

    string m[terms];
    for(int i=0;i<terms;i++)
    {
        string temp="";
        int l=s[i].length();
        //temp+=s[i][0];
        temp+='0'+i;
        for(int k=1;k<l;k++)
        {
            if((s[i][k]>='a' && s[i][k]<='z') && k+1<l)
            {
                if(s[i][k+1]=='^')
                {
                    char ch=s[i][k];
                    k = k+3 ;
                    int num = 0;
                    while ( s[i][k] != ')') 
                    {
                        num = num*10 + (s[i][k]-'0') ;
                        k++ ; 
                    }

                    for(int r=0;r<num;r++)
                        temp+=ch;
                }

                else
                    temp+=s[i][k];
            }
            else if(s[i][k]>='0' && s[i][k]<='9')
                continue;
            else 
                temp+=s[i][k];

            
        }
        m[i]=temp;
    }

    sort_terms(m,terms);
    cout<<"Product in Lexicographic Order of Terms:"<<endl;
    for(int i=0;i<terms;i++)
    {
        int y=m[i][0]-'0';
        cout<<s[y]<<" ";
    }
}
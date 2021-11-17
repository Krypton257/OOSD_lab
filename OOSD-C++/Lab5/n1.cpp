#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main (){
 
    fstream myfile;
    myfile.open("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input.txt");
    string word = "";

    getline(myfile, word);
    myfile.close();

    int freq[26];
    for(int i = 0; i < 26; i++){
        freq[i] = 0;
    }

    string num = "",final = "";
    int n = 0;
    for(int i = 0; i<word.length(); i++) 
    {
       char ch = word[i];
       if ( ch>=65 && ch<=90)
	{	n=1;
	   if( word[i+1]=='^')
	    {
	        i+=2;
		while(word[i]  !=')')
		{
		    num+=word[i];
                    i+=1;
		}
		    n = stoi(num);

            num="";
	    }
	    		    freq[ch-65]+=n;
 
	}
     }
     for (int i =0; i<26;i++)
     {
           if(freq[i]!=0)
           {
		if(freq[i]==1)
		{
			final+=char(65+i);
		}
		else
		{
			final+=char(65+i)+"("+to_string(freq[i])+")";		
		}
	   }
     }

    for(int j = 0; j < 26; j++){
        cout<<freq[j];
    }

    cout<< "The final output : "<<final ;
    
    return 0;

}
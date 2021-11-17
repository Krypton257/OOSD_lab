//Code to eliminate spaces in the string

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
  int data;
  struct Node* link;
};

struct Node* top;

void push(int data)
{
  struct Node* temp;
  temp = new Node();

  if (!temp)
  {
    cout << "\nHeap Overflow";
    exit(1);
  }

  temp->data = data;

  temp->link = top;

  top = temp;
}

int isEmpty()
{
  return top == NULL;
}

int peek()
{
  
  if (!isEmpty())
    return top->data;
  else
    exit(1);
}

void pop()
{
  struct Node* temp;

  if (top == NULL)
  {
    cout << "\nStack Underflow" << endl;
    exit(1);
  }
  else
  {

    temp = top;

    top = top->link;

    temp->link = NULL;

    free(temp);
  }
}

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
  string str,str1;
  int i,j,end=0;
  ifstream myfile ("C:\\Users\\Rahul Saini\\OneDrive\\Desktop\\input.txt");
  if (myfile.is_open())
  {
    getline (myfile,str);
    myfile.close();
  }

  int n=str.length();
  str1=str;
  cout<<str1<<endl;

  i=0;

  while (i < str.length()) 
    {
      if (str[i] == '(') {
        if (str[i + 1] == '(') {
          push(-i);
        } 
        else {
          push(i);
        }
        i++;
      } 
      else if (str[i] != ')' && str[i] != '(') {
        i++;
      } 
      else if (str[i] == ')') {
        int top = peek();
        
          if (str[i - 1] == ')' && top < 0) {
            str1[-top] = '$';
            str1[i] = '$';
            pop();
          }

         else if (str[i - 1] == ')' && top > 0) {
            cout<<"Something is wrong!!";
          }

         else if (str[i - 1] != ')' && top > 0)
            pop();
          i++;
        }
    }

    int top = peek();
    while(!isEmpty()){
      if(top>0){
        str1[top]='$';
        pop();
      }
      else{
        str1[-top]='$';
        pop();
      }
  }

    

    for (i = 0; i<str1.length(); i++) {
      if (str1[i] == '$') {
        continue;
      }
      cout<<str1[i];
    }

  //print_without_spaces(str1);

  return 0;
}
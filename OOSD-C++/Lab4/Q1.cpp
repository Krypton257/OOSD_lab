#include <iostream>
#include <fstream>

using namespace std;

struct node // single node or link of the list
 {
 	char data;
 	node* next;
 	node* prev;
};


class list // a list of links
{
	private:
	    node* head; // pointer to the head link
	    node* tail; // pointer to the tail link

    public:
    	list() // zero argument constructor
    	{
            head=NULL;
        	tail = NULL;
        	head = tail;	
    	}

    	void addfront(char d);  // adds a data item to the linked list (in front)
    	void addend(char d);  // adds a data item to the linked list (at the back)


    	void deltop();   // deletes the first data item

    	void delend(); // deletes the last data item

    


    	void display(); // displays the whole linked list

};

void list::addfront(char d){ // added a new node in front of the list

    node *newnode = new node;

    newnode-> data = d;
    newnode-> prev = NULL;
    newnode->next = head;

    if(head!=NULL){
        head->prev = newnode;
    }


    head = newnode;


    if (newnode->next!=NULL and (newnode->next)->next==NULL){  // the first instance where the head and tail separate out
        tail=newnode->next;
    }

}

void list::addend(char d){
	node* newnode = new node;
	newnode->data = d;

	if(tail!=NULL)
	{
		tail->next = newnode;
	}

    newnode->prev=tail;         // initially attaches new node after tail

    tail = newnode;         // tail becomes the last node once again

    tail->next = NULL;

    if (newnode->prev!=NULL and (newnode->prev)->prev==NULL)  // the first instance where the head and tail separate out
    {
        head=newnode->prev;
    }

}


 
void list::display(){

    node* current = head;
    while(current != NULL)
    {
        cout << current->data;
        current = current->next;
    }
}

void div(list n1, list n2){

    
}


int main (){
 
    fstream inputfile;

    inputfile.open("input.txt"); // OPENS THE FILE - input.txt

    char c;
    list n1, n2;
    
    while (inputfile.get(c)) // TERMINATES with END OF LINE
    {
        if(c == '\n'){
            break;
        }
        n1.addend(c);
    }
    while (inputfile.get(c)) // TERMINATES with END OF LINE
    {
        if(c == '\n'){
            break;
        }
        n2.addend(c);
    }
    
    inputfile.close();
    n1.display();
    cout<<endl;
    n2.display();

    div(n1, n2);

    return 0;
}
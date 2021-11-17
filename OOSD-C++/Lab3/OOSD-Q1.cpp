#include <iostream>
#include <fstream>

using namespace std;

int b_greater_than_a(char a,char b){
    if(a=='0'){
        if(b=='1' || b=='2' || b=='3' || b=='4' || b=='5' || b=='6' || b=='7' || b=='8' || b=='9')
            return 1;
        else
            return 0;
    }
    else if(a=='1'){
        if(b=='2' || b=='3' || b=='4' || b=='5' || b=='6' || b=='7' || b=='8' || b=='9')
             return 1;
        else
            return 0;  
    }
    else if(a=='2'){
        if(b=='3' || b=='4' || b=='5' || b=='6' || b=='7' || b=='8' || b=='9')
             return 1;
        else
            return 0;
    }
    else if(a=='3'){
        if(b=='4' || b=='5' || b=='6' || b=='7' || b=='8' || b=='9')
             return 1;
        else
            return 0;
    }  
    else if(a=='4'){
        if(b=='5' || b=='6' || b=='7' || b=='8' || b=='9')
             return 1;
        else
            return 0;
    }  
    else if(a=='5'){
        if(b=='6' || b=='7' || b=='8' || b=='9')
             return 1;
        else
            return 0;
    }  
    else if(a=='6'){
        if(b=='7' || b=='8' || b=='9')
             return 1;
        else
            return 0;
    }  
    else if(a=='7'){
        if(b=='8' || b=='9')
             return 1;
        else
            return 0;
    }  
    else if(a=='8'){
        if(b=='9')
             return 1;
        else
            return 0;
    }  
}

int b_less_than_a(char a,char b){
    if(a=='9'){
        if(b=='0' || b=='1' || b=='2' || b=='3' || b=='4' || b=='5' || b=='6' || b=='7' || b=='8')
            return 1;
        else
            return 0;
    }
    else if(a=='8'){
        if(b=='0' || b=='1' || b=='2' || b=='3' || b=='4' || b=='5' || b=='6' || b=='7')
            return 1;
        else
            return 0;   
    }
    else if(a=='7'){
        if(b=='0' || b=='1' || b=='2' || b=='3' || b=='4' || b=='5' || b=='6')
            return 1;
        else
            return 0;
    }
    else if(a=='6'){
        if(b=='0' || b=='1' || b=='2' || b=='3' || b=='4' || b=='5')
            return 1;
        else
            return 0;
    }  
    else if(a=='5'){
        if(b=='0' || b=='1' || b=='2' || b=='3' || b=='4')
            return 1;
        else
            return 0;
    }  
    else if(a=='4'){
        if(b=='0' || b=='1' || b=='2' || b=='3')
            return 1;
        else
            return 0;
    }  
    else if(a=='3'){
        if(b=='0' || b=='1' || b=='2')
            return 1;
        else
            return 0;
    }  
    else if(a=='2'){
        if(b=='0' || b=='1')
            return 1;
        else
            return 0;
    }  
    else if(a=='1'){
        if(b=='0')
            return 1;
        else
            return 0;
    }  
}
int b_equal_to_a(char a,char b){
    if(a=='9'){
        if(b=='9')
            return 1;
        else
            return 0;
    }
    else if(a=='8'){
        if(b=='8')
            return 1;
        else
            return 0;
    }
    else if(a=='7'){
        if(b=='7')
            return 1;
        else
            return 0;
    }
    else if(a=='6'){
        if(b=='6')
            return 1;
        else
            return 0;
    }  
    else if(a=='5'){
        if(b=='5')
            return 1;
        else
            return 0;
    }  
    else if(a=='4'){
        if(b=='4')
            return 1;
        else
            return 0;
    }  
    else if(a=='3'){
        if(b=='3')
            return 1;
        else
            return 0;
    }  
    else if(a=='2'){
        if(b=='2')
            return 1;
        else
            return 0;
    }  
    else if(a=='1'){
        if(b=='1')
            return 1;
        else
            return 0;
    }  
    else if(a=='0'){
        if(b=='0')
            return 1;
        else
            return 0;
    }  
}

struct node // single node or link of the list
 {
 	char data;
 	node* next;
 	node* prev;
};

node* removeLeadingZeros(struct node* x)
{
    if (x != NULL && x->data == 0)
        return removeLeadingZeros(x->next);
    else
        return x;
}

int getSize(struct node* x)
{
    int size = 0;
    while (x != NULL) {
        x = x->next;
        size++;
    }
    return size;
}


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



int main (){
 
    fstream inputfile;

    inputfile.open("input.txt"); // OPENS THE FILE - input.txt

    char c;
    list n1, n2;

    cout<<"Two Numbers are: ";
    
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
    cout<<" , ";
    n2.display();

    cout<<endl;
    cout<<"Relation is : ";

    return 0;
}
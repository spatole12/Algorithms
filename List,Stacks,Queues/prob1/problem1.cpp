#include <iostream>
#include "LinkedList.h"
#include <set>
using namespace std;

// First implementation uses set as the additional data structure
void removeDupl_1(Node* head)
{
    set<int> s; //declaring set of int
    Node* temp;
	Node* prev;
    if (head == NULL)
    {
        return; // if head is null return
    }

    temp = head;

	while(temp!=NULL){ //till we reach the last node
	if(s.find(temp->data)==s.end()){ //compare with set 
      	s.insert(temp->data); //insert in set if not found
		prev = temp; 
		temp = temp->next; // move to next 
     }
	 else{ //it is found in the set
		prev->next = temp->next; //assign previous node's next to temp's next
        delete temp; // delete the duplicate node
        temp = temp->next; // move to next
	 }
	}
	
}


// This implementation uses no additional data structure 
void removeDupl_2(Node* head)
{
	Node* temp;
	Node* current;
	Node* prev;
	if (head == NULL)
    {
        return; // if head is null return
    }
	
	current=head; 
	while(current!=NULL){
		temp=head;
		while(temp!=NULL){
			
			if((current->data==temp->data)&&temp!=current){ // check if data is duplicate 
			prev->next=temp->next;  //assign previous node's next to temp's next
			delete temp; // delete the duplicate node
			temp=temp->next;	// move to next
			
			}
			else{
				prev=temp; 
				temp=temp->next; // move to next
			}
			
		}
		current=current->next; // move current to next
	}
}


int main()
{
    LinkedList* myList = new LinkedList();
    myList->insert(5);
    myList->insert(7);
    myList->insert(12);
    myList->insert(7);
    myList->insert(16);
    myList->insert(16);
    myList->insert(25);
    myList->insert(11);
    myList->insert(5);
	

    cout << "The original list is: ";
    myList->display();
	LinkedList* myList2= myList; //copy of myList
   
	removeDupl_1(myList->head);
	 //Use removeDupl_2 to run that implementation
	removeDupl_2(myList2->head);
    cout << "The list with duplicated removed with removeDupl_1 is: ";
    myList->display();
	cout << "The list with duplicated removed with removeDupl_2 is: ";
	myList2->display();
    delete myList;

    return 0;
}
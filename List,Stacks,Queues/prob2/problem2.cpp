#include<iostream>
#include <stack>
#include<climits>
using namespace std;

class Queue{
private:
    stack<int> stack1, stack2;
public:
    void EnQueue(int data){
		//pushing each element that needs to be enqueued into stack1
        stack1.push(data);
    }

    int DeQueue(){
		int popped_ele;
		int stack1_ele;
		
		
		if(!stack2.empty())   
            {	
			//if stack2 is not empty then the topmost element represents the first element in the queue
			//ie .it is the element that is to get dequeued
			popped_ele = stack2.top();
			stack2.pop();
		}
		else{
			//if stack2 is empty ,then we have to pop all the elements of stack1 and push them into stack2
			//the last element in stack2 now would be the first element in the queue and needs to be popped out and returned
			
		    while(!stack1.empty())    //checking if stack1 is not empty as we have to pop elements from stack1 and push them in stack2 
			{
			stack1_ele = stack1.top(); //takes uppermost element in stack1
			stack2.push(stack1_ele); //push it in stack2
			stack1.pop(); //pop it from stack1
			}
			popped_ele = stack2.top(); //this is the first element of the queue that has to be dequeued  
			stack2.pop();
		}
        return popped_ele; 
    }

};

int main(){
    Queue q;
	
	//elements to be enqueued
    for(int i=0; i<10; i++)
        q.EnQueue(i);
    cout<<q.DeQueue()<<'\n';
    cout<<q.DeQueue()<<'\n';
    for(int i=10; i<20; i++){
        q.EnQueue(i);
    }
   
	cout<<q.DeQueue()<<" ";
	cout<<q.DeQueue()<<'\n';
    
    return 0;
}






#include<iostream>
#include<string.h>
#include<cmath>
#include<string>
using namespace std;

#define size 50
class node
	 {
	 public:
		int data;
		node*next;
};
class stack{
	public:
		node*head;
		node*tail;
	public:
		stack(){	
			head=NULL;
			tail=NULL;
		}
    	void push(char n);
    	char pop ();
    	char top ();	
};
void stack::push(char n){
   	node* tptr;
	tptr = head;

	node* nptr = new node();
	nptr->data = n;
	tail=nptr;
	tail->next =NULL ;

	if (head == NULL)
	{
		head = nptr;
		tail = nptr;
		tail->next=NULL;
	}
	
	else {
		while(tptr->next!=NULL)
		{
			tptr=tptr->next;
			
    	}
      tptr->next=nptr;
	}
}
char stack::pop(){
	node *current = head;
	node *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			head = head -> next;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
			previous -> next = current -> next;
	    	return n ;
		}
		
	}
}
char stack::top(){
	node *current = head;
	node *previous = head;
	
	if(head == NULL){
		return -1;
	}
	else{
		int i = 0;
		while(current -> next != NULL){
			current = current -> next;
			i++;
		}
		
		if(current == head){
			int n = current -> data;
			return n; 
		}
		else{
			while(i > 1){
				previous = previous -> next;
				i--;
			}
			int n = current -> data;
	    	return n ;
		}
		
	}
}
int typeCasting(char data){
	return data-'0';
}
int postfixEvaluater(string infix){
	stack s;
	char operation;
	char op1,op2;
	int length=infix.length();
	for(int i=0;i<length;i++){
	if(infix[i]!='+' && infix[i]!='-' && infix[i]!='/' && infix[i]!='*' && infix[i]!='^' && infix[i]!='(' && infix[i]!=')'){
		s.push(infix[i]);
		}
	else{
		op1=s.pop();
		op2=s.pop();
		int numOp1=typeCasting(op1);
		int numOp2=typeCasting(op2);
		operation=infix[i];
		
		if(operation=='+'){
			s.push(numOp1+numOp2);
		}
		else if(operation=='-'){
			s.push(numOp1-numOp2);
		}
		else if(operation=='*'){
			s.push(numOp1*numOp2);
		}
		else if(operation=='/'){
			s.push(numOp1*numOp2);
		}
		else{
			s.push(pow(numOp1,numOp2));
		}
		}
    }
    cout<<"result:"<<s.pop();
}
int main(){
	string fixx="23-";
		postfixEvaluater(fixx);
	return 0;
}

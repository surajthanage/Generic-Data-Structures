#include<iostream>
using namespace std;

Template<class T>
struct Node
{
	T Data;
	struct Node *Next;
};

Template<class T>
class Stack
{
	private:
		struct Node<T>*Head;
		int Count;
		
	public:
		Stack();
		void Push(T);
		void Pop();
		void Display();
		int CountNode();
};

Template<class T>
Stack<T>::Stack()
{
	Head=NULL;
	Count=0;
}

Template<class T>
void Stack<T>::Push(T No)
{
	struct Node<T>*Newn=new Node<T>;
	
	Newn->Data=No;
	Newn->Next=NULL;

	Newn->Next=Head;
	Head=Newn;
	
	Count++;
}

Template<class T>
void Stack<T>::Pop()
{
	T no;
	struct Node<T>*Temp=Head;
	
	if(Head==NULL)
	{
		cout<<"Stack is empty"<<endl;
		return;
	}
	no=Head->Data;
		
	Head=Head->Next;
	delete Temp;
	
	Count--;
	cout<<"Remove element is :"<<no<<endl;
}

Template<class T>
void Stack<T>::Display()
{
	struct Node<T>*Temp=Head;
	cout<<"Element of stack is :"<<endl;
	
	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
	}
	cout<<"NULL"<<endl;
}

Template<class T>
int Stack<T>::CountNode()
{
	return Count;
}



int main()
{
	Stack<int>obj1;
	
	obj1.Push(50);
	obj1.Push(40);
	obj1.Push(30);
	obj1.Push(20);
	obj1.Push(10);
	obj1.Display();
	
	obj1.Pop();
	obj1.Pop();
	obj1.Pop();
	obj1.Display();
	cout<<"Number of stack Node is :"<<obj1.CountNode()<<endl;
	return 0;
}
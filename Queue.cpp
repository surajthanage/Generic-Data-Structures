#include<iostream>

using namespace std;
Template<class T>
struct Node
{
	T Data;
	struct Node *Next;
};

Template<class T>
class Queue
{
	private:
		struct Node<T>*Head;
		int Count;
		
	public:
		Queue();
		void EnQueue(T);
		void DeQueue();
		void Display();
		int CountNode();
		
};

Template<class T>
Queue<T>::Queue()
{
	Head=NULL;
	Count=0;
}

Template<class T>
void Queue<T>::EnQueue(T no)
{
	struct Node<T>*Newn=new Node<T>;
	
	Newn->Data=no;
	Newn->Next=NULL;
	
	if(Count==0)
	{
		Head=Newn;
	}
	else
	{
		struct Node<T>*Temp=Head;
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Newn;
	}
	Count++;
}

Template<class T>
void Queue<T>::DeQueue()
{
	struct Node<T>*Temp=Head;
	if(Head==NULL)
	{
		return;
	}
	else
	{
		Head=Head->Next;
		delete Temp;
	}
	Count--;
}

Template<class T>
void Queue<T>::Display()
{
	struct  Node<T>*Temp=Head;
	cout<<"Element of Queue is :"<<endl;
	
	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
	}
	cout<<"NULL"<<endl;
}

Template<class T>
int Queue<T>::CountNode()
{
	return Count;
}

int main()
{
	Queue<int>obj1;
	obj1.EnQueue(50);
	obj1.EnQueue(40);
	obj1.EnQueue(30);
	obj1.EnQueue(20);
	obj1.EnQueue(10);
	obj1.Display();
	obj1.DeQueue();
	obj1.DeQueue();
	obj1.DeQueue();
	obj1.Display();	
	return 0;
}
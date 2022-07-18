#include<iostream>
using namespace std;

Template<class T>
struct Node
{
	T Data;
	struct Node *Next;
	struct Node *Prev;
};

Template<class T>
class DoublyLL
{
	private:
		struct Node<T> *Head;
		int Count;
	
	public:
		DoublyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int CountNode();
};

Template<class T>
DoublyLL<T>::DoublyLL()
{
	Head=NULL;
	Count=0;
}

Template<class T>
void DoublyLL<T>::InsertFirst(T No)
{
	struct Node<T>*Newn=new Node<T>;
	
	Newn->Data=No;
	Newn->Next=NULL;
	Newn->Prev=NULL;
	if(Head==NULL)
	{
		Head=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head->Prev=Newn;
		Head=Newn;
	}
	Count++;
}


Template<class T>
void DoublyLL<T>::InsertLast(T No)
{
	struct Node<T>*Newn=new Node<T>;
	struct Node<T>*Temp=Head;
	
	Newn->Data=No;
	Newn->Next=NULL;
	Newn->Prev=NULL;
	if(Head==NULL)
	{
		Head=Newn;
		Head->Prev=Newn;
	}
	else
	{
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Newn;
		Newn->Prev=Temp;
	}
	Count++;
}

Template<class T>
void DoublyLL<T>::InsertAtPos(T No,int iPos)
{
	if((iPos<1)&&(iPos>>Count+1))
	{
		cout<<"Invalid position"<<endl;
		return;
	}
	else if(iPos==1)
	{
		InsertFirst(No);
	}
	else if(iPos==Count+1)
	{
		InsertLast(No);
	}
	else
	{
		struct Node<T>*Newn=new Node<T>;
		struct Node<T>*Temp=Head;
		
		Newn->Data=No;
		Newn->Next=NULL;
		Newn->Prev=NULL;
		
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Newn->Next->Prev=Newn;
		Temp->Next=Newn;
		Newn->Prev=Temp;
		Count++;
	}
}

Template<class T>
void DoublyLL<T>::DeleteFirst()
{
	Head=Head->Next;
	delete Head->Prev;
	Head->Prev=NULL;
	Count--;
}

Template<class T>
void DoublyLL<T>::DeleteLast()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
		Head->Prev=NULL;
	}
	else
	{
		struct Node<T>*Temp=Head;
		while(Temp->Next->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		delete Temp->Next;
		Temp->Next=NULL;
	}
	Count--;
}

Template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
	if((iPos<1)&&(iPos>>Count))
	{
		cout<<"Invalid position"<<endl;
		return;
	}
	else if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==Count)
	{
		DeleteLast();
	}
	else
	{
		struct Node<T>*Temp=Head;
		
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Temp->Next->Next;
		delete Temp->Next->Prev;
		Temp->Next->Prev=Temp;
		Count--;
	}
}
Template<class T>
void DoublyLL<T>::Display()
{
	struct Node<T>*Temp=Head;
	cout<<"Element of genric Doubly LL are :"<<endl;
	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
	}
	cout<<"NULL"<<endl;
}
Template<class T>
int DoublyLL<T>::CountNode()
{
	return Count;
}

int main()
{
	DoublyLL<int>obj1;
	obj1.InsertFirst(50);
	obj1.InsertFirst(40);
	obj1.InsertFirst(30);
	obj1.InsertFirst(20);
	obj1.InsertFirst(10);
	obj1.InsertLast(10);
	obj1.Display();
	obj1.InsertAtPos(55,3);
	obj1.Display();
	obj1.DeleteFirst();
	obj1.Display();
	obj1.DeleteLast();
	obj1.Display();
	obj1.DeleteAtPos(2);
	obj1.Display();
	cout<<"Number of genric Doubly LL is  :"<<obj1.CountNode()<<endl<<endl;
	
	return 0;
}
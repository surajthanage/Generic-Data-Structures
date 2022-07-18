#include<iostream>
using namespace std;
Template<class T>
struct Node
{
	T Data;
	struct Node *Next;
};

Template<class T>
class SinglyLL
{
	private :
		struct Node<T> *Head;
		T Data;
		int Count;
	
	public:
		SinglyLL();
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
SinglyLL<T>::SinglyLL()
{
	Head=NULL;
	Count=0;
}

Template<class T>
void SinglyLL<T>::InsertFirst(T No)
{
	struct Node<T>*Newn=new Node<T>;
	Newn->Data=No;
	Newn->Next=NULL;
	
	Newn->Next=Head;
	Head=Newn;
	Count++;
}

Template<class T>
void SinglyLL<T>::InsertLast(T No)
{
	struct Node<T>*Newn=new Node<T>;
	struct Node<T> *Temp=Head;
	Newn->Data=No;
	Newn->Next=NULL;
	if(Newn==NULL)
	{
		return;
	}
	else if(Head==NULL)
	{
		Newn=Head;
	}
	else
	{
		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}
		Temp->Next=Newn;
		Count++;
	}
}

Template<class T>
void SinglyLL<T>::InsertAtPos(T No,int iPos)
{
	if(iPos<1 || iPos>Count+1)
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
		struct Node<T>*Newn=NULL;
		Newn=new Node<T>;
		struct Node<T> *Temp=Head;
		Newn->Data=No;
		Newn->Next=NULL;
		
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next=Newn;
		Count++;
	}
}

Template<class T>
void SinglyLL<T>::DeleteFirst()
{
	struct Node <T>*Temp=Head;
	
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
void SinglyLL<T>::DeleteLast()
{
	struct Node <T>*Temp=Head;
	
	if(Head==NULL)
	{
		return;
	}
	else if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
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
void SinglyLL<T>::DeleteAtPos(int iPos)
{
	if(iPos<1 || iPos>Count)
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
		struct Node<T> *Temp=Head;
		struct Node <T>*Tempdel=NULL;;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Tempdel=Temp->Next;
		Temp->Next=Tempdel->Next;
		delete Tempdel;
		Count--;
	}
}

Template<class T>
void SinglyLL<T>::Display()
{
	struct Node<T>*Temp=Head;
	cout<<"Element of genric Singly LL  are:"<<endl;
	
	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
	}
	cout<<"NULL"<<endl;
}

Template<class T>
int SinglyLL<T>::CountNode()
{
	return Count;
}


int main()
{
	SinglyLL<int>obj1;
	obj1.InsertFirst(50);
	obj1.InsertFirst(40);
	obj1.InsertFirst(30);
	obj1.InsertFirst(20);
	obj1.InsertFirst(10);
	obj1.Display();
	obj1.InsertAtPos(55,3);
	obj1.Display();
	obj1.DeleteFirst();
	obj1.Display();
	obj1.DeleteLast();
	obj1.Display();
	obj1.DeleteAtPos(2);
	obj1.Display();
	cout<<"Number of genric Singly LL is  :"<<obj1.CountNode()<<endl<<endl;

	SinglyLL<float>obj2;
	
	obj2.InsertFirst(50.11);
	obj2.InsertFirst(40.12);
	obj2.InsertFirst(30.13);
	obj2.InsertFirst(20.11);
	obj2.InsertFirst(10.12);
	obj2.Display();
	obj2.InsertAtPos(55.22,3);
	obj2.Display();
	obj2.DeleteFirst();
	obj2.Display();
	obj2.DeleteLast();
	obj2.Display();
	obj2.DeleteAtPos(2);
	obj2.Display();
	cout<<"Number of genric Singly LL is  :"<<obj2.CountNode()<<endl;

	return 0;
}
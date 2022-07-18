#include<iostream>
using namespace std;

template<class T>
struct Node
{
	T Data;
	struct Node *Next;
	struct Node *Prev;
};

template<class T>
class DoublyCircularLL
{
	private:
		struct Node<T> *Head;
		struct Node<T> *Tail;
		int Count;
	
	public:
		DoublyCircularLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int CountNode();
};

template<class T>
DoublyCircularLL<T>::DoublyCircularLL()
{
	Head=NULL;
	Tail=NULL;
	Count=0;
}

template<class T>
void DoublyCircularLL<T>::InsertFirst(T no)
{
	struct Node<T>*Newn=new Node<T>;
	
	Newn->Data=no;
	Newn->Next=NULL;
	Newn->Prev=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=Newn;
		Head->Prev=Newn;
		Tail=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head->Prev=Newn;
		Head=Newn;
	}
	Tail->Next=Head;
	Count++;
}


template<class T>
void DoublyCircularLL<T>::InsertLast(T no)
{
	struct Node<T>*Newn=new Node<T>;
	
	Newn->Data=no;
	Newn->Next=NULL;
	Newn->Prev=NULL;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		Head=Newn;
		Head->Prev=Newn;
		Tail=Newn;
	}
	else
	{
		Tail->Next=Newn;
		Newn->Prev=Tail;
		Tail=Newn;
	}
	Tail->Next=Head;
	Count++;
}

template<class T>
void DoublyCircularLL<T>::InsertAtPos(T no,int iPos)
{
	if((iPos<1)&&(iPos>Count+1))
	{
		cout<<"Invalid postion"<<endl;
		return;
	}
	else if(iPos==1)
	{
		InsertFirst(no);
	}
	else if(iPos==Count+1)
	{
		InsertLast(no);
	}
	else
	{
		struct Node<T>*Newn=new Node<T>;
		struct Node<T>*temp=Head;
	
		Newn->Data=no;
		Newn->Next=NULL;
		Newn->Prev=NULL;
		
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		Newn->Next=temp->Next;
		Newn->Next->Prev=Newn;
		Newn->Prev=temp;
		temp->Next=Newn;
		Count++;
	}
	Tail->Next=Head;
}

template<class T>
void DoublyCircularLL<T>::DeleteFirst()
{
	Head=Head->Next;
	delete Head->Prev;
	Head->Prev=NULL;
	Tail->Next=Head;
	Count--;
}

template<class T>
void DoublyCircularLL<T>::DeleteLast()
{
	struct Node<T>*temp=Head;
	if(Head==NULL && Tail==NULL)
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		while(temp->Next!=Tail)
		{
			temp=temp->Next;
		}
		delete temp->Next;
		Tail=temp;
		Tail->Next=Head;
	}
	Count--;
}

template<class T>
void DoublyCircularLL<T>::DeleteAtPos(int iPos)
{
	if((iPos<1)&&(iPos>Count))
	{
		cout<<"Invalid postion"<<endl;
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
		struct Node<T>*temp=Head;
		
		for(int i=1;i<iPos-1;i++)
		{
			temp=temp->Next;
		}
		temp->Next=temp->Next->Next;
		delete temp->Next->Prev;
		temp->Next->Prev=temp;
		Count--;
	}
}
template<class T>
void DoublyCircularLL<T>::Display()
{
	struct Node<T>*temp=Head;
	cout<<"Element of doubly circular LL are :"<<endl;
	
	do
	{
		cout<<"|"<<temp->Data<<"|->";
		temp=temp->Next;
	}while(temp!=Tail->Next);
	cout<<"NULL"<<endl;
}
template<class T>
int DoublyCircularLL<T>::CountNode()
{
	return Count;
}

int main()
{
	DoublyCircularLL<int>obj1;
	obj1.InsertFirst(50);
	obj1.InsertFirst(40);
	obj1.InsertFirst(30);
	obj1.InsertFirst(20);
	obj1.InsertFirst(10);
	obj1.Display();
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
	cout<<"Number of genric Doubly Circular LL is  :"<<obj1.CountNode()<<endl<<endl;
	
	return 0;
}
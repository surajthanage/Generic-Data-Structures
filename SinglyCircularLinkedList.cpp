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
class CircularLL
{
	private:
		struct Node<T>*Head;
		struct Node<T>*Tail;
		int Count;
		
	public:
		CircularLL();
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
CircularLL<T>::CircularLL()
{
	Head=NULL;
	Tail=NULL;
	int Count=0;
}

template<class T>
void CircularLL<T>::InsertFirst(T No)
{
	struct Node<T>*Newn=NULL;
	Newn=new Node<T>;
	
	Newn->Data=No;
	Newn->Next=NULL;
	
	if(Newn==NULL)
	{
		return;
	}
	else if((Head==NULL)&(Tail==NULL))
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Newn->Next=Head;
		Head=Newn;
	}
	Tail->Next=Head;
}

template<class T>
void CircularLL<T>::InsertLast(T No)
{
	struct Node<T>*Newn=NULL;
	Newn=new Node<T>;
	
	Newn->Data=No;
	Newn->Next=NULL;
	
	if(Newn==NULL)
	{
		return;
	}
	else if((Head==NULL)&(Tail==NULL))
	{
		Head=Newn;
		Tail=Newn;
	}
	else
	{
		Tail->Next=Newn;
		Tail=Newn;
	}
	Tail->Next=Head;
	
}

template<class T>
void CircularLL<T>::InsertAtPos(T No,int iPos)
{
	if((iPos<1)&(iPos>Count+1))
	{
		cout<<"Invalid postion"<<endl;
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
		struct Node<T>*Temp=Head;
		Newn=new Node<T>;
		
		Newn->Data=No;
		Newn->Next=NULL;
		
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Newn->Next=Temp->Next;
		Temp->Next=Newn;
		Tail->Next=Head;
		
	}
}

template<class T>
void CircularLL<T>::DeleteFirst()
{
	if((Head==NULL)&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Tail=NULL;
		Head=NULL;
	}
	else
	{
		Head=Head->Next;
		delete Tail->Next;
		Tail->Next=Head;
	}
	
}

template<class T>
void CircularLL<T>::DeleteLast()
{
	struct Node<T>*Temp=Head;
	
	if((Head==NULL)&(Tail==NULL))
	{
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Tail=NULL;
		Head=NULL;
	}
	else
	{
		while(Temp->Next!=Tail)
		{
			Temp=Temp->Next;
		}
		delete Temp->Next;
		Tail=Temp;
		Tail->Next=Head;
	}
}

template<class T>
void CircularLL<T>::DeleteAtPos(int iPos)
{
	if((iPos<1)&(iPos>Count))
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
		struct Node<T>*Temp=Head;
		struct Node<T>*Tempdel=Head;
		
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}
		Tempdel=Temp->Next;
		Temp->Next=Tempdel->Next;
		delete Tempdel;
		
	}
	Tail->Next=Head;
}
template<class T>
void CircularLL<T>::Display()
{
	struct Node<T>*Temp=Head;
	
	cout<<"Element of Genric Circular LL are :"<<endl;
	
	do
	{
		cout<<"|"<<Temp->Data<<"|->";
		Temp=Temp->Next;
	}while(Temp!=Tail->Next);
	
	cout<<"NULL"<<endl<<endl;
}

template<class T>
int CircularLL<T>::CountNode()
{
	int iCnt=0;
	struct Node<T>*Temp=Head;
	
	cout<<"Element of Genric Circular LL are :"<<endl;
	
	do
	{
		iCnt++;
		Temp=Temp->Next;
	}while(Temp!=Tail->Next);
	return iCnt;
}

int main()
{
	CircularLL<int>obj1;
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

	return 0;
}
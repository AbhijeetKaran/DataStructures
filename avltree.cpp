#include<iostream>

using namespace std;

class node
{
	public:
	int x;
	bool colr;
	node *next;

	node(int a,bool b)
	{
		x = a;
		colr = 0;
		next = NULL;	
	}
};

node *createnode(int x)
{
	node *p = new node(x,0);
	return p;	
}

void insertnode(node *h, int nn)
{
	auto q = h;
	while(q->next != NULL)
	{
		q = q->next;
	}
	q->next = createnode(nn);
}

void display(node *h)
{
	auto q = h;
	while(q != NULL)
	{
		cout<<q->x<<endl;
		q = q->next;
	}
}

int main()
{
	node *h = createnode(5);
	insertnode(h,7);
	insertnode(h,5);
	insertnode(h,6);
	insertnode(h,8);
	display(h);
	return 0;
}


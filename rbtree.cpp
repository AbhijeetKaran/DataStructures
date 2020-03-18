#include<iostream>

using namespace std;


class node
{
    public:
	node(int x) : number(x), color(1), parent(nullptr), left(nullptr), right(nullptr) {}	
	int number;
	bool color;
	node *parent;
	node *left;
	node *right;	
};



node *left_rotation(node *q)
{
	bool tcase;
	tcase = (q->right->right == nullptr) ? 1 : 0;
	node *x,*y,*z;
	x = q;
	y = q->right;
	if(tcase)
	{
		z = y->left;
		y->left = z->right;
		if(z->right != nullptr)
			z->right->parent = y;
		x->right = z->left;
		if(z->right != nullptr)
			z->right->parent = x;
		z->right = y;
		y->parent = z;
		z->parent = x->parent;
		if(x->parent != nullptr)
			x->parent->left = z;
		z->left = x;
		x->parent = z;
		return z;
	}
	else 
	{
		z = y->right;
		x->right = y->left;
		if(y->left != nullptr)
			y->left->parent = x;
		y->left = x;
		y->parent = x->parent;
		if(x->parent != nullptr)
			x->parent->right = y;
		x->parent = y;
		return y;
	}
}

node *right_rotation(node *q)
{
	bool tcase;
	tcase = (q->left->left == nullptr) ? 1 : 0;
	node *x,*y,*z;
	x = q;
	y = q->left;
	if(tcase)
	{
		z = y->right;
		y->right = z->left;
		if(z->left != nullptr)
			z->left->parent = y;
		x->left = z->right;
		if(z->left != nullptr)
			z->left->parent = x;
		z->left = y;
		y->parent = z;
		z->parent = x->parent;
		if(x->parent != nullptr)
			x->parent->right = z;
		z->right = x;
		x->parent = z;
		return z;
	}
	else 
	{
		z = y->left;
		x->left = y->right;
		if(y->right != nullptr)
			y->right->parent = x;
		y->right = x;
		y->parent = x->parent;
		if(x->parent != nullptr)
			x->parent->left = y;
		x->parent = y;
		return y;
	}
}

bool getdirection(node *c,node *gp)
{
	bool direction = (c->number > gp->number) ? 1 : 0;
	return direction;
}

node *insertnode(node *h,int x)
{
	if(h == NULL)
	{
		h = new node(x);
		h->color = 0;
		return h;
	}
	node *q = NULL;
	q = h;
	bool direction;
	while(((q->left != nullptr) || (q->right != nullptr)) || ((q->left != nullptr) && (q->right != nullptr)))
	{	
		if((q->number > x) && (q->left != nullptr))
			q = q->left;
		else if((q->number > x) && (q->left == nullptr))
			break;
		else if((q->number < x) && (q->right != nullptr))
			q = q->right;
		else if((q->number < x) && (q->right == nullptr))
			break;
	}
	if(q->number > x)
	{	
		q->left = new node(x);
		q->left->parent = q;
		q = q->left;
	}
	else
	{
		q->right = new node(x);
		q->right->parent = q;
		q = q->right;
	}
	if((q->parent)->parent != 0)
	{	
		while((q->color) && (q->parent->color))
		{
			direction = getdirection(q,q->parent->parent);
			if(direction == 0)
			{
				if(q->parent->parent->right != nullptr)
				{
					if(q->parent->parent->right->color)
					{
						q->parent->color = 0;
						q->parent->parent->right->color = 0;
						if(q->parent->parent->parent != 0)
						{
							q->parent->parent->color = 1;
							q = q->parent->parent;
						}
						else
						{
							q = q->parent->parent;
							return q;
						}
						
					}
					else
					{
						q = q->parent->parent;
						q = right_rotation(q);
						q->color = 0;
						q->right->color = 1;
						if(q->parent == nullptr)
							return q;
					}
				}
				else
				{
					q = q->parent->parent;
					q = right_rotation(q);
					q->color = 0;
					q->right->color = 1;
					if(q->parent == nullptr)
						return q;
				}
			}
			else
			{
				if(q->parent->parent->left != nullptr)
				{
					if(q->parent->parent->left->color)
					{
						q->parent->color = 0;
						q->parent->parent->left->color = 0;
						if(q->parent->parent->parent != 0)
						{
							q->parent->parent->color = 1;
							q = q->parent->parent;
						}
						else
						{
							q = q->parent->parent;
							return q;
						}
					}
					else
					{
						q = q->parent->parent;
						q = left_rotation(q);
						q->color = 0;
						q->left->color = 1;
						if(q->parent == nullptr)
							return q;
					}
				}
				else
				{
					q = q->parent->parent;
					q = left_rotation(q);
					q->color = 0;
					q->left->color = 1;
					if(q->parent == nullptr)
						return q;	
				}
			}				
		}
	}
	return h;		
}


void preorder(node *q)
{
	if(q != nullptr)
	{
		preorder(q->left);
		cout<<q->number<<"\t"<<q->color<<"\t"<<q->parent<<endl;
		preorder(q->right);
	}
}


int main()
{
	node *h = NULL;
	for(int i = 1;i<11;i++)
	{
		h = insertnode(h,i);
	}
	cout<<"PREORDER"<<endl;	
	preorder(h);
	return 0;
} 





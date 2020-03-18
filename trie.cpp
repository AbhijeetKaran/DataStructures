#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

struct trie
{
	char c;
	vector<trie*> branches;		
};

struct trie *root()
{
	trie *r = new trie();
	r->c = '$';
	r->branches = {};
	return r;
}

struct trie *charentry(char ch)
{
	trie *r = new trie();
	r->c = ch;
	r->branches = {};
	return r;
}

struct trie *trieinsertword(struct trie *h, char n)
{
	struct trie *q;
	q = h;
	bool found = false;
	if(q->branches.empty())
	{
		q->branches.insert(q->branches.end(),charentry(n));
		return q;
	}
	else
	{
		for(vector<struct trie*>::iterator ptr = q->branches.begin(); ptr < q->branches.end(); ptr++)
		{
			struct trie *g = *ptr;
			if(g->c == n)
			{
				found  = true;
				q = trieinsertword(g,n);
				return q;
			}
		}
	}				
}

void display(struct trie *h)
{
	struct trie *q;
	q = h;
	if(q->branches.empty())
	{
		cout<<"end of the trie"<<endl;
	}
	else
	{
		for(vector<struct trie*>::iterator ptr = q->branches.begin(); ptr < q->branches.end(); ptr++)
		{
			struct trie *g = *ptr;
			display(g);
			cout<<g->c<<endl;
		}
	}
	
}

int main()
{
	vector<string> st = {"hello","hellod"};
	struct trie *h,*q;
	h = NULL;
	for(vector<string>::iterator ptr = st.begin();ptr < st.end(); ptr++)
	{
		string hlp = *ptr;
		int i = hlp.length();
		//cout<<hlp<<"\t"<<i<<endl;
		int j = 0;
		while(j < i)
		{
			//cout<<"character "<<hlp[j]<<endl;
			if(h == NULL)
			{
				h = root();
			}
			else
			{
				q = h;
				q = trieinsertword(q,hlp[j]);
			}
		j++;
		}
	}
// does not work properly, do not mark the end character nodes and is not designed properly to display the characters

return 0;

}

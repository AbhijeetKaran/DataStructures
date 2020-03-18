#include<iostream>

using namespace std;

class ListNode
{
    public:
	ListNode(string chr_id,int hcode) : cid(chr_id), hashcode(hcode), next(NULL) {} 
	string cid;
	int hashcode;
	ListNode *next;
};

int hashc(string s1)
{
	int hashsum , is = 0;
	for(auto c : s1) {
		hashsum = hashsum + (int(c)*62^is); is++; }
	return hashsum;
}

ListNode *createnode(string id,int x)
{
	ListNode *p = new ListNode(id,x);
	return p;
}

ListNode *headnode(ListNode *h, ListNode *p)
{
	p->next = h;
	h = p;
	return h;
}

ListNode *insertnode(ListNode *h,string chid)
{
	int hd = hashc(chid);
	ListNode *p = createnode(chid,hd);
	ListNode *q = h;
	if(h == NULL) {
		h = p;
		return h; }	
	else if(hd < h->hashcode) {
		h = headnode(h,p);
		return h; }
	else {  while(q->next != NULL) {
			if((hd > q->hashcode) && (hd < q->next->hashcode)) {
				p->next = q->next;
				q->next = p;
				q = p;
				return h; }
			q = q->next; } }
	q->next = p;
	return h;
}

void display(ListNode *h)
{
	ListNode *q = h;
	while(q != NULL) {
		cout<<q->cid<<"\t"<<q->hashcode<<endl;
		q = q->next; }
}


int main()
{
	ListNode *h = NULL;
	for(int i=0;i<5;i++)
	{
		string c;
		cin>>c;
		h = insertnode(h,c);
	display(h);
	cout<<endl;
	}
	return 0;
}

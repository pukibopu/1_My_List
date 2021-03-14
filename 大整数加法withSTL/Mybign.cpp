#include<iostream>

#include<string>
using namespace std;
using namespace std;
typedef int ElemType;

struct LNode
{
	ElemType data;
	LNode* next;
};

struct LinkList
{
	LNode* head;

	void Init();
	void Clear();
	void Create(int n);
	int Locate(ElemType e);
	void InsertBefore(int i, ElemType e);
	void Delete(int i, ElemType& e);
	void Traverse();
	bool Empty();

};

void LinkList::Init()
{
	head = new LNode;
	head->next = NULL;
}

void LinkList::Clear()
{
	if (!head->next)
		return;
	LNode* temp = head->next;
	head->next = NULL;
	while (temp)
	{
		LNode* del = temp;
		temp = temp->next;
		delete del;
	}
}

bool LinkList::Empty()
{
	return head->next == NULL;
}

void LinkList::Create(int n)
{

	while (n--)
	{
		LNode* temp = new LNode;

		cin >> temp->data;
		temp->next = head->next;
		head->next = temp;

	}
}

int LinkList::Locate(ElemType e)
{
	LNode* p = head->next;
	int i = 0;
	while (p)
	{

		if (p->data == e)
		{
			return i;
		}
		i++;
		p = p->next;
	}
	return i;
}

void LinkList::InsertBefore(int i, ElemType e)
{
	LNode* p = head;
	i--;
	while (i--)
	{
		p = p->next;
	}
	LNode* q = new LNode;
	q->data = e;

	q->next = p->next;
	p->next = q;
}

void LinkList::Traverse()
{
	LNode* p = head->next;
	if (p != NULL)
		cout << p->data;
	p = p->next;
	while (p)
	{
		cout << p->data;
		p = p->next;
	}
}
void LinkList::Delete(int i, ElemType& e)
{
	LNode* p = head;
	i--;
	while (i--)
	{
		p = p->next;
	}
	LNode* del = p->next;
	e = p->next->data;

	p->next = p->next->next;

	delete del;
}

void string2list(string& s, LinkList& La)
{
	La.Init();
	for (int i=0;i<s.size();i++)
	{
		LNode* t = new LNode;
		t->data = s[i] - '0';
		t->next = La.head->next;
		La.head->next = t;
	}
}

void add(LinkList& La, LinkList& Lb, LinkList& Lc)  
{
	Lc.Init();
	if (!La.head->next)
	{
		Lc.head = Lb.head;
		return;
	}
	if (!Lb.head->next)
	{
		Lc.head = La.head;
		return;
	}

	LNode* p1 = La.head->next, * p2 = Lb.head->next, * q;
	int tempN = 0;

	q = new LNode;

	q->data = (p1->data + p2->data) % 10;
	q->next = Lc.head->next;
	Lc.head->next = q;
	tempN = (p1->data + p2->data) / 10;
	p1 = p1->next;
	p2 = p2->next;

	while (p1 && p2)
	{
		LNode* q = new LNode;
		q->next = Lc.head->next;
		Lc.head->next = q;


		int tmp = (p1->data + p2->data) + tempN;
		tempN = tmp / 10;
		q->data = tmp % 10;


		p1 = p1->next;
		p2 = p2->next;
	}

	while (p1)
	{
		LNode* q = new LNode;
		q->next = Lc.head->next;

		Lc.head->next = q;

		int tmp = p1->data + tempN;
		tempN = tmp / 10;
		q->data = tmp % 10;


		p1 = p1->next;
	}

	while (p2)
	{
		LNode* q = new LNode;
		q->next = Lc.head->next;

		Lc.head->next = q;

		int tmp = p2->data + tempN;
		tempN = tmp / 10;
		q->data = tmp % 10;


		p2 = p2->next;
	}

	if (tempN)
	{
		LNode* q = new LNode;
		q->data = tempN;
		q->next = Lc.head->next;
		Lc.head->next = q;
	}

}


int main()
{
	LinkList a,b,c;
	
	int n;
	cin >> n;
	while (n--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		string2list(s1, a);
		string2list(s2, b);
		add(a, b, c);

		c.Traverse();
		cout << endl;
		a.Clear();
		b.Clear();
		c.Clear();

	}
	
	return 0;
	
}
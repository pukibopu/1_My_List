#include<iostream>

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
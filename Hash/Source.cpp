#include <conio.h>
#include <iostream>

using namespace std;

class Node
{
	int key;
	Node *next;
public:
	Node(int k = 0, Node *nxt = 0)
	{
		key = k; next = nxt;
	}
	int & Key() { return key; }
	friend class List;
};

class List
{
	Node *head;
public:
	List() { head = 0; }
	~List() { Clear(); }

	void AddToTail(int x);  //void AddToHead(int x)
	Node *Find(int x);
	void DelHead()
	{
		Node *p = head;
		head = head->next;
		delete p;
	}
	void DelAfter(Node *pr)
	{
		Node *p = pr->next;
		pr->next = p->next;
		delete p;
	}

	void Print();
	void Clear();
	Node *Head() { return head; }
};

Node * List::Find(int x)
{
	if (head->key == x)
		return head;
	else
	{
		Node *p = head;
		while (p->next && p->next->key != x)
			p = p->next;
		if (p->next)
			return p;
		else return NULL;
	}
}

void List::Print()
{
	cout << head->key << ' ';
	Node *p = head->next;
	while (p)
	{
		cout << p->key << ' ';
		p = p->next;
	}
}

void List::Clear()
{
	while (head)
		DelHead();
}

void List::AddToTail(int x)
{
	if (!head)
	{
		Node *q;
		q = new Node;
		q->key = x;
		head = q;
	}
	else
	{
		Node *p = head;
		while (p->next)
			p = p->next;
		Node *q;
		q = new Node;
		q->key = x;
		p->next = q;
	}
}

int main()
{
	int a[15] = { 2, 6, 7, 3, 15, 16, 12, 1, 14, 8, 47, 99, 10, 48, 0 };//перечислены 15 чисел
	int p = 5, i, t, x, y;

	List *L;
	L = new List[p];
	for (i = 0; i<15; i++)
	{
		t = a[i] % p;
		L[t].AddToTail(a[i]);
	}

	cout << "Array of lists:" << endl;
	for (i = 0; i<p; i++)
	{
		cout << i << ": ";
		L[i].Print();
		cout << endl;
	}

	cout << endl;
	cout << "Input elements: ";
	cin >> x >> y;

	t = x % 5;
	Node *q;
	q = L[t].Find(x);
	if (q)
	{
		if (L[t].Head() != q)
			L[t].DelAfter(q);
		else L[t].DelHead();
	}
	else L[t].AddToTail(x);

	t = y % 5;
	q = L[t].Find(y);
	if (q)
	{
		if (L[t].Head() != q)
			L[t].DelAfter(q);
		else L[t].DelHead();
	}
	else L[t].AddToTail(y);

	cout << endl;
	for (i = 0; i<p; i++)
	{
		cout << i << ": ";
		L[i].Print();
		cout << endl;
		cout << endl;
	}

	system("PAUSE");
	return 0;
}

//задание: ввести 2 числа (одно есть в массиве,
//другого нет. То, которого нет - добавить; 
//то, которое есть - удалить


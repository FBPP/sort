#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node
{
	int data;
	Node * next;
	Node(int d):data(d), next(NULL)
	{
	}

};

vector<int> a = {5,4,3,2,1};

Node * create_list(vector<int>& a)
{
	Node * head = new Node(-1);
	int n = a.size(),
	    i = 0;
	Node * p = head;
	while(i < n)
	{
		p->next = new Node(a[i]);
		p = p->next;
		i++;
	}
	return head;
}
void printf_list(Node * p)
{
	if(!p)
	{
		cout << "NULL list" << endl;
		return;
	}
	p = p->next;
	while(p)
	{
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}
void delete_list(Node*& head)
{
	auto p = head;
	while(head)
	{
		head = head->next;
		delete p;
		p = head;
	}	
}
void quick_sort( Node * l, Node * r = NULL)
{
	if( l == NULL || r == l) return;
	Node * q = l,
	   * p = q->next;
	int x = l->data;
	while(p != r)
	{
		if(p ->data < x)
		{	
			q = q->next;
			swap(q->data,p->data);
		}
		p = p->next;

	}
	swap(l->data, q->data);
	quick_sort(l, q);
	quick_sort(q->next, r);
}
int main()
{
	Node * head = create_list(a);
	printf_list(head);
	quick_sort(head->next, NULL);
	printf_list(head);
	delete_list(head);	
	printf_list(head);
	return 0;
}

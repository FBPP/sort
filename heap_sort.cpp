#include <iostream>
#include <vector>
using namespace std;

void push_down(vector<int>&q, int size, int u)
{
	int t = u,
	    left = u * 2,
	    right = u * 2 +1;
	if(left <= size &&  q[t] < q[left]) t = left;
	if(right <= size &&  q[t] < q[right]) t = right;
	if(t != u)
	{
		swap(q[t],q[u]);
		push_down(q, size, t);
	}
}
void push_up(vector<int>& q, int u)
{
	while(u/2 && q[u/2] < q[u])
	{
		swap(q[u], q[u/2]);
		u /= 2;
	}
}
void insert(vector<int>& q, int& size, int val)
{
	q[++size] = val;
	push_up(q,size);
}
int pop(vector<int>& q, int& size)
{
	int t = q[1];
	q[1] = q[size--];
	push_down(q, size, 1);
	push_up(q,size);
	return t;
}
void print(vector<int>& q, int size)
{	
	for(int i = 1; i <= size; i++)
	cout << q[i] << ' ' ;
	cout << endl;
}
void heap_sort(vector<int>& q, int size)
{
	for(int i = 1; i <= size; i++)
	{
		push_up(q,i);
		
	}
	int n = size;
	for(int i = 1; i <= n; i++)
	{
		swap(q[1],q[size]);
		size--;
		push_down(q, size, 1);
	}
}
int main()
{
	vector<int> q;
	int n;
	cin >> n;
	q.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> q[i];
	print(q,n);
	heap_sort(q,n);
	print(q,n);
	int val;
	cin >> val;
	insert(q,n,val);
	print(q,n);
	cout << pop(q,n) << endl;
	print(q,n);
	heap_sort(q,n);
	print(q,n);


	return 0;
}


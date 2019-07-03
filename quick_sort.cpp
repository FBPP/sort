#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void quick_sort(vector<int>& q, int l, int r)
{
	if(l >= r)
		return;
	int i = l - 1,
	    j = r + 1,
	    x = q[l + r >> 1];
	while(i < j)
	{
		do j--; while(q[j] > x);
		do i++; while(q[i] < x);
		if(i < j) swap(q[i],q[j]);
		else quick_sort(q,l,j),quick_sort(q,j+1,r);
	}
}
int main()
{
	vector<int> q;
	int n;
	cin >> n;
	for(int i = 0 , k; i < n; i++)
	{
		cin >> k;
		q.push_back(k);

	}
	quick_sort(q,0,q.size()-1);
	for(auto x : q )
		cout << x << ' ';
	cout << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void insertionSort(vector<int>& q)
{
	for(int i = 1; i < q.size(); i++)
	{
		int t = q[i],j;
		for(j = i - 1; j >= 0; j--)
		{
			if(q[j] > t)
				q[j + 1] = q[j];
			else break;
		}
		q[j + 1] = t;
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
	insertionSort(q);
	for(auto x : q )
		cout << x << ' ';
	cout << endl;
	return 0;
}

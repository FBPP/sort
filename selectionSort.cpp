#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void selectionSort(vector<int>& q)
{
	for(int i = 0; i < q.size(); i++)
		for(int j = i + 1; j < q.size(); j++)
			if(q[i] > q[j])
			{
				swap(q[i],q[j]);
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
	selectionSort(q);
	for(auto x : q )
		cout << x << ' ';
	cout << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// o(n ^ 2)
void bubbleSort(vector<int>& q)
{
	for(int i = q.size()-1; i > 0; i--)
		for(int j = 0; j + 1 <= i; j++) //remember (j + 1 <= i)
			if(q[j] > q[j + 1])
			swap(q[j],q[j+1]);
}	
void bubbleSortPlus(vector<int>& q)
{
	for(int i = q.size()-1; i > 0; i--)
	{
		bool flag = false;
		for(int j = 0; j + 1 <= i; j++) //remember (j + 1 <= i)
			if(q[j] > q[j + 1])
			{
				swap(q[j],q[j+1]);
				flag = true;
			}
		if(!flag) return; // the vector is not be swaped,so it's ordered
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
//	bubbleSort(q);
	bubbleSortPlus(q);
	for(auto x : q )
		cout << x << ' ';
	cout << endl;
	return 0;
}

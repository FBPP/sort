#include <iostream>
#include <vector>
using namespace std;

//计数排序要求每个数   num       > 0 && num < cnt.size()
void counting_sort(vector<int> &q)
{
	vector<int> cnt(101, 0);
	for(int i = 1; i < q.size(); ++i)
		++cnt[q[i]];
	
	for(int i = 1, k = 1; i < cnt.size(); ++i)
		while(cnt[i]--)
			q[k++] = i;
}

int main()
{
	int n;
	cin >> n;
	vector<int> q(n + 1);
	for(int i = 1 , k; i <= n; i++)
	{
		cin >> k;
		q[i] = k;

	}
	counting_sort(q);
	
	for(int i = 1; i <= n; ++i)
		cout << q[i] << " ";
	cout << endl;
	return 0;

}

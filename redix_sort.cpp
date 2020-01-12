#include <iostream>
#include <vector>
using namespace std;

//基数排序看似很快, 但是除法和取余耗费时间很多, 实际时间比sort慢

int get(int x, int i)
{
	while(i--) x /= 10;
	return x % 10;
}

void redix_sort(vector<int> &q, int n)
{
	vector<vector<int>> cnt(10);
	for(int i = 0; i < 3; ++i)
		{
			for(int j = 0; j < 10; ++j) cnt[j].clear();
			for(int j = 1; j <= n; ++j)
				cnt[get(q[j], i)].push_back(q[j]);
			for(int j = 0, k = 1; j < 10; ++j)
				for(auto x : cnt[j])
					q[k++] = x;					
		}
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
	redix_sort(q, n);
	
	for(int i = 1; i <= n; ++i)
		cout << q[i] << " ";
	cout << endl;
	return 0;

}


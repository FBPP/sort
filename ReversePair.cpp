#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int merge_sort(vector<int> &q, int l, int r)
{
	if(l >= r)
		return 0;
	int res = 0;
	int mid = (l + r)/2;
	res += merge_sort(q, l, mid);
	res += merge_sort(q, mid+1, r);
	static vector<int> w;
	w.clear();
	int i = l,
	    j = mid + 1;
	while(i <= mid && j <= r)
		if(q[i] <= q[j])
			w.push_back(q[i++]);
		else
		{
		       	w.push_back(q[j++]);
			res += mid - i + 1;
		}
	while(i <= mid) w.push_back(q[i++]);
	while(j <= r) w.push_back(q[j++]);
	for(i = l,j = 0 ; j < w.size(); i++,j++) q[i] = w[j];
	return res;

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
	cout << merge_sort(q, 0, q.size()-1) << endl;
	for(auto x : q )
		cout << x << ' ';
	cout << endl;
	return 0;
}

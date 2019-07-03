#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void merge_sort(vector<int> &q, int l, int r)
{
	if(l >= r)
		return;
	int mid = (l + r)/2;
	merge_sort(q, l, mid);
	merge_sort(q, mid+1, r);
	static vector<int> w;
	w.clear();
	int i = l,
	    j = mid + 1;
	while(i <= mid && j <= r)
		if(q[i] <= q[j])
			w.push_back(q[i++]);
		else w.push_back(q[j++]);
	while(i <= mid) w.push_back(q[i++]);
	while(j <= r) w.push_back(q[j++]);
	for(i = l,j = 0 ; i < w.size(); i++,j++) q[i] = w[j];

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
	merge_sort(q, 0, q.size()-1);
	for(auto x : q )
		cout << x << ' ';
	cout << endl;
	return 0;
}

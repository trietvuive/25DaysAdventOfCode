#include<unordered_set>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define long long ll
int main()
{
	vector<int>v;
	int temp;
	while (cin >> temp)
	{
		if (cin.eof())
			break;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	int n = v.size();
	int res1 = 0;
	int res2 = 0;
	int res3 = 0;
	bool finished = false;
	for (int i = 0; i < n; i++)
	{
		if (finished)
			break;
		int a = v[i];
		int left = i + 1;
		int right = n - 1;
		while (left < right)
		{
			if (a + v[left] + v[right] == 2020)
			{
				res1 = a;
				res2 = v[left];
				res3 = v[right];
				finished = true;
				break;
			}
			else if (a + v[left] + v[right] < 2020)
				left++;
			else
				right--;
		}
	}
	cout << res1 * res2 * res3;
}
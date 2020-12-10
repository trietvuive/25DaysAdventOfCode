/*#include<set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
#define ll long long
vector<int>subsetSum(vector<int>list, int sum);
int main()
{
	int temp;
	int _max = INT32_MIN;
	vector<int>jolt;
	while (cin >> temp) {
		_max = max(_max, temp);
		jolt.push_back(temp);
	}
	jolt.push_back(0);
	sort(jolt.begin(), jolt.end());
	int diff1 = 0;
	int diff3 = 0;
	for (int i = 0; i < jolt.size() - 1; i++)
	{
		if (jolt[i + 1] - jolt[i] == 1)
			diff1++;
		if (jolt[i + 1] - jolt[i] == 3)
			diff3++;
	}
	diff3++;
	cout << diff1 * diff3 << endl;
	vector<ll>dp(_max + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < jolt.size(); i++)
	{
		dp[jolt[i]] += jolt[i] - 1 >= 0 ? dp[jolt[i] - 1] : 0;
		dp[jolt[i]] += jolt[i] - 2 >= 0 ? dp[jolt[i] - 2] : 0;
		dp[jolt[i]] += jolt[i] - 3 >= 0 ? dp[jolt[i] - 3] : 0;
	}
	for (ll i : dp)
		cout << i << " ";
	cout << dp[_max] << endl;
	return 0;
}*/
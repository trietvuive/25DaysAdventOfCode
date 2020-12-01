/*#include<unordered_set>
#include <iostream>
using namespace std;
#define long long ll
int main()
{
	unordered_set<int>s;
	int temp;
	int res1 = 0;
	int res2 = 0;
	while (cin >> temp)
	{
		if (cin.eof())
			break;
		if (s.count(2020 - temp) == 1)
		{
			res1 = temp;
			res2 = 2020 - temp;
		}
		s.insert(temp);
	}
	cout << endl;
	cout << res1 * res2 << endl;
}*/
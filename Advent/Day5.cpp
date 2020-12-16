/*#include<unordered_set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define long long ll
int main()
{
	string temp;
	int maxid = 0;
	int ans = 0;
	unordered_set<int>seat;
	for (int i = 0; i < 1000; i++)
		seat.insert(i);
	while (getline(cin, temp))
	{
		if (temp.size() == 0)
			break;
		int rowfront = 0;
		int rowback = 127;
		for (int i = 0; i < 7; i++)
		{
			int mid = (rowback + rowfront + 1) / 2;
			if (temp[i] == 'F')
				rowback = mid - 1;
			else
				rowfront = mid;
		}
		int row = rowfront;
		int columnleft = 0;
		int columnright = 7;
		for (int i = 7; i < 10; i++)
		{
			int mid = (columnright + columnleft + 1) / 2;
			if (temp[i] == 'R')
				columnleft = mid;
			else
				columnright = mid - 1;
		}
		int column = columnleft;
		int seatid = row * 8 + column;
		seat.erase(seatid);
		ans = max(ans, seatid);
	}
	for (int i : seat)
	{
		cout << i << " ";
	}
	cout << ans;
}*/
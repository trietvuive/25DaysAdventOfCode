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
vector<vector<char>>matrix;
int width, height;
int x_increase[] = { -1,-1,-1,0,0,1,1,1 };
int y_increase[] = { -1, 0, 1, -1, 1, -1,0,1 };
bool switchSeat(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		int tempx = x, tempy = y;
		tempx += x_increase[i], tempy += y_increase[i];
		while (tempx >= 0 && tempx < height && tempy >= 0 && tempy < width && matrix[tempx][tempy] == '.')
			tempx += x_increase[i], tempy += y_increase[i];
		if (tempx >= 0 && tempx < height && tempy >= 0 && tempy < width)
			if (matrix[tempx][tempy] == '#')
				count++;
	}
	if (matrix[x][y] == 'L' && count == 0)
		return true;
	if (matrix[x][y] == '#' && count >= 5)
		return true;
	return false;
}
bool simulateRound()
{
	vector<pair<int, int>>seat_switch;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			bool swap = switchSeat(i, j);
			if (swap)
				seat_switch.push_back(pair<int, int>(i, j));
;		}
	}
	if (seat_switch.size() == 0)
		return false;
	for (pair<int, int> pair : seat_switch)
	{
		if (matrix[pair.first][pair.second] == '#')
			matrix[pair.first][pair.second] = 'L';
		else
			matrix[pair.first][pair.second] = '#';
	}
	return true;
}
int main()
{
	string temp;
	while (getline(cin, temp))
	{
		if (temp.size() == 0)
			break;
		vector<char>v;
		for (char i : temp)
			v.push_back(i);
		matrix.push_back(v);
	}
	width = matrix[0].size();
	height = matrix.size();
	bool simulating = true;
	while (simulating)
		simulating = simulateRound();
	int occupiedSeat = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] == '#')
				occupiedSeat++;
		}
	}
	cout << occupiedSeat << endl;

}*/
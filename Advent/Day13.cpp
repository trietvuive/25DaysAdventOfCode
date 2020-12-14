/*#include<set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <queue>
#include <unordered_set>
#include<math.h>
#include<complex>
#define ll long long;
using namespace std;
vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}
int extendedgcd(int a, int b, int& x, int& y)
{
	if (a == 0)
	{
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int gcd = extendedgcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return gcd;
}
int mod_inverse(int a, int m)
{
	int x, y;
	int g = extendedgcd(a, m, x, y);
	return (x % m + m) % m;
}
int main()
{
	int timestamp;
	cin >> timestamp;
	vector<int>bus;
	vector<int>rem;
	string temp;
	getline(cin, temp);
	getline(cin, temp);
	vector<string>line_split = split(temp, ",");
	for (int i = 0; i < line_split.size();i++)
	{
		if (line_split[i] == "x")
			continue;
		int busid = stoi(line_split[i]);
		bus.push_back(busid);
		int remainder = -i;
		while (remainder < 0)
			remainder += busid;
		rem.push_back(remainder);
	}
	int minbusid = -1;
	int minwaittime = INT32_MAX;
	long long product = 1;
	for (int i = 0; i < bus.size(); i++)
		product *= bus[i];
	long long result = 0;

	for (int i = 0; i < bus.size(); i++)
	{
		long long pp = product / bus[i];
		long long mod_inv = mod_inverse(pp, bus[i]);
		result += (long long)rem[i] * mod_inv * pp;
	}
	result %= product;
	cout << result % product << endl;
}*/
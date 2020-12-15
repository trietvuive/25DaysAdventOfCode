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
#include<bitset>
#define ll long long;
using namespace std;
bitset<36> mask;
vector<int>x_location;
unordered_map<long long, long long>map;
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
int getBit(long long ID, long long position)
{
	long long shift = ID >> position;
	return (ID >> position) & 1;
}
void qubit_weird_shit(int i,bitset<36> &mask_index, long long mask_value)
{
	if (i == x_location.size())
	{
		long long index = mask_index.to_ullong();
		map[index] = mask_value;
		return;
	}
	mask_index[x_location[i]] = 0;
	qubit_weird_shit(i+1,mask_index, mask_value);
	mask_index[x_location[i]] = 1;
	qubit_weird_shit(i+1,mask_index, mask_value);
}
int main()
{
	string line;
	while (getline(cin, line))
	{
		if (line.size() == 0)
			break;
		vector<string> command_split = split(line, "= "); 
		if (command_split[0] == "mask ")
		{
			string mask_s = command_split[1];
			int n = mask_s.size();
			x_location = vector<int>();
			for (int i = 0; i < n; i++)
			{
				if (mask_s[i] == 'X')
					x_location.push_back(n-1-i);
			}
			replace(mask_s.begin(), mask_s.end(), 'X', '0');
			mask = bitset<36>(mask_s);
		}
		else
		{
			int n = command_split[0].size();
			int index = stoi(command_split[0].substr(4, n - 6));
			int value = stoi(command_split[1]);
			bitset<36>mask_value = mask;
			for (int i : x_location)
			{
				mask_value[i] = getBit(value, i);
			}
			value = (long long)value;
			bitset<36>mask_index = mask;
			mask_index |= index;
			qubit_weird_shit(0, mask_index, value);
		}
	}
	long long result = 0;
	for (pair<int, long long>pair : map)
	{
		result += pair.second;
	}
	cout << result << endl;
}*/
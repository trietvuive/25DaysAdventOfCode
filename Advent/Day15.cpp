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
#include<chrono>
#define ll long long;
using namespace std; 
using namespace std::chrono;
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
int main()
{
	unordered_map<long long, long long>tracker;
	string line;
	getline(cin, line);
	long long last = -1;
	long long curr = -1;
	vector<string> line_separate = split(line, ",");
	long long index = 1;
	for (int i = 0;i<line_separate.size()-1;i++)
	{
		int digit = stoi(line_separate[i]);
		tracker[digit] = index++;
	}
	last = stoi(line_separate.back());
	curr = last;
	while (index < 30000000)
	{
		auto start = high_resolution_clock::now();
		last = curr;
		if (!tracker[last])
			curr = 0;
		else
			curr = index-tracker[last];
		index++;
		tracker[last] = index-1;
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		cout << "Time taken by function: "
			<< duration.count() << " nanoseconds" << endl;
	}
	cout << curr << endl;
	return 0;

}*/
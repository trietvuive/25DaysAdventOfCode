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
	vector<int>range_check(1000, 0);
	unordered_map<string, vector<int>>range_mapping;
	unordered_map<string, int>true_mapping;
	unordered_map<string, unordered_set<int>>elimination_map;
	vector<int>my_ticket;
	vector<vector<int>> other_tickets;
	vector<int>check_ticket(1000,0);
	int result = 0;
	string line;
	while (getline(cin, line))
	{
		if (line.size() == 0)
			break;
		vector<string> range = split(split(line, ": ")[1]," or ");
		for (string i : range)
		{
			vector<string>endpoints = split(i, "-");
			int start = stoi(endpoints[0]);
			int end = stoi(endpoints[1]);
			string name = split(line, ": ")[0];
			range_mapping[name].push_back(start);
			range_mapping[name].push_back(end);
			for (int i = start; i <= end; i++)
				range_check[i] = 1;
			elimination_map[name] = unordered_set<int>();
		}
	}
	getline(cin, line);
	getline(cin, line);
	for (string i : split(line, ","))
		my_ticket.push_back(stoi(i));
	int n = my_ticket.size();
	for (int i = 0; i < n; i++)
		for (pair<string, unordered_set<int>> it : elimination_map)
			elimination_map[it.first].insert(i);
	getline(cin, line);
	getline(cin, line);
	while (getline(cin, line))
	{
		if (line.size() == 0)
			break;
		vector<string>number_list = split(line, ",");
		vector<int>ticket;
		bool false_ticket = false;
		for (string i : number_list)
		{
			int num = stoi(i);
			if (!range_check[num])
				false_ticket = true;
			ticket.push_back(num);
		}
		other_tickets.push_back(ticket);
		if (!false_ticket)
		{
			for (pair<string, unordered_set<int>>it : elimination_map)
			{
				vector<int> pair = range_mapping[it.first];
				for (const int elem : it.second)
				{
					if ((pair[0] <= ticket[elem] && ticket[elem] <= pair[1]) ||
						(pair[2] <= ticket[elem] && ticket[elem] <= pair[3]))
						continue;
					else
						elimination_map[it.first].erase(elem);
				}
			}
		}
	}
	while (!elimination_map.empty())
	{
		vector<string>elimination;
		for (pair<string, unordered_set<int>>it : elimination_map)
		{
			if (it.second.size() == 1)
			{
				int element = -1;
				for (const int elem : it.second)
					element = elem;
				for (pair<string, unordered_set<int>> it : elimination_map)
					elimination_map[it.first].erase(element);
				true_mapping[it.first] = element;
				elimination.push_back(it.first);
			}
		}
		for (string i : elimination)
			elimination_map.erase(i);
	}
	long long product = 1;
	int count = 0;
	for (pair<string, int>it : true_mapping)
	{
		if (it.first.find("departure") != string::npos)
		{
			product *= my_ticket[it.second];
			count++;
		}
		cout << it.first << " "<<it.second << endl;
	}
	cout << count<<" "<<product << endl;
	return 0;
}*/
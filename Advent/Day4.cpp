/*#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include <unordered_set>
using namespace std;
#define ll long long
bool fourdigits(string i, int start, int end);
bool hgt(string hgt);
bool ecl(string ecl);
bool hcl(string hcl);
bool pid(string pid);
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
	string passport;
	string temp;
	int ans = 0;
	while (getline(cin,temp))
	{
		if(temp == ":")
			break;
		if (temp.size() == 0)
		{
			unordered_set<string> required;
			required.insert("byr");
			required.insert("iyr");
			required.insert("eyr");
			required.insert("hgt");
			required.insert("hcl");
			required.insert("ecl");
			required.insert("pid");

			passport += " " + temp;
			vector<string>element = split(passport, " ");
			bool valid = true;
			for (string i : element)
			{
				string type = i.substr(0, 3);
				required.erase(type);
				if (type == "byr")
					valid &= fourdigits(i, 1920, 2002);
				if (type == "iyr")
					valid &= fourdigits(i, 2010, 2020);
				if (type == "eyr")
					valid &= fourdigits(i, 2020, 2030);
				if (type == "hgt")
					valid &= hgt(i);
				if (type == "hcl")
					valid &= hcl(i);
				if (type == "ecl")
					valid &= ecl(i);
				if (type == "pid")
					valid &= pid(i);
			}
			if (required.size() == 0 && valid)
				ans++;
			passport = "";
		}
		else
		{
			passport += " "+temp;
		}
	}
	cout << ans;
	return 0;

}
bool fourdigits(string byr,int start,int end)
{
	int by = stoi(byr.substr(4, 4));
	return by >= start && by <= end;
}
bool hgt(string hgt)
{
	int n = hgt.size();
	string measurement = hgt.substr(n - 2, 2);
	if (measurement != "cm" && measurement != "in")
		return false;
	string h = split(hgt, ":")[1];
	h.pop_back();
	h.pop_back();
	int height = stoi(h);
	if (measurement == "cm" && height >= 150 && height <= 193)
		return true;
	if (measurement == "in" && height >= 59 && height <= 76)
		return true;
	return false;
}
bool hcl(string hcl)
{
	string hair = split(hcl, ":")[1];
	if (hair[0] != '#')
		return false;
	if (hair.size() != 7)
		return false;
	for (int i = 1; i < hair.size(); i++)
	{
		if (!((hair[i] >= '0' && hair[i] <= '9') || (hair[i] >= 'a' && hair[i] <= 'f')))
			return false;
	}
	return true;
}
bool ecl(string ecl)
{
	string amb = split(ecl, ":")[1];
	return amb == "amb" || amb == "blu" || amb == "brn" || amb == "gry" || amb == "grn" || amb == "hzl" || amb == "oth";
}
bool pid(string pid)
{
	pid = split(pid, ":")[1];
	try
	{
		int passport = stoi(pid);
	}
	catch (...)
	{
		return false;
	}
	return pid.size() == 9;
}*/
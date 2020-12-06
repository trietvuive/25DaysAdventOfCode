/*#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
#define long long ll
vector<string> split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}
int main()
{
    string line;
    int ans = 0;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            break;
        vector<string>colon = split(line, ':');
        vector<string>spaceleft = split(colon[0], ' ');
        vector<string>range = split(spaceleft[0], '-');
        int min = stoi(range[0]);
        int max = stoi(range[1]);
        char c = spaceleft[1][0];
        string haystack = colon[1];
        if ((haystack[min] == c) ^ (haystack[max] == c))
            ans++;
    }
    cout << ans;
    return 0;
}*/
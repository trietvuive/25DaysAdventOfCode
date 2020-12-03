/*#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
#define long long ll
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
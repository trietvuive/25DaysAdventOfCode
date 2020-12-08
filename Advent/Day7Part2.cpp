/*#include<set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <queue>

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
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}
int main()
{
    string line;
    unordered_map<string, set<string>> graph;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            break;
        if (line.find("no other") != string::npos)
            continue;
        vector<string>comma_splitted = split(line, ", ");
        vector<string> first_phrase = split(comma_splitted[0], " ");
        set<string> contained_color_set;
        string container_color = first_phrase[0] + first_phrase[1];
        for (int i = 0; i < comma_splitted.size(); i++)
        {
            vector<string> phrase = split(comma_splitted[i], " ");
            int n = phrase.size();
            string contained_color = phrase[n - 3] + phrase[n - 2];
            contained_color_set.insert(contained_color+" "+phrase[n-4]);
        }
        if (graph.find(container_color) != graph.end())
            graph[container_color].insert(contained_color_set.begin(),contained_color_set.end());
        else
        {
            graph[container_color] = contained_color_set;
        }
    }
    set<string>container_set = graph["shinygold"];
    queue<pair<string,int>>q;
    for (set<string>::iterator it = container_set.begin(); it != container_set.end(); ++it) {
        string repr = *it;
        vector<string>space_sep = split(repr, " ");
        pair<string, int>p = make_pair(space_sep[0], stoi(space_sep[1]));
        q.push(p);
    }
    int ans = 0;
    while (q.size() != 0)
    {
        pair<string, int>pa = q.front();
        ans += q.front().second;
        q.pop();
        container_set = graph[pa.first];    
        for (set<string>::iterator it = container_set.begin(); it != container_set.end(); ++it) {
            string repr = *it;
            vector<string>space_sep = split(repr, " ");
            pair<string,int> p = make_pair(space_sep[0], stoi(space_sep[1])*pa.second);
            q.push(p);
        }
    }
    for (pair<string, set<string>> element : graph)
    {
        cout << element.first << ": ";
        for (set<string>::iterator it = element.second.begin(); it != element.second.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << ans << endl;
    return 0;

}*/
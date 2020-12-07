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
    queue<string>q;
    set<string> container_set;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            break;
        if (line.find("no other") != string::npos)
            continue;
        vector<string>comma_splitted = split(line, ", ");
        vector<string> first_phrase = split(comma_splitted[0], " ");
        string container_color = first_phrase[0] + first_phrase[1];
        for (int i = 0; i < comma_splitted.size(); i++)
        {
            vector<string> phrase = split(comma_splitted[i], " ");
            int n = phrase.size();
            string contained_color = phrase[n - 3] + phrase[n - 2];
            if (graph.find(contained_color) != graph.end())
                graph[contained_color].insert(container_color);
            else
            {
                set<string>temp;
                temp.insert(container_color);
                graph[contained_color] = temp;
            }
        }
    }
    container_set = graph["shinygold"];
    for (set<string>::iterator it = container_set.begin(); it != container_set.end(); ++it) {
        q.push(*it);
    }
    while (q.size() != 0)
    {
        string container = q.front();
        q.pop();
        set<string> temp_set = graph[container];
        for (set<string>::iterator it = temp_set.begin(); it != temp_set.end(); ++it) {
            q.push(*it);
            container_set.insert(*it);
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

    cout << container_set.size() << endl;
    return 0;

}*/
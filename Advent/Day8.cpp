#include<set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <queue>

using namespace std;
#define long long ll
int test_acc(vector<string>command);
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
    vector<string>command_vector;
    vector<bool>visited;
    int acc = 0;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            break;
        command_vector.push_back(line);
        visited.push_back(false);
    }
    int i = 0;
    vector<int>command_to_change;
    while (!visited[i])
    {
        command_to_change.push_back(i);
        visited[i] = true;
        vector<string>command_split = split(command_vector[i], " ");
        if (command_split[0] == "acc")
        {
            acc += stoi(command_split[1]);
            i++;
        }
        if (command_split[0] == "jmp")
            i += stoi(command_split[1]);
        if (command_split[0] == "nop")
            i++;

    }
    sort(command_to_change.begin(), command_to_change.end());
    for (int i : command_to_change)
    {
        vector<string> command_split = split(command_vector[i], " ");
        if (command_split[0] == "nop" || command_split[0] == "jmp")
        {
            if(command_split[0] == "nop")
                command_vector[i] = "jmp " + command_split[1];
            else
                command_vector[i] = "nop " + command_split[1];
            int result = test_acc(command_vector);
            if (result != -1)
            {
                cout << result;
                break;
            }
            command_vector[i] = command_split[0] + " " + command_split[1];
        }

    }
}
int test_acc(vector<string>command)
{
    vector<bool>visited;
    for (int i = 0; i < command.size(); i++)
        visited.push_back(false);
    int i = 0;
    int acc = 0;
    while (i<visited.size() && !visited[i])
    {
        visited[i] = true;
        vector<string>command_split = split(command[i], " ");
        if (command_split[0] == "acc")
        {
            acc += stoi(command_split[1]);
            i++;
        }
        if (command_split[0] == "jmp")
            i += stoi(command_split[1]);
        if (command_split[0] == "nop")
            i++;

    }
    if (i == command.size())
        return acc;
    return -1;
}
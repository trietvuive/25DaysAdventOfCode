/*#include<set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <queue>
#include<stack>
#include <unordered_set>
#include<math.h>
#include<complex>
#include<bitset>
#include<chrono>
typedef long long ll;
using namespace std;
unordered_map<queue<int>,vector<queue<int>>>anti_recursion;
bool recursion_combat(queue<int> p_1, queue<int> p_2)
{
	while (!p_1.empty() && !p_2.empty())
	{
		if (anti_recursion.count(p_1) == 0)
			anti_recursion[p_1] = vector<queue<int>>();
		vector<queue<int>> v = anti_recursion[p_1];
		if (find(v.begin(),v.end(),p_2)!= v.end())
			return true;
		anti_recursion[p_1].push_back(p_2);
		int card1 = p_1.front(); p_1.pop();
		int card2 = p_2.front(); p_2.pop();
		if (card1 <= p_1.size() && card2 <= p_2.size())
		{
			queue<int>temp1 = p_1;
			queue<int>temp2 = p_2;
			queue<int>sub_1;
			queue<int>sub_2;
			for (int i = 0; i < card1; i++)
			{
				sub_1.push(temp1.front());
				temp1.pop();
			}
			for (int i = 0; i < card2; i++)
			{
				sub_2.push(temp2.front());
				temp2.pop();
			}
			if (recursion_combat(sub_1, sub_2))
			{
				p_1.push(card1); p_1.push(card2);
			}
			else
			{
				p_2.push(card2); p_2.push(card1);
			}
		}
		else if (card1 > card2)
		{
			p_1.push(card1); p_1.push(card2);
		}
		else {
			p_2.push(card2); p_2.push(card1);
		}
	}
	return p_2.empty();
}
int main()
{
	queue<int>player_1;
	queue<int>player_2;
	string line;
	getline(cin, line);
	while (getline(cin, line))
	{
		if (line.size() == 0)
			break;
		player_1.push(stoi(line));
	}
	getline(cin, line);
	while (getline(cin, line))
	{
		if (line.size() == 0)
			break;
		player_2.push(stoi(line));
	}
	recursion_combat(player_1, player_2);
	queue<int>winner = player_1.empty() ? player_2 : player_1;
	ll score = 0;
	while (!winner.empty())
	{
		score += (ll)winner.front() * winner.size();
		winner.pop();
	}
	cout << score << endl;

	return 0;
}*/
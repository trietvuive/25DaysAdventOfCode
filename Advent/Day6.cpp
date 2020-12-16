/*#include<unordered_set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define long long ll
int main()
{
	string temp;
	unordered_set<char>s;
	int ans = 0;
	int person_index = 0;
	while (getline(cin, temp))
	{
		if (temp.size() == 0)
		{
			ans += s.size();
			person_index = 0;
			s.clear();
		}
		else if (temp == ":")
			break;
		else
		{
			if (person_index == 0)
			{
				for (char i : temp)
					s.insert(i);
			}
			else
			{
				unordered_set<char>temp_set;
				for (char i : temp)
					if (s.count(i) > 0)
						temp_set.insert(i);
				s = temp_set;
			}
			person_index++;
		}
	}
	std::cout<<ans;
	return 0;
}*/
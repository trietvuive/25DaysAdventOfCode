#include<set>
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
#define ll long long;
using namespace std;
static int precedence(char c)
{
	if (c == '*' || c == '/')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	return -1;
}
long long process(stack<long long>&operand, stack<char>&signs)
{
	long long two = operand.top();
	operand.pop();
	long long one = operand.top();
	operand.pop();
	char oper = signs.top();
	signs.pop();
	if (oper == '+')
		return one + two;
	if (oper == '/')
		return one / two;
	if (oper == '*')
		return one * two;
	if (oper == '-')
		return one - two;
	return -1;
}
int main()
{
	string line;
	long long result = 0;
	while (getline(cin, line))
	{
		stack<char>math_signs;
		stack<long long>operand;
		if (line.size() == 0)
			break;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ')
				continue;
			else if (line[i] == '(')
				math_signs.push(line[i]);
			else if (line[i] >= '0' && line[i] <= '9')
				operand.push(line[i]-48);
			else if (line[i] != ')'){
				if (math_signs.size() != 0)
					while (math_signs.size() != 0 && precedence(line[i])<=precedence(math_signs.top()))
						operand.push(process(operand, math_signs));
				math_signs.push(line[i]);
			}
			else
			{
				while (math_signs.top() != '(')
					operand.push(process(operand,math_signs));
				math_signs.pop();
			}
		}
		while (math_signs.size() != 0)
			operand.push(process(operand, math_signs));
		result += operand.top();
		cout << operand.top() << " " << result << endl;
	}
	cout << result << endl;
	return 0;
}
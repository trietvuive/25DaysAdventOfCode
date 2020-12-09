#include<set>
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
#define long long ll
vector<int>subsetSum(vector<int>list, int sum);
int main()
{
    int target = 32321523;
    vector<int>vect;
    int temp;
    int result = 0;
    while (cin >> temp)
    {
        if (temp == target)
            break;
        vect.push_back(temp);
    }
    cout << endl;
    vector<int> res = subsetSum(vect, target);
    cout << res[0] << " " << res[1] << endl;
    int _min = INT32_MAX;
    int _max = INT32_MIN;
    for (int i = res[0]; i < res[1]; i++)
    {
        _min = min(vect[i], _min);
        _max = max(vect[i], _max);
    }
    cout << _min+_max << endl;
}
vector<int>subsetSum(vector<int>list, int sum)
{
    int start = 0;
    int end = 0;
    int curr_sum = 0;
    while (end < list.size())
    {
        if (curr_sum < sum)
        {
            curr_sum += list[end++];
        }
        else if (curr_sum == sum)
            return vector<int>{start, end};
        else
        {
            curr_sum -= list[start++];
        }
    }
}
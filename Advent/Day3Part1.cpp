/*#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;
#define ll long long
int main()
{
    string line;
    int i1 = 0;
    int i3 = 0;
    int i5 = 0;
    int i7 = 0;
    ll tree1 = 0;
    ll tree3 = 0;
    ll tree5 = 0;
    ll tree7 = 0;
    ll treeskip = 0;
    int skip1 = 0;
    int n = 0;
    while (getline(cin, line))
    {
        if (line.size() == 0)
            break;
        if (line[i1 % line.size()] == '#')
            tree1++;
        i1++;
        if (line[(i3) % line.size()] == '#')
            tree3++;
        i3 += 3;
        if (line[(i5) % line.size()] == '#')
            tree5++;
        i5 += 5;
        if (line[(i7) % line.size()] == '#')
            tree7++;
        i7 += 7;
        if (n % 2 == 0)
        {
            if (line[skip1 % line.size()] == '#')
                treeskip++;
            skip1++;
        }
        n++;
    }
    cout << tree1 << " " << tree3 << " " << tree5 << " " << tree7 << " " << treeskip << endl;
    cout << tree1*tree3*tree5*tree7*treeskip;
    return 0;
}*/
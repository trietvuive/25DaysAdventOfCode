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
struct Node
{
    int val;
    Node* next;
    Node* prev;
};

int main()
{
    int numballs = 1000000;
    vector<Node*> nodeptrs(numballs + 1);
    string order = "589174263";
    Node* buf = NULL;
    for (int i = 0; i < numballs; i++)
    {

        Node* n;
        if (i < order.length())
            n = new Node({ order[i] - '0',NULL,NULL });
        else
            n = new Node({ i + 1, NULL, NULL });
        nodeptrs[n->val] = n;
        if (buf == NULL)
        {
            buf = n;
            buf->next = buf;
            buf->prev = buf;
        }
        else
        {
            Node* last = buf->prev;
            last->next = n;
            n->prev = last;
            n->next = buf;
            buf->prev = n;
        }
    }
    int nmoves = 10000000;
    for (int move = 0; move < nmoves; move++)
    {
        if (move % 1000000 == 0)
            cout << move << std::endl;
        Node* n1 = buf->next;
        Node* n2 = n1->next;
        Node* n3 = n2->next;
        std::set<int> removedvals;
        removedvals.insert(n1->val);
        removedvals.insert(n2->val);
        removedvals.insert(n3->val);
        int nextval = buf->val;
        nextval = 1 + ((numballs + nextval - 2) % numballs);
        while (removedvals.count(nextval))
        {
            nextval = 1 + ((numballs + nextval - 2) % numballs);
        }

        buf->next = n3->next;
        n3->next->prev = buf;

        Node* destcup = nodeptrs[nextval];
        Node* nn = destcup->next;
        destcup->next = n1;
        n1->prev = destcup;
        n3->next = nn;
        nn->prev = n3;
        buf = buf->next;
    }
    Node* one = nodeptrs[1];
    ll val1 = one->next->val;
    ll val2 = one->next->next->val;
    cout << val1 * val2 << endl;
    Node* temp = one;
    one = one->next;
    /*while (one!= temp)
    {
        std::cout << one->val;
        one = one->next;
    }
    cout << endl;
}*/
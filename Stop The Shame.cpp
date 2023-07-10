/*
Stop The Shame

The general public often body shame the people who are obese or not beautiful as per their standard of weight.
They do not even consider that it might be a medical condition for some people. Because of this, the people start
doubting themselves and start cutting them off from the general discussions or the public places. To fight body
shaming and spread awareness about the issue, an event is conducted in the city where people are participating and
are ranked according to their weights from highest to lowest. The people with the same weights are ranked the same.

There are N people who have already participated. The official has noted their weight and has ranked them. The problem is,
he has fallen sick and there are still P people who are left to rank and participate. Considering this, you are expected to
finish the process and provide the rank of the P people. Once the person is ranked, his weight is included in the category 
and the weight of the new person will have to consider this weight also to be ranked. To help you out, the new P people are
organized in a queue in increasing order of their weights.
*/


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ll n, p;
    cin >> n >> p;

    vector<ll> vec(n);
    ordered_set stt;
    map<ll, ll> mp;

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        if (mp[vec[i]] == 0) {
            stt.insert(vec[i]);
            mp[vec[i]] = 1;
        }
    }

    for (int i = 0; i < p; i++) {
        ll x;
        cin >> x;

        if (mp[x] == 0) {
            stt.insert(x);
            mp[x] = 1;
        }
        cout << stt.size() - stt.order_of_key(x) << endl;
    }
}
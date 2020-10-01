#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define nt _int128
#define inf (int)1e9
vector<vector<pair<ll,ll>>> graph(100);
bool marked[100];
int prism(int src)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    int m = 0;
    pq.push({0,src});
    while(!pq.empty())
    {
        pair<ll,ll> temp = pq.top();
        pq.pop();
        if(marked[temp.second] == true)
            continue;
        m += temp.first;
        // cout << temp.second << endl;
        marked[temp.second] = true;
        for(auto i: graph[temp.second])
        {
            if(marked[i.second] == false)
            {
                pq.push(i);
            }
        }
    }
    return m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    // cin >> t;
    t  = 1;
    while(t--)
    {
        int n,e;
        cin >> n >> e;
        for(ll i=0;i<e;i++)
        {
            ll a,b,c;
            cin >> a >> b >> c; // C = cost
            graph[a].push_back({c,b});
            graph[b].push_back({c,a});
        }
        int k=0;
        // cout << endl;
        // for(int i=0;i<=n;i++)
        // {
        //     cout << i << " => ";
        //     for(auto j: graph[i])
        //         cout << j.second << j.first << " ";
        //     cout << endl;
        // }
        cout << prism(1) << endl;
    }
    return 0;
}

/*INPUT
4 5
0 1 1
0 3 4
1 2 2
2 3 5
0 2 3*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//Position this line where user code will be pasted.
vector<ll> vec;
bool vis[10000];
void dfs(int s, vector<int> g[] )
{
    vis[s] = true;
    cout << s << " ";
    for (auto i : g[s])
    {
        if (!vis[i])
            dfs(i, g);
    }
    vec.push_back(s);
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;

        vector<int> g[N + 1];
        // bool vis[N+1];

        memset(vis, false, sizeof(vis));

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            // g[v].push_back(u);
        }
        for (ll i = 1; i <= N; i++)
        {
            if (!vis[i])
                dfs(i, g);
        }
        cout << endl << endl;
        for (auto i : vec)
            cout << i << " ";
        cout << endl << endl;
    }
}
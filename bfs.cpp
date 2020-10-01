#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
void bfs(int s, vector<int> adj[], bool vis[], int N)
{
    // Your code here
    for(int i=0;i<N;i++)
    {
        cout << i << "-> ";
        for(auto j: adj[i])
            cout << j << " ";
        cout << endl;
    }

    //BFS
    queue<int> myque;
    myque.push(s);
    vis[s] = true;
    while(!myque.empty())
    {
        int node = myque.front();
        cout << node << " ";
        myque.pop();

        for(auto i: adj[node])
        {
            if(!vis[i])
            {
                myque.push(i);
                vis[i] = true;
            }
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N] = {false};
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis, N);
        cout<<endl;
    }
}

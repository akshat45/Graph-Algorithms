// single source shortest path finding algorithm
// works on positive weight only and which has no cycle
#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int main()
{  
    int n,m;
    cin>>n>>m;
    
    vector<int> dist(n+1,inf);
    vector<pair<int,int>> graph[n+1];
    
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int source;
    cin>>source;
    dist[source] = 0;
    set<pair<int,int>> s;
    // {weight,vertex}
    s.insert({0,source});
    while(!s.empty())
    {
        auto x = *(s.begin());
        s.erase(x);
        for(auto it : graph[x.second])
        {
            if(dist[it.first]>dist[x.second]+it.second)    // it.first is node v and it.second is weight
            {
                s.erase({dist[it.first],it.first});
                dist[it.first] = dist[x.second] + it.second;
                s.insert({dist[it.first],it.first});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]<inf)
        {
            cout<<dist[i]<<" ";
        }
        else{
            cout<<"-1"<<" ";
        }
    }
    return 0;
}
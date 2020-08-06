#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int inf=INT_MAX;

bool ok=false;

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost)
{

    vector<long> dist(adj.size(), inf);
    dist[0] = 0;
    for (int q = 0; q < adj.size(); q++)
    {
        for(int u = 0; u < adj.size(); u++)
        {
            for (int k = 0; k < adj[u].size(); k++)
            {
                int v = adj[u][k];
                if(dist[v] > dist[u] + cost[u][k])
                {
                    ok=true;
                    dist[v] = dist[u] + cost[u][k];
                    if(adj.size() - 1==q )
                        return 1;
                }
            }
        }
        if(ok) ok=false;
    }
    return 0;

}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin>> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    vector<vector<int> > cost(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x - 1].push_back(y - 1);
        cost[x - 1].push_back(w);
    }
    cout << negative_cycle(adj, cost);
    return 0;
}

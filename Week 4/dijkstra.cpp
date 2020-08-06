///Reference problem: https://www.spoj.com/problems/EZDIJKST/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 19;

vector<vector< pair<int,int> >>G; //Careful
vector<bool> vis;
vector<int> dist;

void dijkstra(int s)
{
    fill(dist.begin(),dist.end(), INF);

    set<pair<int, int>> S;
    S.insert({dist[s] = 0, s});
    while(!S.empty())
    {
        int u = S.begin() -> second;
        S.erase(S.begin());

        for(auto v : G[u])
        {
            if(dist[v.first] > dist[u] + v.second)
            {
                S.erase({dist[v.first], v.first});
                dist[v.first] = dist[u] + v.second;
                S.insert({dist[v.first], v.first});
            }
        }
    }
    //cout<<dist[t];

}

int main()
{

    /* int t;
     cin>>t;
     while(t--)
     {
     */

    int n, m;
    cin >> n >> m;

    G.resize(n + 1); ///careful, n+1
    vis.assign(n + 1, false);
    dist.resize(n + 1);
    for (int i = 0; i < m; ++i)
    {
        int u, s, c;
        cin >> u >> s >> c;
        G[u].push_back({s, c});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s);
    if (dist[t] == INF)
        cout<<"-1\n";
    //cout << "There is no path from " << s << " to " << t;
    else
        cout<<dist[t]<<endl;
    //cout << "Min distance(" << s << " -> " << t << ") = " << dist[t];

    G.clear(); ///In case of multiple test cases


    //}
}
/*
Test cases:
3 2
1 2 5
2 3 7
Ans:12

3 3
1 2 4
1 3 7
2 3 1
1 3
Ans:5

3 1
1 2 4
1 3
Ans:-1

*/

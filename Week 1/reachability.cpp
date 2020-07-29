#include <bits/stdc++.h>
using namespace std;

vector <int> G[1001];
int dist[1001];
int parent[1001];
int distance[1001];
bool visit[1001];

int BFS(int source, int destination)
{
    queue <int> Q;
    memset(dist,-1,sizeof (dist) );
    Q.push(source);
    dist[source] = 0;
    visit[source] = true;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            while(!visit[v])
            {
                dist[v] = dist[u]+1;
                visit[v] = true;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
    return dist[destination];
}
int main()
{
    int node,edge;
    cin>>node>>edge;
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin>> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int ans;

    int source,destination;
    cin>> source>> destination;

    //cout<<BFS(source,destination);
    if(BFS(source,destination)!=-1) ans=1; //There exists a path
    else ans=0;

    cout<<ans<<endl;

}

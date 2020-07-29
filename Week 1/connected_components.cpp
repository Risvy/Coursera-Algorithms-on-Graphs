#include <bits/stdc++.h>
using namespace std;

int dist[1001];
bool visit[1001];
vector <int> G[1001];
int parent[1001];
int mark[1001];

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
        cin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }


    int ans=0;
    for(int i=1; i<=node; i++)
    {
        if(mark[i]==0)
        {
            bool ok=0;
            for(int j=1; j<=node; j++)
            {
                if(BFS(i,j)!=-1)
                {
                    mark[j]=1;
                    mark[i]=1;
                    ok=1;

                }
                 memset(visit,0,sizeof visit);
            }
            if(ok)
                ans++;
            ok=0;
        }
    }
    cout<<ans<<endl;

}

#include <bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int vis[100005];
int rectree[100005];
int ans=1,node=1;

void dfs(int s)

{

    vis[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {
        if(rectree[g[s][i]]==1 and ans==1)
        {
            ans=0;
            node=g[s][i];
            return;
        }

        if(!vis[g[s][i]])

        {
            rectree[g[s][i]]=1;
            dfs(g[s][i]);
            if(ans==1)

                rectree[g[s][i]]=0;
        }

    }

}

int main()

{

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
    }

    for(int i=1; i<=n; i++)

    {
        rectree[i]=1;
        if(vis[i]==0)
            dfs(i);
        if(ans==0)
        break;
        rectree[i]=0;
    }

    if(ans==0)
        cout<<1<<endl;

    else
        cout<<0<<endl;

    return 0;

}

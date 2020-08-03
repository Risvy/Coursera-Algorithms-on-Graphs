#include <bits/stdc++.h>
using namespace std;
#define ll long long
int flag=0;
vector<vector<int> > reverseEdges(vector<vector<int> > &adj)
{
    vector<vector<int> > reverse_adj(adj.size(), vector<int>());
    for(int i = 0; i < adj.size(); i++)
    {
        char color;
        for(int j = 0; j < adj[i].size(); j++)

            reverse_adj[adj[i][j]].push_back(i);

    }
    return reverse_adj;
}

void dfs(vector<vector<int> > &adj, int n, vector<int> &visited, stack<int> &Stack)
{
    visited[n] = 1;
    for (int i = 0; i < adj[n].size(); i++)
    {
        if(visited[adj[n][i]]==0)
        {
            dfs(adj, adj[n][i], visited, Stack);
        }
    }

    Stack.push(n);
}

int func(vector<vector<int>> adj)
{

    ///write your code here
    int ans = 0;
    stack<int> Stack;
    vector<int> visited(adj.size(), 0);

    vector<vector<int> > reverse_adj = reverseEdges(adj);
    for (int i = 0; i < reverse_adj.size(); i++)
    {
        if(visited[i]==0)
            dfs(reverse_adj, i, visited, Stack);

    }
    fill(visited.begin(), visited.end(), 0);
    while (! Stack.empty())
    {
        flag++;
        int x = Stack.top();
        Stack.pop();
        if (!visited[x])
        {
            flag=0;
            stack<int> componentStack;
            char vchar;
            dfs(adj, x, visited, componentStack);
            ans++;
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x - 1].push_back(y - 1);
    }
    cout<<func(adj);
    cout<<endl;

    return 0;
}

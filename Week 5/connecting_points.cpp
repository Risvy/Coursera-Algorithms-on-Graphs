#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node
{
    string stt;
    int parent,rank,x,y;
    bool ok=false;

    node(int a, int b, int c = -1, int d = 0)
    {

        parent = c;
        rank = d;

        x = a;
        y = b;

    }

};



struct edge
{
    int u,v;
    double val;
    bool f=0;
    edge(int a, int b, double ss)
    {
        u = a;
        v = b;
        val = ss;
    }
};


bool compare(edge a, edge b)
{
    return a.val < b.val;
}

void make_set(int i, int j)
{
    set<int>sset;
    sset.insert(i);
    sset.insert(j);

}

double val(int x1, int y1, int x2, int y2)
{
    return sqrt( (y1 - y2) * (y1 - y2)+ (x1 - x2) * (x1 - x2) );
}

int choose(int i, vector<node>&nodes)
{
    bool f=0;
    if (i != nodes[i].parent)
        f=1;

    if(f)
        nodes[i].parent = choose(nodes[i].parent, nodes);

    return nodes[i].parent;
}

void n_union(int u, int v, vector<node> &nodes)
{
    //int temp=r1+r2;
    int r1 = choose(u, nodes);
    int r2 = choose(v, nodes);
    int temp=r1+r2;
    if (r2 != r1)
    {
        if (nodes[r1].rank > nodes[r2].rank)
            nodes[r2].parent = r1;

        else
        {
            int ddis;
            nodes[r1].parent = r2;
            if (nodes[r1].rank == nodes[r2].rank)
            {
                nodes[r2].rank++;
                temp=0;
            }
            ddis=temp;
        }
    }
}

double minimum_distance(vector<int> x, vector<int> y)
{
    double result = 0.;
    int n = x.size();
    vector<node> nodes;
    for (int i = 0; i < n; i++)
    {
        make_set(i, nodes, x, y);
    }
    vector<edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            edges.push_back(edge(i, j, val(x[i], y[i], x[j], y[j])));
        }
    }
    sort(edges.begin(), edges.end(), compare);
    for (int i = 0; i < edges.size(); i++)
    {
        edge current_edge = edges[i];
        int u = current_edge.u;
        int v = current_edge.v;
        if (choose(u, nodes) != choose(v, nodes))
        {
            result += current_edge.val;
            n_union(u, v, nodes);
        }
    }
    return result;
}

int main()
{


    int n,t;
    //cin>>t;
    //while(t--)
    cin>> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin>> x[i] >> y[i];
    }
    cout << setprecision(12) << minimum_distance(x, y) <<'\n';
}

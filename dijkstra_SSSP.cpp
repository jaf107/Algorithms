#include<bits/stdc++.h>

#define NIL -1
using namespace std;

int graph[100][100];
int d[100],prev[100];
int visited[100];

int n; // No of nodes


void initializeSingleSource(int s)
{
    for(int i=1; i<=n; i++)
    {
        d[i] = INT_MAX;
        prev[i] = NIL;
    }

    d[s] = 0;
}

void relax(int u,int v)
{
    if(d[v] > d[u]+graph[u][v] && visited[v] == 0)
    {
        d[v] = d[u] + graph[u][v];
        prev[v] = u;

    }
}
int extracMIN()
{
    int minH = INT_MAX;
    int u;
    for(int i=0;i<n;i++)
    {
        if(visited[i] == 0  && d[i]<minH)
        {
            minH = d[i];
            u = i;
        }
    }
    return u;
}

void dijkstra(int source)
{
    int u;
    initializeSingleSource(source);

    while(true)
    {
        u = extracMIN();
        visited[u] = 1;

        for(int v = 1; v <= n; v++)
        {
            if(graph[u][v] != 0)
                relax(u,v);
        }


        int i = 0;

        for(;i<n;i++)
        {
            if(visited[i] == 0)
                break;
        }
        if(i == n)
            break;
    }

    cout<<"\nDistance :";
    for(int i=1; i<=n ; i++)
    {
        printf("%-4d ",d[i]);;
    }
    cout<<endl;

}

int main()
{
    int e;
    cin>>n>>e;

    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        graph[u][v] = w;
    }

    dijkstra(1);

    return 0;
}

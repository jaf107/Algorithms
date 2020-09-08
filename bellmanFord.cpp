
#include<bits/stdc++.h>
using namespace std;

struct Edge
{
    int src,dest,weight;
};

struct Graph
{

    int V,E;

    Edge* edge;
};

Graph* createGraph(int V, int E)
{
    Graph *newGraph = new Graph;
    newGraph->E = E;
    newGraph->V = V;
    newGraph->edge = new Edge[E];
    return newGraph;
}

void printArr(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

void bellmanFord(Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;

    int dist[V];


    for(int i=0; i<V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for(int i=1; i<V; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;

            if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for(int j = 0; j < E; j++)
    {
        int u = graph->edge[j].src;
        int v = graph->edge[j].dest;
        int weight = graph->edge[j].weight;

        if(dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            dist[v] = INT_MAX;
            dist[v] *= -1;

            cout<<"Graph contains negative cycle"<<endl;
        }
    }

    printArr(dist, V);



    return;

}


int main()
{
    int n,e;
    cin>>n>>e;

    Graph *graph = createGraph(n,e);

    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        graph->edge[i].src = u;
        graph->edge[i].dest= v;
        graph->edge[i].weight = w;
    }

    int source;
    cout<<"Source :";
    cin>>source;

    bellmanFord(graph,source);

    return 0;

}
/*
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
*/

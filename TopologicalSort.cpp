
#include<bits/stdc++.h>
using namespace std;

#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[100][100];
int color[100];
int prev[100];

int n;

stack<int> topSort;

void DFS_Visit(int u)
{
    color[u] = GRAY;


    for(int v=1; v<=n ;v++)
    {
        if(graph[u][v] != 0)
        {
            if(color[v] == WHITE)
            {
                prev[v] = u;
                DFS_Visit(v);
            }
        }
    }
    topSort.push(u);
    color[u] = BLACK;

}

void dfs()
{
    for(int i=1; i<=n ; i++)
    {
        color[i] = WHITE;
        prev[i] = NIL;
    }

    for(int i=1; i<=n ; i++)
    {
        if(color[i] == WHITE)
        {
            DFS_Visit(i);
        }
    }

}

void topSortFunction()
{
    dfs();

    while(!topSort.empty())
    {
        int t = topSort.top();

        char A = 'A' + t -1;

        cout<<A<<" ";
        topSort.pop();
    }
}

void showGraph()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%-4d",graph[i][j]);
        }
        printf("\n");
    }
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


    topSortFunction();

}



//INPUT test case
/*
13 18
1 4 1
2 4 1
3 1 1
3 2 1
4 7 1
4 8 1
5 6 1
5 4 1
5 1 1
6 11 1
6 10 1
7 9 1
8 10 1
8 9 1
9 12 1
10 13 1
10 12 1
11 10 1 */












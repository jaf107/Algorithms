
#include<bits/stdc++.h>
using namespace std;

#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int graph[100][100];
int color[100];
int prev[100];

int d[100];
bool V[100];

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

vector<int> topSortFunction()
{
    vector<int> order ;
    order.push_back(0);
    dfs();

    while(!topSort.empty())
    {
        int t = topSort.top();

        order.push_back(t);

        char A = 'A' + t -1;

        cout<<A<<" ";
        topSort.pop();
    }

    return order;
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



void relax(int u, int v)
{
    if(d[v]>graph[u][v] && V[v] == 0)
    {
        d[v] = d[u] + graph[u][v];
    }
}

void dagShortest(int start)
{
    vector<int> order = topSortFunction();



    memset(V,false,n);

    int d[n];
    for(int i = 1; i<=n ;i++)
        d[i] = INT_MAX;

    d[1] = 0;

    for(int i=1; ;i++)
    {
        V[i] = true;
        for(int j = 2; j<= n ; j++)
        {
            if(graph[i][j] != 0)
            {
                relax(i,j);
            }
        }

        int k = 1;
        for(;k<=n;k++)
        {
            if(V[i] == 0)
                break;
        }
        if(k == n+1)
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


    dagShortest(1);

    return 0;
}



//INPUT test case
/*
8 13
1 2 3
1 3 6
2 3 4
2 4 4
2 5 11
3 4 8
3 7 11
4 5 -4
4 6 5
4 7 2
5 8 9
6 8 1
7 8 2
 */












#include<bits/stdc++.h>
using namespace std;

#define NIL -1      // Previous - nothing

#define WHITE 0     // Unvisited
#define GRAY 1      // Node visited - child's not visited
#define BLACK 2     // Node visited completely



int timeT = 0;
int graph[100][100];
int color[100];
int dtime[100]; // Discovery Time
int f[100]; // Finishing Time
int prev[100];

int n;          // NODES

//INPUT
int weight(int a, int b)
{
    int weigh  = 0;

    a *= a;
    b *= b;

    weigh = abs(a-b);
    weigh/=2;

    return weigh;
}
void input()
{

    for(int i = 1; i<=n ; i++)
    {
        for(int j=1; j<=n ; j++)
        {
            graph[i][j] = weight(i,j);
        }
    }

}
void showGraph()
{
    cout<<"Graph :\n";
    for(int i = 1; i<=n ; i++)
    {
        for(int j=1; j<=n ; j++)
        {
            printf("%-4d",graph[i][j]);
        }
        cout<<endl;
    }
}
void DFS_Visit(int u)
{
    color[u] = GRAY;
    timeT++;
    dtime[u] = timeT;

    for(int v = 0; v<= n; v++)
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

    color[u] = BLACK;
    timeT++;
    f[u] = timeT;

}
void DFS()
{
    for(int i=1; i<= n; i++)
    {
        color[i] = WHITE;
        prev[i]  = NIL;
    }
    timeT = 0;
    for(int i=1; i<= n; i++)
    {
        if(color[i] == WHITE)
            DFS_Visit(i);
    }

}

void showStats()
{
    cout<<"Color :";
    for(int i=1; i<=n ; i++)
    {
        printf("%-4d",color[i]);;
    }


    cout<<endl;
    cout<<"Previ :";
    for(int i=1; i<=n ; i++)
    {
        printf("%-4d",prev[i]);
//        cout<<prev[i]<<" ";
    }
    cout<<endl;

    cout<<"DTime :";
    for(int i=1; i<=n ; i++)
    {
        printf("%-4d",dtime[i]);
//        cout<<dtime[i]<<" ";
    }
    cout<<endl;

    cout<<"FTime :";
    for(int i=1; i<=n ; i++)
    {
        printf("%-4d",f[i]);
//        cout<<f[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    n = 10;
    input();
    showGraph();



    DFS();
    cout<<endl<<endl;

    showStats();





    return 0;
}

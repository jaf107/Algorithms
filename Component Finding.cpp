#include<bits/stdc++.h>
using namespace std;

int graph[100][100];
int components[100];
bool visited[100];
int n;
int countC = 0;


void dfs(int u)
{
    if(visited[u])
        return;

    components[u] = countC;
    visited[u] = true;
    for(int v= 1; v<=n; v++)
    {
        if(graph[u][v] != 0)
        {
            if(!visited[v])
                dfs(v);
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

void showStats()
{
    cout<<"\nComponents :";
    for(int i=1; i<=n ; i++)
    {
        printf("%-4d",components[i]);;
    }
    cout<<"\nVisitation :";
    for(int i=1; i<=n ; i++)
    {
        printf("%-4d",visited[i]);;
    }
}

void input()
{
    cout<<"Enter number of edges : ";
    int e;
    cin>>e;

    for(int i=0; i< e; i++)
    {
        cout<<"Start and Ending : ";
        int u,v;
        cin>>u>>v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}
void findComponents()
{
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            countC++;
            dfs(i);
        }
    }
}
int main()
{
    cout<<"Enter the number of Nodes: ";
    cin>>n;
    input();

    findComponents();

    cout<<endl;
    showGraph();
    showStats();

}

/*
8
5
1 2
2 3
1 3
5 6
4 8
*/

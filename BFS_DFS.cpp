#include<bits/stdc++.h>
using namespace std;
#define max 100
void BFS(int g[][max],int n,int start)
{
    int visted[n]={0};
    list<int> queue;
    visted[start]=1;
    cout<<start<<" ";
    queue.push_back(start);
    while(!queue.empty())
    {
        start=queue.front();
        queue.pop_front();
        for(int i=1;i<=n;i++)
        {
            if(g[start][i]==1 && visted[i]!=1)
            {
                visted[i]=1;
                queue.push_back(i);
                cout<<i<<" ";
            }
        }
    }
}
void DFS(int g[][max],int n,int start)
{
    static int vist[max]={0};
    if(vist[start]==0)
    {
        cout<<start<<" ";
        vist[start]=1;
        for(int i=1;i<=n;i++)
        {
            if(g[start][i]==1 && vist[i]==0)
            DFS(g,n,i);
        }
    }
}
int main()
{
    int n,m;
    cout<<"Number of vertices";
    cin>>n;
    int g[max][max]={0};
    cout<<"Number of edges";
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }
    for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++)
    cout<<g[i][j]<<" ";
    cout<<endl;}
    DFS(g,n,4);
}

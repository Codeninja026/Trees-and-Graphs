#include<stdio.h>
void dfs(int);
int G[10][10],visited[10],n;
int main()
{
    int i,j;
    printf("Enter no of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacent matrix of the graph: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&G[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    dfs(0);
    printf("unreachable vertices are\n");
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            flag++;
            printf("not reachable: %d\n",i+1);
        }
    }
    if(flag==0)
    {
        printf("no rechable vertices\n");
    }
    
}
void dfs(int i)
{
    int j;
    printf("visited %d ->",i+1);
    visited[i]=1;
    for(j=0;j<n;j++)
    {
        if(visited[j]&&G[i][j]==1)
        {
            dfs(j);
        }
    }
}

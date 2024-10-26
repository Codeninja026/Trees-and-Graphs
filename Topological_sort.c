#include<stdio.h>
int main()
{
    int i,j,k,n,a[10][10],indeg[10],flag[20],count=0;
    printf("Enter the no of vertices: \n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix: \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter row %d\n",i);
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        indeg[i]=0;
        flag[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indeg[i]=indeg[i]+a[j][i];
        }
    }
    printf("the topologicl order is: ");
    while(count<n)
    {
        for(k=0;k<n;k++)
        {
            if((indeg[k]==0)&& flag[k]==0)
            {
                printf("%d ",k);
                flag[k]=1;
                count++;
                for(int i=0;i<n;i++)
                {
                    if(a[k][i]==1)
                    {
                        indeg[i]--;
                    }
                }
            }
        }
    }
}

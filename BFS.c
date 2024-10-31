#include <stdio.h>
int queue[20],front=-1,rear=-1,a[20][20],visted[20],flag=0;
void add(int);
int deleteele();
void BFS(int s,int n)
{
	int p,i;
	add(s);
	visted[s]=1;
	p=deleteele();
	if(p!=0)
	printf("%d",p);
	while(p!=0)
	{
		for(i=0;i<=n;i++)
		if(a[p][i]!=0&&(visted[i]==0)){
			add(i);
			visted[i]=1;
			
		}
		p=deleteele();
		if(p!=0)
		printf("%d",p);
	}
}
void add(int item)
{
	if(rear ==19)
		printf("Queue full");
	else{
		if(rear == -1)
		{
			queue[++rear]=item;
			front++;
		}
		else{
			queue[++rear]=item;
		}
		
	}
}
int deleteele()
{
	int k;
	if((front>rear)||(front==-1))
	return(0);
	else{
		k=queue[front++];
		return (k);
	}
}	
int main()
{
	int v,i,j,n;
	printf("Enter the no.of vertices: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		visted[i]=0;
	}
	printf("Enter graph data in matrix from: \n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter the starting vertex: ");
	scanf("%d",&v);
	BFS(v,n);
		for(i=0;i<n;i++){
		if(visted[i]==0){
			flag++;
			printf("not reachable %d\n",i+1);
		}
	}
	if(flag==0){
		printf("not present\n");
	}
}

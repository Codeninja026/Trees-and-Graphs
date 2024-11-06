#include <stdio.h>

void merge(int A[100],int n,int l,int mid,int up){
	int i=l,j=mid+1,k=l;
	int temp[30];
	while(i<=mid && j<=up){
		if(A[i]<=A[j]){
			temp[k]=A[i];
			i++;
		}
		else{
			temp[k]=A[j];
			j++;
		}
		k++;
	}
	if(i>mid){
		while(j<=up){
			temp[k]=A[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			temp[k]=A[i];
			i++;
			k++;
		}
	}
	for(i=l;i<k;i++){
		A[i]=temp[i];
	}
}
void mergesort(int A[100],int n,int l,int up){
	int mid=(l+up)/2;
	if(l<up){
		mergesort(A,n,l,mid);
		mergesort(A,n,mid+1,up);
		merge(A,n,l,mid,up);
	}
}

int main(){
	int n,A[100],i;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	printf("Enter the Elements: ");
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	
	mergesort(A,n,0,n-1);
	
	printf("The sorted array is: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	return 0;
	
}

#include <stdio.h>


void swap(int *p1,int *p2)
{
    int temp = *p1 ;
    *p1= *p2 ;
    *p2 = temp ;
}


void bitonicmerge(int a[],int low,int n,int div){
	int k,i,dir=1;
	if(n>1){
		k=n/2;
		for(i=0;i<low+k;i++){
			if(dir==(a[i]>a[i+k])){
				swap(&a[i],&a[i+k]);
			}
		}
		bitonicmerge(a,low,k,dir);
		bitonicmerge(a,low+k,k,dir);
	}
}

void bitonicsort(int a[],int low,int n,int dir){
	int k;
	if(n>1){
		k=n/2;
		bitonicsort(a,low,k,1);
		bitonicsort(a,low+k,k,0);
		bitonicmerge(a,low,n,dir);
	}
}

void read(int a[],int n){
	int i;
	printf("Enter the %d elements: ",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
}

void display(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}

int main(){
	int a[50],n,i;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	read(a,n);
	printf("before sorting elements: ");
	display(a,n);
	printf("\nAfter sorting elements: ");
	bitonicsort(a,0,n,1);
	display(a,n);
	return 0;
}

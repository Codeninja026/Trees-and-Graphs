#include<stdio.h>


void swap(int *p1,int *p2)
{
    int temp = *p1;
    *p1= *p2;
    *p2 = temp;

}
int partition(int a[],int n,int l,int r)
{
    int p = l  ;
    while(l<r)
    {
        while(a[p]<=a[r] && p<r){
            r-- ;
        }
        if(a[p]>a[r]){
            swap(&a[p],&a[r]) ;
            p=r ;
            l++ ;
        }
        while(a[p]>=a[l] && p>l){
                l++ ;
        }
        if(a[p]<a[l]){
            swap(&a[p],&a[l]) ;     
            p = l;
            r-- ;
        }
    }
    return p ;
}
void QuickSort(int a[],int n,int l,int r)
{
    int pivot ;
    if(l<r)
    {
        pivot = partition(a,n,l,r) ;
        QuickSort(a,n,l,pivot-1) ;
        QuickSort(a,n,pivot+1,r) ;

    }
}
int main() {
    int n,i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the %d elements: ",n);
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    QuickSort(a, n, 0, n - 1);

    printf("Sorted array: ");
    for (i=0;i<n;i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int partition(int *a,int l,int u)
{
    int pivot=l;
    int start=l;
    int end=u,t;
    while(start<end)
    {
        while(a[start]<a[pivot])
        {
            start++;
        }
        while(a[end]>a[pivot])
        {
            end--;
        }
        if(start<end)
        {
            t=a[start];
            a[start]=a[end];
            a[end]=t;
        }

    }
    t=a[end];
    a[end]=a[pivot];
    a[pivot]=t;
    return end;

}
void quicksort(int *a,int lb,int ub)
{
    if(lb<ub)
    {
        int j=partition(a,lb,ub);
        quicksort(a,lb,j-1);
        quicksort(a,j+1,ub);
    }
}
void main()
{
    int n;
    printf("enter n");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
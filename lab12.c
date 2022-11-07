#include<stdio.h>
#include<stdlib.h>


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int j=m-1,k=n-1,i=nums1Size-1;
    while(j>=0 && k>=0)
    {
        if(nums1[j]<=nums2[k])
        {
            nums1[i]=nums2[k];
            k--;
            i--;
        }
        else
        {
            nums1[i]=nums1[j];
            j--;
            i--;
        }
    }
    while(k>=0)
    {
        nums1[i]=nums2[k];
        i--;
        k--;
    }
}
void display(int *a,int n)
{
    int i;
    printf("The elements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void main()
{
    int m,n;
    printf("enter 1st array size");
    scanf("%d",&m);
    printf("enter 2nd array size");
    scanf("%d",&n);
    int *nums1,*nums2;
    int nums1size=m+n;
    nums1=(int*)(malloc(nums1size*sizeof(int)));
    nums2=(int*)(malloc(n*sizeof(int)));
    printf("enter nums1 elements ");
    for(int i=0;i<nums1size;i++)
    {
        
        
        if(i>m-1)
        {
            nums1[i]=0;
        }
        else
        {
            scanf("%d",&nums1[i]);
        }
    }
    printf("enter nums2 elements ");
    for(int i=0;i<n;i++)
    {
        
        scanf("%d",&nums2[i]);
        
    }
    merge(nums1,nums1size,m,nums2,n,n);
    display(nums1,nums1size);

}
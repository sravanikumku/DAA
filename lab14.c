#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void merge(int *a,int l,int mid,int r){
    int i=l;
    int j=mid+1;
    int k=l;
    
    int b[r+1];

    while(i<=mid && j<=r){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
    
    if(i>mid){
        while(j<=r){
            b[k]=a[j];
            k++;
            j++;
        }
    }
    else{
        while(i<=mid){
            b[k]=a[i];
            k++;
            i++;
        }
    }
    
    for(int z=l;z<=r;z++){
        a[z]=b[z];
    }
}

void mergesort(int *a,int l,int r){
  if(l<r){
   int mid = (l+r)/2;
   mergesort(a,l,mid);
   mergesort(a,mid+1,r);
   merge(a,l,mid,r);
  }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    
    int l=0;
    int r=numsSize-1;
    int *res = malloc(numsSize*sizeof(int));
    mergesort(nums,l,r);
    
    for(int i=0; i<numsSize; i++)
    {
        res[i]=nums[i];
    }
    
    *returnSize = numsSize;

    
    return res;
}
void display(int *res,int n)
{
    int i=0;
    printf("The resulted array is:");
    for(i=0;i<n;i++)
    {
        printf("%d ",res[i]);
    }
}
void main()
{
    int *nums;
    int numssize;
    printf("enter numssize");
    scanf("%d",&numssize);
    nums=(int*)(malloc(numssize*sizeof(int)));
    for(int i=0;i<numssize;i++)
    {
        scanf("%d",(nums+i));
    }
    int *res=sortArray(nums,numssize,&numssize);
    display(res,numssize);
}
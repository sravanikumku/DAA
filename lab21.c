#include<stdio.h>
#include<stdlib.h>
void sort(int **bt,int s)
{
    int i,j;
    int *t;
    for(i=0;i<s;i++)
    {
        for(j=i+1;j<s;j++)
        {
            if(bt[i][1]<bt[j][1])
            {
                  t=bt[i];
                bt[i]=bt[j];
                bt[j]=t;
            }
        }
    }
}
int maximumUnits(int** boxTypes, int boxTypesSize, int* boxTypesColSize, int truckSize){

    int s=0;
    int bs=truckSize;
    sort(boxTypes,boxTypesSize);
    for(int i=0;i<boxTypesSize && bs!=0;i++)
    {
        if(bs>boxTypes[i][0])
        {
        s+=boxTypes[i][1]*boxTypes[i][0];
        bs-=boxTypes[i][0];
        }
        else
        {
            s+=boxTypes[i][1]*(bs);
            bs=0;
        }
    }
    return s;
}
void main()
{
    int boxsize,trucksize;
    int i,j;
    printf("enter box size");
    scanf("%d",&boxsize);
    printf("enter trucksize");
    scanf("%d",&trucksize);
    int k=2,d;
    int *a=&k;
    int *boxTypes[boxsize];
    for(int i=0;i<boxsize;i++)
    {
        for(int j=0;j<2;j++)
        {
        boxTypes[i]=(int*)(malloc(2*sizeof(int)));
        }
    }
    for(i=0;i<boxsize;i++)
    {
        
        printf("enter %d row",(i+1));
        for(j=0;j<k;j++)
        {
            scanf("%d",&d);
            boxTypes[i][j]=d;
        }
    }
    int prod=maximumUnits(boxTypes,boxsize,a,trucksize);
    printf("the total products is: %d",prod);

}
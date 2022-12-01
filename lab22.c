#include<stdio.h>
#include<stdlib.h>

void merge(int **a,int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int b[r+1][2];
    while(i<=mid && j<=r)
    {
        if(a[i][1]<a[j][1])
        {
            b[k][0]=a[i][0];
            b[k][1]=a[i][1];
            i++;
        }
        else
        {
            b[k][0]=a[j][0];
            b[k][1]=a[j][1];
            j++;
        }
        k++;
    }
    if(i>mid)
    {
        while(j<=r)
        {
            b[k][0]=a[j][0];
            b[k][1]=a[j][1];
            k++;
            j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k][0]=a[i][0];
            b[k][1]=a[i][1];
            k++;
            i++;
        }
    }
    for(int z=l;z<=r;z++)
    {
        a[z][0]=b[z][0];
        a[z][1]=b[z][1];
    }
}
void mergesort(int **a,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
int maxEvents(int** events, int eventsSize, int* eventsColSize){

    int c=0;
    int flag=0;
    mergesort(events,0,eventsSize-1);
    int n=100000;
    int a[n+1];
    for(int i=0;i<=n;i++)
    {
        a[i]=0;
    }
    for(int i=0;i<eventsSize;i++)
    {
        if(a[events[i][0]]!=1)
        {
        a[events[i][0]]=1;
            //printf("%d\n",events[i][0]);
        
        c+=1;
        }
        else
        {
            for(int k=events[i][0];k<=events[i][1];k++)
            {
                if(a[k]!=1 )
                {
                    a[k]=1;
                    printf("%d\n",k);
                    c+=1;
                    break;
              
                    
                }
                
            }
           
            
            
        }
        
        
        
        
    }
    return c;
    
}
void main()
{
    int es,d;
    printf("enter events size");
    scanf("%d",&es);
    int *events[es];
    for(int i=0;i<es;i++)
    {
        events[i]=(int*)(malloc(2*sizeof(int)));

    }
    for(int i=0;i<es;i++)
    {
        printf("enter %d row",(i+1));
        for(int j=0;j<2;j++)
        {
            scanf("%d",&d);
            events[i][j]=d;
        }
    }
    int k=2;
    int *col=&k;
    int e=maxEvents(events,es,col);
    printf("the max events are: %d",e);
}
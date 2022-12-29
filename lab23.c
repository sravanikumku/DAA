#include<stdio.h>
#include<stdlib.h>
int d(int **points,int u,int j)
{
    return (abs(points[u][0]-points[j][0])+abs(points[u][1]-points[j][1]));
}
int minind(int *dist,int n,int *visited)
{
    int i;
    int min=__INT_MAX__;
    int index;
    for(i=0;i<n;i++)
    {
        if(dist[i]<min && visited[i]!=1)
        {
            min=dist[i];
            index=i;
        }
    }
    //printf("%d",index);
    return index;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
   int visited[pointsSize];
   int i,j;
   for(i=0;i<pointsSize;i++)
   {
       visited[i]=0;
   }
   int dist[pointsSize];
   
   for(i=0;i<pointsSize;i++)
   {
       dist[i]=__INT_MAX__;
   }
   dist[0]=0;
   int u;
   for(i=0;i<pointsSize-1;i++)
   {
       u=minind(dist,pointsSize,visited);

       for(j=0;j<pointsSize;j++)
       {
           //printf("the dis:%d ",d(points,u,j));
           if(visited[j]!=1 && d(points,u,j)<dist[j] && j!=u)
           {
               //printf("1");
               //printf("%d",j);
               dist[j]=d(points,u,j);
               //printf( " the point %d ",dist[j]);
               
           }
       }
       visited[u]=1;
   }
   int sum=0;
   for(i=0;i<pointsSize;i++)
   {
    printf("%d ",dist[i]);
       sum+=dist[i];
   }

return sum;
}
void main()
{
    int n,i,j;
    printf("enter number  of points");
    scanf("%d",&n);
    int *points[n];
    for(int i=0;i<n;i++)
    {
        points[i]=(int *)(malloc(2*sizeof(int)));
    }
    for(i=0;i<n;i++)
    {
        printf("enter %d point",(i+1));
        for(j=0;j<2;j++)
        {
          scanf("%d",&points[i][j]);
        }

    }
    int a=2;
    int *d=&a;
     printf("min cost to connect all points is %d",minCostConnectPoints(points,n,d));
}

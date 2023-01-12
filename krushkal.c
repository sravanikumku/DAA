#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
int find(int a,int *parent)
{
    if(parent[a]==-1)
    {
        return a;
    }
    find(parent[a],parent);
}
void union1(int s,int d,int *parent)
{
    int a,b;
    a=find(s,parent);
    b=find(d,parent);
    parent[a]=b;
}
void krushkals(int (*adj)[3],int m,int n)
{
    //printf("adj %d ",adj[0][0]);
    int parent[n],i=0,j=0,s,d;
    int ans[10][3];
    //printf("n %d ",n);
    for(i=0;i<n;i++)
    {
        parent[i]=-1;
    }
    //int i=0,j=0,s,d;
    i=0;
    j=0;
    while(i<n-1 && j<m)
    {
        //printf("ho");
        s=find(adj[j][0],parent);
        d=find(adj[j][1],parent);
        //printf("s %d\n",s);
        if(s==d)
        {
            j++;
            continue;
        }
        union1(adj[j][0],adj[j][1],parent);
        ans[i][0]=adj[j][0];
        ans[i][1]=adj[j][1];
        ans[i][2]=adj[j][2];
       // printf("m %d m",ans[0][0]);


        i++;
        
    }
    for(i=0;i<n-1;i++)
    {
        printf("%d %d %d",ans[i][0],ans[i][1],ans[i][2]);
        printf("\n");
    }

}

void main()
{
    int i,j,m,n,d;
    printf("enter no .of vertices");
    scanf("%d",&n);
    printf("enter no of edges");
    scanf("%d",&m);
    
    /*for(i=0;i<m;i++)
    {
        printf("enter %d edge",(i+1));
        for(j=0;j<3;j++)
        {
            scanf("%d",&d);
            adj[i][j]=d;
        }
    }*/
   int adj[10][3]={{0,1,1},{1,3,1},{2,4,1},{0,2,2},{2,3,2},{3,4,2},{1,2,3},{1,4,3},{4,5,3},{3,5,4}};
   //printf("n1 %d",n);
    krushkals(adj,m,n);


}
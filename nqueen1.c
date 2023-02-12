#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char c1[100][100][100];
int x[100];
int z=0;
void print(int n)
{
    int j,r,c;
    
    for(int i=1;i<=n;i++)
    {
        int k=x[i];
           for(c=1;c<=n;c++)
            {
           if(k==c)
           {
             c1[z][i][c]='Q';
           }
           else
           {
             c1[z][i][c]='.';
           }
          printf("%c",c1[z][i][c]);
            }
           printf(" ");
        
        

    }
    printf("\n");
    z++;
}
int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if(x[j]==i ||abs(x[j]-i)==abs(j-k))
        {
            return 0;
        }
    }
    return 1;
}
void nqueen(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                for(int t=1;t<=n;t++)
                {
                    printf("%d ",x[t]);
                }
                printf("\n");
                print(n);
                break;
            }
            else
            {
                nqueen(k+1,n);
            }
        }
        
    }
}
void main()
{
    int n;
    printf("enter queen size");
    scanf("%d",&n);
    nqueen(1,n);
}
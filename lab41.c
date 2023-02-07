#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
char ***c; 
int z=0;     
 void array(int *x,int n)
 {
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if((j+1)==x[i+1])
            { c[z][i][j]='Q';}
             else
             {c[z][i][j]='.';}
             printf("%c",c[z][i][j]);
         }
         printf(" ");
     }
     printf("\n");
     z++;
 }
 bool place(int k,int i,int *x)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k))
        {
            
            return false;
        }

    }
    
    return true;
}
void nqueen(int k,int n,int *x)
{
        int i,m;
        for(i=1;i<=n;i++)
        {
            if(place(k,i,x))
            {
                x[k]=i;
                if(k==n)
                {
                    if(k==n)
                { array(x,n);}
                     else
           {  nqueen(k+1,n,x);}
                    
                    break;
                }
                
                else
                {
                    nqueen(k+1,n,x);
                }
            }
        }
}
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    
    int *x,i,j;
    x=(int *)(malloc((n+1)*sizeof(int)));
    for(int i=1;i<=n;i++)
    {
       x[i]=0;
    }
     c=(malloc(352*sizeof(char**)));
     for(i=0;i<352;i++)
     {
         c[i]=(char**)(malloc(352*sizeof(char*)));
         for(j=0;j<n;j++)
         {
             c[i][j]=(char*)(malloc((n+1)*sizeof(char)));
         }
     }
     nqueen(1,n,x);
  
    
return c;
}
void main()
{
    int n;
    printf("Enter queen size");
    scanf("%d",&n);
    int a=1;
    int *b=&a;
    int **rcs1;
    c=solveNQueens(n,b,rcs1);
}
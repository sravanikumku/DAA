#include<stdio.h>
int uniquePaths(int m, int n){
int a[m][n];
int i,j;
for(i=0;i<m;i++)
{
    for(j=0;j<n;j++)
    {
        if(i==0 || j==0)
        {
              a[i][j]=1;
        }
        else
        {
           a[i][j]=a[i-1][j]+a[i][j-1];
        }

    }
}
return a[m-1][n-1];

}
void main()
{
    int m,n;
    printf("Enter no .of rows and columns\n");
    scanf("%d%d",&m,&n);
    int p=uniquePaths(m,n);
    printf("No.of unique paths will be %d",p);

}
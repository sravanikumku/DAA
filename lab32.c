#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
int min(int a,int b)
{
    return a>b?b:a;
}
int coinChange(int* coins, int coinsSize, int amount){

    int g[coinsSize+1][amount+1];
    int i,j;
    for(i=0;i<coinsSize+1;i++)
    {
        for(j=0;j<amount+1;j++)
        {
            if(j==0)
            {
                g[i][j]=0;

            }
            else if(i==0)
            {
                g[i][j]=pow(10,5);
            }
            else if(coins[i-1]>j)
            {
                g[i][j]=g[i-1][j];
            }
            else
            {
                g[i][j]=min(g[i-1][j],1+g[i][j-coins[i-1]]);
            }
        }
    }
    

    if(g[coinsSize][amount]>pow(10,4))
    {
        return -1;
    }
    return g[coinsSize][amount];




}
void main()
{
    int n,amount;
    printf("enter coin size");
    scanf("%d",&n);
    printf("enter amount");
    scanf("%d",&amount);
    int *coins;
    coins=(int*)(malloc(n*sizeof(int)));
    for(int i=0;i<n;i++)
    {
        scanf("%d",&coins[i]);
    }
    printf("The minimum no.of coins requires are: %d",coinChange(coins,n,amount));

}
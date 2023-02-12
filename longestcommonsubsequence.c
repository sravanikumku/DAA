#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
int longestCommonSubsequence(char * text1, char * text2){
     int i,j;
     int dp[strlen(text1)+1][strlen(text2)+1];
     for(i=0;i<=strlen(text1);i++)
     {
         for(j=0;j<=strlen(text2);j++)
         {
             if(i==0 || j==0)
             {
                 dp[i][j]=0;
             }
             else
             {
                 if(text1[i-1]!=text2[j-1])
                 {
                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                 }
                 else
                 {
                     dp[i][j]=1+dp[i-1][j-1];
                 }
             }
         }
     }
     return dp[strlen(text1)][strlen(text2)];

}
void main()
{
    
    int n1,n2;
    printf("Enter size of text1");
    scanf("%d",&n1);
    printf("Enter size of text2");
    scanf("%d",&n2);
    char text1[n1],text2[n2];
    printf("Enter text1");
    scanf("%s",text1);
    printf("Enter text2");
    scanf("%s",text2);
    int l=longestCommonSubsequence(text1,text2);
    printf("The longest common subsequence is %d",l);
}
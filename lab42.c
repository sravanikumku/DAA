#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int max(int a,int b)
{
    return (a>b)?a:b;
}
bool check(char *s, char ch,int a,int b)
{
     for(int i=a;i<=b;i++)
     {
         if(s[i]==ch)
         {
             return true;
         }
     }
     return false;
}
int lengthOfLongestSubstring(char * s){

   int i;
   int l=0;
   int res=0;
   if(strlen(s)==1)
   {
       return 1;
   }
   for(i=1;i<strlen(s);i++)
   {
       while(check(s,s[i],l,i-1))
       {
           l=l+1;
       }
       res=max(res,i-l+1);
   }
   return res;
}
void main()
{
    int n;
    printf("Enter length of string");
    scanf("%d",&n);
    char *s=(char *)(malloc(n*sizeof(char)));
    printf("Enter string");
    scanf("%s",s);
    printf("The length of longest substring without repeating characters is %d",lengthOfLongestSubstring(s));
}
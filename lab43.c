#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *prefix;
void check(char *prefix,char *str)
{
    int small=(strlen(prefix))>(strlen(str))?(strlen(str)):strlen(prefix);
    char *s1=(malloc(small*sizeof(char)));
    int i,j,k=0;

    for(i=0;i<small;i++)
    {
        if(prefix[i]==str[i])
        {
           s1[i]=prefix[i];
           k++;
        }
        else
        {
            s1[i]='\0';
            break;
        }
    }

   for(i=0;i<k;i++)
   {
    prefix[i]=s1[i];
   }
   prefix[i]='\0';
   //return s1;
}
char * longestCommonPrefix(char ** strs, int strsSize){
 int i=0;
prefix=strs[0];
 for(i=1;i<strsSize;i++)
 {
     check(prefix,strs[i]);
 }
return prefix;


}
void main()
{
    int m,n;
    printf("enter no.of strings");
    scanf("%d",&m);
    char *strs[m];
    for(int i=0;i<m;i++)
    {
        //printf("enter string size");
        //scanf("%d",&n);
        strs[i]=(char *)(malloc(100*sizeof(char)));
        scanf("%s",strs[i]);
    }
    printf("The longest common prefix is %s",longestCommonPrefix(strs,m));

}
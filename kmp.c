#include<stdio.h>
#include<string.h>
#include<malloc.h>
int* compute_prefix(char *p)
{
    int p1=0;
    int *a;
    a=(int *)(malloc(strlen(p)*sizeof(int)));
    a[0]=0;
    printf("%d\n",strlen(p));
  
    for(int i=1;i<strlen(p);i++)
    {
        while(p1>0 && p[i]!=p[p1])
        {
            p1=a[p1-1];
        }
        if(p[p1]==p[i])
        {
            p1++;
        }
        a[i]=p1;

    }
    for(int i=0;i<strlen(p);i++)
    {
        printf("%d ",a[i]);
    }
    return a;
}
void kmp_matcher(char *t,char *p)
{
     int i=0,j=0;
     int n=strlen(t);
     int m=strlen(p);
     int *map;
   
     map=(int *)(strlen(p)*sizeof(int));
     map=compute_prefix(p);
     for(i=0;i<n;i++)
     {
        while(j>0 && p[j]!=t[i])
        {
            j=map[j];
        }
        if(p[j]==t[i])
        {
            j++;
        }
        if(j==m-1)
        {
            printf("pattern occurs at %d index\n",(i-j)+1);
            j=map[j];

        }
       

     }
     
}
void main()
{
    int m,n;
    m=100;
    n=20;
    char s[m],p[n];

    scanf("%s",s);
    scanf("%s",p);
    kmp_matcher(s,p);
}
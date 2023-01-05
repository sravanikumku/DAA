#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<stdio.h>
#include<string.h>
char pop(char *stack,int *top)
{
    return stack[(*top)--];
}
void push(char *stack,int *top,char ch)
{
    stack[++(*top)]=ch;

}
char * reverseWords(char * s){
int right=strlen(s)-1;
char stack[strlen(s)];
char *ans=malloc(strlen(s)+1);
int top=-1;
int k=0;
for(int i=right;i>=0;i--)
{
    if((s[i]==' ' && i==right)||(s[i]==' ' && i==0))
    {
        continue;
    }
    else if(s[i]==' '&& s[i+1]==' ')
{
    continue;
}
    else if(s[i]==' ')
    {
        while(top!=-1)

        {
           
           ans[k++]=pop(stack,&top);
        }
       
        ans[k++]=' ';
    }
    else
    {
        
        push(stack,&top,s[i]);
       
    }
}

while(top!=-1)
{
    
ans[k++]=pop(stack,&top);
}
if(ans[k-1]==' ')
{
    
    ans[k-1]='\0';
}
else
{
    
ans[k++]='\0';

}

char *p=ans;
return p;
}
void main()
{
  int n;
  char *s;
  printf("enter string");
  scanf("%[^\n]",s);
  char *k=reverseWords(s);
  printf("The resulted string is: %s",k);
}
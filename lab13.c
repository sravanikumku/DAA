#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *create(struct ListNode *head)
{
    struct ListNode* new,*prev;
    char ch;
    int x;
    printf("press n to stop s to continue");
    scanf(" %c",&ch);
    if(ch!='n')
    {
        printf("enter value");
        scanf("%d",&x);
        new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
        new->val=x;
        new->next=NULL;
        while(ch!='n')
        {
            if(head==NULL)
            {
                head=new;
                prev=new;
            }
            else
            {
                prev->next=new;
                prev=new;
            }
            printf("press n to stop s to contiue");
            scanf(" %c",&ch);
            if(ch=='n')
            {
                break;
            }
            printf("enter x");
            scanf("%d",&x);
            new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
            new->val=x;
            new->next=NULL;


        }
        return head;
    }
    return head;
}
struct ListNode* mergeList(struct ListNode *l1,struct ListNode *l2)
{
    if(l1==NULL && l2==NULL){return NULL;}
    if(l1==NULL){return l2;}
    if(l2==NULL){return l1;}

    
    struct ListNode *ptr1 = l1;
    struct ListNode *ptr2 = l2;
    
    struct ListNode *new_head = (ptr2->val < ptr1->val) ? ptr2 : ptr1;
    struct ListNode *ptr = new_head;
    
    if(new_head == ptr1){ptr1=ptr1->next;}
    else{ptr2=ptr2->next;}
    
    while(ptr1 && ptr2)
    {
        if(ptr1->val <= ptr2->val){
            ptr->next = ptr1;
            ptr = ptr->next;
            ptr1 = ptr1->next;
        }   
        else{
            ptr->next = ptr2;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
    }
    
    while(ptr1){ptr->next = ptr1;ptr = ptr->next;ptr1 = ptr1->next;}
    while(ptr2){ptr->next = ptr2;ptr = ptr->next;ptr2 = ptr2->next;}
    
    return new_head;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    
    struct ListNode  *new_head = NULL;
    
    for(int i=0;i<listsSize;i++){
        new_head = mergeList(new_head,lists[i]);
    }
    
    return new_head;
}
void display(struct ListNode* head)
{
    struct ListNode* temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->val);
        temp=temp->next;
    }
    printf("NULL");
}
void main()
{
    struct ListNode *first=NULL,*new,*res;
    int ls,i=0;
    printf("enter list size");
    scanf("%d",&ls);
    struct ListNode*lists[ls];
    for(i=0;i<ls;i++)
    {
        lists[i]=(struct ListNode*)(malloc(sizeof(struct ListNode)));

    }
    for(i=0;i<ls;i++)
    {
         new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
         lists[i]=create(first);
         
         
    } 
    res=mergeKLists(lists,ls);
    
    display(res);
}
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
 struct ListNode* addnode(struct ListNode* l1,struct ListNode* l2)
{
    struct ListNode* temp;
    if(l1==NULL)
    {
        l1=l2;
    }
    else
    {
        temp=l1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            
        }
        temp->next=l2;
    }
   return l1; 
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
  struct ListNode *new,*temp1=list1,*temp2=list2,*l3=NULL;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->val<temp2->val)
        {
            new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
            new->val=temp1->val;
            new->next=NULL;
            temp1=temp1->next;
            l3=addnode(l3,new);
            
            
        }
        else if(temp1->val>temp2->val)
        {
            new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
            new->val=temp2->val;
            new->next=NULL;
            temp2=temp2->next;
            l3=addnode(l3,new);
        }
        else
        {
            new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
            new->val=temp1->val;
            new->next=NULL;
            l3=addnode(l3,new);
            new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
            new->val=temp1->val;
            new->next=NULL;
            l3=addnode(l3,new);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        
    }
    if(temp2==NULL)
    {
        while(temp1!=NULL)
        {
            
            new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
            new->val=temp1->val;
            new->next=NULL;
            l3=addnode(l3,new);
            temp1=temp1->next;
        }
    }
    if(temp1==NULL)
    {
        while(temp2!=NULL)
        {
            new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
            new->val=temp2->val;
            new->next=NULL;
            temp2=temp2->next;
            l3=addnode(l3,new);
        }
    }
    return l3;
}

struct ListNode* create(struct ListNode *first)
{
    int x;
    char ch;
    struct ListNode* new;
    struct ListNode *prev;
    printf("enter data");
    scanf("%d",&x);
    printf("press n to stop s to continue");
    scanf(" %c",&ch);
    while(ch!='n')
    {
        new=(struct ListNode*)(malloc(sizeof(struct ListNode)));
        new->val=x;
        new->next=NULL;
        if(first==NULL)
        {
            first=new;
            prev=first;
        }
        else
        {
            prev->next=new;
            prev=new;

        }
        printf("enter data");
        scanf("%d",&x);
        printf("press n to stop s to continue");
        scanf(" %c",&ch);
    }
    return first;
}

void display(struct ListNode* head)
{
    struct ListNode* temp=head;
    while(temp!=NULL)
    {
       printf("%d->",temp->val);
       temp=temp->next;
    }
}

void main()
{
    struct ListNode*head1=NULL,*head2=NULL,*head3=NULL;
    printf("enter first linked list")
    head1=create(head1);
    printf("enter second linked list");
    head2=create(head2);

    head3=mergeTwoLists(head1,head2);
    printf("the merged list is");
display(head3);

}
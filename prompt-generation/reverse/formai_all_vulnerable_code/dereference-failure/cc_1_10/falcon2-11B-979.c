//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;

void push(int data)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    
    if(head==NULL)
    {
        head=new_node;
        return;
    }
    
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    
    temp->next=new_node;
}

void print()
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void delete(int data)
{
    struct node* temp=head;
    struct node* prev=NULL;
    
    if(temp==NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            if(prev==NULL)
            {
                head=temp->next;
            }
            else
            {
                prev->next=temp->next;
            }
            
            free(temp);
            return;
        }
        
        prev=temp;
        temp=temp->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    print();
    
    delete(20);
    print();
    
    return 0;
}
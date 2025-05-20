//FormAI DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
void create(int n)
{
    struct node *temp,*newnode;
    int i;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory allocation failed");
    }
    else
    {
        printf("Enter data for node 1: ");
        scanf("%d",&head->data);
        head->next=NULL;
        temp=head;
    for(i=2;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
            printf("Memory allocation failed");
        }
        else
        {
            printf("Enter data for node %d: ",i);
            scanf("%d",&newnode->data);
            newnode->next=NULL;
            temp->next=newnode;
            temp=temp->next;
        }
    }
    }
}
void display()
{
    struct node *temp=head;
    if(temp==NULL)
    {
        printf("Empty List");
    }
    else
    {
        printf("Data : ");
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void insert(int x)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Memory allocation failed");
    }
    else
    {
        printf("Enter the data to be inserted: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=head;
        while(temp->next!=NULL&&temp->data!=x)
        {
            temp=temp->next;
        }
        if(temp->next==NULL&&temp->data!=x)
        {
            printf("Data not found in the list");
        }
        else
        {
            newnode->next=temp->next;
            temp->next=newnode;
            printf("Data %d inserted successfully",newnode->data);
        }
    }
}
void delete(int x)
{
    struct node *temp,*prev;
    if(head==NULL)
    {
        printf("Empty List");
    }
    else if(head->data==x)
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("Data %d deleted successfully",x);
    }
    else
    {
        temp=head;
        while(temp->next!=NULL&&temp->data!=x)
        {
            prev=temp;
            temp=temp->next;
        }
        if(temp->next==NULL&&temp->data!=x)
        {
            printf("Data not found in the list");
        }
        else
        {
            prev->next=temp->next;
            free(temp);
            printf("Data %d deleted successfully",x);
        }
    }
}
int main()
{
    int n,x,choice;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    create(n);
    while(1)
    {
        printf("\n\n1.Display\n2.Insert\n3.Delete\n4.Exit\n");        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: display();
                    break;
            
            case 2: printf("Enter the data after which the new node is to be inserted: ");
                    scanf("%d",&x);
                    insert(x);
                    break;

            case 3: printf("Enter the data to be deleted: ");
                    scanf("%d",&x);
                    delete(x);
                    break;

            case 4: exit(0);

            default:printf("Invalid Choice");
        }
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Database simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Record
{
    int id;
    char name[20];
    int age;
    char dept[20];
}Record;

typedef struct Node
{
    Record data;
    struct Node *next;
}Node;

Node *start = NULL;

int count = 0;

void insert();
void display();
void search();
void delete();
void modify();

int main()
{
    int choice;
    do
    {
        printf("\nC DATABASE SIMULATION");
        printf("\n1: Insert");
        printf("\n2: Display");
        printf("\n3: Search");
        printf("\n4: Delete");
        printf("\n5: Modify");
        printf("\n6: Exit");

        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                delete();
                break;
            case 5:
                modify();
                break;
            case 6:
                printf("\nExiting...");
                break;
            default:
                printf("\nInvalid choice! Try again.");
        }
    }while(choice!=6);

    return 0;
}

void insert()
{
    Node *temp;
    int id;
    char name[20];
    int age;
    char dept[20];
    srand(time(NULL));
    temp = (Node*)malloc(sizeof(Node));
    temp->data.id = rand()%10000+1;
    printf("\nEnter name: ");
    scanf("%s",temp->data.name);
    printf("\nEnter age: ");
    scanf("%d",&temp->data.age);
    printf("\nEnter department: ");
    scanf("%s",temp->data.dept);
    printf("\nRecord added successfully with ID: %d",temp->data.id);
    temp->next = NULL;
    if(start==NULL)
    {
        start = temp;
        count++;
        return;
    }
    Node *ptr = start;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    count++;
}

void display()
{
    if(start==NULL)
    {
        printf("\nNo records found!");
        return;
    }
    printf("\nList of records:");
    printf("\nID\t\tName\t\tAge\t\tDepartment");
    Node *ptr = start;
    while(ptr!=NULL)
    {
        printf("\n%d\t\t%s\t\t%d\t\t%s",ptr->data.id,ptr->data.name,ptr->data.age,ptr->data.dept);
        ptr = ptr->next;
    }
}

void search()
{
    if(start==NULL)
    {
        printf("\nNo records found!");
        return;
    }
    int id,flag=0;
    printf("\nEnter ID to search: ");
    scanf("%d",&id);
    Node *ptr = start;
    while(ptr!=NULL)
    {
        if(ptr->data.id==id)
        {
            printf("\nRecord found!");
            printf("\nID\t\tName\t\tAge\t\tDepartment");
            printf("\n%d\t\t%s\t\t%d\t\t%s",ptr->data.id,ptr->data.name,ptr->data.age,ptr->data.dept);
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(flag==0)
    {
        printf("\nRecord not found!");
    }
}

void delete()
{
    if(start==NULL)
    {
        printf("\nNo records found!");
        return;
    }
    int id,flag=0;
    printf("\nEnter ID to delete: ");
    scanf("%d",&id);
    Node *ptr = start;
    Node *prev=NULL;
    while(ptr!=NULL)
    {
        if(ptr->data.id==id)
        {
            printf("\nRecord deleted!");
            if(prev==NULL)
            {
                start = ptr->next;
            }
            else
            {
                prev->next = ptr->next;
            }
            free(ptr);
            count--;
            flag = 1;
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    if(flag==0)
    {
        printf("\nRecord not found!");
    }
}

void modify()
{
    if(start==NULL)
    {
        printf("\nNo records found!");
        return;
    }
    int id,flag=0;
    printf("\nEnter ID to modify: ");
    scanf("%d",&id);
    Node *ptr = start;
    while(ptr!=NULL)
    {
        if(ptr->data.id==id)
        {
            printf("\nRecord found!");
            printf("\nID\t\tName\t\tAge\t\tDepartment");
            printf("\n%d\t\t%s\t\t%d\t\t%s",ptr->data.id,ptr->data.name,ptr->data.age,ptr->data.dept);
            printf("\nEnter new name: ");
            scanf("%s",ptr->data.name);
            printf("\nEnter new age: ");
            scanf("%d",&ptr->data.age);
            printf("\nEnter new department: ");
            scanf("%s",ptr->data.dept);
            printf("\nRecord modified!");
            flag = 1;
            break;
        }
        ptr = ptr->next;
    }
    if(flag==0)
    {
        printf("\nRecord not found!");
    }
}
//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head;

void insert(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        return;
    }

    node *ptr = head;
    while(ptr->next!= NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = temp;
}

void print()
{
    if(head == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    node *ptr = head;
    while(ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;
    do
    {
        printf("1. Insert element\n");
        printf("2. Print queue\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                print();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while(choice!= 3);

    return 0;
}
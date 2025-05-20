//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* head = NULL;

void push(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList()
{
    struct node* current = head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int choice, data;
    printf("Enter 1 to push a number to the stack\n");
    printf("Enter 2 to print the list\n");
    printf("Enter 3 to exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            printList();
            break;
        case 3:
            printf("Exiting the program...\n");
            return 0;
        default:
            printf("Invalid choice, try again\n");
    }
    return 0;
}
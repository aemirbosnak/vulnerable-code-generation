//FormAI DATASET v1.0 Category: Linked list operations ; Style: modular
#include<stdio.h>
#include<stdlib.h>

// Structure of a node
typedef struct node
{
    int data;
    struct node *next;
}node;

// Function to insert node at the beginning
node *insertBegin(node *head, int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

// Function to insert node at the end
node *insertEnd(node *head, int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
        return head;
    }

    node *current = head;

    while(current->next != NULL)
        current = current->next;

    current->next = newNode;

    return head;
}

// Function to delete the beginning node
node *deleteBegin(node *head)
{
    if(head == NULL)
    {
        printf("List is already empty!\n");
        return NULL;
    }

    node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Function to delete the end node
node *deleteEnd(node *head)
{
    if(head == NULL)
    {
        printf("List is already empty!\n");
        return NULL;
    }

    node *current = head;
    node *prev = NULL;

    while(current->next != NULL)
    {
        prev = current;
        current = current->next;
    }

    if(prev)
        prev->next = NULL;
    else
        head = NULL;

    free(current);

    return head;
}

// Function to display the linked list
void display(node *head)
{
    if(head == NULL)
        printf("List is empty!\n");
    else
    {
        printf("List: ");
        while(head != NULL)
        {
            printf("%d ",head->data);
            head = head->next;
        }
        printf("\n");
    }
}

int main()
{
    node *head = NULL;

    head = insertBegin(head, 10);
    head = insertBegin(head, 20);
    head = insertEnd(head, 30);
    display(head);
    head = deleteBegin(head);
    display(head);
    head = deleteEnd(head);
    display(head);

    return 0;
}
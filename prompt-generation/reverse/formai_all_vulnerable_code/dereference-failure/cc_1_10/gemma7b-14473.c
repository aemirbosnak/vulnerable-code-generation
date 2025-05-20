//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void schedule(struct node** head)
{
    struct node* current = *head;
    struct node* next = NULL;

    while (current)
    {
        next = current->next;
        current->next = NULL;
        printf("Executing process %d\n", current->data);
        sleep(current->data);
        insert(head, current->data);
        current = next;
    }
}

int main()
{
    struct node* head = NULL;

    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);

    schedule(&head);

    return 0;
}
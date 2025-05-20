//FormAI DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} Node;

Node *head = NULL;

void insert(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Out of memory!\n");
        exit(1);
    }

    newNode->value = value;
    newNode->next = head;
    head = newNode;
}

void delete(int value)
{
    Node *current = head;
    Node *previous = NULL;

    while (current != NULL && current->value != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Value not found!\n");
        return;
    }

    if (previous == NULL)
    {
        head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current);
}

void print()
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main()
{
    insert(1);
    insert(2);
    insert(3);

    print();

    delete(2);

    print();

    return 0;
}
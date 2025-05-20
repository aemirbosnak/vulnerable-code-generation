//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

Node* insert(Node* head, char data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

void compress(Node* head)
{
    Node* current = head;
    Node* previous = NULL;
    int count = 1;

    while (current)
    {
        if (previous && current->data == previous->data)
        {
            count++;
        }
        else
        {
            previous = current;
            insert(head, (count - 1) + (int)current->data);
            count = 1;
        }
    }

    insert(head, count - 1);
}

int main()
{
    Node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 2);
    head = insert(head, 3);

    compress(head);

    Node* current = head;
    while (current)
    {
        printf("%c ", current->data);
    }

    printf("\n");

    return 0;
}
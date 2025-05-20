//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

void insert(Node* head, char data)
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
}

void traverse(Node* head)
{
    while (head)
    {
        printf("%c ", head->data);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    insert(head, 'a');
    insert(head, 'b');
    insert(head, 'c');
    insert(head, 'd');
    insert(head, 'e');

    traverse(head);

    return 0;
}
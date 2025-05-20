//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // Create a few nodes
    for (int i = 0; i < MAX_SIZE; i++)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = 'a' + i;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Traverse the linked list
    tail = head;
    while (tail)
    {
        printf("%c ", tail->data);
        tail = tail->next;
    }

    // Free the nodes
    tail = head;
    while (tail)
    {
        Node* temp = tail;
        tail = tail->next;
        free(temp);
    }

    return 0;
}
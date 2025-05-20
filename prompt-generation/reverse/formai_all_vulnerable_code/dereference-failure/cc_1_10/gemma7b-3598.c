//Gemma-7B DATASET v1.0 Category: Audio processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct Node
{
    struct Node* next;
    int value;
} Node;

Node* insert_node(Node* head, int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;
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

void traverse(Node* head)
{
    while (head)
    {
        printf("%d ", head->value);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;
    head = insert_node(head, 10);
    insert_node(head, 20);
    insert_node(head, 30);
    insert_node(head, 40);

    traverse(head);

    return 0;
}
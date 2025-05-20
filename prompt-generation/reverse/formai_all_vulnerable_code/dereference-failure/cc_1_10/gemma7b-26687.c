//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node
{
    int x, y;
    struct Node* next;
} Node;

Node* insert(Node* head, int x, int y)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
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
        printf("(%d, %d) ", head->x, head->y);
        head = head->next;
    }
}

int main()
{
    Node* head = NULL;

    insert(head, 1, 2);
    insert(head, 3, 4);
    insert(head, 5, 6);
    insert(head, 7, 8);

    traverse(head);

    return 0;
}
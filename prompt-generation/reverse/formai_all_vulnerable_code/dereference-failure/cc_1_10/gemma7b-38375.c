//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node
{
    int x, y;
    struct Node* next;
} Node;

void Insert(Node** head, int x, int y)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
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

int Distance(Node* node1, Node* node2)
{
    int dx = node2->x - node1->x;
    int dy = node2->y - node1->y;
    return (int)sqrt(dx * dx + dy * dy);
}

int main()
{
    Node* head = NULL;
    Insert(&head, 0, 0);
    Insert(&head, 10, 10);
    Insert(&head, 20, 20);

    int distance = Distance(head, head->next);
    printf("Distance between (0, 0) and (10, 10) is: %d\n", distance);

    distance = Distance(head, head->next->next);
    printf("Distance between (0, 0) and (20, 20) is: %d\n", distance);

    return 0;
}
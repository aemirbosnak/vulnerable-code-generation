//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node
{
    int x, y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y)
{
    Node* newNode = malloc(sizeof(Node));
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

void findPath(Node* head, int x, int y)
{
    if (head == NULL)
    {
        return;
    }

    if (head->x == x && head->y == y)
    {
        printf("Path found!\n");
        return;
    }

    findPath(head->next, x, y);

    if (head->x - 1 >= 0 && head->x - 1 != x && head->y == y)
    {
        insert(head, head->x - 1, head->y);
    }

    if (head->y - 1 >= 0 && head->y - 1 != y && head->x == x)
    {
        insert(head, head->x, head->y - 1);
    }
}

int main()
{
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 0);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 3, 1);
    insert(&head, 3, 2);

    findPath(head, 2, 2);

    return 0;
}
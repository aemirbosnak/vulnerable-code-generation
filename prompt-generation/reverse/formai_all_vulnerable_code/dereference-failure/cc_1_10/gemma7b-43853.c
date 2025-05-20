//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node
{
    int x, y;
    struct Node* next;
} Node;

void findPath(int x, int y, Node** head)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(Node));
        (*head)->x = x;
        (*head)->y = y;
        (*head)->next = NULL;
    }

    Node* current = *head;

    while (current)
    {
        if (current->x == x && current->y == y)
        {
            return;
        }

        if (current->next == NULL)
        {
            current->next = malloc(sizeof(Node));
            current = current->next;
            current->x = x;
            current->y = y;
            current->next = NULL;
        }

        current = current->next;
    }

    return;
}

int main()
{
    Node* head = NULL;

    findPath(2, 3, &head);
    findPath(4, 5, &head);
    findPath(6, 7, &head);

    for (Node* current = head; current; current = current->next)
    {
        printf("(%d, %d)\n", current->x, current->y);
    }

    return 0;
}
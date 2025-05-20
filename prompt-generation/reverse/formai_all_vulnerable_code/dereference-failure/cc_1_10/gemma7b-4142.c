//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node
{
    int x;
    int y;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int x, int y)
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
        ((*head)->next = newNode);
    }
}

void findClosestPair(Node* head, int targetX, int targetY)
{
    int minDistance = MAX;
    Node* current = head;

    while (current)
    {
        int dx = abs(targetX - current->x);
        int dy = abs(targetY - current->y);
        int distance = dx + dy;

        if (distance < minDistance)
        {
            minDistance = distance;
        }
        current = current->next;
    }

    printf("The closest pair is: (%d, %d) with a distance of %d\n", head->x, head->y, minDistance);
}

int main()
{
    Node* head = NULL;
    insertAtTail(&head, 1, 2);
    insertAtTail(&head, 3, 4);
    insertAtTail(&head, 5, 6);
    insertAtTail(&head, 7, 8);

    findClosestPair(head, 4, 5);

    return 0;
}
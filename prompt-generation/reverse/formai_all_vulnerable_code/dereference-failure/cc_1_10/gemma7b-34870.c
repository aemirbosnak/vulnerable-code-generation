//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
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

void insertNode(Node* head, int x, int y)
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
}

void findClosestNode(Node* head, int x, int y)
{
    int minDistance = MAX;
    Node* closestNode = NULL;

    for (Node* currentNode = head; currentNode != NULL; currentNode = currentNode->next)
    {
        int distance = abs(x - currentNode->x) + abs(y - currentNode->y);

        if (distance < minDistance)
        {
            minDistance = distance;
            closestNode = currentNode;
        }
    }

    printf("Closest node: (%d, %d)\n", closestNode->x, closestNode->y);
    printf("Distance: %d\n", minDistance);
}

int main()
{
    Node* head = NULL;

    insertNode(head, 10, 10);
    insertNode(head, 20, 20);
    insertNode(head, 30, 30);

    findClosestNode(head, 15, 15);

    return 0;
}
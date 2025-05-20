//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct Node
{
    int x;
    int y;
    struct Node* next;
} Node;

Node* insertNode(Node* head, int x, int y)
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

void findClosestNode(Node* head, int x, int y)
{
    Node* current = head;
    int minDistance = MAX_SIZE;

    while (current)
    {
        int distance = abs(current->x - x) + abs(current->y - y);

        if (distance < minDistance)
        {
            minDistance = distance;
        }

        current = current->next;
    }

    printf("The closest node is at (%d, %d) with a distance of %d\n", current->x, current->y, minDistance);
}

int main()
{
    Node* head = NULL;

    insertNode(head, 10, 20);
    insertNode(head, 20, 30);
    insertNode(head, 30, 40);
    insertNode(head, 40, 50);

    findClosestNode(head, 25, 35);

    return 0;
}
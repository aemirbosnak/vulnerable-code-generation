//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node
{
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

int isSafe(int x, int y)
{
    return (x >= 0 && x < MAX_SIZE && y >= 0 && y < MAX_SIZE);
}

int heuristic(Node* current, Node* goal)
{
    return abs(current->x - goal->x) + abs(current->y - goal->y);
}

void findPath(Node* current, Node* goal)
{
    if (current->x == goal->x && current->y == goal->y)
    {
        return;
    }

    for (Node* neighbor = current->next; neighbor; neighbor)
    {
        if (isSafe(neighbor->x, neighbor->y) && heuristic(neighbor, goal) < heuristic(current, goal))
        {
            findPath(neighbor, goal);
        }
    }

    return;
}

int main()
{
    Node* start = createNode(0, 0);
    Node* goal = createNode(MAX_SIZE - 1, MAX_SIZE - 1);

    findPath(start, goal);

    return 0;
}
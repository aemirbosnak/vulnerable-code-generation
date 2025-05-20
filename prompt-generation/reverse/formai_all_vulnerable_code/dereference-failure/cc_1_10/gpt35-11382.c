//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int g_map[ROW][COL] = {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
}; // the map we are working with

int g_destinationX = 8;
int g_destinationY = 8;

typedef struct
{
    int x;
    int y;
} Node;

Node *g_path;

void push(int length, Node node)
{
    Node *newPath = malloc(length * sizeof(Node));
    for (int i = 0; i < length - 1; ++i)
        newPath[i] = g_path[i];
    newPath[length - 1] = node;

    if (g_path != NULL)
        free(g_path);

    g_path = newPath;
}

int euclideanDistance(int startX, int startY, int destX, int destY)
{
    int x = startX - destX;
    int y = startY - destY;
    return x * x + y * y;
} // A utility function to compute Euclidean distance

bool isValid(int x, int y)
{
    if (g_map[x][y] == 0)
        return true;

    if (x == g_destinationX && y == g_destinationY)
        return true;

    return false;
} // A utility function to check whether a given cell is valid or not

bool isDestination(int x, int y)
{
    if (x == g_destinationX && y == g_destinationY)
        return true;

    return false;
} // A utility function to check whether the given cell is destination or not

bool search(Node *currentNode, int currentCost)
{
    if (g_path == NULL)
        push(1, *currentNode);
    else
        push(sizeof(g_path) + 1, *currentNode);

    if (isDestination(currentNode->x, currentNode->y))
        return true;

    int min = 1000000;
    Node nextNode;
    nextNode.x = currentNode->x + 1;
    nextNode.y = currentNode->y;
    int distance = euclideanDistance(nextNode.x, nextNode.y, g_destinationX, g_destinationY);
    if (isValid(nextNode.x, nextNode.y) && distance < min)
    {
        min = distance;
        search(&nextNode, currentCost + 1);
    }

    nextNode.x = currentNode->x - 1;
    nextNode.y = currentNode->y;
    distance = euclideanDistance(nextNode.x, nextNode.y, g_destinationX, g_destinationY);
    if (isValid(nextNode.x, nextNode.y) && distance < min)
    {
        min = distance;
        search(&nextNode, currentCost + 1);
    }

    nextNode.x = currentNode->x;
    nextNode.y = currentNode->y + 1;
    distance = euclideanDistance(nextNode.x, nextNode.y, g_destinationX, g_destinationY);
    if (isValid(nextNode.x, nextNode.y) && distance < min)
    {
        min = distance;
        search(&nextNode, currentCost + 1);
    }

    nextNode.x = currentNode->x;
    nextNode.y = currentNode->y - 1;
    distance = euclideanDistance(nextNode.x, nextNode.y, g_destinationX, g_destinationY);
    if (isValid(nextNode.x, nextNode.y) && distance < min)
        search(&nextNode, currentCost + 1);

    return false;
} // The main searching function using Depth First Search

int main()
{
    g_path = NULL;

    Node start;
    start.x = 1;
    start.y = 1;

    printf("Depth First Search Pathfinding Algorithm\n\n");

    if (search(&start, 0))
    {
        printf("Path found!\n\n");

        for (int i = 0; i < sizeof(g_path) / sizeof(Node); i++)
            printf("x: %d, y: %d\n", g_path[i].x, g_path[i].y);
    }
    else
        printf("Path not found.\n");

    return 0;
}
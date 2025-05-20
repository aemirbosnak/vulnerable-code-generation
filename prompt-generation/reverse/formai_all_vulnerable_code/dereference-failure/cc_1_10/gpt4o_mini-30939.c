//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define MAX 20

// Struct to represent a point on the grid
typedef struct {
    int x, y;
} Point;

// Struct to represent a node in the A* pathfinding algorithm
typedef struct Node {
    Point point;
    int gCost; // Cost from start to node
    int hCost; // Heuristic cost from node to end
    int fCost; // Total cost
    struct Node *parent;
} Node;

// Grid and its properties
int grid[MAX][MAX] = {
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

Point start = {0, 0}; // Starting point
Point end = {9, 9}; // Target point

// Function prototypes
Node* createNode(int x, int y, Node *parent);
bool isValid(int x, int y);
int heuristic(Point a, Point b);
bool isInOpenList(Node *node, Node *openList[], int openCount);
void printPath(Node *node);
void aStarPathfinding();

int main() {
    printf("Elementary, my dear Watson! We shall uncover the path using the A* algorithm.\n");
    aStarPathfinding();
    return 0;
}

Node* createNode(int x, int y, Node *parent) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->gCost = 0;
    newNode->hCost = 0;
    newNode->fCost = 0;
    newNode->parent = parent;
    return newNode;
}

bool isValid(int x, int y) {
    return (x >= 0 && x < MAX && y >= 0 && y < MAX && grid[x][y] == 0);
}

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool isInOpenList(Node *node, Node *openList[], int openCount) {
    for (int i = 0; i < openCount; i++) {
        if (openList[i]->point.x == node->point.x && openList[i]->point.y == node->point.y) {
            return true;
        }
    }
    return false;
}

void printPath(Node *node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d, %d) ", node->point.x, node->point.y);
}

void aStarPathfinding() {
    Node *openList[MAX * MAX];
    int openCount = 0;

    Node *startNode = createNode(start.x, start.y, NULL);
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, end);
    startNode->fCost = startNode->gCost + startNode->hCost;
    
    openList[openCount++] = startNode;

    while (openCount > 0) {
        Node *currentNode = openList[0];
        int currentIndex = 0;

        // Find the node with the lowest fCost
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->fCost < currentNode->fCost) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        // Remove currentNode from openList
        for (int i = currentIndex; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;

        // If we have reached the end, print the path
        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            return;
        }

        // Explore the neighbors
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) == abs(j)) continue; // Skip diagonal movements
                int neighborX = currentNode->point.x + i;
                int neighborY = currentNode->point.y + j;

                if (isValid(neighborX, neighborY)) {
                    Node *neighborNode = createNode(neighborX, neighborY, currentNode);
                    neighborNode->gCost = currentNode->gCost + 1;
                    neighborNode->hCost = heuristic(neighborNode->point, end);
                    neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;

                    if (!isInOpenList(neighborNode, openList, openCount)) {
                        openList[openCount++] = neighborNode;
                    } else {
                        free(neighborNode); // Free memory for nodes already in open list
                    }
                }
            }
        }
    }

    printf("No path found. The game of cat and mouse continues, but we shall return!\n");
}
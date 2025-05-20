//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point location;
    float gCost;
    float hCost;
    float fCost;
    struct Node* parent;
} Node;

Node* openList[MAX_NODES];
Node* closedList[MAX_NODES];
int openListCount = 0;
int closedListCount = 0;

// Function prototypes
float heuristic(Point a, Point b);
bool inClosedList(Node* node);
bool inOpenList(Node* node);
void addToOpenList(Node* node);
Node* popLowestFCostNode();

// The whimsically adventurous 2D grid
int grid[HEIGHT][WIDTH] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 0}
};

float heuristic(Point a, Point b) {
    // Gandalf's straight line distance (Manhattan distance)
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool inClosedList(Node* node) {
    for (int i = 0; i < closedListCount; i++) {
        if (closedList[i]->location.x == node->location.x && closedList[i]->location.y == node->location.y)
            return true;
    }
    return false;
}

bool inOpenList(Node* node) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->location.x == node->location.x && openList[i]->location.y == node->location.y)
            return true;
    }
    return false;
}

void addToOpenList(Node* node) {
    openList[openListCount++] = node;
}

Node* popLowestFCostNode() {
    int lowestIndex = 0;
    for (int i = 1; i < openListCount; i++) {
        if (openList[i]->fCost < openList[lowestIndex]->fCost) {
            lowestIndex = i;
        }
    }
    Node* node = openList[lowestIndex];
    openListCount--;
    for (int i = lowestIndex; i < openListCount; i++) {
        openList[i] = openList[i + 1];
    }
    return node;
}

void printPath(Node* node) {
    // Printing the path in an exciting manner
    if (node == NULL) return;
    printPath(node->parent);
    printf("Move to (%d, %d)\n", node->location.x, node->location.y);
}

void findPath(Point start, Point end) {
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->location = start;
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, end);
    startNode->fCost = startNode->hCost;
    startNode->parent = NULL;
    
    addToOpenList(startNode);
    
    while (openListCount > 0) {
        Node* currentNode = popLowestFCostNode();
        
        if (currentNode->location.x == end.x && currentNode->location.y == end.y) {
            printf("Path found:\n");
            printPath(currentNode);
            return;
        }

        closedList[closedListCount++] = currentNode;
        
        // The directions the brave adventurer can wander
        Point directions[] = {
            {0, 1},   // Down
            {1, 0},   // Right
            {0, -1},  // Up
            {-1, 0}   // Left
        };

        for (int i = 0; i < 4; i++) {
            Point newPoint = {currentNode->location.x + directions[i].x, currentNode->location.y + directions[i].y};

            if (newPoint.x < 0 || newPoint.x >= WIDTH || newPoint.y < 0 || newPoint.y >= HEIGHT || grid[newPoint.y][newPoint.x] == 1) {
                continue; // Out of bounds or blocked path
            }

            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->location = newPoint;
            newNode->gCost = currentNode->gCost + 1;
            newNode->hCost = heuristic(newPoint, end);
            newNode->fCost = newNode->gCost + newNode->hCost;
            newNode->parent = currentNode;

            if (inClosedList(newNode)) {
                free(newNode);
                continue; // Already visited
            }

            if (inOpenList(newNode)) {
                // Optionally update the node if this path is better (gCost)
                for (int j = 0; j < openListCount; j++) {
                    if (openList[j]->location.x == newNode->location.x && openList[j]->location.y == newNode->location.y && newNode->gCost < openList[j]->gCost) {
                        openList[j]->gCost = newNode->gCost;
                        openList[j]->parent = currentNode;
                        break;
                    }
                }
                free(newNode);
            } else {
                addToOpenList(newNode);
            }
        }
    }
    
    printf("No path found!\n");
}

int main() {
    Point start = {0, 0};
    Point end = {9, 9};
    
    printf("Questing for a path...\n");
    findPath(start, end);
    
    return 0;
}
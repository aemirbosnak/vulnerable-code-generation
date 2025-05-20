//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define INF 9999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    float gCost; // Cost from start to current node
    float hCost; // Heuristic cost to goal
    float fCost; // Total cost
    struct Node* parent; // Pointer to parent node
} Node;

Node* openList[WIDTH * HEIGHT];
Node* closedList[WIDTH * HEIGHT];
int openCount = 0;
int closedCount = 0;

// Function prototypes
float heuristic(Point a, Point b);
void addToOpenList(Node* node);
bool isInOpenList(Point point);
bool isInClosedList(Point point);
Node* getLowestFCostNode();
void reconstructPath(Node* node);
Point directions[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // Right, Down, Left, Up

int grid[WIDTH][HEIGHT] = {
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0}
};

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y); // Manhattan distance
}

void addToOpenList(Node* node) {
    openList[openCount++] = node;
}

bool isInOpenList(Point point) {
    for (int i = 0; i < openCount; i++) {
        if (openList[i]->pos.x == point.x && openList[i]->pos.y == point.y)
            return true;
    }
    return false;
}

bool isInClosedList(Point point) {
    for (int i = 0; i < closedCount; i++) {
        if (closedList[i]->pos.x == point.x && closedList[i]->pos.y == point.y)
            return true;
    }
    return false;
}

Node* getLowestFCostNode() {
    Node* lowest = NULL;
    for (int i = 0; i < openCount; i++) {
        if (!lowest || openList[i]->fCost < lowest->fCost)
            lowest = openList[i];
    }
    return lowest;
}

void reconstructPath(Node* node) {
    if (node == NULL)
        return;
    reconstructPath(node->parent);
    printf("-> (%d, %d) ", node->pos.x, node->pos.y);
}

int main() {
    Point start = {0, 0};
    Point goal = {9, 9};

    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->pos = start;
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, goal);
    startNode->fCost = startNode->hCost;
    startNode->parent = NULL;

    addToOpenList(startNode);

    while (openCount > 0) {
        Node* currentNode = getLowestFCostNode();

        if (currentNode->pos.x == goal.x && currentNode->pos.y == goal.y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            printf("-> (%d, %d)\n", goal.x, goal.y);
            return 0;
        }

        openCount--;
        closedList[closedCount++] = currentNode;

        for (int i = 0; i < 4; i++) {
            Point neighborPos = {currentNode->pos.x + directions[i].x, currentNode->pos.y + directions[i].y};

            if (neighborPos.x < 0 || neighborPos.x >= WIDTH || neighborPos.y < 0 || neighborPos.y >= HEIGHT)
                continue;

            if (grid[neighborPos.x][neighborPos.y] == 1 || isInClosedList(neighborPos))
                continue;

            Node* neighborNode = (Node*)malloc(sizeof(Node));
            neighborNode->pos = neighborPos;
            neighborNode->gCost = currentNode->gCost + 1; // Assume cost between nodes is 1
            neighborNode->hCost = heuristic(neighborPos, goal);
            neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
            neighborNode->parent = currentNode;

            if (!isInOpenList(neighborPos))
                addToOpenList(neighborNode);
        }
    }

    printf("No path found!\n");
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define INF 10000

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point point;
    int gCost;
    int hCost;
    int fCost;
    struct Node* parent;
} Node;

Node* openList[WIDTH * HEIGHT];
int openListCount = 0;

bool grid[HEIGHT][WIDTH] = {
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void addOpenList(Node* node) {
    openList[openListCount++] = node;
}

Node* popLowestFCost() {
    int lowestIndex = 0;
    for (int i = 1; i < openListCount; i++) {
        if (openList[i]->fCost < openList[lowestIndex]->fCost) {
            lowestIndex = i;
        }
    }
    Node* lowestNode = openList[lowestIndex];
    openListCount--;
    for (int i = lowestIndex; i < openListCount; i++) {
        openList[i] = openList[i + 1];
    }
    return lowestNode;
}

bool isInOpenList(Point point) {
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->point.x == point.x && openList[i]->point.y == point.y) {
            return true;
        }
    }
    return false;
}

void findPath(Point start, Point end) {
    Node* startNode = malloc(sizeof(Node));
    startNode->point = start;
    startNode->gCost = 0;
    startNode->hCost = heuristic(start, end);
    startNode->fCost = startNode->gCost + startNode->hCost;
    startNode->parent = NULL;
    addOpenList(startNode);
    
    while (openListCount > 0) {
        Node* currentNode = popLowestFCost();
        
        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            printf("Path found:\n");
            Node* pathNode = currentNode;
            while (pathNode != NULL) {
                printf("(%d, %d) ", pathNode->point.x, pathNode->point.y);
                pathNode = pathNode->parent;
            }
            printf("\n");
            return;
        }
        
        // Check four directions (up, down, left, right)
        Point directions[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
        for (int i = 0; i < 4; i++) {
            Point neighbor = { currentNode->point.x + directions[i].x, currentNode->point.y + directions[i].y };
            if (neighbor.x < 0 || neighbor.x >= WIDTH || neighbor.y < 0 || neighbor.y >= HEIGHT || grid[neighbor.y][neighbor.x]) {
                continue; // Skip walls and out of bounds
            }

            Node* neighborNode = malloc(sizeof(Node));
            neighborNode->point = neighbor;
            neighborNode->gCost = currentNode->gCost + 1;
            neighborNode->hCost = heuristic(neighbor, end);
            neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
            neighborNode->parent = currentNode;

            if (!isInOpenList(neighbor) || neighborNode->gCost < currentNode->gCost) {
                addOpenList(neighborNode);
            }
        }
    }
    
    printf("No path found.\n");
}

int main() {
    Point start = {0, 0};
    Point end = {9, 9};
    findPath(start, end);
    return 0;
}
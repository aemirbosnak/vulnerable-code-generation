//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define OPEN_LIST_CAPACITY 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point point;
    float gCost;
    float hCost;
    float fCost;
    struct Node* parent;
} Node;

typedef struct {
    Node* nodes[OPEN_LIST_CAPACITY];
    int count;
} OpenList;

Node* createNode(int x, int y, float gCost, float hCost, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->point.x = x;
    newNode->point.y = y;
    newNode->gCost = gCost;
    newNode->hCost = hCost;
    newNode->fCost = gCost + hCost;
    newNode->parent = parent;
    return newNode;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool isInOpenList(OpenList* openList, Point point) {
    for (int i = 0; i < openList->count; i++) {
        if (openList->nodes[i]->point.x == point.x && openList->nodes[i]->point.y == point.y) {
            return true;
        }
    }
    return false;
}

void addToOpenList(OpenList* openList, Node* node) {
    if (openList->count < OPEN_LIST_CAPACITY) {
        openList->nodes[openList->count++] = node;
    }
}

Node* popLowestFCost(OpenList* openList) {
    Node* lowest = openList->nodes[0];
    int index = 0;

    for (int i = 1; i < openList->count; i++) {
        if (openList->nodes[i]->fCost < lowest->fCost) {
            lowest = openList->nodes[i];
            index = i;
        }
    }
    openList->nodes[index] = openList->nodes[--openList->count];
    return lowest;
}

bool isPointValid(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

// A* pathfinding algorithm
void AStar(Point start, Point goal) {
    OpenList openList = { .count = 0 };
    Node* startNode = createNode(start.x, start.y, 0, heuristic(start, goal), NULL);
    addToOpenList(&openList, startNode);

    while (openList.count > 0) {
        Node* currentNode = popLowestFCost(&openList);

        if (currentNode->point.x == goal.x && currentNode->point.y == goal.y) {
            printf("Path found:\n");
            Node* pathNode = currentNode;
            while (pathNode != NULL) {
                printf("(%d, %d) ", pathNode->point.x, pathNode->point.y);
                pathNode = pathNode->parent;
            }
            printf("\n");
            free(currentNode);
            return;
        }

        Point neighbors[4] = {
            {currentNode->point.x, currentNode->point.y - 1},
            {currentNode->point.x, currentNode->point.y + 1},
            {currentNode->point.x - 1, currentNode->point.y},
            {currentNode->point.x + 1, currentNode->point.y}
        };

        for (int i = 0; i < 4; i++) {
            Point neighbor = neighbors[i];

            if (isPointValid(neighbor.x, neighbor.y)) {
                float gCost = currentNode->gCost + 1; // Assuming all edges have a cost of 1
                float hCost = heuristic(neighbor, goal);
                
                if (!isInOpenList(&openList, neighbor)) {
                    Node* neighborNode = createNode(neighbor.x, neighbor.y, gCost, hCost, currentNode);
                    addToOpenList(&openList, neighborNode);
                }
            }
        }
        free(currentNode);
    }

    printf("No path found\n");
}

int main() {
    Point start = {0, 0};
    Point goal = {7, 5};
    AStar(start, goal);
    return 0;
}
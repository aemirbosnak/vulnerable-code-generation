//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10
#define INFINITY 99999

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point position;
    int g; // Cost from start to this node
    int h; // Heuristic cost to target
    int f; // Total cost
    struct Node* parent;
} Node;

Node* openList[WIDTH * HEIGHT];
Node* closedList[WIDTH * HEIGHT];

int openListSize = 0;
int closedListSize = 0;

int calculateHeuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y); // Manhattan distance
}

bool isInList(Node* list[], int size, Point position) {
    for (int i = 0; i < size; ++i) {
        if (list[i]->position.x == position.x && list[i]->position.y == position.y) {
            return true;
        }
    }
    return false;
}

void addToOpenList(Node* node) {
    openList[openListSize++] = node;
}

Node* getLowestCostNode() {
    Node* lowest = NULL;
    for (int i = 0; i < openListSize; ++i) {
        if (lowest == NULL || openList[i]->f < lowest->f) {
            lowest = openList[i];
        }
    }
    return lowest;
}

void removeNodeFromOpenList(Node* node) {
    for (int i = 0; i < openListSize; ++i) {
        if (openList[i] == node) {
            openList[i] = openList[--openListSize]; // Replace with last node
            return;
        }
    }
}

void displayPath(Node* node) {
    if (node == NULL) {
        return;
    }
    displayPath(node->parent);
    printf("-> (%d, %d) ", node->position.x, node->position.y);
}

void aStar(Point start, Point goal) {
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->position = start;
    startNode->g = 0;
    startNode->h = calculateHeuristic(start, goal);
    startNode->f = startNode->h;
    startNode->parent = NULL;

    addToOpenList(startNode);

    while (openListSize > 0) {
        Node* currentNode = getLowestCostNode();

        if (currentNode->position.x == goal.x && currentNode->position.y == goal.y) {
            printf("Path found: ");
            displayPath(currentNode);
            printf("\n");
            return;
        }

        removeNodeFromOpenList(currentNode);
        closedList[closedListSize++] = currentNode;

        // Check neighboring nodes
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                if (abs(dx) + abs(dy) != 1) continue; // Skip diagonal moves
                Point neighborPos = { currentNode->position.x + dx, currentNode->position.y + dy };

                if (neighborPos.x < 0 || neighborPos.x >= WIDTH || neighborPos.y < 0 || neighborPos.y >= HEIGHT) {
                    continue; // Out of bounds
                }

                if (isInList(closedList, closedListSize, neighborPos)) {
                    continue; // Already evaluated
                }

                Node* neighborNode = (Node*)malloc(sizeof(Node));
                neighborNode->position = neighborPos;
                neighborNode->g = currentNode->g + 1;
                neighborNode->h = calculateHeuristic(neighborPos, goal);
                neighborNode->f = neighborNode->g + neighborNode->h;
                neighborNode->parent = currentNode;

                if (isInList(openList, openListSize, neighborPos) && neighborNode->g >= currentNode->g) {
                    free(neighborNode); // Discard this node
                    continue;
                }

                addToOpenList(neighborNode);
            }
        }
    }
    printf("No path found.\n");
}

int main() {
    Point start = {0, 0}; // Start point
    Point goal = {7, 6};  // Goal point

    printf("A* Pathfinding from (%d, %d) to (%d, %d)\n", start.x, start.y, goal.x, goal.y);
    aStar(start, goal);
    return 0;
}
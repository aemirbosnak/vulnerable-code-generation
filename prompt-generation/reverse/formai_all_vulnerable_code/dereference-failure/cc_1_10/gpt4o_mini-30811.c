//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES 100

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point position;
    int g; // Cost from start to the current node
    int h; // Heuristic cost to the end node
    int f; // Total cost
    struct Node* parent;
} Node;

Node* openList[MAX_NODES];
Node* closedList[MAX_NODES];
int openCount = 0, closedCount = 0;

int grid[HEIGHT][WIDTH] = {
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int heuristic(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

bool inClosedList(Point point) {
    for (int i = 0; i < closedCount; i++) {
        if (closedList[i]->position.x == point.x && closedList[i]->position.y == point.y) {
            return true;
        }
    }
    return false;
}

bool inOpenList(Point point) {
    for (int i = 0; i < openCount; i++) {
        if (openList[i]->position.x == point.x && openList[i]->position.y == point.y) {
            return true;
        }
    }
    return false;
}

Node* createNode(Point position, Node* parent, int g, Point goal) {
    Node* node = malloc(sizeof(Node));
    node->position = position;
    node->parent = parent;
    node->g = g;
    node->h = heuristic(position, goal);
    node->f = node->g + node->h;
    return node;
}

void addToClosedList(Node* node) {
    closedList[closedCount++] = node;
}

void addToOpenList(Node* node) {
    openList[openCount++] = node;
}

void removeFromOpenList(Node* node) {
    for (int i = 0; i < openCount; i++) {
        if (openList[i] == node) {
            for (int j = i; j < openCount - 1; j++) {
                openList[j] = openList[j + 1];
            }
            openCount--;
            return;
        }
    }
}

void findPath(Point start, Point goal) {
    addToOpenList(createNode(start, NULL, 0, goal));

    while (openCount > 0) {
        Node* current = openList[0];
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < current->f) {
                current = openList[i];
            }
        }

        if (current->position.x == goal.x && current->position.y == goal.y) {
            printf("Path found:\n");
            Node* node = current;
            while (node) {
                printf("(%d, %d) <- ", node->position.x, node->position.y);
                node = node->parent;
            }
            printf("Start\n");
            return;
        }

        removeFromOpenList(current);
        addToClosedList(current);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Skip diagonal moves

                Point neighbor = {current->position.x + dx, current->position.y + dy};
                
                if (neighbor.x < 0 || neighbor.x >= WIDTH || neighbor.y < 0 || neighbor.y >= HEIGHT ||
                    grid[neighbor.y][neighbor.x] == 1 || inClosedList(neighbor)) {
                    continue;
                }

                int gCost = current->g + 1;

                if (!inOpenList(neighbor)) {
                    addToOpenList(createNode(neighbor, current, gCost, goal));
                } else {
                    for (int i = 0; i < openCount; i++) {
                        if (openList[i]->position.x == neighbor.x && openList[i]->position.y == neighbor.y) {
                            if (gCost < openList[i]->g) {
                                openList[i]->g = gCost;
                                openList[i]->parent = current;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    Point start = {0, 0};
    Point goal = {9, 9};
    
    findPath(start, goal);
    
    for (int i = 0; i < openCount; i++) free(openList[i]);
    for (int j = 0; j < closedCount; j++) free(closedList[j]);
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)
#define OBSTACLE '#'
#define FREE '.'

typedef struct Node {
    int x, y;
    int g_cost;  // Cost from start to this node
    int h_cost;  // Heuristic cost to end
    int f_cost;  // Total cost
    struct Node* parent; // Parent node in path
    bool closed;
    bool open;
} Node;

Node* nodes[MAX_NODES];
int obstacle_positions[WIDTH][HEIGHT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void initializeNodes() {
    for (int i = 0; i < MAX_NODES; i++) {
        nodes[i] = (Node*) malloc(sizeof(Node));
        nodes[i]->x = i % WIDTH;
        nodes[i]->y = i / WIDTH;
        nodes[i]->g_cost = 0;
        nodes[i]->h_cost = 0;
        nodes[i]->f_cost = 0;
        nodes[i]->parent = NULL;
        nodes[i]->open = false;
        nodes[i]->closed = false;
    }
}

void cleanUpNodes() {
    for (int i = 0; i < MAX_NODES; i++) {
        free(nodes[i]);
    }
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y); // Manhattan distance
}

Node* getLowestFNode(Node* openSet[], int count) {
    Node* lowest = openSet[0];
    for (int i = 1; i < count; i++) {
        if (openSet[i]->f_cost < lowest->f_cost) {
            lowest = openSet[i];
        }
    }
    return lowest;
}

bool isValidNode(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && obstacle_positions[x][y] == 0);
}

void retracePath(Node* endNode) {
    Node* current = endNode;
    while (current != NULL) {
        printf("(%d, %d) <- ", current->x, current->y);
        current = current->parent;
    }
    printf("Start\n");
}

void aStar(int startX, int startY, int endX, int endY) {
    Node* startNode = nodes[startY * WIDTH + startX];
    Node* endNode = nodes[endY * WIDTH + endX];
    
    Node* openSet[MAX_NODES];
    int openCount = 0;

    startNode->open = true;
    openSet[openCount++] = startNode;

    while (openCount > 0) {
        Node* current = getLowestFNode(openSet, openCount);

        if (current == endNode) {
            retracePath(current);
            return;
        }

        current->closed = true;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (abs(dx) == abs(dy))) {
                    continue; // Skip diagonal and self
                }

                int neighborX = current->x + dx;
                int neighborY = current->y + dy;

                if (!isValidNode(neighborX, neighborY))
                    continue;

                Node* neighbor = nodes[neighborY * WIDTH + neighborX];

                if (neighbor->closed) continue;

                int tentativeGCost = current->g_cost + 1;

                if (!neighbor->open || tentativeGCost < neighbor->g_cost) {
                    neighbor->g_cost = tentativeGCost;
                    neighbor->h_cost = heuristic(neighbor, endNode);
                    neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;
                    neighbor->parent = current;

                    if (!neighbor->open) {
                        neighbor->open = true;
                        openSet[openCount++] = neighbor;
                    }
                }
            }
        }
        
        // Remove current node from openSet
        for (int i = 0; i < openCount; i++) {
            if (openSet[i] == current) {
                openSet[i] = openSet[--openCount]; // Swap with last and reduce count
                break;
            }
        }
    }

    printf("No path found to endpoint\n");
}

int main() {
    initializeNodes();
    aStar(0, 1, 9, 8); // starting point (0,1) to end point (9,8)
    cleanUpNodes();
    return 0;
}
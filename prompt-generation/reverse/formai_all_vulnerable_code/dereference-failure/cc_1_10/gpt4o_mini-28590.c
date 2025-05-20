//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define CELL_SIZE 4

typedef struct {
    int x;
    int y;
} Node;

typedef struct {
    Node node;
    float f, g, h;
    struct NodeList *prev;
} NodeList;

NodeList *openList[WIDTH * HEIGHT];
int openCount = 0;

NodeList *closedList[WIDTH * HEIGHT];
int closedCount = 0;

float heuristic(Node a, Node b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

void addToOpenList(NodeList *newNode) {
    openList[openCount++] = newNode;
}

bool inOpenList(NodeList *node) {
    for (int i = 0; i < openCount; i++) {
        if (openList[i]->node.x == node->node.x && openList[i]->node.y == node->node.y) {
            return true;
        }
    }
    return false;
}

bool inClosedList(NodeList *node) {
    for (int i = 0; i < closedCount; i++) {
        if (closedList[i]->node.x == node->node.x && closedList[i]->node.y == node->node.y) {
            return true;
        }
    }
    return false;
}

NodeList *createNode(int x, int y, NodeList *prev) {
    NodeList *newNode = (NodeList *)malloc(sizeof(NodeList));
    newNode->node.x = x;
    newNode->node.y = y;
    newNode->prev = prev;
    return newNode;
}

void printPath(NodeList *node) {
    if (node != NULL) {
        printPath(node->prev);
        printf("-> (%d, %d) ", node->node.x, node->node.y);
    }
}

void aStarPathfind(Node start, Node goal) {
    NodeList *startNode = createNode(start.x, start.y, NULL);
    startNode->g = 0;
    startNode->h = heuristic(start, goal);
    startNode->f = startNode->g + startNode->h;
    addToOpenList(startNode);

    while (openCount > 0) {
        // Find the node with the lowest f in open list
        int lowestIndex = 0;
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < openList[lowestIndex]->f) {
                lowestIndex = i;
            }
        }

        NodeList *currentNode = openList[lowestIndex];

        // Check if we reached the goal
        if (currentNode->node.x == goal.x && currentNode->node.y == goal.y) {
            printf("Path found: ");
            printPath(currentNode);
            printf("\n");
            return;
        }

        // Move current to closed list
        closedList[closedCount++] = currentNode;
        openCount--;
        for (int i = lowestIndex; i < openCount; i++) {
            openList[i] = openList[i + 1];
        }

        // Explore neighboring nodes
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < 4; i++) {
            Node neighbor = {currentNode->node.x + directions[i][0], currentNode->node.y + directions[i][1]};

            if (neighbor.x < 0 || neighbor.x >= WIDTH || neighbor.y < 0 || neighbor.y >= HEIGHT) {
                continue; // Out of bounds
            }

            NodeList *neighborNode = createNode(neighbor.x, neighbor.y, currentNode);
            if (inClosedList(neighborNode)) {
                free(neighborNode);
                continue; // Already evaluated
            }

            neighborNode->g = currentNode->g + 1;
            neighborNode->h = heuristic(neighbor, goal);
            neighborNode->f = neighborNode->g + neighborNode->h;

            if (!inOpenList(neighborNode)) {
                addToOpenList(neighborNode);
            } else {
                free(neighborNode);
            }
        }
    }

    printf("No path found.\n");
}

int main() {
    Node start = {0, 0};
    Node goal = {7, 6};

    printf("Starting A* Pathfinding...\n");
    aStarPathfind(start, goal);

    return 0;
}
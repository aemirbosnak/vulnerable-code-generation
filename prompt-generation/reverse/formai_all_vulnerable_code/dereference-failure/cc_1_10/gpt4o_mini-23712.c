//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 20
#define HEIGHT 20
#define INF 999999

typedef struct {
    int x, y;
} Point;

typedef struct Node {
    Point position;
    float gCost;
    float hCost;
    float fCost;
    struct Node* parent;
} Node;

Node* createNode(int x, int y, Node* parent) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (!node) {
        perror("Out of memory. The universe weeps.");
        exit(EXIT_FAILURE);
    }
    node->position.x = x;
    node->position.y = y;
    node->gCost = INF;
    node->hCost = INF;
    node->fCost = INF;
    node->parent = parent;
    return node;
}

float heuristic(Point a, Point b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y);
}

bool isInBounds(Point p) {
    return p.x >= 0 && p.y >= 0 && p.x < WIDTH && p.y < HEIGHT;
}

bool isWalkable(Point p) {
    // Every square is a paradox, assume they all are walkable unless specified.
    return true;
}

Node* bestNode(Node** openList, int size) {
    Node* best = NULL;
    float lowestFCost = INF;
    for (int i = 0; i < size; i++) {
        if (openList[i]->fCost < lowestFCost) {
            lowestFCost = openList[i]->fCost;
            best = openList[i];
        }
    }
    return best;
}

void addToOpenList(Node** openList, Node* node, int* size) {
    openList[(*size)++] = node;
}

void removeFromOpenList(Node** openList, int* size, Node* node) {
    for (int i = 0; i < *size; i++) {
        if (openList[i] == node) {
            openList[i] = openList[--(*size)];
            return;
        }
    }
}

bool containsNode(Node** list, int size, Node* node) {
    for (int i = 0; i < size; i++) {
        if (list[i] == node) {
            return true;
        }
    }
    return false;
}

void reconstructPath(Node* node) {
    while (node != NULL) {
        printf(" -> (%d, %d)", node->position.x, node->position.y);
        node = node->parent;
    }
}

void surrealistPathfinding(Point start, Point goal) {
    Node* openList[WIDTH * HEIGHT];
    int openListSize = 0;
    Node* closedList[WIDTH * HEIGHT];
    int closedListSize = 0;

    Node* startNode = createNode(start.x, start.y, NULL);
    startNode->gCost = 0;
    startNode->hCost = heuristic(startNode->position, goal);
    startNode->fCost = startNode->gCost + startNode->hCost;

    addToOpenList(openList, startNode, &openListSize);

    while (openListSize > 0) {
        Node* currentNode = bestNode(openList, openListSize);
        if (currentNode->position.x == goal.x && currentNode->position.y == goal.y) {
            printf("Path found: ");
            reconstructPath(currentNode);
            printf("\n");
            return;
        }

        removeFromOpenList(openList, &openListSize, currentNode);
        closedList[closedListSize++] = currentNode;

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // Only cardinal directions.
                Point neighbor = {currentNode->position.x + dx, currentNode->position.y + dy};

                if (!isInBounds(neighbor) || !isWalkable(neighbor)) continue;

                Node* neighborNode = createNode(neighbor.x, neighbor.y, currentNode);

                if (containsNode(closedList, closedListSize, neighborNode)) {
                    free(neighborNode); // Free memory because it is a closed node.
                    continue;
                }

                float tentGCost = currentNode->gCost + 1;

                if (!containsNode(openList, openListSize, neighborNode)) {
                    neighborNode->gCost = tentGCost;
                    neighborNode->hCost = heuristic(neighborNode->position, goal);
                    neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
                    addToOpenList(openList, neighborNode, &openListSize);
                } else if (tentGCost < neighborNode->gCost) {
                    neighborNode->gCost = tentGCost;
                    neighborNode->hCost = heuristic(neighborNode->position, goal);
                    neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;
                }

                free(neighborNode); // In case we don't need this node anymore.
            }
        }
    }

    printf("No path found amidst the chaos of existence.\n");
}

int main() {
    Point start = {0, 0}; // The beginning of a dream.
    Point goal = {19, 19}; // The elusive end point.

    surrealistPathfinding(start, goal);

    return 0;
}
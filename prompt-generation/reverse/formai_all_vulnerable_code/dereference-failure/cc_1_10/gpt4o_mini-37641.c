//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_PATH 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point point;
    double gCost;
    double hCost;
    double fCost;
    struct Node* parent;
} Node;

typedef struct {
    Node* nodes[MAX_PATH];
    int length;
} NodeList;

void initializeNode(Node* node, int x, int y, Node* parent) {
    node->point.x = x;
    node->point.y = y;
    node->gCost = 0;
    node->hCost = 0;
    node->fCost = 0;
    node->parent = parent;
}

double calculateH(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y); // Manhattan distance
}

NodeList* createNodeList() {
    NodeList* list = (NodeList*)malloc(sizeof(NodeList));
    list->length = 0;
    return list;
}

void addNode(NodeList* list, Node* node) {
    if (list->length < MAX_PATH) {
        list->nodes[list->length++] = node;
    }
}

bool containsNode(NodeList* list, Node* node) {
    for (int i = 0; i < list->length; i++) {
        if (list->nodes[i]->point.x == node->point.x && list->nodes[i]->point.y == node->point.y) {
            return true;
        }
    }
    return false;
}

int compareFN(const void* a, const void* b) {
    Node* nodeA = *(Node**)a;
    Node* nodeB = *(Node**)b;

    if (nodeA->fCost < nodeB->fCost) return -1;
    if (nodeA->fCost > nodeB->fCost) return 1;
    return 0;
}

Node* aStar(Point start, Point end) {
    NodeList* openSet = createNodeList();
    NodeList* closedSet = createNodeList();

    Node* startNode = (Node*)malloc(sizeof(Node));
    initializeNode(startNode, start.x, start.y, NULL);
    startNode->hCost = calculateH(startNode->point, end);
    startNode->fCost = startNode->gCost + startNode->hCost;
    addNode(openSet, startNode);

    while (openSet->length > 0) {
        qsort(openSet->nodes, openSet->length, sizeof(Node*), compareFN);

        Node* currentNode = openSet->nodes[0];

        if (currentNode->point.x == end.x && currentNode->point.y == end.y) {
            free(openSet);
            free(closedSet);
            return currentNode; // Return the path found
        }

        // Transfer currentNode to closedSet
        addNode(closedSet, currentNode);
        memmove(openSet->nodes, openSet->nodes + 1, (openSet->length - 1) * sizeof(Node*));
        openSet->length--;

        // Generate valid neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || (abs(dx) == abs(dy))) continue; // Skip itself and diagonals

                Point neighborPoint = {currentNode->point.x + dx, currentNode->point.y + dy};

                if (neighborPoint.x < 0 || neighborPoint.x >= WIDTH || neighborPoint.y < 0 || neighborPoint.y >= HEIGHT) {
                    continue; // Out of bounds
                }

                Node* neighborNode = (Node*)malloc(sizeof(Node));
                initializeNode(neighborNode, neighborPoint.x, neighborPoint.y, currentNode);
                neighborNode->gCost = currentNode->gCost + 1;
                neighborNode->hCost = calculateH(neighborNode->point, end);
                neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;

                if (containsNode(closedSet, neighborNode)) {
                    free(neighborNode); // Already evaluated
                    continue;
                }
                
                if (!containsNode(openSet, neighborNode)) {
                    addNode(openSet, neighborNode); // Add to open set
                } else {
                    // Compare fCosts to see if we need to update
                    for (int i = 0; i < openSet->length; i++) {
                        if (openSet->nodes[i]->point.x == neighborNode->point.x && openSet->nodes[i]->point.y == neighborNode->point.y) {
                            if (openSet->nodes[i]->gCost > neighborNode->gCost) {
                                openSet->nodes[i]->gCost = neighborNode->gCost;
                                openSet->nodes[i]->fCost = neighborNode->fCost;
                                openSet->nodes[i]->parent = currentNode;
                            }
                            free(neighborNode);
                            break;
                        }
                    }
                }
            }
        }
    }

    free(openSet);
    free(closedSet);
    return NULL; // No path found
}

void printPath(Node* node) {
    if (node == NULL) return;
    printPath(node->parent);
    printf("(%d, %d) -> ", node->point.x, node->point.y);
}

int main() {
    Point start = {0, 0};
    Point end = {7, 4};

    Node* pathNode = aStar(start, end);

    if (pathNode) {
        printf("Path found: \n");
        printPath(pathNode);
        printf("END\n");
        free(pathNode);
    } else {
        printf("Path not found.\n");
    }

    return 0;
}
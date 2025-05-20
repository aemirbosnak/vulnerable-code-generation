//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_NODES (WIDTH * HEIGHT)

typedef struct {
    int x, y;
} Node;

typedef struct {
    Node node;
    float gCost; // Cost from start to current node
    float hCost; // Heuristic cost to target
    float fCost; // Total cost (g + h)
    struct NodeListNode* parent;
} NodeListNode;

typedef struct {
    NodeListNode* nodes[MAX_NODES];
    int count;
} NodeList;

Node start, end;
NodeList openSet, closedSet;

float heuristic(Node a, Node b) {
    return fabs(a.x - b.x) + fabs(a.y - b.y); // Manhattan distance
}

bool contains(NodeList* list, Node node) {
    for (int i = 0; i < list->count; i++) {
        if (list->nodes[i]->node.x == node.x && list->nodes[i]->node.y == node.y) {
            return true;
        }
    }
    return false;
}

void addNode(NodeList* list, NodeListNode* node) {
    list->nodes[list->count++] = node;
}

NodeListNode* removeLowestFCost(NodeList* list) {
    int lowestIndex = 0;
    for (int i = 1; i < list->count; i++) {
        if (list->nodes[i]->fCost < list->nodes[lowestIndex]->fCost) {
            lowestIndex = i;
        }
    }
    NodeListNode* lowestNode = list->nodes[lowestIndex];
    list->nodes[lowestIndex] = list->nodes[--list->count];
    return lowestNode;
}

bool isWalkable(Node node) {
    // Implement your own map here.
    return node.x >= 0 && node.x < WIDTH && node.y >= 0 && node.y < HEIGHT;
}

NodeListNode* createNode(Node node, NodeListNode* parent) {
    NodeListNode* newNode = malloc(sizeof(NodeListNode));
    newNode->node = node;
    newNode->parent = parent;
    newNode->gCost = (parent == NULL) ? 0 : parent->gCost + 1; 
    newNode->hCost = heuristic(node, end);
    newNode->fCost = newNode->gCost + newNode->hCost;
    return newNode;
}

void reconstructPath(NodeListNode* current) {
    NodeListNode* pathNode = current;
    while (pathNode != NULL) {
        printf("(%d, %d) ", pathNode->node.x, pathNode->node.y);
        pathNode = pathNode->parent;
    }
    printf("\n");
}

void aStar() {
    addNode(&openSet, createNode(start, NULL));

    while (openSet.count > 0) {
        NodeListNode* current = removeLowestFCost(&openSet);
        if (current->node.x == end.x && current->node.y == end.y) {
            printf("Path: ");
            reconstructPath(current);
            return;
        }

        addNode(&closedSet, current);

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (fabs(i) == fabs(j)) continue; // Skip diagonals
                Node neighbor = {current->node.x + i, current->node.y + j};

                if (!isWalkable(neighbor) || contains(&closedSet, neighbor)) {
                    continue;
                }

                NodeListNode* neighborNode = createNode(neighbor, current);

                if (contains(&openSet, neighbor)) {
                    for (int k = 0; k < openSet.count; k++) {
                        if (openSet.nodes[k]->node.x == neighborNode->node.x && openSet.nodes[k]->node.y == neighborNode->node.y) {
                            if (openSet.nodes[k]->gCost > neighborNode->gCost) {
                                openSet.nodes[k]->parent = current;
                                openSet.nodes[k]->gCost = neighborNode->gCost;
                                openSet.nodes[k]->fCost = openSet.nodes[k]->gCost + openSet.nodes[k]->hCost;
                            }
                            free(neighborNode);
                            break;
                        }
                    }
                } else {
                    addNode(&openSet, neighborNode);
                }
            }
        }
    }
    printf("No Path Found\n");
}

int main() {
    start.x = 0; start.y = 0;
    end.x = 7; end.y = 8;

    openSet.count = 0;
    closedSet.count = 0;

    aStar();
    return 0;
}
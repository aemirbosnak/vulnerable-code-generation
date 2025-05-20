//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define GRID_SIZE 10
#define INF 999999

typedef struct Node {
    int x, y;
    int gCost;
    int hCost;
    int fCost;
    struct Node* parent;
} Node;

typedef struct {
    Node* nodes[GRID_SIZE][GRID_SIZE];
    int size;
} NodeList;

NodeList* createNodeList() {
    NodeList* list = malloc(sizeof(NodeList));
    list->size = 0;
    return list;
}

void addNode(NodeList* list, Node* node) {
    list->nodes[list->size][0] = node;
    list->size++;
}

bool removeNode(NodeList* list, Node* node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i][0] == node) {
            list->nodes[i][0] = list->nodes[list->size - 1][0];
            list->size--;
            return true;
        }
    }
    return false;
}

Node* findLowestFCostNode(NodeList* list) {
    Node* bestNode = NULL;
    for (int i = 0; i < list->size; i++) {
        Node* currentNode = list->nodes[i][0];
        if (bestNode == NULL || currentNode->fCost < bestNode->fCost) {
            bestNode = currentNode;
        }
    }
    return bestNode;
}

bool isNodeInList(NodeList* list, Node* node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i][0] == node) {
            return true;
        }
    }
    return false;
}

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y); // Manhattan distance
}

Node* createNode(int x, int y, int gCost, int hCost, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->gCost = gCost;
    node->hCost = hCost;
    node->fCost = gCost + hCost;
    node->parent = parent;
    return node;
}

bool isWalkable(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
    return (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE && grid[x][y] == 0);
}

void tracePath(Node* target) {
    Node* current = target;
    while (current != NULL) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->parent;
    }
    printf("\n");
}

void aStar(int grid[GRID_SIZE][GRID_SIZE], Node* start, Node* target) {
    NodeList* openList = createNodeList();
    NodeList* closedList = createNodeList();
    
    addNode(openList, start);
    
    while (openList->size > 0) {
        Node* currentNode = findLowestFCostNode(openList);
        
        if (currentNode->x == target->x && currentNode->y == target->y) {
            printf("Path found: ");
            tracePath(currentNode);
            free(openList);
            free(closedList);
            return;
        }
        
        removeNode(openList, currentNode);
        addNode(closedList, currentNode);
        
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (int i = 0; i < 4; i++) {
            int newX = currentNode->x + directions[i][0];
            int newY = currentNode->y + directions[i][1];
            
            if (isWalkable(grid, newX, newY)) {
                Node* neighbor = createNode(newX, newY, currentNode->gCost + 1, heuristic(target, createNode(newX, newY, 0, 0, NULL)), currentNode);
                
                if (isNodeInList(closedList, neighbor)) {
                    free(neighbor);
                    continue;
                }

                if (!isNodeInList(openList, neighbor) || neighbor->gCost < currentNode->gCost + 1) {
                    if (!isNodeInList(openList, neighbor)) {
                        addNode(openList, neighbor);
                    }
                } else {
                    free(neighbor);
                }
            }
        }
    }
    
    printf("No path found!\n");
    free(openList);
    free(closedList);
}

int main() {
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 0, 0, 0}
    };
    
    Node* start = createNode(0, 0, 0, heuristic(createNode(0, 0, 0, 0, NULL), createNode(9, 9, 0, 0, NULL)), NULL);
    Node* target = createNode(9, 9, 0, 0, NULL);
    
    aStar(grid, start, target);
    
    free(start);
    free(target);
    
    return 0;
}
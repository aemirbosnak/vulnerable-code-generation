//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_LIST_SIZE 100

typedef struct {
    int x, y;
    int gCost, hCost, fCost;
    bool walkable;
    bool closed;
    struct Node* parent;
} Node;

typedef struct {
    Node* nodes[MAX_LIST_SIZE];
    int size;
} NodeList;

Node* grid[WIDTH][HEIGHT];

int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

void initGrid() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[x][y] = (Node*)malloc(sizeof(Node));
            grid[x][y]->x = x;
            grid[x][y]->y = y;
            grid[x][y]->gCost = 0;
            grid[x][y]->hCost = 0;
            grid[x][y]->fCost = 0;
            grid[x][y]->walkable = true; // all nodes walkable initially
            grid[x][y]->closed = false;
            grid[x][y]->parent = NULL;
        }
    }
}

void setObstacles() {
    grid[2][3]->walkable = false;
    grid[2][4]->walkable = false;
    grid[2][5]->walkable = false;
}

void addNode(NodeList* list, Node* node) {
    if (list->size < MAX_LIST_SIZE) {
        list->nodes[list->size++] = node;
    }
}

Node* popLowestFCostNode(NodeList* list) {
    int lowestIndex = -1;
    for (int i = 0; i < list->size; i++) {
        if (!list->nodes[i]->closed && (lowestIndex == -1 || list->nodes[i]->fCost < list->nodes[lowestIndex]->fCost)) {
            lowestIndex = i;
        }
    }
    if (lowestIndex != -1) {
        Node* lowestNode = list->nodes[lowestIndex];
        lowestNode->closed = true; // Mark as closed
        return lowestNode;
    }
    return NULL; // No node found, something must be wrong!
}

bool isNodeInList(NodeList* list, Node* node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i] == node) {
            return true;
        }
    }
    return false;
}

void findPath(Node* startNode, Node* endNode) {
    NodeList openList = { .size = 0 };
    addNode(&openList, startNode);

    while (openList.size > 0) {
        Node* currentNode = popLowestFCostNode(&openList);
        if (currentNode == NULL) {
            printf("No path found. Are you sure the start and end nodes are valid?");
            return;
        }

        // If reached end node, build path
        if (currentNode == endNode) {
            printf("Path found:\n");
            Node* pathNode = currentNode;
            while (pathNode != NULL) {
                printf("(%d, %d) -> ", pathNode->x, pathNode->y);
                pathNode = pathNode->parent;
            }
            printf("NULL\n");
            return;
        }

        // Check neighbors
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) + abs(dy) != 1) continue; // Only orthogonal movement
                int newX = currentNode->x + dx;
                int newY = currentNode->y + dy;
                if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT) {
                    Node* neighbor = grid[newX][newY];
                    if (neighbor->walkable && !neighbor->closed) {
                        int tentativeGCost = currentNode->gCost + 1; // Assume cost between nodes is 1
                        if (!isNodeInList(&openList, neighbor) || tentativeGCost < neighbor->gCost) {
                            neighbor->gCost = tentativeGCost;
                            neighbor->hCost = heuristic(neighbor, endNode);
                            neighbor->fCost = neighbor->gCost + neighbor->hCost;
                            neighbor->parent = currentNode;

                            if (!isNodeInList(&openList, neighbor)) {
                                addNode(&openList, neighbor);
                            }
                        }
                    }
                }
            }
        }
    }
    printf("Path not found. Ensure all nodes are walkable and try again!\n");
}

void cleanUp() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            free(grid[x][y]);
        }
    }
}

int main() {
    initGrid();
    setObstacles();

    Node* startNode = grid[0][0];
    Node* endNode = grid[5][5];

    findPath(startNode, endNode);
    cleanUp();

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX 100

typedef struct Node {
    int x, y;
    int g_cost; // cost from start to current node
    int h_cost; // heuristic cost to end node
    int f_cost; // total cost (g + h)
    struct Node* parent;
} Node;

typedef struct NodeList {
    Node* nodes[MAX];
    int size;
} NodeList;

Node* createNode(int x, int y, int g_cost, int h_cost, Node* parent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->g_cost = g_cost;
    newNode->h_cost = h_cost;
    newNode->f_cost = g_cost + h_cost;
    newNode->parent = parent;
    return newNode;
}

void addNode(NodeList* list, Node* node) {
    list->nodes[list->size++] = node;
}

bool isInList(NodeList* list, Node* node) {
    for (int i = 0; i < list->size; i++) {
        if (list->nodes[i]->x == node->x && list->nodes[i]->y == node->y) {
            return true;
        }
    }
    return false;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

void freeNodeList(NodeList* list) {
    for (int i = 0; i < list->size; i++) {
        free(list->nodes[i]);
    }
}

void printPath(Node* node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("-> (%d, %d) ", node->x, node->y);
}

void aStar(int grid[MAX][MAX], int startX, int startY, int goalX, int goalY, int rows, int cols) {
    NodeList openList = { .size = 0 };
    NodeList closedList = { .size = 0 };

    Node* startNode = createNode(startX, startY, 0, heuristic(startX, startY, goalX, goalY), NULL);
    addNode(&openList, startNode);

    while (openList.size > 0) {
        Node* currentNode = openList.nodes[0];

        for (int i = 1; i < openList.size; i++) {
            if (openList.nodes[i]->f_cost < currentNode->f_cost ||
                (openList.nodes[i]->f_cost == currentNode->f_cost &&
                 openList.nodes[i]->h_cost < currentNode->h_cost)) {
                currentNode = openList.nodes[i];
            }
        }

        if (currentNode->x == goalX && currentNode->y == goalY) {
            printf("Path found: ");
            printPath(currentNode);
            printf("-> (%d, %d)\n", goalX, goalY);
            freeNodeList(&openList);
            freeNodeList(&closedList);
            return;
        }

        for (int i = 0; i < openList.size; i++) {
            if (openList.nodes[i] == currentNode) {
                openList.nodes[i] = openList.nodes[openList.size - 1];
                openList.size--;
                break;
            }
        }

        addNode(&closedList, currentNode);

        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (abs(dx) == abs(dy)) continue; // skip diagonals

                int newX = currentNode->x + dx;
                int newY = currentNode->y + dy;

                if (newX < 0 || newY < 0 || newX >= rows || newY >= cols || grid[newX][newY] != 0) {
                    continue; // out of bounds or blocked
                }

                Node* neighbor = createNode(newX, newY, currentNode->g_cost + 1,
                                             heuristic(newX, newY, goalX, goalY),
                                             currentNode);

                if (isInList(&closedList, neighbor)) {
                    free(neighbor);
                    continue; // already evaluated
                }

                if (!isInList(&openList, neighbor)) {
                    addNode(&openList, neighbor);
                } else {
                    free(neighbor);
                }
            }
        }
    }

    printf("No path found!\n");
    freeNodeList(&openList);
    freeNodeList(&closedList);
}

int main() {
    int grid[MAX][MAX] = {0}; // 0 = walkable, 1 = obstacle
    int rows = 5, cols = 5;
    // Adding obstacles
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[1][3] = 1;  

    int startX = 0, startY = 0;
    int goalX = 4, goalY = 4;

    aStar(grid, startX, startY, goalX, goalY, rows, cols);
    return 0;
}
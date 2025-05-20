//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 5

typedef struct Node {
    int row, col;
    int fCost, gCost, hCost;
    struct Node *parent;
} Node;

typedef struct List {
    Node *data[SIZE];
    int size;
} List;

Node *startNode = NULL;
Node *endNode = NULL;
List *openSet = NULL;

int heuristicDistance(Node *node) {
    int rowDistance = abs(node->row - endNode->row);
    int colDistance = abs(node->col - endNode->col);
    return rowDistance + colDistance;
}

Node *createNode(int row, int col) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->fCost = node->gCost = node->hCost = 0;
    node->parent = NULL;
    return node;
}

List *listCreate() {
    List *list = (List*) malloc(sizeof(List));
    list->size = 0;
    return list;
}

void listAdd(List *list, Node *node) {
    list->data[list->size++] = node;
}

void listRemove(List *list, Node *node) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == node) {
            for (int j = i; j < list->size - 1; j++) {
                list->data[j] = list->data[j+1];
            }
            list->size--;
            break;
        }
    }
}

bool listContains(List *list, Node *node) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == node) {
            return true;
        }
    }
    return false;
}

bool isValid(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

bool isObstacle(int map[SIZE][SIZE], int row, int col) {
    return map[row][col] == 1;
}

void getNeighbours(int neighbours[8][2], int row, int col) {
    neighbours[0][0] = row - 1;
    neighbours[0][1] = col - 1;
    neighbours[1][0] = row - 1;
    neighbours[1][1] = col;
    neighbours[2][0] = row - 1;
    neighbours[2][1] = col + 1;
    neighbours[3][0] = row;
    neighbours[3][1] = col + 1;
    neighbours[4][0] = row + 1;
    neighbours[4][1] = col + 1;
    neighbours[5][0] = row + 1;
    neighbours[5][1] = col;
    neighbours[6][0] = row + 1;
    neighbours[6][1] = col - 1;
    neighbours[7][0] = row;
    neighbours[7][1] = col - 1;
}

void printPath(Node *node) {
    if (node->parent != NULL) {
        printPath(node->parent);
    }
    printf("(%d,%d) ", node->row, node->col);
}

void aStar(int map[SIZE][SIZE]) {
    startNode->gCost = 0;
    startNode->hCost = heuristicDistance(startNode);
    startNode->fCost = startNode->gCost + startNode->hCost;
    openSet = listCreate();
    listAdd(openSet, startNode);
    while (openSet->size > 0) {
        Node *current = openSet->data[0];
        for (int i = 0; i < openSet->size; i++) {
            if (openSet->data[i]->fCost < current->fCost ||
                    (openSet->data[i]->fCost == current->fCost &&
                     openSet->data[i]->hCost < current->hCost)) {
                current = openSet->data[i];
            }
        }
        if (current == endNode) {
            printPath(current);
            return;
        }
        listRemove(openSet, current);
        int neighbours[8][2];
        getNeighbours(neighbours, current->row, current->col);
        for (int i = 0; i < 8; i++) {
            int row = neighbours[i][0];
            int col = neighbours[i][1];
            if (isValid(row, col) && !isObstacle(map, row, col)) {
                Node *neighbour = createNode(row, col);
                int gCost = current->gCost + 1;
                if (listContains(openSet, neighbour) && gCost >= neighbour->gCost) {
                    continue;
                }
                neighbour->parent = current;
                neighbour->gCost = gCost;
                neighbour->hCost = heuristicDistance(neighbour);
                neighbour->fCost = neighbour->gCost + neighbour->hCost;
                if (!listContains(openSet, neighbour)) {
                    listAdd(openSet, neighbour);
                }
            }
        }
    }
}

int main() {
    int map[SIZE][SIZE] = {
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 0, 0}
    };
    startNode = createNode(0, 0);
    endNode = createNode(4, 4);
    aStar(map);
    return 0;
}
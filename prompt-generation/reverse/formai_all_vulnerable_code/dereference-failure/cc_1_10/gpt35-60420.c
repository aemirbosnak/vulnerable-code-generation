//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#define ROW 5
#define COL 5
#define MAX_NODES ROW * COL

typedef struct Node {
    int x, y, f, g, h;
    struct Node *parent;
} Node;

int map[ROW][COL] = {{0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 1},
                     {0, 0, 0, 0, 0}};

Node *openList[MAX_NODES];
Node *closedList[MAX_NODES];
int openCount = 0, closedCount = 0;
Node *startNode, *endNode;

int isValid(int x, int y) {
    return (x >= 0 && x < ROW && y >= 0 && y < COL);
}

int isUnblocked(int x, int y) {
    return map[x][y] == 0;
}

int isEndNode(int x, int y) {
    return (x == endNode->x && y == endNode->y);
}

int calculateH(int x, int y) {
    return abs(endNode->x - x) + abs(endNode->y - y);
}

int calculateG(Node *parent, int x, int y) {
    if (parent)
        return parent->g + 1 + calculateH(x, y);
    else
        return 0;
}

Node* createNode(int x, int y, Node *parent) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->f = node->g = node->h = 0;
    node->parent = parent;
    return node;
}

int findNode(Node **list, int count, Node *node) {
    int i;
    for (i = 0; i < count; i++)
        if (list[i]->x == node->x && list[i]->y == node->y)
            return i;
    return -1;
}

void removeNode(Node **list, int *count, int pos) {
    int i;
    for (i = pos; i < *count - 1; i++)
        list[i] = list[i + 1];
    (*count)--;
}

void addNode(Node **list, int *count, Node *node) {
    list[*count] = node;
    (*count)++;
}

void printPath(Node *end) {
    if (end->parent)
        printPath(end->parent);
    printf("(%d, %d) ", end->x, end->y);
}

void aStarSearch() {
    startNode->g = calculateG(NULL, startNode->x, startNode->y);
    startNode->h = calculateH(startNode->x, startNode->y);
    startNode->f = startNode->g + startNode->h;

    addNode(openList, &openCount, startNode);

    while (openCount) {
        Node *currentNode = openList[0];
        int currentIndex = 0;
        int i;

        for (i = 1; i < openCount; i++)
            if (openList[i]->f < currentNode->f ||
                    (openList[i]->f == currentNode->f && openList[i]->h < currentNode->h)) {
                currentNode = openList[i];
                currentIndex = i;
            }

        removeNode(openList, &openCount, currentIndex);
        addNode(closedList, &closedCount, currentNode);

        if (isEndNode(currentNode->x, currentNode->y)) {
            printPath(currentNode);
            return;
        }

        int mt[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        for (i = 0; i < 8; i++) {
            int x = currentNode->x + mt[i][0];
            int y = currentNode->y + mt[i][1];
            if (isValid(x, y) && isUnblocked(x, y)) {
                Node *childNode = createNode(x, y, currentNode);
                childNode->g = calculateG(currentNode, x, y);
                childNode->h = calculateH(x, y);
                childNode->f = childNode->g + childNode->h;
                int openIndex = findNode(openList, openCount, childNode);
                int closedIndex = findNode(closedList, closedCount, childNode);
                if (closedIndex > -1 && closedList[closedIndex]->f <= childNode->f) {
                    free(childNode);
                    continue;
                }
                if (openIndex > -1 && openList[openIndex]->f <= childNode->f) {
                    free(childNode);
                    continue;
                }
                if (openIndex > -1)
                    removeNode(openList, &openCount, openIndex);
                if (closedIndex > -1)
                    removeNode(closedList, &closedCount, closedIndex);
                addNode(openList, &openCount, childNode);
            }
        }
    }
}

int main() {
    startNode = createNode(0, 0, NULL);
    endNode = createNode(4, 4, NULL);
    printf("Path: ");
    aStarSearch();
    printf("\n");
    return 0;
}
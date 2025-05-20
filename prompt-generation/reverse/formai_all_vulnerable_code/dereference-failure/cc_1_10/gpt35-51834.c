//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct Node {
    int x;
    int y;
    int f, g, h;
    struct Node* parent;
} Node;

Node* openList[WIDTH*HEIGHT];
int openListIndex = 0;
int closedList[WIDTH][HEIGHT];
int startNode[2] = {0, 0};
int endNode[2] = {9, 9};

int heuristic(int x, int y) {
    return abs(x - endNode[0]) + abs(y - endNode[1]);
}

void addOpenNode(int x, int y, int f, int g, int h, Node* parent) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->f = f;
    newNode->g = g;
    newNode->h = h;
    newNode->parent = parent;
    openList[openListIndex++] = newNode;
}

Node* getLowestCostNode() {
    int lowestCost = openList[0]->f;
    Node* lowestNode = openList[0];
    int i;
    for(i = 1; i < openListIndex; i++) {
        if(openList[i]->f < lowestCost) {
            lowestCost = openList[i]->f;
            lowestNode = openList[i];
        }
    }
    return lowestNode;
}

void removeFromOpenList(Node* node) {
    int i;
    for(i = 0; i < openListIndex; i++) {
        if(openList[i] == node) {
            int j;
            for(j = i; j < openListIndex - 1; j++) {
                openList[j] = openList[j+1];
            }
            openListIndex--;
            break;
        }
    }
}

int nodeInOpenList(int x, int y) {
    int i;
    for(i = 0; i < openListIndex; i++) {
        if(openList[i]->x == x && openList[i]->y == y) {
            return 1;
        }
    }
    return 0;
}

int nodeInClosedList(int x, int y) {
    return closedList[x][y];
}

void addNodeToClosedList(int x, int y) {
    closedList[x][y] = 1;
}

void printPath(Node* node) {
    if(node->parent != NULL) {
        printPath(node->parent);
    }
    printf("(%d,%d) -> ", node->x, node->y);
}

void findPath() {
    addOpenNode(startNode[0], startNode[1], 0, 0, heuristic(startNode[0], startNode[1]), NULL);
    while(openListIndex > 0) {
        Node* currentNode = getLowestCostNode();
        if(currentNode->x == endNode[0] && currentNode->y == endNode[1]) {
            printf("Path found: ");
            printPath(currentNode);
            printf("End\n");
            return;
        }
        removeFromOpenList(currentNode);
        addNodeToClosedList(currentNode->x, currentNode->y);
        int i, j;
        for(i = -1; i <= 1; i++) {
            for(j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(currentNode->x+i < 0 || currentNode->x+i >= WIDTH || currentNode->y+j < 0 || currentNode->y+j >= HEIGHT) {
                    continue;
                }
                if(nodeInClosedList(currentNode->x+i, currentNode->y+j)) {
                    continue;
                }
                int newG = currentNode->g + abs(i) + abs(j);
                int newH = heuristic(currentNode->x+i, currentNode->y+j);
                int newF = newG + newH;
                if(!nodeInOpenList(currentNode->x+i, currentNode->y+j)) {
                    addOpenNode(currentNode->x+i, currentNode->y+j, newF, newG, newH, currentNode);
                } else {
                    int k;
                    for(k = 0; k < openListIndex; k++) {
                        if(openList[k]->x == currentNode->x+i && openList[k]->y == currentNode->y+j) {
                            if(newF < openList[k]->f) {
                                openList[k]->f = newF;
                                openList[k]->g = newG;
                                openList[k]->h = newH;
                                openList[k]->parent = currentNode;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("No path found.\n");
}

int main() {
    findPath();
    return 0;
}
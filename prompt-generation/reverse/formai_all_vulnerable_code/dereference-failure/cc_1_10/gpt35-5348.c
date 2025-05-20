//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

typedef struct node {
    int x, y;
    int f, g, h;
    struct node *parent;
} Node;

int map[ROW][COL] = { // Example map, 1 means wall, 0 means free
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

Node *openList[ROW*COL];
Node *closedList[ROW*COL];
int openCount = 0, closedCount = 0;
int startX = 2, startY = 2;
int endX = 8, endY = 8;

void printPath(Node *current) {
    if(current->parent != NULL) {
        printPath(current->parent);
    }
    printf("(%d, %d) ", current->x, current->y);
}

int calculateH(Node *node) {
    return abs(node->x - endX) + abs(node->y - endY);
}

void insertToOpenList(Node *node) {
    int i;
    for(i = 0; i < openCount; i++) {
        if(node->f < openList[i]->f) {
            break;
        }
    }

    for(int j = openCount; j > i; j--) {
        openList[j] = openList[j-1];
    }

    openList[i] = node;
    openCount++;
}

Node* findInOpenList(int x, int y) {
    for(int i = 0; i < openCount; i++) {
        if(openList[i]->x == x && openList[i]->y == y) {
            return openList[i];
        }
    }
    return NULL;
}

Node* findInClosedList(int x, int y) {
    for(int i = 0; i < closedCount; i++) {
        if(closedList[i]->x == x && closedList[i]->y == y) {
            return closedList[i];
        }
    }
    return NULL;
}

void removeFromOpenList(Node *node) {
    for(int i = 0; i < openCount; i++) {
        if(openList[i] == node) {
            for(int j = i; j < openCount-1; j++) {
                openList[j] = openList[j+1];
            }
            openCount--;
            break;
        }
    }
}

void addToClosedList(Node *node) {
    closedList[closedCount] = node;
    closedCount++;
}

void Astar() {
    Node *startNode = (Node*) calloc(1, sizeof(Node));
    startNode->x = startX;
    startNode->y = startY;
    startNode->f = startNode->g = startNode->h = 0;
    startNode->parent = NULL;

    insertToOpenList(startNode);

    while(openCount > 0) {
        Node *current = openList[0];
        removeFromOpenList(current);
        addToClosedList(current);
        if(current->x == endX && current->y == endY) {
            printPath(current);
            return;
        }

        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                if(i == 0 && j == 0) continue;
                int x = current->x + i;
                int y = current->y + j;

                if(x < 0 || x >= ROW || y < 0 || y >= COL) continue;
                if(map[x][y] == 1) continue;
                if(findInClosedList(x, y) != NULL) continue;

                Node *successor = findInOpenList(x, y);
                if(successor == NULL) {
                    successor = (Node*) calloc(1, sizeof(Node));
                    successor->x = x;
                    successor->y = y;
                    successor->parent = current;
                    successor->g = current->g + 1;
                    successor->h = calculateH(successor);
                    successor->f = successor->g + successor->h;
                    insertToOpenList(successor);
                }
                else {
                    if(current->g + 1 < successor->g) {
                        successor->g = current->g + 1;
                        successor->parent = current;
                        removeFromOpenList(successor);
                        insertToOpenList(successor);
                    }
                }

            }
        }

    }
}

int main() {
    Astar();
    return 0;
}
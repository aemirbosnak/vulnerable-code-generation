//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 5
#define COL 5

int grid[ROW][COL] = {
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}
};

int hScores[ROW][COL] = {
    {9, 8, 7, 6, 5},
    {8, 7, 6, 5, 4},
    {7, 6, 5, 4, 3},
    {6, 5, 4, 3, 2},
    {5, 4, 3, 2, 1}
};

typedef struct node {
    int row;
    int col;
    struct node *parent;
    int f;
    int g;
    int h;
} Node;

Node *initNode(int row, int col, Node *parent, int g, int h) {
    Node *node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->parent = parent;
    node->g = g;
    node->h = h;
    node->f = g + h;
    return node;
}

bool isDestination(Node *n, int row, int col) {
    return n->row == row && n->col == col;
}

bool isValid(int row, int col) {
    return row >=0 && row < ROW && col >= 0 && col < COL && grid[row][col] == 0;
}

bool isUnExplored(int row, int col, Node **closedList, int len) {
    for(int i=0; i<len; i++) {
        Node *n = closedList[i];
        if(n->row == row && n->col == col) {
            return false;
        }
    }
    return true;
}

void printPath(Node *node) {
    while(node) {
        printf("(%d,%d)\n", node->row, node->col);
        node = node->parent;
    }
}

Node *findMinFNode(Node **openList, int len) {
    Node *minNode = openList[0];
    int minF = minNode->f;
    for(int i=1; i<len; i++) {
        Node *node = openList[i];
        if(node->f < minF) {
            minF = node->f;
            minNode = node;
        }
    }
    return minNode;
}

Node *aStarPathFinding(int startRow, int startCol, int endRow, int endCol) {
    Node *start = initNode(startRow, startCol, NULL, 0, 0);
    start->h = hScores[startRow][startCol];
    start->f = start->g + start->h;
    
    Node *closedList[ROW * COL] = {NULL};
    int closedListLen = 0;
    Node *openList[ROW * COL] = {NULL};
    int openListLen = 0;
    openList[0] = start;
    openListLen++;
    
    while(openListLen > 0) {
        Node *current = findMinFNode(openList, openListLen);
        if(isDestination(current, endRow, endCol)) {
            return current;
        }
        
        for(int row = current->row-1; row <= current->row+1; row++) {
            for(int col = current->col-1; col <= current->col+1; col++) {
                if(isValid(row, col) && !(row==current->row && col==current->col)) {
                    int g = current->g + 1;
                    int h = hScores[row][col];
                    Node *child = initNode(row, col, current, g, h);
                    if(isUnExplored(row, col, closedList, closedListLen)) {
                        Node *openListChild = NULL;
                        for(int i=0; i<openListLen; i++) {
                            Node *n = openList[i];
                            if(n->row==row && n->col==col) {
                                openListChild = n;
                                break;
                            }
                        }
                        if(!openListChild) {
                            openList[openListLen] = child;
                            openListLen++;
                        } else if(child->f < openListChild->f) {
                            openListChild->f = child->f;
                            openListChild->g = child->g;
                            openListChild->h = child->h;
                            openListChild->parent = current;
                        }
                    }
                }
            }
        }
        closedList[closedListLen] = current;
        closedListLen++;
        
        int currentIdx = -1;
        for(int i=0; i<openListLen; i++) {
            Node *n = openList[i];
            if(n == current) {
                currentIdx = i;
                break;
            }
        }
        if(currentIdx == -1) {
            printf("Error: couldn't find current in open list!\n");
            exit(1);
        }
        openListLen--;
        for(int i=currentIdx; i<openListLen; i++) {
            openList[i] = openList[i+1];
        }
    }
    printf("Error: Couldn't find a path!\n");
    exit(1);
}

int main() {
    Node *endNode = aStarPathFinding(2, 0, 2, 4);
    printPath(endNode);
    return 0;
}
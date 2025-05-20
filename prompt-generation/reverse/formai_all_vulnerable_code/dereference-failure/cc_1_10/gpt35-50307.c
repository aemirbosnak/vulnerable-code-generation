//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// define the map size
#define ROW_COUNT 10
#define COLUMN_COUNT 10

// define node for A* algorithm
typedef struct node {
    int row;
    int column;
    int gVal; // cost from the starting point to the current point
    int hVal; // heuristic value (estimated cost) from the current point to the destination
    struct node* parent;
} Node;

// define the destination point
int destinationRow = 9;
int destinationColumn = 9;

// define the map
int map[ROW_COUNT][COLUMN_COUNT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
};

// define the open and close lists
Node* openList[ROW_COUNT*COLUMN_COUNT];
Node* closeList[ROW_COUNT*COLUMN_COUNT];

// define the heuristic function
int heuristic(int row, int column) {
    int dx = abs(column - destinationColumn);
    int dy = abs(row - destinationRow);
    int min = dx < dy ? dx : dy;
    int max = dx > dy ? dx : dy;
    return (max * 14 - min * 10);
}

// check if the node is in the close list
int isInCloseList(int row, int column) {
    for (int i = 0; i < ROW_COUNT*COLUMN_COUNT; i++) {
        if (closeList[i] != NULL && closeList[i]->row == row && closeList[i]->column == column) {
            return 1;
        }
    }
    return 0;
}

// check if the node is in the open list and return the index in the list
int isInOpenList(int row, int column) {
    for (int i = 0; i < ROW_COUNT*COLUMN_COUNT; i++) {
        if (openList[i] != NULL && openList[i]->row == row && openList[i]->column == column) {
            return i;
        }
    }
    return -1;
}

// add a node to the open list
void addToOpenList(Node* node) {
    for (int i = 0; i < ROW_COUNT*COLUMN_COUNT; i++) {
        if (openList[i] == NULL) {
            openList[i] = node;
            return;
        }
    }
}

// remove a node from the open list
void removeFromOpenList(int index) {
    openList[index] = NULL;
}

// find the node with the lowest fVal in the open list and return the index in the list
int findLowestFValNodeInOpenList() {
    int lowestIndex = -1;
    int lowestFVal = 1000000;
    for (int i = 0; i < ROW_COUNT*COLUMN_COUNT; i++) {
        if (openList[i] != NULL && openList[i]->gVal + openList[i]->hVal < lowestFVal) {
            lowestIndex = i;
            lowestFVal = openList[i]->gVal + openList[i]->hVal;
        }
    }
    return lowestIndex;
}

// find the path using the A* algorithm
void findPath(int startRow, int startColumn) {
    // create the starting node
    Node* startNode = (Node*)malloc(sizeof(Node));
    startNode->row = startRow;
    startNode->column = startColumn;
    startNode->gVal = 0;
    startNode->hVal = heuristic(startRow, startColumn);
    startNode->parent = NULL;
    
    // add the starting node to the open list
    addToOpenList(startNode);
    
    // while the open list is not empty
    while (openList[0] != NULL) {
        // find the node with the lowest fVal in the open list
        int currentIndex = findLowestFValNodeInOpenList();
        
        // if the current node is the destination, we have found the path
        if (openList[currentIndex]->row == destinationRow && openList[currentIndex]->column == destinationColumn) {
            return;
        }
        
        // remove the current node from the open list and add it to the close list
        Node* currentNode = openList[currentIndex];
        removeFromOpenList(currentIndex);
        for (int i = 0; i < ROW_COUNT*COLUMN_COUNT; i++) {
            if (closeList[i] == NULL) {
                closeList[i] = currentNode;
                break;
            }
        }
        
        // explore the neighbors of the current node
        int row = currentNode->row;
        int column = currentNode->column;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if ((dx == 0 && dy == 0) || row+dx < 0 || row+dx >= ROW_COUNT || column+dy < 0 || column+dy >= COLUMN_COUNT || map[row+dx][column+dy] == 0 || isInCloseList(row+dx, column+dy)) {
                    continue;
                }
                
                // calculate the gVal and hVal of the neighbor
                int neighborGVal = currentNode->gVal + (dx == 0 || dy == 0 ? 10 : 14);
                int neighborHVal = heuristic(row+dx, column+dy);
                
                // check if the neighbor is already in the open list
                int neighborIndex = isInOpenList(row+dx, column+dy);
                if (neighborIndex >= 0) {
                    // if the neighbor is already in the open list and the new gVal is smaller, update the gVal and the parent of the neighbor
                    if (neighborGVal < openList[neighborIndex]->gVal) {
                        openList[neighborIndex]->gVal = neighborGVal;
                        openList[neighborIndex]->parent = currentNode;
                    }
                } else {
                    // if the neighbor is not in the open list, create a new node for it and add it to the open list
                    Node* neighborNode = (Node*)malloc(sizeof(Node));
                    neighborNode->row = row+dx;
                    neighborNode->column = column+dy;
                    neighborNode->gVal = neighborGVal;
                    neighborNode->hVal = neighborHVal;
                    neighborNode->parent = currentNode;
                    addToOpenList(neighborNode);
                }
            }
        }
    }
}

// print the map with the path
void printMapWithPath() {
    for (int i = 0; i < ROW_COUNT; i++) {
        for (int j = 0; j < COLUMN_COUNT; j++) {
            if (map[i][j] == 0) {
                printf("X ");
            } else {
                int found = 0;
                for (int k = 0; k < ROW_COUNT*COLUMN_COUNT; k++) {
                    if (closeList[k] != NULL && closeList[k]->row == i && closeList[k]->column == j) {
                        printf("* ");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("  ");
                }
            }
        }
        printf("\n");
    }
}

int main() {
    // find the path
    findPath(0, 0);
    
    // print the map with the path
    printMapWithPath();
    
    return 0;
}
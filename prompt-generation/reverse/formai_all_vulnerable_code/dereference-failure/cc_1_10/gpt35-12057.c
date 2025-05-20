//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = { // sample maze
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 0, 1, 0, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

typedef struct Node {
    int row;
    int col;
    struct Node* parent;
} Node;

Node* createNode(int row, int col, Node* parent) {
    Node* newNode = malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->parent = parent;
    return newNode;
}

Node* getNextMove(int row, int col, Node* currNode) {
    if (maze[row][col] == 0) {
        return NULL; // wall, cannot move here
    }
    Node* nextNode = createNode(row, col, currNode);
    return nextNode;
}

void printPath(Node* node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d,%d) ", node->row, node->col);
}

void findPath(int startRow, int startCol, int goalRow, int goalCol) {
    Node* startPos = createNode(startRow, startCol, NULL);
    Node* goalPos = createNode(goalRow, goalCol, NULL);
    
    Node* openList[ROWS*COLS];
    int numOpen = 1;
    openList[0] = startPos;
    
    Node* closedList[ROWS*COLS];
    int numClosed = 0;
    
    while (numOpen > 0) {
        Node* currNode = openList[0];
        int currIndex = 0;
        
        for (int i = 0; i < numOpen; i++) {
            Node* openNode = openList[i];
            int manDist = abs(openNode->row - goalRow) + abs(openNode->col - goalCol);
            if (manDist < abs(currNode->row - goalRow) + abs(currNode->col - goalCol)) {
                currNode = openNode;
                currIndex = i;
            }
        }
        
        if (currNode->row == goalRow && currNode->col == goalCol) {
            printf("Path Found: ");
            printPath(currNode);
            printf("\n");
            return;
        }
        
        openList[currIndex] = openList[numOpen - 1];
        numOpen--;
        closedList[numClosed] = currNode;
        numClosed++;
        
        Node* neighbors[4];
        neighbors[0] = getNextMove(currNode->row-1, currNode->col, currNode); // up
        neighbors[1] = getNextMove(currNode->row, currNode->col+1, currNode); // right
        neighbors[2] = getNextMove(currNode->row+1, currNode->col, currNode); // down
        neighbors[3] = getNextMove(currNode->row, currNode->col-1, currNode); // left
        
        for (int i = 0; i < 4; i++) {
            Node* neighbor = neighbors[i];
            if (neighbor != NULL) {
                // check if it's already been visited
                int visited = 0;
                for (int j = 0; j < numClosed; j++) {
                    if (closedList[j]->row == neighbor->row && closedList[j]->col == neighbor->col) {
                        visited = 1;
                        break;
                    }
                }
                if (visited == 0) {
                    int inOpenList = -1;
                    for (int j = 0; j < numOpen; j++) {
                        if (openList[j]->row == neighbor->row && openList[j]->col == neighbor->col) {
                            inOpenList = j;
                            break;
                        }
                    }
                    if (inOpenList != -1) {
                        // already in open list
                        if (currNode->parent != NULL && 
                            abs(currNode->row - neighbor->row) + abs(currNode->col - neighbor->col) == 2) {
                            // if diagonal, only update distance if it's shorter
                            int newDist = currNode->parent == NULL ? 1 : currNode->parent->row - neighbor->row;
                            if (newDist < currNode->parent->row - currNode->row) {
                                openList[inOpenList]->parent = currNode;
                            }
                        }
                    } else {
                        openList[numOpen] = neighbor;
                        numOpen++;
                    }
                }
            }
        }
    }
    
    printf("Could not find path.\n");
}

int main() {
    findPath(1, 0, 8, 9);
    return 0;
}
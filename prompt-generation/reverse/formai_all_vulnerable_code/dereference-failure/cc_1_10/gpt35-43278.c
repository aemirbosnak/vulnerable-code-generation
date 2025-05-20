//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

typedef struct Node {
    int f, g, h;
    int row, col;
    bool isBlocked;
    struct Node *parent;
} Node;

int heuristicCostEstimate(int startRow, int startCol, int endRow, int endCol) {
    int x = abs(startRow - endRow);
    int y = abs(startCol - endCol);
    int heuristic = x + y;
    return heuristic;
}

bool isNodeValid(int row, int col) {
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        return false;
    }
    return true;
}

Node* getNode(int grid[][COL], int row, int col) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->row = row;
    node->col = col;
    node->isBlocked = (grid[row][col] == 1) ? true : false;
    node->parent = NULL;
    return node;
}

void printPath(Node* node) {
    if (node != NULL) {
        printPath(node->parent);
        printf("[(%d,%d)] -> ", node->row, node->col);
    }
}

void aStar(int grid[][COL], int startRow, int startCol, int endRow, int endCol) {
    Node* startNode = getNode(grid, startRow, startCol);
    Node* endNode = getNode(grid, endRow, endCol);
    
    bool visited[ROW][COL] = {false};
    bool isFound = false;
    
    Node* openList[ROW*COL] = {NULL};
    int openCount = 0;
    
    startNode->f = startNode->g + heuristicCostEstimate(startRow, startCol, endRow, endCol);
    openList[openCount++] = startNode;
    
    while (openCount > 0) {
        Node* currentNode = openList[0];
        int currentIndex = 0;
        
        for (int i = 1; i < openCount; i++) {
            if (openList[i]->f < currentNode->f) {
                currentNode = openList[i];
                currentIndex = i;
            }
        }
        
        openList[currentIndex] = openList[--openCount];
        
        if (currentNode == endNode) {
            isFound = true;
            printf("Path found: ");
            printPath(currentNode);
            break;
        }
        
        int row = currentNode->row;
        int col = currentNode->col;
        
        visited[row][col] = true;
        
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nRow = row + i;
                int nCol = col + j;
                
                if (isNodeValid(nRow, nCol) && !visited[nRow][nCol]) {
                    Node* neighborNode = getNode(grid, nRow, nCol);
                    if (neighborNode->isBlocked) {
                        visited[nRow][nCol] = true;
                        continue;
                    }
                    int newG = currentNode->g + 1;
                    if (newG < neighborNode->g || neighborNode->g == 0) {
                        neighborNode->parent = currentNode;
                        neighborNode->g = newG;
                        neighborNode->h = heuristicCostEstimate(nRow, nCol, endRow, endCol);
                        neighborNode->f = neighborNode->g + neighborNode->h;
                        
                        if (openCount == 0) {
                            openList[openCount++] = neighborNode;
                        } else {
                            int k;
                            for (k = 0; k < openCount; k++) {
                                if (openList[k]->f > neighborNode->f) {
                                    break;
                                }
                            }
                            for (int m = openCount; m > k; m--) {
                                openList[m] = openList[m - 1];
                            }
                            openList[k] = neighborNode;
                            openCount++;
                        }
                    }
                }
            }
        }
    }
    
    if (!isFound) {
        printf("Path not found!\n");
    }
}

int main() {
    int grid[ROW][COL] = {
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 0, 0, 1, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    };
    
    int startRow = 0;
    int startCol = 0;
    int endRow = 0;
    int endCol = 8;
    
    aStar(grid, startRow, startCol, endRow, endCol);
    
    return 0;
}
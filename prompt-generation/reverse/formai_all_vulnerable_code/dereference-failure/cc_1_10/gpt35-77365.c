//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10
#define MAX_COST 999999

typedef struct Node{
    int row;
    int col;
    struct Node* parent;
    int g;
    int h;
}Node;

Node* openSet[ROW * COL]; // The open set
int openSetSize; // The size of the open set
Node* closedSet[ROW * COL]; // The closed set
int closedSetSize; // The size of the closed set
int map[ROW][COL] = {{0,1,0,0,0,0,0,0,0,0},
                     {0,1,0,0,0,0,0,0,0,0},
                     {0,1,0,0,0,0,0,0,0,0},
                     {0,1,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0,0}}; // Map of the area
int startRow = 0; // Start row index
int startCol = 0; // Start column index
int goalRow = 9; // Goal row index
int goalCol = 9; // Goal column index

void addNodeToOpenSet(Node* node);
void removeNodeFromOpenSet(Node* node);
Node* getBestNodeFromOpenSet();
int calculateHeuristicCost(int currentRow, int currentCol);
int calculateMovementCost(int currentRow, int currentCol, int neighborRow, int neighborCol);
Node* createNode(int row, int col, Node* parent, int g);

int main()
{
    openSetSize = 0;
    closedSetSize = 0;
    
    Node* startNode = createNode(startRow, startCol, NULL, 0);
    addNodeToOpenSet(startNode);

    while (openSetSize > 0) {
        Node* currentNode = getBestNodeFromOpenSet();
        if (currentNode->row == goalRow && currentNode->col == goalCol) {
            Node* current = currentNode;
            printf("Path: ");
            while (current != NULL) {
                printf("(%d,%d) ", current->row, current->col);
                current = current->parent;
            }
            printf("\n");
            return 0;
        }

        closedSet[closedSetSize++] = currentNode;

        int x, y;
        for (x = -1; x <= 1; x++) {
            for (y = -1; y <= 1; y++) {
                if (x == 0 && y == 0) continue;
                int neighborRow = currentNode->row + x;
                int neighborCol = currentNode->col + y;
                if (neighborRow < 0 || neighborCol < 0 || neighborRow >= ROW || neighborCol >= COL) {
                    continue;
                }
                if (map[neighborRow][neighborCol] == 1) continue;
                Node* neighborNode = createNode(neighborRow, neighborCol, currentNode, currentNode->g + calculateMovementCost(currentNode->row, currentNode->col, neighborRow, neighborCol));
                int foundInClosed = 0, foundInOpen = 0;
                int i;
                for (i = 0; i < closedSetSize; i++) {
                    if (closedSet[i]->row == neighborNode->row && closedSet[i]->col == neighborNode->col) {
                        foundInClosed = 1;
                        break;
                    }
                }
                if (foundInClosed) continue;
                for (i = 0; i < openSetSize; i++) {
                    if (openSet[i]->row == neighborNode->row && openSet[i]->col == neighborNode->col) {
                        foundInOpen = 1;
                        break;
                    }
                }
                if (!foundInOpen) {
                    addNodeToOpenSet(neighborNode);
                } else {
                    if (neighborNode->g < openSet[i]->g) {
                        openSet[i]->parent = neighborNode->parent;
                        openSet[i]->g = neighborNode->g;
                    }
                }
            }
        }
    }
    printf("Path not found!\n");
    return 0;
}

void addNodeToOpenSet(Node* node) {
    openSet[openSetSize++] = node;
}

void removeNodeFromOpenSet(Node* node) {
    int i;
    for (i = 0; i < openSetSize; i++) {
        if (openSet[i] == node) {
            openSet[i] = NULL;
            int j;
            for (j = i; j < openSetSize - 1; j++) {
                openSet[j] = openSet[j+1];
            }
            openSetSize--;
            break;
        }
    }
}

Node* getBestNodeFromOpenSet() {
    int i, minIndex = 0, minCost = MAX_COST;
    for (i = 0; i < openSetSize; i++) {
        int f = openSet[i]->g + openSet[i]->h;
        if (f < minCost) {
            minCost = f;
            minIndex = i;
        }
    }
    return openSet[minIndex];
}

int calculateHeuristicCost(int currentRow, int currentCol) {
    return abs(currentRow - goalRow) + abs(currentCol - goalCol);
}

int calculateMovementCost(int currentRow, int currentCol, int neighborRow, int neighborCol) {
    if (abs(currentRow - neighborRow) + abs(currentCol - neighborCol) == 2) {
        return 14;
    } else {
        return 10;
    }
}

Node* createNode(int row, int col, Node* parent, int g) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->parent = parent;
    node->g = g;
    node->h = calculateHeuristicCost(row, col);
    return node;
}
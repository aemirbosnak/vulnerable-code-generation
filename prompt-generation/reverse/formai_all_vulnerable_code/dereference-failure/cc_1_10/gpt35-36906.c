//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/* Define Constants */
#define ROWS 5
#define COLS 5
#define HEURISTIC_FACTOR 10
#define DIAGONAL_COST 14
#define HORIZONTAL_VERTICAL_COST 10

/* Define structure for Node */
struct Node {
    int row;
    int col;
    int fCost;
    int gCost;
    int hCost;
    struct Node* parent;
};

/* Define the global variables*/
struct Node* openList[ROWS * COLS] = { NULL }; //Open List
struct Node* closedList[ROWS * COLS] = { NULL }; //Closed List
int openListCount = 0;
int closedListCount = 0;
int grid[ROWS][COLS] = {
    {1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1},
    {1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1}
};

/* Check if a given node is in the closed list */
bool isInClosedList(struct Node* node){
    for (int i = 0; i < closedListCount; i++) {
        if (closedList[i] == node) {
            return true;
        }
    }
    return false;
}

/* Check if a given node is in the open list */
bool isInOpenList(struct Node* node){
    for (int i = 0; i < openListCount; i++) {
        if (openList[i] == node) {
            return true;
        }
    }
    return false;
}

/* Get the node with the lowest fCost in the open list */
struct Node* getLowestFCostNode(struct Node* currentNode) {
    struct Node* lowestFCostNode = openList[0];
    int lowestFCost = currentNode->gCost +
        currentNode->hCost + HORIZONTAL_VERTICAL_COST;
    for (int i = 0; i < openListCount; i++) {
        if (openList[i]->fCost < lowestFCost) {
            lowestFCost = openList[i]->fCost;
            lowestFCostNode = openList[i];
        }
    }
    return lowestFCostNode;
}

/* Generate Child Nodes */
void generateChildNodes(struct Node* currentNode) {
    int row = currentNode->row;
    int col = currentNode->col;

    /* Generate child nodes for all 8 adjacent squares */
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int adjacentRow = row + i;
            int adjacentCol = col + j;

            /* Skip if the adjacent square is out of bounds or the current square */
            if (adjacentRow < 0 || adjacentCol < 0 || adjacentRow >= ROWS || adjacentCol >= COLS
                || (i == 0 && j == 0)) {
                continue;
            }

            /* Skip if the adjacent square is a wall or in the closed list */
            if (grid[adjacentRow][adjacentCol] == 0) {
                continue;
            }

            /* Calculate H cost using Manhattan distance */
            int hCost = HEURISTIC_FACTOR * (abs(adjacentRow - ROWS + 1) + abs(adjacentCol - COLS + 1));

            /* Calculate G cost */
            int gCost = currentNode->gCost + ((i * j == 0) ? HORIZONTAL_VERTICAL_COST : DIAGONAL_COST);

            /* Calculate F cost */
            int fCost = gCost + hCost;

            /* Create child node and assign f, g, and h costs */
            struct Node* childNode = (struct Node*)malloc(sizeof(struct Node));
            childNode->row = adjacentRow;
            childNode->col = adjacentCol;
            childNode->gCost = gCost;
            childNode->hCost = hCost;
            childNode->fCost = fCost;
            childNode->parent = currentNode;

            /* Add child node to open list */
            if (!isInOpenList(childNode)) {
                openList[openListCount++] = childNode;
            }
        }
    }
}

/* Trace the shortest path from the start node to the end node */
void tracePath(struct Node* startNode, struct Node* endNode) {
    struct Node* node = endNode;
    int stepCount = 0;

    /* Trace back through the parent nodes to the start node */
    while (node != startNode) {
        printf("Step %d: (%d,%d)\n", ++stepCount, node->row, node->col);
        node = node->parent;
    }

    printf("Step %d: (%d,%d) [START]", ++stepCount, node->row, node->col);
}

/* A* Algorithm */
void aStarAlgorithm(struct Node* startNode, struct Node* endNode) {
    /* Add the start node to the open list */
    openList[openListCount++] = startNode;

    /* Loop until the end node is found or the open list is empty */
    while (openListCount > 0) {
        /* Get the node with the lowest fCost in the open list */
        struct Node* currentNode = getLowestFCostNode(startNode);

        /* Remove the current node from the open list */
        for (int i = 0; i < openListCount; i++) {
            if (openList[i] == currentNode) {
                openList[i] = openList[--openListCount];
                break;
            }
        }

        /* Add the current node to the closed list */
        closedList[closedListCount++] = currentNode;

        /* Generate child nodes for the current node */
        generateChildNodes(currentNode);

        /* Check if the end node is reached */
        if (currentNode == endNode) {
            tracePath(startNode, endNode);
            return;
        }
    }

    /* No path found */
    printf("No path found!");
}

int main() {
    struct Node* startNode = (struct Node*)malloc(sizeof(struct Node));
    startNode->row = 0;
    startNode->col = 0;
    startNode->fCost = 0;
    startNode->gCost = 0;
    startNode->hCost = 0;
    startNode->parent = NULL;

    struct Node* endNode = (struct Node*)malloc(sizeof(struct Node));
    endNode->row = ROWS - 1;
    endNode->col = COLS - 1;
    endNode->fCost = 0;
    endNode->gCost = 0;
    endNode->hCost = 0;
    endNode->parent = NULL;

    aStarAlgorithm(startNode, endNode);

    return 0;
}
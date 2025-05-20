//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// The map used for pathfinding
int map[ROWS][COLS] = {
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 0, 0, 1, 1, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

// Struct to represent a node
typedef struct Node {
    int row;
    int col;
    int g;
    int f;
    struct Node* parent;
} Node;

// Function to create a new node
Node* createNode(int row, int col, Node* parent, int g, int h) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->parent = parent;
    newNode->g = g;
    newNode->f = g + h;
    return newNode;
}

// Function to calculate the heuristic value for a node
int heuristic(int row, int col, int goalRow, int goalCol) {
    return abs(goalRow-row) + abs(goalCol-col);
}

// Function to check if a node is valid
bool isValid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS) {
        return false;
    }
    if (map[row][col] == 1) {
        return false;
    }
    return true;
}

// Function to get the adjacent nodes for the current node
void getAdjacentNodes(Node* currentNode, Node* nodes[8], int goalRow, int goalCol) {
    int row = currentNode->row;
    int col = currentNode->col;
    int g = currentNode->g + 1;
    
    // Upper Left
    if (isValid(row-1, col-1)) {
        nodes[0] = createNode(row-1, col-1, currentNode, g, heuristic(row-1, col-1, goalRow, goalCol));
    }
    // Upper
    if (isValid(row-1, col)) {
        nodes[1] = createNode(row-1, col, currentNode, g, heuristic(row-1, col, goalRow, goalCol));
    }
    // Upper Right
    if (isValid(row-1, col+1)) {
        nodes[2] = createNode(row-1, col+1, currentNode, g, heuristic(row-1, col+1, goalRow, goalCol));
    }
    // Left
    if (isValid(row, col-1)) {
        nodes[3] = createNode(row, col-1, currentNode, g, heuristic(row, col-1, goalRow, goalCol));
    }
    // Right
    if (isValid(row, col+1)) {
        nodes[4] = createNode(row, col+1, currentNode, g, heuristic(row, col+1, goalRow, goalCol));
    }
    // Lower Left
    if (isValid(row+1, col-1)) {
        nodes[5] = createNode(row+1, col-1, currentNode, g, heuristic(row+1, col-1, goalRow, goalCol));
    }
    // Lower
    if (isValid(row+1, col)) {
        nodes[6] = createNode(row+1, col, currentNode, g, heuristic(row+1, col, goalRow, goalCol));
    }
    // Lower Right
    if (isValid(row+1, col+1)) {
        nodes[7] = createNode(row+1, col+1, currentNode, g, heuristic(row+1, col+1, goalRow, goalCol));
    }
}

// Function to find the shortest path from start to goal using A* algorithm
void aStar(int startRow, int startCol, int goalRow, int goalCol) {
    Node* openList[ROWS*COLS];
    Node* closedList[ROWS*COLS];
    int numOpenNodes = 1;
    int numClosedNodes = 0;
    
    // Create the start node
    Node* startNode = createNode(startRow, startCol, NULL, 0, heuristic(startRow, startCol, goalRow, goalCol));
    openList[0] = startNode;
    
    // Loop until the goal is found or no more nodes are left
    while (numOpenNodes > 0) {
        int lowestF = 99999;
        int index = -1;
        
        // Find the node in the open list with the lowest f value
        for (int i = 0; i < numOpenNodes; i++) {
            if (openList[i]->f < lowestF) {
                lowestF = openList[i]->f;
                index = i;
            }
        }
        
        // Get the node with the lowest f value
        Node* currentNode = openList[index];
        
        // Remove the current node from the open list
        for (int i = index; i < numOpenNodes-1; i++) {
            openList[i] = openList[i+1];
        }
        numOpenNodes--;
        
        // Add the current node to the closed list
        closedList[numClosedNodes] = currentNode;
        numClosedNodes++;
        
        // Check if the current node is the goal
        if (currentNode->row == goalRow && currentNode->col == goalCol) {
            // Path found, print the path
            printf("Path Found:\n");
            while (currentNode != NULL) {
                printf("(%d,%d) ", currentNode->row, currentNode->col);
                currentNode = currentNode->parent;
            }
            printf("\n");
            return;
        }
        
        // Get the adjacent nodes for the current node
        Node* nodes[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
        getAdjacentNodes(currentNode, nodes, goalRow, goalCol);
        
        // Add the adjacent nodes to the open list if they are valid and not already in the closed list
        for (int i = 0; i < 8; i++) {
            if (nodes[i] != NULL) {
                bool inClosedList = false;
                for (int j = 0; j < numClosedNodes; j++) {
                    if (nodes[i]->row == closedList[j]->row && nodes[i]->col == closedList[j]->col) {
                        inClosedList = true;
                        break;
                    }
                }
                if (!inClosedList) {
                    // Check if the node is already in the open list
                    bool inOpenList = false;
                    for (int j = 0; j < numOpenNodes; j++) {
                        if (nodes[i]->row == openList[j]->row && nodes[i]->col == openList[j]->col) {
                            inOpenList = true;
                            // If the node is already in the open list and has a higher g value, update the parent and g value
                            if (nodes[i]->g > openList[j]->g) {
                                openList[j]->parent = currentNode;
                                openList[j]->g = nodes[i]->g;
                                openList[j]->f = nodes[i]->f;
                            }
                            break;
                        }
                    }
                    if (!inOpenList) {
                        // Add the node to the open list
                        openList[numOpenNodes] = nodes[i];
                        numOpenNodes++;
                    }
                }
            }
        }
    }
    
    // Path not found
    printf("Path not found.\n");
}


int main() {
    aStar(0, 0, 9, 9); // Find the shortest path from (0,0) to (9,9)
    return 0;
}
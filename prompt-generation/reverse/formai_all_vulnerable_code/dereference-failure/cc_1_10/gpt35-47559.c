//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the grid array and its dimensions
int grid[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0},
    {0,0,0,1,0,1,0,0,0,0},
    {0,0,0,1,0,1,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

// Define the start and goal nodes
int start[2] = {1,1};
int goal[2] = {7,9};

// Define the dimensions of the grid
int ROWS = 10;
int COLS = 10;

// Define the node struct
typedef struct Node{
    int row;
    int col;
    int fCost;
    int hCost;
    int gCost;
    struct Node* parent;
} Node;

// Define a function to initialize a new node with given values
Node* initializeNode(int row, int col, int gCost, int hCost, Node* parent){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->gCost = gCost;
    newNode->hCost = hCost;
    newNode->fCost = gCost + hCost;
    newNode->parent = parent;
    return newNode;
}

// Define a function to check if a given node is the goal node
int isGoalNode(Node* node){
    if(node->row == goal[0] && node->col == goal[1]){
        return 1;
    }else{
        return 0;
    }
}

// Define a function to get the heuristic cost from a given node to the goal node
int getHeuristicCost(int row, int col){
    int d1 = abs(row - goal[0]);
    int d2 = abs(col - goal[1]);
    return d1 + d2;
}

// Define a function to check if a given node is valid
int isValidNode(int row, int col){
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS && grid[row][col] == 0){
        return 1;
    }else{
        return 0;
    }
}

// Define a function to check if a given node is in the open or closed list
Node* isInOpenOrClosedList(Node* node, Node** list, int length){
    for(int i=0; i<length; i++){
        if(list[i]->row == node->row && list[i]->col == node->col){
            return list[i];
        }
    }
    return NULL;
}

// Define the A* pathfinding algorithm function
Node* aStar(){
    // Initialize the open and closed lists
    int openLength = 0;
    Node* openList[ROWS * COLS];
    Node* closedList[ROWS * COLS];

    // Initialize the start node
    Node* startNode = initializeNode(start[0], start[1], 0, getHeuristicCost(start[0], start[1]), NULL);
    openList[openLength] = startNode;
    openLength++;

    // Loop until the open list is empty
    while(openLength > 0){
        // Get the node with the lowest fCost from the open list
        int lowestCostIndex = 0;
        for(int i=0; i<openLength; i++){
            if(openList[i]->fCost < openList[lowestCostIndex]->fCost){
                lowestCostIndex = i;
            }
        }
        Node* currentNode = openList[lowestCostIndex];

        // Check if current node is the goal node
        if(isGoalNode(currentNode)){
            return currentNode;
        }

        // Move current node from open to closed list
        openList[lowestCostIndex] = openList[openLength-1];
        openLength--;
        closedList[currentNode->row * COLS + currentNode->col] = currentNode;

        // Loop through all neighboring nodes
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                // Skip diagonals
                if(i!=0 && j!=0){
                    continue;
                }
                int neighborRow = currentNode->row + i;
                int neighborCol = currentNode->col + j;
                // Skip invalid nodes
                if(!isValidNode(neighborRow, neighborCol)){
                    continue;
                }
                // Generate the neighbor node
                int neighborGCost = currentNode->gCost + 1;
                int neighborHCost = getHeuristicCost(neighborRow, neighborCol);
                Node* neighborNode = initializeNode(neighborRow, neighborCol, neighborGCost, neighborHCost, currentNode);
                // Check if neighbor node is in the closed list
                Node* closedNode = isInOpenOrClosedList(neighborNode, closedList, ROWS*COLS);
                if(closedNode != NULL){
                    free(neighborNode);
                    continue;
                }
                // Check if neighbor node is in the open list
                Node* openNode = isInOpenOrClosedList(neighborNode, openList, openLength);
                if(openNode != NULL){
                    if(neighborNode->gCost < openNode->gCost){
                        openNode->gCost = neighborNode->gCost;
                        openNode->hCost = neighborNode->hCost;
                        openNode->fCost = neighborNode->fCost;
                        openNode->parent = neighborNode->parent;
                    }
                    free(neighborNode);
                }else{
                    // Add neighbor node to open list
                    openList[openLength] = neighborNode;
                    openLength++;
                }
            }
        }
    }

    // No path found
    return NULL;
}

// Define a function to print the path from start to goal
void printPath(Node* goalNode){
    Node* currentNode = goalNode;
    int pathLength = 0;
    while(currentNode != NULL){
        pathLength++;
        currentNode = currentNode->parent;
    }
    Node* pathNodes[pathLength];
    currentNode = goalNode;
    for(int i=pathLength-1; i>=0; i--){
        pathNodes[i] = currentNode;
        currentNode = currentNode->parent;
    }
    for(int i=0; i<pathLength; i++){
        printf("-> (%d,%d) ", pathNodes[i]->row, pathNodes[i]->col);
    }
}

// Main
int main(){
    Node* goalNode = aStar();
    if(goalNode != NULL){
        printf("Path found:");
        printPath(goalNode);
    }else{
        printf("No path found.");
    }
    return 0;
}
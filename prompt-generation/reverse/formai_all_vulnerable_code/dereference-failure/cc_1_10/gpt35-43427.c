//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: imaginative
// Welcome to the world of A* Pathfinding Algorithm!

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

//Defining a Structure for Nodes used
struct Node {
    int row, col;
    int f, g, h;
    struct Node* parent;
};

//Making a 2D matrix/grid with random obstacles
int grid[ROW][COL] = { { 0, 0, 0, 0, 0 },
                       { 0, 1, 0, 1, 0 },
                       { 0, 0, 0, 0, 0 },
                       { 0, 1, 0, 1, 0 },
                       { 0, 0, 0, 0, 0 } };

//Function to check whether the node is in the grid or not
bool isInsideGrid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

//Function to check whether the node is not blocked or not (i.e it should be 0)
bool isUnblocked(int row, int col)
{
    return grid[row][col] == 0;
}

//Function to check whether it is a destination node or not
bool isDestination(int row, int col, struct Node dest)
{
    return (row == dest.row && col == dest.col);
}

//Function to calculate the 'h' heuristic value of the node
int calculateHValue(int row, int col, struct Node dest)
{
    return abs(row - dest.row) + abs(col - dest.col);
}

//Function to print the path of the A* Pathfinding Algorithm
void printPath(struct Node* endNode)
{
    if (endNode->parent == NULL)
        return;

    printPath(endNode->parent);
    printf("-> (%d,%d) ", endNode->row, endNode->col);
}

//A Star Pathfinding Algorithm Function
bool aStarSearch(struct Node source, struct Node dest)
{
    if (!isInsideGrid(source.row, source.col)) {
        printf("\nSource node is out of the Grid!");
        return false;
    }
    if (!isInsideGrid(dest.row, dest.col)) {
        printf("\nDestination node is out of the Grid!");
        return false;
    }
    if (!isUnblocked(source.row, source.col)) {
        printf("\nSource node is Blocked! Cannot find Path!");
        return false;
    }
    if (!isUnblocked(dest.row, dest.col)) {
        printf("\nDestination node is Blocked! Cannot find Path!");
        return false;
    }

    //Node is created to store the details of a Node
    struct Node node;
    node.row = source.row;
    node.col = source.col;
    node.f = 0;
    node.g = 0;
    node.h = 0;
    node.parent = NULL;

    //Creating a Closed List and Open List of nodes
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));

    struct Node* openList[ROW * COL];
    int openListCount = 0;

    openList[openListCount++] = &node;

    //Run until there are no more nodes to explore or the destination node is found
    while (openListCount != 0) {
        //Get the current node from the openList with the lowest value of f
        struct Node* currentNode = openList[0];
        int currentNodeIndex = 0;

        for (int i = 1; i < openListCount; i++) {
            if (openList[i]->f < currentNode->f
                || (openList[i]->f == currentNode->f
                    && openList[i]->h < currentNode->h)) {
                currentNode = openList[i];
                currentNodeIndex = i;
            }
        }

        //Remove the currentNode from openList and add to closedList
        openList[currentNodeIndex] = openList[--openListCount];
        closedList[currentNode->row][currentNode->col] = true;

        // if the currentNode is the destination node, print the path
        if (isDestination(currentNode->row, currentNode->col, dest)) {
            printf("Path found: \n ");
            printPath(currentNode);
            return true;
        }

        //Explore 8 adjacent nodes: left, right, up, down, and 4 diagonals
        int row[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
        int col[] = { 0, -1, 0, 1, -1, 1, -1, 1 };

        for (int i = 0; i < 8; i++) {
            int newRow = currentNode->row + row[i];
            int newCol = currentNode->col + col[i];

            // Check if the new node is inside the grid
            if (isInsideGrid(newRow, newCol)) {
                // Check if the new node is unblocked and hasn't been explored before
                if (isUnblocked(newRow, newCol) && !closedList[newRow][newCol]) {
                    int gValue = currentNode->g + 1;
                    int hValue = calculateHValue(newRow, newCol, dest);
                    int fValue = gValue + hValue;

                    //Check if the new node has a better f value than the current one and add it to openList
                    bool isAlreadyInOpenList = false;
                    for (int j = 0; j < openListCount; j++) {
                        if (openList[j]->row == newRow && openList[j]->col == newCol) {
                            isAlreadyInOpenList = true;
                            if (fValue < openList[j]->f) {
                                openList[j]->f = fValue;
                                openList[j]->g = gValue;
                                openList[j]->h = hValue;
                                openList[j]->parent = currentNode;
                            }
                        }
                    }

                    if (!isAlreadyInOpenList) {
                        struct Node* newNode
                            = (struct Node*)malloc(sizeof(struct Node));
                        newNode->row = newRow;
                        newNode->col = newCol;
                        newNode->f = fValue;
                        newNode->g = gValue;
                        newNode->h = hValue;
                        newNode->parent = currentNode;
                        openList[openListCount++] = newNode;
                    }
                }
            }
        }
    }

    printf("\nPath not found between Source and Destination nodes!\n");
    return false;
}

int main()
{

    //Initialzing Source and Destination rows and colums
    struct Node source;
    source.row = 0;
    source.col = 0;

    struct Node dest;
    dest.row = 4;
    dest.col = 4;

    printf("A* Pathfinding Algorithm:\n\n");
  
    //Prints Grid as a Matrix
    printf("Initial Grid: \n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }

    //Calls A* Pathfinding Algorithm function if it is possible for the source and destination nodes to be found
    if (aStarSearch(source, dest) == false)
        printf("\nFailed to find Path between the Source and Destination nodes!\n\n");

    return 0;
}
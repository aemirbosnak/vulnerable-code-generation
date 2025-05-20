//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// A Node structure for A* Pathfinding Algorithm
struct Node
{
    int row, col;
    struct Node* parent;
    double f, g, h;
};

// Function to find the adjacent nodes of the current node
bool findAdjacentNodes(int mat[ROW][COL], int visited[ROW][COL], int row, int col, struct Node* parent, struct Node* adjList[8], int* adjCount)
{
    // Check all 8 adjacent nodes
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            // Skip the current node and diagonals
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (abs(i) == abs(j))
            {
                continue;
            }
            // Check if the adjacent node is within bounds of the matrix
            int adjRow = row + i;
            int adjCol = col + j;
            if (adjRow < 0 || adjRow >= ROW || adjCol < 0 || adjCol >= COL)
            {
                continue;
            }
            // Check if the node is already visited or not
            if (visited[adjRow][adjCol] == true)
            {
                continue;
            }
            // Check if the adjacent node is not blocked
            if (mat[adjRow][adjCol] == 1)
            {
                continue;
            }
            // Initialize the adjacent node and add it to the adjacent list
            struct Node* adjNode = (struct Node*)malloc(sizeof(struct Node));
            adjNode->row = adjRow;
            adjNode->col = adjCol;
            adjNode->parent = parent;
            adjList[*adjCount] = adjNode;
            (*adjCount)++;
            // Return true if the destination node is found
            if (mat[adjRow][adjCol] == 2)
            {
                return true;
            }
        }
    }
    return false;
}

// Function to calculate the heuristic distance between two nodes
double distance(int currRow, int currCol, int destRow, int destCol)
{
    int dx = abs(currRow - destRow);
    int dy = abs(currCol - destCol);
    return sqrt(dx*dx + dy*dy);
}

// Function to implement A* Pathfinding Algorithm
void Astar(int mat[ROW][COL], int srcRow, int srcCol, int destRow, int destCol)
{
    int visited[ROW][COL];
    memset(visited, false, sizeof(visited));
    struct Node* adjList[8];
    memset(adjList, 0, sizeof(adjList));
    int adjCount = 0;
    struct Node* srcNode = (struct Node*)malloc(sizeof(struct Node));
    srcNode->row = srcRow;
    srcNode->col = srcCol;
    srcNode->parent = NULL;
    srcNode->f = srcNode->g = srcNode->h = 0.0;
    adjList[adjCount++] = srcNode;
    while (adjCount > 0)
    {
        int currIndex = 0;
        double currF = adjList[0]->f;
        for (int i = 1; i < adjCount; i++)
        {
            if (adjList[i]->f < currF)
            {
                currIndex = i;
                currF = adjList[i]->f;
            }
        }
        struct Node* currNode = adjList[currIndex];
        visited[currNode->row][currNode->col] = true;
        // Check if the current node is the destination node
        if (mat[currNode->row][currNode->col] == 2)
        {
            printf("Destination node found!!!\n");
            return;
        }
        adjCount = 0;
        findAdjacentNodes(mat, visited, currNode->row, currNode->col, currNode, adjList, &adjCount);
        // Calculate the f,g,h values of the adjacent nodes
        for (int i = 0; i < adjCount; i++)
        {
            struct Node* adjNode = adjList[i];
            adjNode->g = currNode->g + distance(currNode->row, currNode->col, adjNode->row, adjNode->col);
            adjNode->h = distance(adjNode->row, adjNode->col, destRow, destCol);
            adjNode->f = adjNode->g + adjNode->h;
        }
    }
    printf("Destination node not found!!!\n");
}

// Driver function
int main()
{
    int mat[ROW][COL] =
    {
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 1, 0, 1, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 1, 1, 1, 2, 1}
    };
    Astar(mat, 0, 0, 9, 8);
    return 0;
}
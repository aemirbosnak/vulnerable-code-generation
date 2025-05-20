//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define ROWS 5 // Define rows of the map
#define COLS 5 // Define columns of the map

typedef struct // Define a node as a struct that contains x, y coordinates and other properties
{
    int x;
    int y;
    bool walkable;
    int gCost;
    int hCost;
    int fCost;
    struct Node* parent;
} Node;

Node* openList[ROWS * COLS]; // Create an open list array to store the nodes
Node* closedList[ROWS * COLS]; // Create a closed list array to store the nodes
Node* grid[ROWS][COLS]; // Create a grid to store the map nodes

int openListCount = 0; // Keep track of the number of nodes in the open list
int closedListCount = 0; // Keep track of the number of nodes in the closed list

Node* startNode; // Initialize the start node
Node* endNode; // Initialize the end node

void initGrid() // Function to initialize the map with walkable and non-walkable nodes
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            Node* node = malloc(sizeof(Node));
            node->x = i;
            node->y = j;
            node->walkable = true; // Set all the nodes to walkable initially
            grid[i][j] = node;
        }
    }

    grid[2][1]->walkable = false; // Set some of the nodes to non-walkable to create obstacles
    grid[2][2]->walkable = false;
    grid[2][3]->walkable = false;
    grid[3][3]->walkable = false;
}

int calcDistance(Node* node1, Node* node2) // Function to calculate the Euclidean distance between two nodes
{
    int xDist = abs(node1->x - node2->x);
    int yDist = abs(node1->y - node2->y);
    return sqrt(xDist * xDist + yDist * yDist);
}

void addToOpenList(Node* node) // Function to add a node to the open list
{
    openList[openListCount] = node;
    openListCount++;
}

void removeFromOpenList(Node* node) // Function to remove a node from the open list
{
    for (int i = 0; i < openListCount; i++)
    {
        if (openList[i] == node)
        {
            for (int j = i; j < openListCount - 1; j++)
            {
                openList[j] = openList[j + 1];
            }
            openListCount--;
            break;
        }
    }
}

void addToClosedList(Node* node) // Function to add a node to the closed list
{
    closedList[closedListCount] = node;
    closedListCount++;
}

bool isInOpenList(Node* node) // Function to check if a node is in the open list
{
    for (int i = 0; i < openListCount; i++)
    {
        if (openList[i] == node)
        {
            return true;
        }
    }
    return false;
}

bool isInClosedList(Node* node) // Function to check if a node is in the closed list
{
    for (int i = 0; i < closedListCount; i++)
    {
        if (closedList[i] == node)
        {
            return true;
        }
    }
    return false;
}

Node* getLowestFCostNode() // Function to get the node with the lowest f cost in the open list
{
    Node* lowestFCostNode = openList[0];
    for (int i = 0; i < openListCount; i++)
    {
        if (openList[i]->fCost < lowestFCostNode->fCost)
        {
            lowestFCostNode = openList[i];
        }
    }
    return lowestFCostNode;
}

void calculateCosts(Node* currNode) // Function to calculate the g, h and f costs for a node
{
    currNode->gCost = calcDistance(currNode, startNode);
    currNode->hCost = calcDistance(currNode, endNode);
    currNode->fCost = currNode->gCost + currNode->hCost;
}

void tracePath(Node* endNode) // Function to trace the path from the start node to the end node
{
    Node* currNode = endNode;
    while (currNode != startNode)
    {
        printf("(%d, %d) -> ", currNode->x, currNode->y);
        currNode = currNode->parent;
    }
    printf("(%d, %d) \n", startNode->x, startNode->y);
}

void runAStar() // Function to run the A* algorithm
{
    addToOpenList(startNode);

    while (openListCount > 0)
    {
        Node* currNode = getLowestFCostNode();

        if (currNode == endNode)
        {
            printf("Path found successfully!\n");
            tracePath(currNode);
            return;
        }

        removeFromOpenList(currNode);
        addToClosedList(currNode);

        for (int i = currNode->x - 1; i <= currNode->x + 1; i++)
        {
            for (int j = currNode->y - 1; j <= currNode->y + 1; j++)
            {
                if (i >= 0 && i < ROWS && j >= 0 && j < COLS)
                {
                    Node* neighbour = grid[i][j];

                    if ((neighbour->walkable) && (!isInClosedList(neighbour)))
                    {
                        int newCostToNeighbour = currNode->gCost + calcDistance(currNode, neighbour);

                        if ((newCostToNeighbour < neighbour->gCost) || (!isInOpenList(neighbour)))
                        {
                            neighbour->gCost = newCostToNeighbour;
                            calculateCosts(neighbour);
                            neighbour->parent = currNode;

                            if (!isInOpenList(neighbour))
                            {
                                addToOpenList(neighbour);
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Path not found!\n");
}

int main()
{
    initGrid();

    // Set the start and end nodes
    startNode = grid[0][0];
    endNode = grid[4][4];

    // Run the A* algorithm
    runAStar();

    return 0;
}
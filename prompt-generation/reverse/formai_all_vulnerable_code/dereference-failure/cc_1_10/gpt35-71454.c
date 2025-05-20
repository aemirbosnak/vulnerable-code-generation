//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

//Structure for a single node in the grid
typedef struct Node
{
    int x, y; //Coordinates of node
    bool isWall; //Is the node a wall?
    bool isVisited; //Has the node been visited?
    double f, g, h; //Variables for A* algorithm
    struct Node* parent; //Pointer to parent node
} Node;

Node* grid[ROWS][COLS];

//Function to calculate the heuristic value (h) for a given node and the destination node
double calculateH(Node* currNode, Node* destNode)
{
    return abs(currNode->x - destNode->x) + abs(currNode->y - destNode->y);
}

//Function to initialize the grid with nodes
void initializeGrid()
{
    //Code to initialize the grid with nodes, walls, and start/end nodes goes here...

    //Example code to create a 10x10 grid with walls and start/end nodes:
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            Node* node = (Node*)malloc(sizeof(Node));
            node->x = i;
            node->y = j;
            node->isVisited = false;
            node->parent = NULL;

            //Set wall nodes at random (30% chance)
            if(rand()%100 < 30)
            {
                node->isWall = true;
            }
            else
            {
                node->isWall = false;
            }

            //Set start and end nodes
            if(i == 0 && j == 0)
            {
                node->isWall = false;
                node->f = 0;
                node->g = 0;
                node->h = 0;
            }
            else if(i == ROWS-1 && j == COLS-1)
            {
                node->isWall = false;
                node->f = 0;
                node->g = 0;
                node->h = 0;
            }
            else
            {
                node->f = 0;
                node->g = 0;
                node->h = 0;
            }

            grid[i][j] = node;
        }
    }
}

//Function to print the grid (for testing purposes only)
void printGrid()
{
    //Code to print the grid goes here...

    //Example code to print the grid:
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(grid[i][j]->isWall)
            {
                printf("# ");
            }
            else if(grid[i][j]->parent == NULL)
            {
                printf("O ");
            }
            else if(grid[i][j]->parent->x == i && grid[i][j]->parent->y == j)
            {
                printf("x ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

//Function to find the node with the lowest f value in the open set
Node* getLowestFNode(Node** openSet, int openSetSize)
{
    Node* lowestNode = openSet[0];
    for(int i=1;i<openSetSize;i++)
    {
        if(openSet[i]->f < lowestNode->f)
        {
            lowestNode = openSet[i];
        }
    }
    return lowestNode;
}

//Function to find the neighboring nodes of a given node (excluding walls and visited nodes)
Node** getNeighbors(Node* node, int* neighborsSize)
{
    //Code to find the neighboring nodes goes here...

    //Example code to find the neighboring nodes:
    Node** neighbors = (Node**)malloc(8*sizeof(Node*));
    *neighborsSize = 0;

    for(int i=node->x-1;i<=node->x+1;i++)
    {
        for(int j=node->y-1;j<=node->y+1;j++)
        {
            if(i>=0 && j>=0 && i<ROWS && j<COLS && (i!=node->x || j!=node->y) && !grid[i][j]->isWall && !grid[i][j]->isVisited)
            {
                neighbors[*neighborsSize] = grid[i][j];
                (*neighborsSize)++;
            }
        }
    }

    return neighbors;
}

//Function to run the A* algorithm and return the path (if found)
Node** runAStar(Node* startNode, Node* destNode, int* pathSize)
{
    //Create open and closed sets
    Node** openSet = (Node**)malloc(ROWS*COLS*sizeof(Node*));
    int openSetSize = 1;
    openSet[0] = startNode;

    Node** closedSet = (Node**)malloc(ROWS*COLS*sizeof(Node*));
    int closedSetSize = 0;

    //Run A* algorithm
    while(openSetSize > 0)
    {
        //Find node with lowest f value in open set
        Node* currentNode = getLowestFNode(openSet, openSetSize);

        //If current node is destination node, reconstruct and return path
        if(currentNode == destNode)
        {
            Node** path = (Node**)malloc(ROWS*COLS*sizeof(Node*));
            *pathSize = 0;

            Node* node = destNode;
            while(node != startNode)
            {
                path[*pathSize] = node;
                (*pathSize)++;
                node = node->parent;
            }
            path[*pathSize] = startNode;
            (*pathSize)++;

            return path;
        }

        //Move current node from open to closed set
        openSetSize--;
        for(int i=0;i<openSetSize;i++)
        {
            if(openSet[i] == currentNode)
            {
                openSet[i] = openSet[openSetSize];
                break;
            }
        }
        closedSet[closedSetSize] = currentNode;
        closedSetSize++;

        //Find and loop through neighboring nodes
        int neighborsSize;
        Node** neighbors = getNeighbors(currentNode, &neighborsSize);

        for(int i=0;i<neighborsSize;i++)
        {
            Node* neighbor = neighbors[i];

            //If neighbor node is in closed set, skip it
            bool isInClosedSet = false;
            for(int j=0;j<closedSetSize;j++)
            {
                if(closedSet[j] == neighbor)
                {
                    isInClosedSet = true;
                    break;
                }
            }

            if(isInClosedSet)
            {
                continue;
            }

            //Calculate new tentative g value for neighbor node
            double newG = currentNode->g + abs(currentNode->x - neighbor->x) + abs(currentNode->y - neighbor->y);

            bool isInOpenSet = false;
            for(int j=0;j<openSetSize;j++)
            {
                if(openSet[j] == neighbor)
                {
                    isInOpenSet = true;
                    break;
                }
            }

            //If neighbor node is not in open set or new g value is lower, update neighbor node
            if(!isInOpenSet || newG < neighbor->g)
            {
                neighbor->g = newG;
                neighbor->h = calculateH(neighbor, destNode);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = currentNode;

                if(!isInOpenSet)
                {
                    openSet[openSetSize] = neighbor;
                    openSetSize++;
                }
            }
        }

        //Mark current node as visited
        currentNode->isVisited = true;

        free(neighbors);
    }

    //Path not found
    *pathSize = 0;
    return NULL;
}

int main()
{
    srand(time(NULL)); //Seed random number generator

    initializeGrid(); //Create grid and set start/end nodes
    printGrid(); //Print initial grid for testing purposes

    Node** path;
    int pathSize;

    path = runAStar(grid[0][0], grid[ROWS-1][COLS-1], &pathSize); //Run A* algorithm from start to end
    if(path != NULL)
    {
        printf("Path found!\n");

        //Print path for testing purposes
        for(int i=pathSize-1;i>=0;i--)
        {
            printf("(%d,%d) ", path[i]->x, path[i]->y);
        }
        printf("\n");

        free(path);
    }
    else
    {
        printf("Path not found!\n");
    }

    return 0;
}
//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#define ROW 10
#define COL 10
#define MAX_SIZE 100

struct Node
{
    int row;
    int col;
    int g;
    int h;
    int f;
    struct Node *parent;
};

int maze[ROW][COL] = {
    {1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1}
};

int isOpen(int row, int col)
{
    if(maze[row][col] == 1)
        return 1;
    else
        return 0;
}

int isDestination(int row, int col, struct Node *destinationNode)
{
    if(row == destinationNode->row && col == destinationNode->col)
        return 1;
    else
        return 0;
}

int getH(int row, int col, struct Node *destinationNode)
{
    return abs(row - destinationNode->row) + abs(col - destinationNode->col);
}

struct Node* createNode(int row, int col, int g, int h, struct Node *parent)
{
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->g = g;
    node->h = h;
    node->f = g + h;
    node->parent = parent;
    return node;
}

void printPath(struct Node *node)
{
    if (node->parent != NULL)
        printPath(node->parent);
    printf("(%d,%d) -> ", node->row, node->col);
}

void aStarSearch(struct Node *startNode, struct Node *destinationNode)
{
    struct Node *openList[MAX_SIZE];
    int openListSize = 0;

    struct Node *closedList[MAX_SIZE];
    int closedListSize = 0;

    openList[openListSize++] = startNode;

    while(openListSize > 0)
    {
        struct Node *currentNode = openList[0];
        int currentIndex = 0;

        for(int i=0;i<openListSize;i++)
        {
            if(openList[i]->f < currentNode->f)
            {
                currentNode = openList[i];
                currentIndex = i;
            }
        }

        openList[currentIndex] = openList[openListSize-1];
        openListSize--;

        closedList[closedListSize++] = currentNode;

        if(isDestination(currentNode->row, currentNode->col, destinationNode))
        {
            printf("Path found : ");
            printPath(currentNode);
            printf("(%d,%d)\n", destinationNode->row, destinationNode->col);
            return;
        }

        int row = currentNode->row;
        int col = currentNode->col;

        struct Node *succesors[8];
        int successorSize = 0;

        if(isOpen(row-1, col))
            succesors[successorSize++] = createNode(row-1, col, currentNode->g+1, getH(row-1, col, destinationNode), currentNode);
        if(isOpen(row+1, col))
            succesors[successorSize++] = createNode(row+1, col, currentNode->g+1, getH(row+1, col, destinationNode), currentNode);
        if(isOpen(row, col-1))
            succesors[successorSize++] = createNode(row, col-1, currentNode->g+1, getH(row, col-1, destinationNode), currentNode);
        if(isOpen(row, col+1))
            succesors[successorSize++] = createNode(row, col+1, currentNode->g+1, getH(row, col+1, destinationNode), currentNode);
        if(isOpen(row-1, col-1))
            succesors[successorSize++] = createNode(row-1, col-1, currentNode->g+1, getH(row-1, col-1, destinationNode), currentNode);
        if(isOpen(row+1, col-1))
            succesors[successorSize++] = createNode(row+1, col-1, currentNode->g+1, getH(row+1, col-1, destinationNode), currentNode);
        if(isOpen(row-1, col+1))
            succesors[successorSize++] = createNode(row-1, col+1, currentNode->g+1, getH(row-1, col+1, destinationNode), currentNode);
        if(isOpen(row+1, col+1))
            succesors[successorSize++] = createNode(row+1, col+1, currentNode->g+1, getH(row+1, col+1, destinationNode), currentNode);

        for(int i=0;i<successorSize;i++)
        {
            int isInClosedList = 0;
            for(int j=0;j<closedListSize;j++)
            {
                if(succesors[i]->row == closedList[j]->row && succesors[i]->col == closedList[j]->col)
                {
                    isInClosedList = 1;
                    break;
                }
            }

            if(isInClosedList)
                continue;

            int g = currentNode->g + 1;

            int isInOpenList = 0;
            for(int j=0;j<openListSize;j++)
            {
                if(succesors[i]->row == openList[j]->row && succesors[i]->col == openList[j]->col)
                {
                    isInOpenList = 1;
                    if(g < openList[j]->g)
                    {
                        openList[j]->g = g;
                        openList[j]->h = getH(succesors[i]->row, succesors[i]->col, destinationNode);
                        openList[j]->f = g + openList[j]->h;
                        openList[j]->parent = currentNode;
                    }
                    break;
                }
            }

            if(!isInOpenList)
            {
                succesors[i]->g = g;
                succesors[i]->h = getH(succesors[i]->row, succesors[i]->col, destinationNode);
                succesors[i]->f = g + succesors[i]->h;
                succesors[i]->parent = currentNode;

                openList[openListSize++] = succesors[i];
            }
        }

    }

    printf("Path not found\n");
}

int main()
{
    struct Node *startNode = createNode(0, 0, 0, 0, NULL);
    struct Node *destinationNode = createNode(ROW-1, COL-1, 0, 0, NULL);

    aStarSearch(startNode, destinationNode);

    return 0;
}
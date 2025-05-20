//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10

struct node
{
    int x, y;
    int f, g, h;
    struct node* parent;
};

char map[WIDTH][HEIGHT] = {
    {'x','x','x','x','x','x','x','x','x','x'},
    {'x','s',' ',' ',' ',' ',' ',' ',' ','x'},
    {'x',' ','x','x',' ','x',' ','x',' ','x'},
    {'x',' ','x','x',' ','x',' ','x',' ','x'},
    {'x',' ',' ',' ',' ','x',' ','x',' ','x'},
    {'x',' ','x',' ',' ',' ',' ','x',' ','x'},
    {'x',' ','x','x','x','x','x','x',' ','x'},
    {'x',' ',' ',' ',' ',' ',' ',' ',' ','x'},
    {'x',' ',' ',' ',' ',' ',' ',' ','e','x'},
    {'x','x','x','x','x','x','x','x','x','x'},
};

bool closedList[WIDTH][HEIGHT];
bool openList[WIDTH][HEIGHT];
struct node* nodeList[WIDTH][HEIGHT];
int numNodes;
struct node* startNode;
struct node* endNode;

void initializeMap()
{
    numNodes = 0;
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            closedList[i][j] = false;
            openList[i][j] = false;
            nodeList[i][j] = NULL;

            if (map[i][j] == 's')
            {
                startNode = (struct node*)malloc(sizeof(struct node));
                startNode->x = i;
                startNode->y = j;
                startNode->f = 0;
                startNode->g = 0;
                startNode->h = 0;
                startNode->parent = NULL;
                nodeList[i][j] = startNode;
                numNodes++;
            }

            if (map[i][j] == 'e')
            {
                endNode = (struct node*)malloc(sizeof(struct node));
                endNode->x = i;
                endNode->y = j;
                endNode->f = 0;
                endNode->g = 0;
                endNode->h = 0;
                endNode->parent = NULL;
                nodeList[i][j] = endNode;
                numNodes++;
            }

            if (map[i][j] == 'x')
            {
                nodeList[i][j] = (struct node*)malloc(sizeof(struct node));
                nodeList[i][j]->x = i;
                nodeList[i][j]->y = j;
                nodeList[i][j]->f = 0;
                nodeList[i][j]->g = 0;
                nodeList[i][j]->h = 0;
                nodeList[i][j]->parent = NULL;
                closedList[i][j] = true;
                numNodes++;
            }
        }
    }
}

void updateNode(struct node* parent, struct node* successor)
{
    successor->parent = parent;
    successor->g = parent->g + 1;
    successor->h = abs(successor->x - endNode->x) + abs(successor->y - endNode->y);
    successor->f = successor->g + successor->h;
}

struct node* findSmallestF()
{
    int smallestF = WIDTH * HEIGHT;
    struct node* smallestNode;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < HEIGHT; j++)
        {
            if (openList[i][j] && nodeList[i][j]->f < smallestF)
            {
                smallestF = nodeList[i][j]->f;
                smallestNode = nodeList[i][j];
            }
        }
    }

    return smallestNode;
}

int main()
{
    initializeMap();
    openList[startNode->x][startNode->y] = true;

    while (true)
    {
        struct node* current = findSmallestF();

        if (current == endNode)
        {
            break;
        }

        closedList[current->x][current->y] = true;
        openList[current->x][current->y] = false;

        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                int x = current->x + i;
                int y = current->y + j;

                if (i == 0 && j == 0)
                {
                    continue;
                }

                if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
                {
                    continue;
                }

                if (closedList[x][y])
                {
                    continue;
                }

                if (map[x][y] == 'x')
                {
                    continue;
                }

                if (!openList[x][y])
                {
                    struct node* newNode = (struct node*)malloc(sizeof(struct node));
                    newNode->x = x;
                    newNode->y = y;
                    nodeList[x][y] = newNode;
                    numNodes++;
                    updateNode(current, newNode);
                    openList[x][y] = true;
                }
                else
                {
                    struct node* existingNode = nodeList[x][y];
                    int tempG = current->g + 1;
                    if (tempG < existingNode->g)
                    {
                        updateNode(current, existingNode);
                    }
                }
            }
        }
    }

    int pathLength = 0;
    struct node* current = endNode;
    while (current != startNode)
    {
        pathLength++;
        current = current->parent;
    }

    char* path = (char*)malloc(pathLength + 1);
    current = endNode;
    for (int i = pathLength - 1; i >= 0; i--)
    {
        if (current->parent->x == current->x + 1 && current->parent->y == current->y)
        {
            path[i] = 'D';
        }
        else if (current->parent->x == current->x - 1 && current->parent->y == current->y)
        {
            path[i] = 'U';
        }
        else if (current->parent->x == current->x && current->parent->y == current->y + 1)
        {
            path[i] = 'R';
        }
        else if (current->parent->x == current->x && current->parent->y == current->y - 1)
        {
            path[i] = 'L';
        }

        current = current->parent;
    }
    path[pathLength] = '\0';

    printf("The shortest path is: %s", path);

    return 0;
}
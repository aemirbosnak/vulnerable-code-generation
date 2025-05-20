//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10
#define INF 999

struct node
{
    int x, y, f, g, h;
    struct node *parent;
};

int heuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int row, int col, int x, int y)
{
    return (x >= 0 && x < row && y >= 0 && y < col);
}

bool isDestination(int x, int y, struct node *dest)
{
        return (x == dest->x && y == dest->y);
}

void tracePath(struct node *dest)
{
    if(dest->parent == NULL)
    {
        return;
    }

    tracePath(dest->parent);
    printf("(%d,%d) ", dest->x, dest->y);
}

void AStar(int grid[][COL], struct node *src, struct node *dest)
{
    bool closedList[ROW][COL];
    memset(closedList, false, sizeof(closedList));
    struct node *arr[ROW * COL];

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COL; j++)
        {
            arr[i * COL + j] = (struct node *)malloc(sizeof(struct node));
            arr[i * COL + j]->x = i;
            arr[i * COL + j]->y = j;
            arr[i * COL + j]->f = INF;
            arr[i * COL + j]->g = INF;
            arr[i * COL + j]->h = INF;
            arr[i * COL + j]->parent = NULL;
        }
    }

    int x = src->x;
    int y = src->y;
    arr[x * COL + y]->f = 0;
    arr[x * COL + y]->g = 0;
    arr[x * COL + y]->h = 0;
    arr[x * COL + y]->parent = arr[x * COL + y];

    int openListSize = ROW * COL;
    while(openListSize--)
    {
        int minIndex = 0;
        for(int i = 0; i < ROW * COL; i++)
        {
            if(arr[i]->f < arr[minIndex]->f)
            {
                minIndex = i;
            }
        }

        struct node *cur = arr[minIndex];
        int x = cur->x;
        int y = cur->y;
        closedList[x][y] = true;

        if(isDestination(x, y, dest))
        {
            printf("Path found: ");
            tracePath(dest);
            printf("\n");
            return;
        }

        if(isValid(ROW, COL, x - 1, y) == true && closedList[x - 1][y] == false && grid[x - 1][y] != INF)
        {
            int gNew = cur->g + grid[x - 1][y];
            if(gNew < arr[(x - 1) * COL + y]->g)
            {
                arr[(x - 1) * COL + y]->g = gNew;
                arr[(x - 1) * COL + y]->h = heuristic(x - 1, y, dest->x, dest->y);
                arr[(x - 1) * COL + y]->f = gNew + arr[(x - 1) * COL + y]->h;
                arr[(x - 1) * COL + y]->parent = cur;
            }
        }

        if(isValid(ROW, COL, x + 1, y) == true && closedList[x + 1][y] == false && grid[x + 1][y] != INF)
        {
            int gNew = cur->g + grid[x + 1][y];
            if(gNew < arr[(x + 1) * COL + y]->g)
            {
                arr[(x + 1) * COL + y]->g = gNew;
                arr[(x + 1) * COL + y]->h = heuristic(x + 1, y, dest->x, dest->y);
                arr[(x + 1) * COL + y]->f = gNew + arr[(x + 1) * COL + y]->h;
                arr[(x + 1) * COL + y]->parent = cur;
            }
        }

        if(isValid(ROW, COL, x, y - 1) == true && closedList[x][y - 1] == false && grid[x][y - 1] != INF)
        {
            int gNew = cur->g + grid[x][y - 1];
            if(gNew < arr[x * COL + y - 1]->g)
            {
                arr[x * COL + y - 1]->g = gNew;
                arr[x * COL + y - 1]->h = heuristic(x, y - 1, dest->x, dest->y);
                arr[x * COL + y - 1]->f = gNew + arr[x * COL + y - 1]->h;
                arr[x * COL + y- 1]->parent = cur;
            }
        }

        if(isValid(ROW, COL, x, y + 1) == true && closedList[x][y + 1] == false && grid[x][y + 1] != INF)
        {
            int gNew = cur->g + grid[x][y + 1];
            if(gNew < arr[x * COL + y + 1]->g)
            {
                arr[x * COL + y + 1]->g = gNew;
                arr[x * COL + y + 1]->h = heuristic(x, y + 1, dest->x, dest->y);
                arr[x * COL + y + 1]->f = gNew + arr[x * COL + y + 1]->h;
                arr[x * COL + y + 1]->parent = cur;
            }
        }
    }
}

int main()
{
    int grid[ROW][COL] =
    {
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF},
        { 0, 1, 0, INF, INF, INF, INF, INF, INF, INF}
    };

    struct node *src = (struct node *)malloc(sizeof(struct node));
    src->x = 0;
    src->y = 0;

    struct node *dest = (struct node *)malloc(sizeof(struct node));
    dest->x = 9;
    dest->y = 9;

    AStar(grid, src, dest);

    return 0;
}
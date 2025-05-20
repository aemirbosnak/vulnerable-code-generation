//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

//Definitions for Node, openSet, and closedSet
typedef struct Node
{
    int row, col;
    struct Node* parent;
    double f, g, h;
} Node;

typedef struct openSet
{
    Node* set[ROW * COL];
    int count;
} openSet;

typedef struct closedSet
{
    Node* set[ROW * COL];
    int count;
} closedSet;

//Functions for A* Pathfinding Algorithm
void addNode(openSet* set, Node* node)
{
    set->set[set->count++] = node;
}

void deleteNode(openSet* set, Node* node)
{
    for (int i = 0; i < set->count; i++)
    {
        if (set->set[i] == node)
        {
            set->set[i] = set->set[set->count - 1];
            set->count--;
            return;
        }
    }
}

Node* getNodeWithLowestF(openSet* set)
{
    Node* lowestNode = set->set[0];
    for (int i = 0; i < set->count; i++)
    {
        if (set->set[i]->f < lowestNode->f)
        {
            lowestNode = set->set[i];
        }
    }
    return lowestNode;
}

bool isInClosedSet(closedSet* set, Node* node)
{
    for (int i = 0; i < set->count; i++)
    {
        if (set->set[i] == node)
        {
            return true;
        }
    }
    return false;
}

bool isInOpenSet(openSet* set, Node* node)
{
    for (int i = 0; i < set->count; i++)
    {
        if (set->set[i] == node)
        {
            return true;
        }
    }
    return false;
}

Node* createNode(int row, int col)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->parent = NULL;
    node->f = node->g = node->h = 0;
    return node;
}

void calculatePath(Node* start, Node* end, int (*grid)[COL])
{
    openSet open;
    closedSet closed;
    open.count = 0;
    closed.count = 0;

    addNode(&open, start);

    while (open.count > 0)
    {
        Node* current = getNodeWithLowestF(&open);
        deleteNode(&open, current);
        addNode(&closed, current);

        if (current == end)
        {
            Node* temp = end;
            while (temp->parent != NULL)
            {
                printf("(%d, %d) -> ", temp->row, temp->col);
                temp = temp->parent;
            }
            printf("(%d, %d)", start->row, start->col);
            return;
        }

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newRow = current->row + i;
                int newCol = current->col + j;

                if (newRow >= 0 && newRow < ROW && newCol >= 0 && newCol < COL && !(i == 0 && j == 0))
                {
                    if (grid[newRow][newCol] == 0)
                    {
                        Node* child = createNode(newRow, newCol);
                        double tentative_g = current->g + sqrt(i*i + j*j);
                        double tentative_h = sqrt((newRow - end->row)*(newRow - end->row) + (newCol - end->col)*(newCol - end->col));
                        double tentative_f = tentative_g + tentative_h;

                        if (isInClosedSet(&closed, child))
                        {
                            continue;
                        }

                        if (!isInOpenSet(&open, child))
                        {
                            child->g = tentative_g;
                            child->h = tentative_h;
                            child->f = tentative_f;
                            child->parent = current;
                            addNode(&open, child);
                        }
                        else if (tentative_f < child->f)
                        {
                            child->g = tentative_g;
                            child->h = tentative_h;
                            child->f = tentative_f;
                            child->parent = current;
                        }
                    }
                }
            }
        }
    }
    printf("No path found.");
}

int main()
{
    int grid[ROW][COL] = 
    {
        { 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 0, 0, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
        { 0, 0, 1, 1, 1, 0, 1, 0, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 0, 1, 0 }
    };

    Node* start = createNode(0, 0);
    Node* end = createNode(9, 9);

    calculatePath(start, end, grid);

    return 0;
}
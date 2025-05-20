//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

struct Node 
{
    int row, col, f, g, h;
    struct Node *parent;
};

int grid[ROW][COL] = 
{ 
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}
};

bool is_valid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL);
}

bool is_obstacle(int row, int col)
{
    return grid[row][col] == 0;
}

bool is_destination(int row, int col, struct Node *dest)
{
    return (row == dest->row) && (col == dest->col);
}

int h_value(int row, int col, struct Node *dest)
{
    return abs(row - dest->row) + abs(col - dest->col);
}

void print_path(struct Node *node)
{
    if (node == NULL)
        return;

    print_path(node->parent);
    printf("(%d, %d) -> ", node->row, node->col);
}

void A_star(struct Node *start, struct Node *dest)
{
    if (!is_valid(start->row, start->col))
    {
        printf("Invalid Start Position.\n");
        return;
    }

    if (!is_valid(dest->row, dest->col))
    {
        printf("Invalid Destination Position.\n");
        return;
    }

    if (is_obstacle(start->row, start->col) || is_obstacle(dest->row, dest->col))
    {
        printf("Start or Destination is an obstacle.\n");
        return;
    }

    if (is_destination(start->row, start->col, dest))
    {
        printf("Already at the Destination.\n");
        return;
    }

    bool closed_list[ROW][COL];
    for (int i = 0; i < ROW; i++)
        for (int j = 0; j < COL; j++)
            closed_list[i][j] = false;

    struct Node *node = NULL;
    node = (struct Node*) malloc(sizeof(struct Node));
    node->row = start->row;
    node->col = start->col;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;

    // Create two lists open and close
    // Add the starting node to open list
    // To be evaluated nodes needs to be added to open list
    struct Node *open_list = NULL, *closed_list1 = NULL;
    node->f = node->g + h_value(node->row, node->col, dest);
    open_list = node;

    // Loop until destination found or OPEN list is empty
    while (open_list != NULL)
    {
        struct Node *current = open_list;
        // Loop through all nodes in open list and find one with lowest F value
        for (struct Node *temp = open_list; temp != NULL; temp = temp->parent)
        {
            if (temp->f < current->f)
                current = temp;
        }

        // Remove node with lowest F value from open list and add to closed list
        open_list = current->parent;
        current->parent = closed_list1;
        closed_list1 = current;

        // If the destination node is reached
        if (is_destination(current->row, current->col, dest))
        {
            printf("Path Found: ");
            print_path(current);
            printf("\n");
            return;
        }

        int succ_row[4] = {-1, 0, 1, 0};
        int succ_col[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int row = current->row + succ_row[i];
            int col = current->col + succ_col[i];

            if (is_valid(row, col))
            {
                if (is_destination(row, col, dest))
                {
                    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
                    node->row = row;
                    node->col = col;
                    node->f = current->f + 1;
                    node->g = node->f;
                    node->h = 0;
                    node->parent = closed_list1;
                    printf("Path Found: ");
                    print_path(node);
                    printf("(%d, %d)\n", dest->row, dest->col);
                    return;
                }

                else if (!is_obstacle(row, col) && !closed_list[row][col])
                {
                    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
                    node->row = row;
                    node->col = col;
                    node->parent = closed_list1;
                    node->g = current->g + 1;
                    node->h = h_value(row, col, dest);
                    node->f = node->g + node->h;

                    // Add to open list if not already present
                    for (struct Node *temp = open_list; temp != NULL; temp = temp->parent)
                    {
                        if (temp->row == node->row && temp->col == node->col && temp->f < node->f)
                        {
                            node = NULL;
                            break;
                        }
                    }

                    if (node != NULL)
                        open_list = node;
                }
            }
        }
    }

    printf("Destination not found.\n");
}

int main()
{
    struct Node *start = (struct Node*) malloc(sizeof(struct Node));
    start->row = 0;
    start->col = 0;
    start->parent = NULL;

    struct Node *dest = (struct Node*) malloc(sizeof(struct Node));
    dest->row = 4;
    dest->col = 4;
    dest->parent = NULL;

    A_star(start, dest);
    return 0;
}
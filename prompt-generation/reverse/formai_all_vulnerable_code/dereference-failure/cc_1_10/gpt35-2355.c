//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 10
#define COL 10

int heuristic_function(int row, int col, int goal_row, int goal_col)
{
    return abs(row - goal_row) + abs(col - goal_col);
}

typedef struct node {
    int row, col;
    int f, g, h;
    struct node* parent;
} node;

node* create_node(int row, int col, int g, int h, node* parent)
{
    node* n = (node*)malloc(sizeof(node));
    n->row = row;
    n->col = col;
    n->g = g;
    n->h = h;
    n->f = g + h;
    n->parent = parent;

    return n;
}

void print_path(node* end_node)
{
    if (end_node == NULL) {
        return;
    }

    print_path(end_node->parent);
    printf("(%d, %d) ", end_node->row, end_node->col);
}

int main()
{
    // Define the start and goal nodes
    node* start = create_node(0, 0, 0, 0, NULL);
    node* goal = create_node(ROW - 1, COL - 1, 0, 0, NULL);

    // Define the obstacles
    bool obstacles[ROW][COL] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // Initialize the open and closed lists
    node* open_list[ROW * COL] = { NULL };
    node* closed_list[ROW * COL] = { NULL };

    // Add the start node to the open list
    open_list[0] = start;
    int open_list_size = 1;

    while (open_list_size > 0) {
        // Find the node with the lowest f score in the open list
        node* current_node = open_list[0];
        int current_index = 0;
        for (int i = 1; i < open_list_size; i++) {
            if (open_list[i]->f < current_node->f) {
                current_node = open_list[i];
                current_index = i;
            }
        }

        // Remove the current node from the open list
        open_list[current_index] = open_list[open_list_size - 1];
        open_list_size--;

        // Add the current node to the closed list
        closed_list[current_index] = current_node;

        // Check if the current node is the goal node
        if (current_node->row == goal->row && current_node->col == goal->col) {
            printf("Path found: ");
            print_path(current_node);
            printf("\n");
            return 0;
        }

        // Generate the successors of the current node
        int successor_count = 0;
        node* successors[4] = { NULL };
        int dr[4] = { -1, 0, 1, 0 };
        int dc[4] = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; i++) {
            int successor_row = current_node->row + dr[i];
            int successor_col = current_node->col + dc[i];
            if (successor_row >= 0 && successor_row < ROW &&
                successor_col >= 0 && successor_col < COL &&
                !obstacles[successor_row][successor_col]) {
                int successor_g = current_node->g + 1;
                int successor_h = heuristic_function(successor_row, successor_col, goal->row, goal->col);
                node* successor = create_node(successor_row, successor_col, successor_g, successor_h, current_node);
                successors[successor_count++] = successor;
            }
        }

        // Add the successors to the open list
        for (int i = 0; i < successor_count; i++) {
            node* successor = successors[i];

            // Check if the successor is already in the closed list
            bool in_closed_list = false;
            for (int j = 0; j < ROW * COL; j++) {
                node* closed_node = closed_list[j];
                if (closed_node != NULL && successor->row == closed_node->row &&
                    successor->col == closed_node->col) {
                    in_closed_list = true;
                    break;
                }
            }
            if (in_closed_list) {
                continue;
            }

            // Check if the successor is already in the open list
            bool in_open_list = false;
            for (int j = 0; j < open_list_size; j++) {
                node* open_node = open_list[j];
                if (open_node->row == successor->row && open_node->col == successor->col) {
                    in_open_list = true;
                    break;
                }
            }
            if (!in_open_list) {
                open_list[open_list_size++] = successor;
            }
        }
    }

    printf("Path not found.\n");
    return 0;
}
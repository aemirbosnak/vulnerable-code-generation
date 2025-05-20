//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROW 5
#define COL 5

// Creating a structure to hold the necessary information for each node in the grid.
struct node {
    int row;
    int col;
    int g_cost;
    int h_cost;
    int f_cost;
    bool is_wall;
    bool is_visited;
    struct node* parent;
};

struct node* grid[ROW][COL];
struct node* open_set[ROW * COL];
struct node* closed_set[ROW * COL];
struct node* start_node;
struct node* end_node;

// Function to initialize the grid with nodes.
void init_grid() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            struct node* nd = malloc(sizeof(struct node));
            nd->row = i;
            nd->col = j;
            nd->g_cost = 0;
            nd->h_cost = 0;
            nd->f_cost = 0;
            nd->is_wall = false;
            nd->is_visited = false;
            nd->parent = NULL;
            grid[i][j] = nd;
        }
    }
}

// Function to create walls in the grid.
void create_walls() {
    for (int i = 1; i < ROW - 1; i++) {
        grid[i][2]->is_wall = true;
    }
}

// Function to calculate the heuristic cost (h cost) of a node.
int calculate_h_cost(struct node* current_node) {
    int h_cost = abs(current_node->row - end_node->row) + abs(current_node->col - end_node->col);
    return h_cost;
}

// Function to calculate the total cost (f cost) of a node.
void calculate_f_cost(struct node* current_node) {
    current_node->f_cost = current_node->g_cost + current_node->h_cost;
}

// Function to get the adjacent nodes of a given node.
struct node** get_adjacent_nodes(struct node* current_node, int* count) {
    int row = current_node->row;
    int col = current_node->col;
    static struct node* adj_nodes[4];
    *count = 0;

    if (row > 0 && !grid[row - 1][col]->is_wall) {
        adj_nodes[*count] = grid[row - 1][col];
        (*count)++;
    }

    if (col > 0 && !grid[row][col - 1]->is_wall) {
        adj_nodes[*count] = grid[row][col - 1];
        (*count)++;
    }

    if (row < ROW - 1 && !grid[row + 1][col]->is_wall) {
        adj_nodes[*count] = grid[row + 1][col];
        (*count)++;
    }

    if (col < COL - 1 && !grid[row][col + 1]->is_wall) {
        adj_nodes[*count] = grid[row][col + 1];
        (*count)++;
    }

    return adj_nodes;
}

// Function to check if a node is in the closed set.
bool is_in_closed_set(struct node* current_node) {
    for (int i = 0; i < ROW * COL; i++) {
        if (closed_set[i] == current_node) {
            return true;
        }
    }
    return false;
}

// Function to check if a node is in the open set.
bool is_in_open_set(struct node* current_node) {
    for (int i = 0; i < ROW * COL; i++) {
        if (open_set[i] == current_node) {
            return true;
        }
    }
    return false;
}

// Function to get the node with the lowest f cost from the open set.
struct node* get_lowest_f_cost_node() {
    int index = 0;
    int lowest_f_cost = open_set[0]->f_cost;
    for (int i = 1; i < ROW * COL; i++) {
        if (open_set[i]->f_cost < lowest_f_cost) {
            lowest_f_cost = open_set[i]->f_cost;
            index = i;
        }
    }
    struct node* lowest_f_cost_node = open_set[index];
    open_set[index] = NULL;
    return lowest_f_cost_node;
}

// Function to print the grid.
void print_grid() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == start_node) {
                printf("S ");
            } else if (grid[i][j] == end_node) {
                printf("E ");
            } else if (grid[i][j]->is_wall) {
                printf("# ");
            } else if (grid[i][j]->is_visited) {
                printf(". ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// The main A* pathfinding algorithm function.
void a_star_pathfinding() {
    int open_set_count = 0;
    int closed_set_count = 0;

    open_set[open_set_count] = start_node;
    open_set_count++;

    while (open_set_count > 0) {
        struct node* current_node = get_lowest_f_cost_node();

        if (current_node == end_node) {
            // Reached the end node. The path has been found.
            struct node* temp = current_node;

            while (temp->parent != NULL) {
                temp = temp->parent;
                temp->is_visited = true;
            }

            printf("\n");
            print_grid();

            return;
        }

        int adj_count;
        struct node** adj_nodes = get_adjacent_nodes(current_node, &adj_count);

        for (int i = 0; i < adj_count; i++) {
            struct node* adj_node = adj_nodes[i];

            if (is_in_closed_set(adj_node)) {
                // The adjacent node is already in the closed set.
                continue;
            }

            if (!is_in_open_set(adj_node)) {
                // The adjacent node is not in the open set.
                adj_node->g_cost = current_node->g_cost + 1;
                adj_node->h_cost = calculate_h_cost(adj_node);
                calculate_f_cost(adj_node);
                adj_node->parent = current_node;
                open_set[open_set_count] = adj_node;
                open_set_count++;
            } else {
                // The adjacent node is already in the open set. Check if it has a better g cost.
                int temp_g_cost = current_node->g_cost + 1;

                if (temp_g_cost < adj_node->g_cost) {
                    adj_node->g_cost = temp_g_cost;
                    calculate_f_cost(adj_node);
                    adj_node->parent = current_node;
                }
            }
        }

        closed_set[closed_set_count] = current_node;
        closed_set_count++;
    }

    // The open set is empty and the end node was not found. No path exists.
    printf("\nNo path exists.\n\n");
}

int main() {
    init_grid();

    start_node = grid[1][1];
    end_node = grid[ROW - 2][COL - 2];

    create_walls();

    printf("\nInitial grid:\n");
    print_grid();

    a_star_pathfinding();

    return 0;
}
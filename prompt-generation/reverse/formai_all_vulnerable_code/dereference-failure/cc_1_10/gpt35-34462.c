//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

#define ROW 10 // row size of the grid
#define COL 20 // column size of the grid

// node struct used to represent each cell in the grid
typedef struct node {
    int row;
    int col;
    int f; // f = g + h
    int g; // cost from start node to current node
    int h; // estimated cost from current node to end node
    struct node *parent; // parent of the current node
    int is_wall; // flag to indicate if the current node is a wall or not
    int is_end; // flag to indicate if the current node is the end point or not
} Node;

// calculate the Manhattan distance between two nodes
int calculate_h(int start_row, int start_col, int end_row, int end_col) {
    return abs(start_row - end_row) + abs(start_col - end_col);
}

// check if the input row and column are valid or not
int is_valid(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

// get the node with the lowest f value from a list of nodes
Node *get_lowest_f_node(Node **open_list, int open_list_size) {
    Node *lowest_f_node = open_list[0];
    for (int i = 1; i < open_list_size; i++) {
        if (open_list[i]->f < lowest_f_node->f) {
            lowest_f_node = open_list[i];
        }
    }
    return lowest_f_node;
}

// check if a node is in the closed list
int is_in_closed_list(Node **closed_list, int closed_list_size, Node *current_node) {
    for (int i = 0; i < closed_list_size; i++) {
        if (closed_list[i]->row == current_node->row && closed_list[i]->col == current_node->col) {
            return 1;
        }
    }
    return 0;
}

// check if a node is in the open list
int is_in_open_list(Node **open_list, int open_list_size, Node *current_node) {
    for (int i = 0; i < open_list_size; i++) {
        if (open_list[i]->row == current_node->row && open_list[i]->col == current_node->col) {
            return 1;
        }
    }
    return 0;
}

// update the g and f values of the node
void update_node(Node *current_node, Node *parent_node, int end_row, int end_col) {
    current_node->parent = parent_node;
    current_node->g = parent_node->g + 1;
    current_node->h = calculate_h(current_node->row, current_node->col, end_row, end_col);
    current_node->f = current_node->g + current_node->h;
}

// generate the path from start node to end node
void generate_path(Node *end_node) {
    Node *current_node = end_node;
    printf("Path: ");
    while (current_node) {
        printf("(%d,%d) ", current_node->row, current_node->col);
        current_node = current_node->parent;
    }
    printf("\n");
}

// A* pathfinding algorithm
void a_star(Node **grid, Node *start, Node *end) {
    Node *open_list[ROW * COL];
    Node *closed_list[ROW * COL];
    int open_list_size = 0;
    int closed_list_size = 0;
    open_list[open_list_size++] = start;
    while (open_list_size > 0) {
        Node *current_node = get_lowest_f_node(open_list, open_list_size);
        if (current_node == end) {
            generate_path(current_node);
            return;
        }
        open_list_size--;
        closed_list[closed_list_size++] = current_node;
        // checking all the adjacent cells
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int new_row = current_node->row + i;
                int new_col = current_node->col + j;
                if ((i == 0 && j == 0) || !is_valid(new_row, new_col)) {
                    continue;
                }
                Node *neighbor_node = &grid[new_row][new_col];
                if (neighbor_node->is_wall || is_in_closed_list(closed_list, closed_list_size, neighbor_node)) {
                    continue;
                }
                int tentative_g_score = current_node->g + 1; // assuming the distance between each node is 1
                if (!is_in_open_list(open_list, open_list_size, neighbor_node) || tentative_g_score < neighbor_node->g) {
                    update_node(neighbor_node, current_node, end->row, end->col);
                    if (!is_in_open_list(open_list, open_list_size, neighbor_node)) {
                        open_list[open_list_size++] = neighbor_node;
                    }
                }
            }
        }
    }
}

int main() {
    Node **grid = malloc(ROW * sizeof(Node *));
    for (int i = 0; i < ROW; i++) {
        grid[i] = malloc(COL * sizeof(Node));
        for (int j = 0; j < COL; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].f = 0;
            grid[i][j].g = 0;
            grid[i][j].h = 0;
            grid[i][j].parent = NULL;
            grid[i][j].is_wall = 0;
            grid[i][j].is_end = 0;
        }
    }
    // setting up some walls
    grid[2][3].is_wall = 1;
    grid[3][3].is_wall = 1;
    grid[4][3].is_wall = 1;
    grid[5][3].is_wall = 1;
    grid[6][3].is_wall = 1;
    grid[7][3].is_wall = 1;
    // setting up the start node
    Node *start = &grid[0][0];
    start->g = 0;
    start->h = calculate_h(start->row, start->col, ROW - 1, COL - 1);
    start->f = start->g + start->h;
    // setting up the end node
    Node *end = &grid[ROW - 1][COL - 1];
    end->is_end = 1;
    // running the A* algorithm
    a_star(grid, start, end);
    // freeing the memory
    for (int i = 0; i < ROW; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
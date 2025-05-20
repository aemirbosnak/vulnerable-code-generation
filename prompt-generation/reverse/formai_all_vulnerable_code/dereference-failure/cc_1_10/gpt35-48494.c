//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int row;
    int col;
    int g_score;
    int f_score;
    struct node *parent;
} Node;

int heuristic_distance(Node *curr_node, Node *target_node) {
    // Manhattan distance
    int distance = abs(curr_node->row - target_node->row) + abs(curr_node->col - target_node->col);
    return distance;
}

Node *lowest_f_score_node(Node **open_set, int open_set_size) {
    // Find the node in open_set with the lowest f_score
    Node *lowest_f_score_node = open_set[0];
    for (int i = 1; i < open_set_size; i++) {
        if (open_set[i]->f_score < lowest_f_score_node->f_score) {
            lowest_f_score_node = open_set[i];
        }
    }
    return lowest_f_score_node;
}

Node **neighbors(Node **grid, int rows, int cols, Node *curr_node) {
    // Find neighbors of curr_node in the grid
    Node **neighbors = malloc(sizeof(Node*) * 4);
    int count = 0;
    // Check North
    int north_row = curr_node->row - 1;
    int north_col = curr_node->col;
    if (north_row >= 0 && grid[north_row][north_col].g_score != -1) {
        neighbors[count] = &grid[north_row][north_col];
        count++;
    }
    // Check East
    int east_row = curr_node->row;
    int east_col = curr_node->col + 1;
    if (east_col < cols && grid[east_row][east_col].g_score != -1) {
        neighbors[count] = &grid[east_row][east_col];
        count++;
    }
    // Check South
    int south_row = curr_node->row + 1;
    int south_col = curr_node->col;
    if (south_row < rows && grid[south_row][south_col].g_score != -1) {
        neighbors[count] = &grid[south_row][south_col];
        count++;
    }
    // Check West
    int west_row = curr_node->row;
    int west_col = curr_node->col - 1;
    if (west_col >= 0 && grid[west_row][west_col].g_score != -1) {
        neighbors[count] = &grid[west_row][west_col];
        count++;
    }
    return neighbors;
}

void reconstruct_path(Node *start_node, Node *end_node) {
    // Reconstruct the path from start_node to end_node
    Node *curr_node = end_node;
    while (curr_node != start_node) {
        printf("(%d,%d) <- ", curr_node->row, curr_node->col);
        curr_node = curr_node->parent;
    }
    printf("(%d,%d)\n", start_node->row, start_node->col);
}

void A_star_pathfinding(Node **grid, int rows, int cols, Node *start_node, Node *end_node) {
    Node **open_set = malloc(sizeof(Node*) * rows * cols);
    int open_set_size = 0;
    Node **closed_set = malloc(sizeof(Node*) * rows * cols);
    int closed_set_size = 0;
    // Add start_node to open_set
    start_node->g_score = 0;
    start_node->f_score = start_node->g_score + heuristic_distance(start_node, end_node);
    open_set[open_set_size] = start_node;
    open_set_size++;
    // Loop until end_node is found or open_set is empty
    while (open_set_size > 0) {
        Node *curr_node = lowest_f_score_node(open_set, open_set_size);
        // If curr_node == end_node, path has been found
        if (curr_node == end_node) {
            reconstruct_path(start_node, end_node);
            break;
        }
        // Remove curr_node from open_set
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i] == curr_node) {
                open_set[i] = open_set[open_set_size-1];
                open_set_size--;
                break;
            }
        }
        // Add curr_node to closed_set
        closed_set[closed_set_size] = curr_node;
        closed_set_size++;
        // Find curr_node's neighbors
        Node **curr_node_neighbors = neighbors(grid, rows, cols, curr_node);
        for (int i = 0; i < 4; i++) {
            if (curr_node_neighbors[i] == NULL) {
                continue;
            }
            int tentative_g_score = curr_node->g_score + 1;
            int in_closed_set = 0;
            for (int j = 0; j < closed_set_size; j++) {
                if (curr_node_neighbors[i] == closed_set[j]) {
                    in_closed_set = 1;
                    break;
                }
            }
            if (in_closed_set) {
                continue;
            }
            int in_open_set = 0;
            for (int j = 0; j < open_set_size; j++) {
                if (curr_node_neighbors[i] == open_set[j]) {
                    in_open_set = 1;
                    break;
                }
            }
            if (!in_open_set) {
                open_set[open_set_size] = curr_node_neighbors[i];
                open_set_size++;
            } else if (tentative_g_score >= curr_node_neighbors[i]->g_score) {
                continue;
            }
            curr_node_neighbors[i]->parent = curr_node;
            curr_node_neighbors[i]->g_score = tentative_g_score;
            curr_node_neighbors[i]->f_score = curr_node_neighbors[i]->g_score + heuristic_distance(curr_node_neighbors[i], end_node);
        }
    }
}

int main() {
    // Create a 2D array to represent the grid
    int rows = 5;
    int cols = 5;
    Node **grid = malloc(sizeof(Node*) * rows);
    for (int i = 0; i < rows; i++) {
        grid[i] = malloc(sizeof(Node) * cols);
        for (int j = 0; j < cols; j++) {
            grid[i][j].row = i;
            grid[i][j].col = j;
            grid[i][j].g_score = -1;
            grid[i][j].f_score = -1;
            grid[i][j].parent = NULL;
        }
    }
    // Set some obstacle nodes
    grid[1][2].g_score = -1;
    grid[2][2].g_score = -1;
    // Find a path from (0,0) to (4,4) using A* pathfinding algorithm
    Node *start_node = &grid[0][0];
    Node *end_node = &grid[4][4];
    A_star_pathfinding(grid, rows, cols, start_node, end_node);
    // Free memory
    for (int i = 0; i < rows; i++) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
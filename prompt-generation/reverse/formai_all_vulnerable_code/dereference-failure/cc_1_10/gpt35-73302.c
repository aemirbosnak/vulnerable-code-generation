//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10
#define WALL '#'
#define START 'S'
#define END 'E'
#define PATH '.'

// Define a structure to represent a node in the grid
struct node {
    int row, col, f_score, g_score, h_score;
    bool visited, wall;
    struct node *parent;
};

// Define a function to initialize a node with given coordinates and check if it is a wall
struct node *create_node(int row, int col, bool is_wall) {
    struct node *n = calloc(1, sizeof(struct node));
    n->row = row;
    n->col = col;
    n->visited = false;
    n->wall = is_wall;
    return n;
}

// Get the Manhattan distance between two nodes
int manhattan_distance(struct node *a, struct node *b) {
    return abs(a->row - b->row) + abs(a->col - b->col);
}

// Get the euclidean distance between two nodes
int euclidean_distance(struct node *a, struct node *b) {
    return sqrt(pow(a->row - b->row, 2) + pow(a->col - b->col, 2));
}

// Define a function to print the grid
void print_grid(struct node **grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j].wall) {
                printf("%c", WALL);
            } else {
                printf("%c", PATH);
            }
        }
        printf("\n");
    }
}

// Define the main function
int main() {
    // Create the grid
    struct node **grid = calloc(ROWS, sizeof(struct node *));
    for (int i = 0; i < ROWS; i++) {
        grid[i] = calloc(COLS, sizeof(struct node));
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = *create_node(i, j, false); //Initialize nodes
        }
    }

    // Set start and end points
    struct node *start = &grid[0][0];
    grid[0][0].visited = true;
    grid[0][0].h_score = manhattan_distance(start, &grid[ROWS - 1][COLS - 1]);
    grid[0][0].g_score = 0;
    struct node *end = &grid[ROWS - 1][COLS - 1];
    end->wall = false;

    // Create the open and closed sets
    struct node **open_set = calloc(ROWS * COLS, sizeof(struct node *));
    int open_set_size = 0;
    struct node **closed_set = calloc(ROWS * COLS, sizeof(struct node *));
    int closed_set_size = 0;

    // Add the start node to the open set
    open_set[open_set_size++] = start;

    // Define some variables for the loop
    struct node *current;
    int tentative_g_score;

    // Start the A* algorithm loop
    while (open_set_size > 0) {
        // Select the node with the lowest f_score in the open set
        int min_f_score = 999999;
        int min_index = -1;
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i]->f_score < min_f_score) {
                min_f_score = open_set[i]->f_score;
                min_index = i;
            }
        }
        current = open_set[min_index];

        // If we have reached the goal, reconstruct the path and print the grid
        if (current == end) {
            while (current != NULL) {
                if (current->parent != NULL) {
                    current = current->parent;
                    current->visited = true;
                } else {
                    break;
                }
            }
            print_grid(grid);
            return 0;
        }

        // Remove the current node from the open set and add it to the closed set
        open_set[min_index] = open_set[--open_set_size];
        closed_set[closed_set_size++] = current;

        // Check the neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) { // Skip the current node
                    continue;
                }

                // Get the neighbor node
                int neighbor_row = current->row + i;
                int neighbor_col = current->col + j;
                if (neighbor_row < 0 || neighbor_row >= ROWS || neighbor_col < 0 || neighbor_col >= COLS) {
                    // Neighbor is out of bounds, skip it
                    continue;
                }
                struct node *neighbor = &grid[neighbor_row][neighbor_col];
                if (neighbor->wall) {
                    // Neighbor is a wall, skip it
                    continue;
                }

                // Calculate the tentative_g_score and check if the neighbor is in the closed set
                tentative_g_score = current->g_score + euclidean_distance(current, neighbor);
                bool neighbor_in_closed_set = false;
                for (int k = 0; k < closed_set_size; k++) {
                    if (closed_set[k] == neighbor) {
                        neighbor_in_closed_set = true;
                        break;
                    }
                }
                if (tentative_g_score >= neighbor->g_score && neighbor_in_closed_set) {
                    // The neighbor is worse than the current path or it's already in the closed set, skip it
                    continue;
                }

                // Calculate the f_score of the neighbor and update its values
                neighbor->g_score = tentative_g_score;
                neighbor->h_score = manhattan_distance(neighbor, end);
                neighbor->f_score = neighbor->g_score + neighbor->h_score;
                neighbor->parent = current;

                // Check if the neighbor is already in the open set
                bool neighbor_in_open_set = false;
                int neighbor_index;
                for (int k = 0; k < open_set_size; k++) {
                    if (open_set[k] == neighbor) {
                        neighbor_in_open_set = true;
                        neighbor_index = k;
                        break;
                    }
                }
                if (!neighbor_in_open_set) {
                    // Add the neighbor to the open set
                    open_set[open_set_size++] = neighbor;
                } else {
                    // Update the neighbor's f_score
                    if (neighbor->f_score < open_set[neighbor_index]->f_score) {
                        open_set[neighbor_index] = neighbor;
                    }
                }
            }
        }
    }

    // No path was found
    printf("No path found.\n");

    return 0;
}
//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

// Node struct to represent each cell in the grid
typedef struct node {
    int row;
    int col;
    int f_score;
    int g_score;
    bool is_obstacle;
    struct node* parent;
} Node;

// Function prototypes
void print_path(Node* end_node);
void generate_obstacles(Node* grid[ROWS][COLS]);
int manhattan_distance(Node* node1, Node* node2);
Node* get_lowest_f_score(Node** open_set);
bool is_valid_node(Node* node);
bool is_in_set(Node** set, Node* node);
void reset_grid(Node* grid[ROWS][COLS]);

int main() {
    // Create the grid
    Node* grid[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = malloc(sizeof(Node));
            grid[i][j]->row = i;
            grid[i][j]->col = j;
            grid[i][j]->f_score = 0;
            grid[i][j]->g_score = 0;
            grid[i][j]->is_obstacle = false;
            grid[i][j]->parent = NULL;
        }
    }

    // Generate some random obstacles in the grid
    generate_obstacles(grid);

    // Set the start and end nodes
    Node* start_node = grid[0][0];
    Node* end_node = grid[ROWS-1][COLS-1];

    // Set the g_score of the start node to 0
    start_node->g_score = 0;

    // Create the open and closed sets
    Node* open_set[ROWS*COLS];
    Node* closed_set[ROWS*COLS];

    // Add the start node to the open set
    open_set[0] = start_node;

    // Main A* algorithm loop
    while (open_set[0] != NULL) {
        // Get the node with the lowest f_score from the open set
        Node* current_node = get_lowest_f_score(open_set);

        // If the current node is the end node, print the path and exit
        if (current_node == end_node) {
            print_path(end_node);
            reset_grid(grid);
            return 0;
        }

        // Remove the current node from the open set and add it to the closed set
        for (int i = 0; i < ROWS*COLS; i++) {
            if (open_set[i] == current_node) {
                open_set[i] = NULL;
                break;
            }
        }
        for (int i = 0; i < ROWS*COLS; i++) {
            if (closed_set[i] == NULL) {
                closed_set[i] = current_node;
                break;
            }
        }

        // Check the neighbors of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;  // Skip the current node
                int neighbor_row = current_node->row + i;
                int neighbor_col = current_node->col + j;
                if (neighbor_row < 0 || neighbor_row >= ROWS || neighbor_col < 0 || neighbor_col >= COLS) {
                    continue;  // Skip nodes outside the grid
                }
                Node* neighbor_node = grid[neighbor_row][neighbor_col];
                if (neighbor_node->is_obstacle || is_in_set(closed_set, neighbor_node)) {
                    continue;  // Skip nodes that are obstacles or are already in the closed set
                }
                int tentative_g_score = current_node->g_score + 1;  // Assuming all edges have equal weight
                if (!is_in_set(open_set, neighbor_node) || tentative_g_score < neighbor_node->g_score) {
                    neighbor_node->parent = current_node;
                    neighbor_node->g_score = tentative_g_score;
                    neighbor_node->f_score = tentative_g_score + manhattan_distance(neighbor_node, end_node);
                    if (!is_in_set(open_set, neighbor_node)) {
                        for (int k = 0; k < ROWS*COLS; k++) {
                            if (open_set[k] == NULL) {
                                open_set[k] = neighbor_node;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // If the while loop ends without finding the end node, there is no path
    printf("There is no path from the start node to the end node.\n");
    reset_grid(grid);
    return 0;
}

// Helper function to print the shortest path
void print_path(Node* end_node) {
    Node* current_node = end_node;
    while (current_node != NULL) {
        printf("(%d,%d)", current_node->row, current_node->col);
        if (current_node->parent != NULL) {
            printf(" -> ");
        }
        current_node = current_node->parent;
    }
    printf("\n");
}

// Helper function to randomly generate obstacles in the grid
void generate_obstacles(Node* grid[ROWS][COLS]) {
    srand(time(0));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int rand_num = rand() % 100;
            if (rand_num < 30) {  // 30% chance to generate an obstacle
                grid[i][j]->is_obstacle = true;
            }
        }
    }
}

// Helper function to calculate the Manhattan distance between two nodes
int manhattan_distance(Node* node1, Node* node2) {
    return abs(node1->row - node2->row) + abs(node1->col - node2->col);
}

// Helper function to get the node with the lowest f_score from the open set
Node* get_lowest_f_score(Node** open_set) {
    Node* lowest_f_node = open_set[0];
    for (int i = 1; i < ROWS*COLS && open_set[i] != NULL; i++) {
        if (open_set[i]->f_score < lowest_f_node->f_score) {
            lowest_f_node = open_set[i];
        }
    }
    return lowest_f_node;
}

// Helper function to check if a node is valid (i.e. inside the grid and not an obstacle)
bool is_valid_node(Node* node) {
    return node->row >= 0 && node->row < ROWS && node->col >= 0 && node->col < COLS && !node->is_obstacle;
}

// Helper function to check if a node is in a set (open or closed)
bool is_in_set(Node** set, Node* node) {
    for (int i = 0; i < ROWS*COLS && set[i] != NULL; i++) {
        if (set[i] == node) {
            return true;
        }
    }
    return false;
}

// Helper function to reset the grid for the next iteration
void reset_grid(Node* grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j]->f_score = 0;
            grid[i][j]->g_score = 0;
            grid[i][j]->parent = NULL;
        }
    }
}
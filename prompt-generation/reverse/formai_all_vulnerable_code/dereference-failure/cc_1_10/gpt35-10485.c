//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

// Structure to represent a node in the grid
struct Node {
    int row, col;
    bool is_wall;
    int f_score, g_score, h_score;
    struct Node* parent;
};

// Matrix to represent the grid
struct Node* grid[ROW][COL];

// Start and end nodes for the path
struct Node* start_node;
struct Node* end_node;

// Function to initialize the grid with nodes
void initialize_grid() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            // Create a new node
            struct Node* node = (struct Node*)malloc(sizeof(struct Node));
            node->row = i;
            node->col = j;
            node->is_wall = false;
            node->f_score = 0;
            node->g_score = 0;
            node->h_score = 0;
            node->parent = NULL;

            // Set start and end nodes
            if(i == 0 && j == 0) {
                start_node = node;
            }
            else if(i == ROW-1 && j == COL-1) {
                end_node = node;
            }

            // Add node to the grid
            grid[i][j] = node;
        }
    }
}

// Function to set the walls in the grid
void set_walls() {
    grid[1][2]->is_wall = true;
    grid[2][2]->is_wall = true;
    grid[2][3]->is_wall = true;
    grid[3][1]->is_wall = true;
    grid[3][4]->is_wall = true;
    grid[4][3]->is_wall = true;
    grid[5][4]->is_wall = true;
    grid[6][3]->is_wall = true;
    grid[7][4]->is_wall = true;
    grid[8][5]->is_wall = true;
}

// Function to calculate the heuristic score of a node
int calculate_h_score(struct Node* node) {
    int dx = abs(node->row - end_node->row);
    int dy = abs(node->col - end_node->col);
    return dx + dy;
}

// Function to check if a node is valid
bool is_valid_node(struct Node* node) {
    return node && !node->is_wall;
}

// Function to get the neighbors of a node
struct Node** get_neighbors(struct Node* node) {
    struct Node** neighbors = (struct Node**)malloc(8 * sizeof(struct Node*));
    int count = 0;

    // Generate all possible neighbors
    for(int i = node->row - 1; i <= node->row + 1; i++) {
        for(int j = node->col - 1; j <= node->col + 1; j++) {
            // Skip the current node
            if(i == node->row && j == node->col) {
                continue;
            }

            // Get node at (i,j) position
            struct Node* neighbor = NULL;
            if(i >= 0 && i < ROW && j >= 0 && j < COL) {
                neighbor = grid[i][j];
            }

            // Add valid neighbor to the list
            if(is_valid_node(neighbor)) {
                neighbors[count++] = neighbor;
            }
        }
    }
    return neighbors;
}

// Function to print the grid
void print_grid() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            char c;
            if(grid[i][j] == start_node) {
                c = 'S';
            }
            else if(grid[i][j] == end_node) {
                c = 'E';
            }
            else if(grid[i][j]->is_wall) {
                c = '#';
            }
            else {
                c = '-';
            }
            printf("%c ", c);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to perform A* pathfinding algorithm
void a_star() {
    // Initialize the open and closed sets
    struct Node* open_set[ROW*COL];
    int open_set_size = 0;

    struct Node* closed_set[ROW*COL];
    int closed_set_size = 0;

    // Add start node to the open set
    open_set[open_set_size++] = start_node;

    // Loop until we find the end node
    while(open_set_size > 0) {
        // Get node with minimum f_score
        int current_index = 0;
        for(int i=0; i<open_set_size; i++) {
            if(open_set[i]->f_score < open_set[current_index]->f_score) {
                current_index = i;
            }
        }
        struct Node* current_node = open_set[current_index];

        // Check if we have found the end node
        if(current_node == end_node) {
            // Reconstruct the path
            printf("Found the path!\n");
            while(current_node != start_node) {
                printf("(%d,%d)\n", current_node->row, current_node->col);
                current_node = current_node->parent;
            }
            printf("(%d,%d)\n", start_node->row, start_node->col);
            return;
        }

        // Remove current node from the open set
        for(int i=current_index; i<open_set_size-1; i++) {
            open_set[i] = open_set[i+1];
        }
        open_set_size--;

        // Add current node to the closed set
        closed_set[closed_set_size++] = current_node;

        // Get neighbors of current node
        struct Node** neighbors = get_neighbors(current_node);

        // Evaluate each neighbor
        for(int i=0; i<8; i++) {
            struct Node* neighbor = neighbors[i];

            // Ignore neighbors in the closed set
            if(neighbor) {
                bool in_closed_set = false;
                for(int j=0; j<closed_set_size; j++) {
                    if(closed_set[j] == neighbor) {
                        in_closed_set = true;
                        break;
                    }
                }
                if(in_closed_set) {
                    continue;
                }
            }

            // Calculate tentative g_score (distance from start node)
            int tentative_g_score = current_node->g_score + 1;

            // Add neighbor to open set if it is not already in it
            bool in_open_set = false;
            for(int j=0; j<open_set_size; j++) {
                if(open_set[j] == neighbor) {
                    in_open_set = true;
                    break;
                }
            }

            if(!in_open_set) {
                open_set[open_set_size++] = neighbor;
                neighbor->h_score = calculate_h_score(neighbor);
            }
            else if(tentative_g_score >= neighbor->g_score) {
                continue;
            }

            // This path is the best until now, record it!
            neighbor->parent = current_node;
            neighbor->g_score = tentative_g_score;
            neighbor->f_score = neighbor->g_score + neighbor->h_score;
        }
    }
}

int main() {
    initialize_grid();
    set_walls();
    print_grid();
    a_star();
    return 0;
}
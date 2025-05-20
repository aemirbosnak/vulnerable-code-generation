//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Define grid size and start/end points
#define ROWS 8
#define COLS 8
#define START_ROW 0
#define START_COL 0
#define END_ROW 7
#define END_COL 7

// Define structure for nodes in grid
struct Node {
    int row;
    int col;
    int f;
    int g;
    int h;
    struct Node* parent;
};

// Define helper functions for node manipulation
void print_nodes(struct Node** path, int len) {
    int i;
    printf("Path: ");
    for (i=0; i<len; i++) {
        printf("(%d,%d) ", path[i]->row, path[i]->col);
    }
    printf("\n");
}
int is_valid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}
int is_end(int row, int col) {
    return row == END_ROW && col == END_COL;
}
int get_h(int row, int col) {
    return abs(row - END_ROW) + abs(col - END_COL);
}

// Define main pathfinding function (A*)
int pathfind(int grid[ROWS][COLS], struct Node** path) {
    // Initialize start and end nodes
    struct Node* start = (struct Node*) malloc(sizeof(struct Node));
    start->row = START_ROW;
    start->col = START_COL;
    start->f = 0;
    start->g = 0;
    start->h = get_h(start->row, start->col);
    start->parent = NULL;
    struct Node* end = (struct Node*) malloc(sizeof(struct Node));
    end->row = END_ROW;
    end->col = END_COL;
    end->f = 0;
    end->g = 0;
    end->h = get_h(end->row, end->col);
    end->parent = NULL;
    
    // Initialize open and closed lists
    struct Node** open = (struct Node**) malloc(ROWS * COLS * sizeof(struct Node*));
    struct Node** closed = (struct Node**) malloc(ROWS * COLS * sizeof(struct Node*));
    int num_open = 0;
    int num_closed = 0;
    
    // Add start node to open list
    open[num_open++] = start;
    
    // Loop through nodes until end is reached or no path is found
    while (num_open > 0) {
        // Find node with lowest f value in open list
        int min_f = open[0]->f;
        int min_i = 0;
        int i;
        for (i=1; i<num_open; i++) {
            if (open[i]->f < min_f) {
                min_f = open[i]->f;
                min_i = i;
            }
        }
        
        // Set current node to lowest f value node
        struct Node* current = open[min_i];
        
        // Remove current node from open list and add to closed list
        open[min_i] = open[--num_open];
        closed[num_closed++] = current;
        
        // Check if current node is end node
        if (is_end(current->row, current->col)) {
            // Build and print path
            int len = 0;
            while (current != NULL) {
                path[len++] = current;
                current = current->parent;
            }
            print_nodes(path, len);
            
            // Free memory and return
            free(start);
            free(end);
            free(open);
            free(closed);
            return 1;
        }
        
        // Loop through neighboring nodes
        int row, col;
        for (row=-1; row<=1; row++) {
            for (col=-1; col<=1; col++) {
                // Skip current node and diagonals
                if (row == 0 && col == 0) continue;
                if (abs(row) == 1 && abs(col) == 1) continue;
                
                // Get neighboring node position
                int neighbor_row = current->row + row;
                int neighbor_col = current->col + col;
                
                // Skip invalid positions, walls, and already closed nodes
                if (!is_valid(neighbor_row, neighbor_col)) continue;
                if (grid[neighbor_row][neighbor_col] == 1) continue;
                int j;
                for (j=0; j<num_closed; j++) {
                    if (closed[j]->row == neighbor_row && closed[j]->col == neighbor_col) break;
                }
                if (j != num_closed) continue;
                
                // Calculate neighbor node costs and add to open list
                struct Node* neighbor = (struct Node*) malloc(sizeof(struct Node));
                neighbor->row = neighbor_row;
                neighbor->col = neighbor_col;
                neighbor->g = current->g + 1;
                neighbor->h = get_h(neighbor_row, neighbor_col);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
                open[num_open++] = neighbor;
            }
        }
    }
    
    // No path found, free memory and return
    printf("No path found.\n");
    free(start);
    free(end);
    free(open);
    free(closed);
    return 0;
}

// Define main function
int main() {
    // Initialize grid with walls and path
    int grid[ROWS][COLS] = {
        {0, 0, 0, 1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0}
    };
    
    // Initialize path array and find path
    struct Node** path = (struct Node**) malloc(ROWS * COLS * sizeof(struct Node*));
    int found = pathfind(grid, path);
    
    return 0;
}
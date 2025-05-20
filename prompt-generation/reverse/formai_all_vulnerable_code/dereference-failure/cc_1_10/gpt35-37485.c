//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the map size, start location, and end location
#define ROW 10
#define COL 10
#define START_ROW 1
#define START_COL 1
#define END_ROW 8
#define END_COL 8

// Define a structure to hold the cell information
struct Cell {
    int row, col, f, g, h;
    bool is_obstacle;
    struct Cell* parent;
};

// Define a function to calculate the Manhattan distance between two cells
int calc_h(struct Cell current, struct Cell end) {
    return abs(current.row - end.row) + abs(current.col - end.col);
}

// Define a function to check if a cell is a valid location on the map
bool is_valid_location(int row, int col) {
    return (row >= 0 && col >= 0 && row < ROW && col < COL);
}

// Define a function to check if a cell is an obstacle
bool is_obstacle(int map[ROW][COL], int row, int col) {
    return map[row][col];
}

// Define the A* pathfinding function
void a_star(int map[ROW][COL]) {
    // Initialize the starting and ending cells
    struct Cell start = {START_ROW, START_COL, 0, 0, 0, false, NULL};
    struct Cell end = {END_ROW, END_COL, 0, 0, 0, false, NULL};
    
    // Create the open and closed lists
    int open_list_count = 0;
    struct Cell* open_list[ROW*COL];
    bool closed_list[ROW][COL];
    
    // Add the starting cell to the open list
    open_list[open_list_count++] = &start;
    
    // Loop until the end cell is found or there are no more cells in the open list
    while (open_list_count > 0) {
        // Find the cell with the lowest f value in the open list
        int min_f = open_list[0]->f;
        int min_index = 0;
        for (int i = 1; i < open_list_count; i++) {
            if (open_list[i]->f < min_f) {
                min_f = open_list[i]->f;
                min_index = i;
            }
        }
        
        // Remove the cell with the lowest f value from the open list
        struct Cell* current = open_list[min_index];
        open_list[min_index] = open_list[--open_list_count];
        
        // Check if the current cell is the end cell
        if (current->row == end.row && current->col == end.col) {
            // Path found, trace it back to the start cell
            while (current) {
                map[current->row][current->col] = '*';
                current = current->parent;
            }
            return;
        }
        
        // Add the current cell to the closed list
        closed_list[current->row][current->col] = true;
        
        // Check the neighbors of the current cell
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                // Skip the current cell and diagonal neighbors
                if (i == 0 && j == 0) {
                    continue;
                }
                if (abs(i) + abs(j) == 2) {
                    continue;
                }
                
                // Calculate the neighbor's location
                int neighbor_row = current->row + i;
                int neighbor_col = current->col + j;
                
                // Check if the neighbor is a valid location and not an obstacle
                if (is_valid_location(neighbor_row, neighbor_col) && !is_obstacle(map, neighbor_row, neighbor_col)) {
                    // Check if the neighbor is already in the closed list
                    if (closed_list[neighbor_row][neighbor_col]) {
                        continue;
                    }
                    
                    // Calculate the g, h, and f values for the neighbor
                    int neighbor_g = current->g + 1;
                    int neighbor_h = calc_h((struct Cell){neighbor_row, neighbor_col}, end);
                    int neighbor_f = neighbor_g + neighbor_h;
                    
                    // Check if the neighbor is already in the open list
                    bool is_in_open_list = false;
                    for (int k = 0; k < open_list_count; k++) {
                        if (open_list[k]->row == neighbor_row && open_list[k]->col == neighbor_col) {
                            is_in_open_list = true;
                            break;
                        }
                    }
                    
                    // If the neighbor is not in the open list, add it and set the parent and f values
                    if (!is_in_open_list) {
                        struct Cell* neighbor_cell = (struct Cell*) malloc(sizeof(struct Cell));
                        neighbor_cell->row = neighbor_row;
                        neighbor_cell->col = neighbor_col;
                        neighbor_cell->f = neighbor_f;
                        neighbor_cell->g = neighbor_g;
                        neighbor_cell->h = neighbor_h;
                        neighbor_cell->is_obstacle = false;
                        neighbor_cell->parent = current;
                        open_list[open_list_count++] = neighbor_cell;
                    }
                    // If the neighbor is already in the open list, check if this path to it is better
                    else {
                        for (int k = 0; k < open_list_count; k++) {
                            if (open_list[k]->row == neighbor_row && open_list[k]->col == neighbor_col) {
                                if (neighbor_g < open_list[k]->g) {
                                    open_list[k]->g = neighbor_g;
                                    open_list[k]->f = neighbor_f;
                                    open_list[k]->parent = current;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Define the map with obstacles
    int map[ROW][COL] = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 1, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 1, 0, 1, 0},
        {0, 1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    // Run the A* pathfinding algorithm
    a_star(map);
    
    // Print the final map
    printf("MAP:\n");
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (map[i][j] == 0) {
                printf(".");
            }
            else {
                printf("%c", map[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}
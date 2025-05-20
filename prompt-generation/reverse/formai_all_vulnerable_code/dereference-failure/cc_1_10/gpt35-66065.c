//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 10
#define COL 10
#define WALL 1
#define PATH 0
#define DEST_ROW 8
#define DEST_COL 8

// Definition of cell in maze grid 
struct cell
{
    int row, col; // row and column index of cell 
    int f, g, h; // distance from start, distance from destination, and total path cost
    struct cell* parent; // parent cell pointer
};

// Function to create a new cell in maze grid
struct cell* create_cell(int row, int col)
{
    struct cell* new_cell = (struct cell*)malloc(sizeof(struct cell));
    new_cell->row = row;
    new_cell->col = col;
    new_cell->f = 0;
    new_cell->g = 0;
    new_cell->h = 0;
    new_cell->parent = NULL;
    return new_cell;
}

// Function to check if given cell is valid or not
int is_valid_cell(int row, int col, int maze[ROW][COL])
{
    if (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] != WALL)
        return 1;
    else
        return 0;
}

// Function to check if given cell is destination or not
int is_destination(int row, int col)
{
    if (row == DEST_ROW && col == DEST_COL)
        return 1;
    else
        return 0;
}

// Function to calculate the heuristic distance between two cells
int calculate_heuristic_distance(int row, int col)
{
    return abs(DEST_ROW - row) + abs(DEST_COL - col);
}

// Function to trace the path from destination to start
void trace_path(int maze[ROW][COL], struct cell* destination)
{
    while (destination != NULL)
    {
        maze[destination->row][destination->col] = PATH;
        destination = destination->parent;
    }
}

// Function to apply A* pathfinding algorithm on maze grid
void apply_pathfinding_algorithm(int maze[ROW][COL], struct cell* start)
{
    // Create an open list and a closed list of cells
    struct cell* open_list[ROW*COL] = { NULL }; // unordered list of cells to be evaluated
    struct cell* closed_list[ROW*COL] = { NULL }; // ordered list of evaluated cells
    
    // Add the start cell to open list
    int open_list_count = 1;
    open_list[0] = start;
    start->h = calculate_heuristic_distance(start->row, start->col);
    start->f = start->h;
    
    // Loop until open list is empty or destination cell is found
    while (open_list_count > 0)
    {
        // Find the cell with lowest f value in open list
        int min_index = 0;
        for (int i = 0; i < open_list_count; i++)
            if (open_list[i]->f < open_list[min_index]->f)
                min_index = i;
        
        // Get the cell with lowest f value
        struct cell* current = open_list[min_index];
        
        // If current cell is destination, trace the path and return
        if (is_destination(current->row, current->col))
        {
            trace_path(maze, current);
            return;
        }
        
        // Move current cell from open list to closed list
        open_list[min_index] = open_list[open_list_count - 1];
        open_list_count--;
        closed_list[current->row * COL + current->col] = current;
        
        // Explore all adjacent cells
        int adjacent_rows[] = { -1, 0, 1, 0 };
        int adjacent_cols[] = { 0, 1, 0, -1 };
        for (int i = 0; i < 4; i++)
        {
            int adjacent_row = current->row + adjacent_rows[i];
            int adjacent_col = current->col + adjacent_cols[i];
            
            // If adjacent cell is not valid or already evaluated, skip it
            if (!is_valid_cell(adjacent_row, adjacent_col, maze))
                continue;
            if (closed_list[adjacent_row * COL + adjacent_col] != NULL)
                continue;
            
            // Create adjacent cell if it is a valid cell
            struct cell* adjacent = create_cell(adjacent_row, adjacent_col);
            adjacent->g = current->g + 1;
            adjacent->h = calculate_heuristic_distance(adjacent_row, adjacent_col);
            adjacent->f = adjacent->g + adjacent->h;
            adjacent->parent = current;
            
            // Add adjacent cell to open list
            open_list[open_list_count] = adjacent;
            open_list_count++;
        }
    }
}

int main()
{
    int maze[ROW][COL] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 0, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 1, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 0, 0, 0, 1, 0, 1, 0 },
        { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    };

    // Set starting cell
    struct cell* start = create_cell(1, 1);

    // Apply A* pathfinding algorithm on maze grid
    apply_pathfinding_algorithm(maze, start);

    // Print path from start to destination
    printf("Path:\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (maze[i][j] == PATH)
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }

    return 0;
}
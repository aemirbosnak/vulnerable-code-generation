//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define colors used for printing the maze
#define RESET   "\x1B[0m"
#define BLUE    "\x1B[34m"
#define GREEN   "\x1B[32m"

// define directions
#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3

// define the maze structure
typedef struct {
    int rows;
    int cols;
    char** cells;
} Maze;

// function to initialize the maze
void init_maze(Maze* maze, int rows, int cols) {
    maze->rows = rows;
    maze->cols = cols;
    maze->cells = (char**) malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        maze->cells[i] = (char*) malloc(cols * sizeof(char));
        memset(maze->cells[i], '#', cols);
    }
}

// function to free the memory used by the maze
void free_maze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
}

// function to print the maze
void print_maze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->cells[i][j] == '#') {
                printf("%s%c%s", BLUE, maze->cells[i][j], RESET);
            } else {
                printf("%s%c%s", GREEN, maze->cells[i][j], RESET);
            }
        }
        printf("\n");
    }
}

// function to check if a cell is valid (within bounds of the maze)
int valid_cell(Maze* maze, int row, int col) {
    return (row >= 0 && row < maze->rows && col >= 0 && col < maze->cols);
}

// function to check if a cell is a wall
int is_wall(Maze* maze, int row, int col) {
    return (maze->cells[row][col] == '#');
}

// function to check if a cell is visited
int is_visited(Maze* maze, int row, int col) {
    return (maze->cells[row][col] == ' ');
}

// function to get a random direction
int get_random_direction() {
    return rand() % 4;
}

// function to get the opposite direction
int get_opposite_direction(int direction) {
    if (direction == NORTH) return SOUTH;
    if (direction == EAST) return WEST;
    if (direction == SOUTH) return NORTH;
    if (direction == WEST) return EAST;
}

// function to get the row and column of a cell in a given direction
void get_new_cell(int* row, int* col, int direction) {
    if (direction == NORTH) (*row)--;
    if (direction == EAST) (*col)++;
    if (direction == SOUTH) (*row)++;
    if (direction == WEST) (*col)--;
}

// function to generate the maze
void generate_maze(Maze* maze, int start_row, int start_col) {
    // set the start cell to visited
    maze->cells[start_row][start_col] = ' ';
    
    int stack_size = 0;
    int* stack_rows = (int*) malloc(maze->rows * maze->cols * sizeof(int));
    int* stack_cols = (int*) malloc(maze->rows * maze->cols * sizeof(int));
    
    // add the start cell to the stack
    stack_rows[stack_size] = start_row;
    stack_cols[stack_size] = start_col;
    stack_size++;
    
    // loop until the stack is empty
    while (stack_size > 0) {
        // get the current cell from the top of the stack
        int current_row = stack_rows[stack_size - 1];
        int current_col = stack_cols[stack_size - 1];
        
        // find a valid unvisited neighbor
        int found_unvisited_neighbor = 0;
        int neighbor_row, neighbor_col, neighbor_direction;
        while (!found_unvisited_neighbor) {
            neighbor_direction = get_random_direction();
            get_new_cell(&neighbor_row, &neighbor_col, neighbor_direction);
            if (valid_cell(maze, neighbor_row, neighbor_col) && is_wall(maze, neighbor_row, neighbor_col)) {
                int num_visited_neighbors = 0;
                if (valid_cell(maze, neighbor_row - 1, neighbor_col) && is_visited(maze, neighbor_row - 1, neighbor_col)) num_visited_neighbors++;
                if (valid_cell(maze, neighbor_row, neighbor_col + 1) && is_visited(maze, neighbor_row, neighbor_col + 1)) num_visited_neighbors++;
                if (valid_cell(maze, neighbor_row + 1, neighbor_col) && is_visited(maze, neighbor_row + 1, neighbor_col)) num_visited_neighbors++;
                if (valid_cell(maze, neighbor_row, neighbor_col - 1) && is_visited(maze, neighbor_row, neighbor_col - 1)) num_visited_neighbors++;
                if (num_visited_neighbors < 2) {
                    found_unvisited_neighbor = 1;
                }
            }
        }
        
        // remove the wall between the current cell and the neighbor
        maze->cells[neighbor_row][neighbor_col] = ' ';
        maze->cells[current_row + (neighbor_row - current_row) / 2][current_col + (neighbor_col - current_col) / 2] = ' ';
        
        // add the neighbor cell to the stack
        stack_rows[stack_size] = neighbor_row;
        stack_cols[stack_size] = neighbor_col;
        stack_size++;
    }
    
    free(stack_rows);
    free(stack_cols);
}

// main function to run the program
int main() {
    // set the random seed
    srand(time(NULL));
    
    // initialize the maze
    Maze maze;
    init_maze(&maze, 15, 15);
    
    // generate the maze
    generate_maze(&maze, 0, 0);
    
    // print the maze
    print_maze(&maze);
    
    // free the memory used by the maze
    free_maze(&maze);
    
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

// Define a structure for the maze
typedef struct {
    int rows;
    int cols;
    char** cells;
} Maze;

// Function to create and initialize the maze
Maze* createMaze(int rows, int cols) {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->rows = rows;
    maze->cols = cols;

    maze->cells = (char**)malloc(rows * sizeof(char*));
    for (int i = 0; i < rows; i++) {
        maze->cells[i] = (char*)malloc(cols * sizeof(char));
    }

    return maze;
}

// Function to free the allocated memory for the maze
void freeMaze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Function to display the maze
void displayMaze(Maze* maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%c ", maze->cells[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the next move is valid
int isValidMove(Maze* maze, int x, int y) {
    return (x >= 0 && y >= 0 && x < maze->rows && y < maze->cols && maze->cells[x][y] != '#');
}

// Recursive function to find the path
int findPath(Maze* maze, int x, int y, int pathLength) {
    if (x == maze->rows - 1 && y == maze->cols - 1) {
        maze->cells[x][y] = 'P';
        return 1; // Path found
    }

    if (isValidMove(maze, x, y)) {
        maze->cells[x][y] = 'P'; // Mark the path
        
        // Explore the four possible directions
        if (findPath(maze, x + 1, y, pathLength) ||
            findPath(maze, x, y + 1, pathLength) ||
            findPath(maze, x - 1, y, pathLength) ||
            findPath(maze, x, y - 1, pathLength)) {
            return 1; // Path found in one of the directions
        }

        // Backtrack and unmark the current cell if no path leads forward
        maze->cells[x][y] = ' '; 
    }

    return 0; // No path found
}

// The main function to drive the maze solver
int main() {
    int rows = 5;
    int cols = 5;

    // Create a maze
    Maze* maze = createMaze(rows, cols);

    // Initialize the maze with walls and paths
    char initialMaze[5][5] = {
        {' ', ' ', '#', ' ', ' '},
        {'#', ' ', '#', '#', ' '},
        {' ', ' ', ' ', '#', ' '},
        {' ', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', 'E'}
    };

    // Copy initial maze setup
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze->cells[i][j] = initialMaze[i][j];
        }
    }

    printf("Initial Maze:\n");
    displayMaze(maze);
    
    // Start the path finding from (0,0)
    if (findPath(maze, 0, 0, 0)) {
        printf("\nPath Found:\n");
    } else {
        printf("\nNo Path Found.\n");
    }
    
    displayMaze(maze);
    
    // Free allocated memory for the maze
    freeMaze(maze);

    return 0;
}
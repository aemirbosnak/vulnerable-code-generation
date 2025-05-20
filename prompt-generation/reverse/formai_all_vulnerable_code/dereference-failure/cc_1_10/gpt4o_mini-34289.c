//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10

// Futuristic Maze with dynamic allocation
char** createMaze() {
    char **maze = (char**)malloc(MAZE_SIZE * sizeof(char*));
    for (int i = 0; i < MAZE_SIZE; i++) {
        maze[i] = (char*)malloc(MAZE_SIZE * sizeof(char));
    }
    
    // Static maze layout (walls, path, start, end)
    const char layout[MAZE_SIZE][MAZE_SIZE] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', 'S', ' ', ' ', '#', ' ', '#', ' ', ' ', '#'},
        {'#', '#', '#', ' ', '#', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'E', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', '#', ' ', '#', ' ', ' ', '#', '#'},
        {'#', '#', ' ', '#', ' ', '#', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {'#', '#', '#', ' ', '#', '#', '#', '#', '#', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
    };

    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j] = layout[i][j];
        }
    }
    return maze;
}

// Function to free the maze
void freeMaze(char** maze) {
    for (int i = 0; i < MAZE_SIZE; i++) {
        free(maze[i]);
    }
    free(maze);
}

// Function to display the maze
void displayMaze(char** maze, int posX, int posY) {
    printf("\nCurrent Position: (%d, %d)\n", posX, posY);
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if (i == posX && j == posY)
                printf("P ");  // P for Player
            else
                printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current move is valid
bool isValidMove(char** maze, int x, int y) {
    return (x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && maze[x][y] != '#');
}

// Recursive function to find the route
bool findRoute(char** maze, int x, int y) {
    if (maze[x][y] == 'E') {
        return true; // Exit found!
    }

    if (!isValidMove(maze, x, y)) {
        return false; // Invalid move
    }
    
    // Mark the cell as visited
    maze[x][y] = '.';

    // Move DOWN
    if (findRoute(maze, x + 1, y)) return true; // Down
    // Move UP
    if (findRoute(maze, x - 1, y)) return true; // Up
    // Move RIGHT
    if (findRoute(maze, x, y + 1)) return true; // Right
    // Move LEFT
    if (findRoute(maze, x, y - 1)) return true; // Left

    // Backtrack, unvisited cell
    maze[x][y] = ' ';
    return false;
}

int main() {
    // Futuristic Console Representation
    printf("Welcome to the Galactic Maze Explorer!\n");
    
    char** maze = createMaze();
    int startX = 1, startY = 1; // Starting Position

    displayMaze(maze, startX, startY);
    
    if (findRoute(maze, startX, startY)) {
        printf("A route to the exit has been found!\n");
    } else {
        printf("No route to exit exists. The maze is too challenging!\n");
    }

    // Free the maze memory
    freeMaze(maze);
    
    return 0;
}
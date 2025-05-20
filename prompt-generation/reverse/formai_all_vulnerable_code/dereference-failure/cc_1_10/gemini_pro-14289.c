//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

// Structure to represent a cell in the maze
typedef struct Cell {
    int x, y;
    bool visited;
} Cell;

// Structure to represent the maze
typedef struct Maze {
    Cell cells[N][N];
} Maze;

// Function to create a maze
Maze* create_maze() {
    Maze* maze = malloc(sizeof(Maze));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maze->cells[i][j].x = i;
            maze->cells[i][j].y = j;
            maze->cells[i][j].visited = false;
        }
    }

    return maze;
}

// Function to print the maze
void print_maze(Maze* maze) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", maze->cells[i][j].visited ? '.' : '#');
        }
        printf("\n");
    }
}

// Function to find a path through the maze
bool find_path(Maze* maze, Cell* start, Cell* end) {
    // Check if the starting cell is valid
    if (start->x < 0 || start->x >= N || start->y < 0 || start->y >= N) {
        return false;
    }

    // Check if the ending cell is valid
    if (end->x < 0 || end->x >= N || end->y < 0 || end->y >= N) {
        return false;
    }

    // Mark the starting cell as visited
    maze->cells[start->x][start->y].visited = true;

    // Check if the current cell is the ending cell
    if (start->x == end->x && start->y == end->y) {
        return true;
    }

    // Recursively check the cells in all four directions
    if (find_path(maze, &(maze->cells[start->x + 1][start->y]), end) ||
        find_path(maze, &(maze->cells[start->x - 1][start->y]), end) ||
        find_path(maze, &(maze->cells[start->x][start->y + 1]), end) ||
        find_path(maze, &(maze->cells[start->x][start->y - 1]), end)) {
        return true;
    }

    // If no path is found, mark the current cell as unvisited
    maze->cells[start->x][start->y].visited = false;

    // Return false
    return false;
}

// Main function
int main() {
    // Create a maze
    Maze* maze = create_maze();

    // Set the starting and ending cells
    Cell start = {0, 0};
    Cell end = {N - 1, N - 1};

    // Find a path through the maze
    bool path_found = find_path(maze, &start, &end);

    // Print the maze
    print_maze(maze);

    // Print whether a path was found
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // Free the maze
    free(maze);

    return 0;
}
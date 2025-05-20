//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a cell in the maze
typedef struct cell {
    int x;
    int y;
    bool visited;
} cell;

// Structure to represent the maze
typedef struct maze {
    cell grid[MAX_SIZE][MAX_SIZE];
    int width;
    int height;
} maze;

// Function to create a new maze
maze* create_maze(int width, int height) {
    maze* m = malloc(sizeof(maze));
    m->width = width;
    m->height = height;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            m->grid[i][j].x = i;
            m->grid[i][j].y = j;
            m->grid[i][j].visited = false;
        }
    }

    return m;
}

// Function to print the maze
void print_maze(maze* m) {
    for (int i = 0; i < m->width; i++) {
        for (int j = 0; j < m->height; j++) {
            if (m->grid[i][j].visited) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Function to find the path through the maze
bool find_path(maze* m, int x, int y) {
    // Check if the given coordinates are valid
    if (x < 0 || x >= m->width || y < 0 || y >= m->height) {
        return false;
    }

    // Check if the current cell has already been visited
    if (m->grid[x][y].visited) {
        return false;
    }

    // Mark the current cell as visited
    m->grid[x][y].visited = true;

    // Check if the current cell is the goal
    if (x == m->width - 1 && y == m->height - 1) {
        return true;
    }

    // Recursively explore the adjacent cells
    if (find_path(m, x + 1, y) || find_path(m, x - 1, y) || find_path(m, x, y + 1) || find_path(m, x, y - 1)) {
        return true;
    }

    // If no path was found, mark the current cell as unvisited
    m->grid[x][y].visited = false;

    return false;
}

// Main function
int main() {
    // Create a new maze
    maze* m = create_maze(10, 10);

    // Print the maze
    print_maze(m);

    // Find the path through the maze
    bool path_found = find_path(m, 0, 0);

    // Print the result
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // Free the maze
    free(m);

    return 0;
}
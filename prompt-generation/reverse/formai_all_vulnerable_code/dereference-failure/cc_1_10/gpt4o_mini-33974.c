//GPT-4o-mini DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define N 5

// Some magical characters for added excitement!
char maze[N][N] = {
    {'S', '.', '#', '.', 'E'},
    {'#', '.', '#', '.', '#'},
    {'.', '.', '.', '#', '.'},
    {'#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.'}
};

// Directions: down, up, right, left
int rowDir[] = {1, -1, 0, 0};
int colDir[] = {0, 0, 1, -1};

// Function to check if the next move is valid
int isValid(int x, int y, int maze[N][N], int visited[N][N]) {
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] != '#' && !visited[x][y]);
}

// The main function to solve the maze using DFS
int findPath(int maze[N][N], int x, int y, int visited[N][N]) {
    // Base conditions
    if (maze[x][y] == 'E') {
        // Found the magical exit
        return 1;
    }

    // Mark the cell as visited
    visited[x][y] = 1;

    printf("Visiting: (%d, %d)\n", x, y);

    // Explore all possible directions
    for (int i = 0; i < 4; i++) {
        int newX = x + rowDir[i];
        int newY = y + colDir[i];

        // Check if the next move is within bounds and unvisited
        if (isValid(newX, newY, maze, visited)) {
            if (findPath(maze, newX, newY, visited)) {
                return 1;  // Path found! 🎉
            }
        }
    }

    // Backtrack - unmark the cell
    visited[x][y] = 0;  
    printf("Backtracking from: (%d, %d)\n", x, y); // Where to next?
    return 0;
}

int main() {
    int visited[N][N] = {0}; // To track visited paths

    printf("Welcome to the Maze Route Finder! Can you reach the exit? 🏁\n");

    // Start from (0, 0)
    if (findPath(maze, 0, 0, visited)) {
        printf("Congratulations! You've found the exit! 🥳✨\n");
    } else {
        printf("Alas! No path to the exit could be found... 😱\n");
    }

    // Print the maze
    printf("Here's the maze:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}
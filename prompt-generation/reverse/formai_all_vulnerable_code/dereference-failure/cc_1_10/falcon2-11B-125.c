//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 100
#define MAX_COLS 100

// Structure to represent a cell in the maze
struct Cell {
    int row;
    int col;
    int visited;
    int explored;
};

// Function to generate a random maze
void generateMaze(struct Cell** maze) {
    // Initialize the maze with all cells unvisited
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            maze[i][j].visited = 0;
            maze[i][j].explored = 0;
        }
    }

    // Choose a random starting cell
    int startRow = rand() % MAX_ROWS;
    int startCol = rand() % MAX_COLS;
    maze[startRow][startCol].visited = 1;

    // Perform a depth-first search to explore the maze
    struct Cell* current = &(maze[startRow][startCol]);
    struct Cell* next;

    while (current->explored < MAX_ROWS * MAX_COLS) {
        // Choose a random adjacent cell
        int dir = rand() % 4;
        switch (dir) {
            case 0: // Up
                if (current->row > 0 && maze[current->row - 1][current->col].visited == 0) {
                    next = &(maze[current->row - 1][current->col]);
                    current->explored = 1;
                }
                break;
            case 1: // Down
                if (current->row < MAX_ROWS - 1 && maze[current->row + 1][current->col].visited == 0) {
                    next = &(maze[current->row + 1][current->col]);
                    current->explored = 1;
                }
                break;
            case 2: // Left
                if (current->col > 0 && maze[current->row][current->col - 1].visited == 0) {
                    next = &(maze[current->row][current->col - 1]);
                    current->explored = 1;
                }
                break;
            case 3: // Right
                if (current->col < MAX_COLS - 1 && maze[current->row][current->col + 1].visited == 0) {
                    next = &(maze[current->row][current->col + 1]);
                    current->explored = 1;
                }
                break;
        }

        if (next!= NULL) {
            // Set the current cell as visited and move to the next cell
            current->visited = 1;
            current = next;
        } else {
            // No more unexplored cells, stop the search
            break;
        }
    }
}

// Function to print the maze
void printMaze(struct Cell** maze) {
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (maze[i][j].visited == 1) {
                printf("O");
            } else if (maze[i][j].explored == 1) {
                printf("X");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    // Allocate memory for the maze
    struct Cell** maze = (struct Cell**)malloc(MAX_ROWS * sizeof(struct Cell*));
    for (int i = 0; i < MAX_ROWS; i++) {
        maze[i] = (struct Cell*)malloc(MAX_COLS * sizeof(struct Cell));
        for (int j = 0; j < MAX_COLS; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].visited = 0;
            maze[i][j].explored = 0;
        }
    }

    // Generate a random maze
    generateMaze(maze);

    // Print the maze
    printf("Random Maze:\n");
    printMaze(maze);

    return 0;
}
//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// Structure to represent a node in the maze
typedef struct node {
    int x;
    int y;
    int next_x;
    int next_y;
} node_t;

// Function to generate a random maze
node_t* generate_maze(void) {
    // Initialize the maze with all walls
    node_t* maze = (node_t*)calloc(WIDTH * HEIGHT, sizeof(node_t));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        maze[i].x = i % WIDTH;
        maze[i].y = i / WIDTH;
        maze[i].next_x = -1;
        maze[i].next_y = -1;
    }

    // Add random walls to the maze
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (rand() % 2) {
            maze[i].next_x = (rand() % WIDTH) + 1;
            maze[i].next_y = (rand() % HEIGHT) + 1;
        }
    }

    return maze;
}

// Function to perform a depth-first search of the maze
void dfs(node_t* maze, int start_x, int start_y) {
    // Mark the current node as visited
    maze[start_x].next_x = -1;
    maze[start_x].next_y = -1;

    // Traverse the maze in depth-first order
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int next_x = maze[i].next_x;
        int next_y = maze[i].next_y;

        if (next_x != -1 && next_y != -1) {
            // If we find a wall, backtrack and try another direction
            if (maze[next_x].next_x == -1 || maze[next_x].next_y == -1) {
                dfs(maze, start_x, start_y);
            } else {
                // Follow the next edge
                start_x = next_x;
                start_y = next_y;
            }
        } else {
            // If we reach the end of the maze, print the solution
            printf("Solution: %d %d\n", start_x, start_y);
            return;
        }
    }
}

int main(void) {
    // Generate a random maze
    node_t* maze = generate_maze();

    // Start the depth-first search at the top-left corner of the maze
    dfs(maze, 0, 0);

    // Free the maze memory
    free(maze);

    return 0;
}
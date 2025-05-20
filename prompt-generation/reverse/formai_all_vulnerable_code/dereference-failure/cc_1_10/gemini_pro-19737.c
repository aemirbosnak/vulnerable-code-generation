//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: random
// Memory Management Maze Runner

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Maze cell
typedef struct {
    int x, y;           // Coordinates
    int walls;          // Bitmask: 0b1111 (up, right, down, left)
} Cell;

// Maze data structure
typedef struct {
    int width, height;  // Dimensions
    Cell *cells;       // Array of cells
} Maze;

// Create a new maze
Maze *createMaze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->cells = calloc(width * height, sizeof(Cell));

    // Initialize cells
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze->cells[i * width + j].x = i;
            maze->cells[i * width + j].y = j;
            maze->cells[i * width + j].walls = 0b1111;
        }
    }
    return maze;
}

// Destroy a maze
void destroyMaze(Maze *maze) {
    free(maze->cells);
    free(maze);
}

// Generate a random maze
void generateMaze(Maze *maze) {
    srand(time(NULL));

    // Create a stack to keep track of visited cells
    int stack[maze->width * maze->height];
    int stackPtr = 0;

    // Start at a random cell
    int x = rand() % maze->width;
    int y = rand() % maze->height;

    // Loop until all cells have been visited
    while (stackPtr > 0 || maze->cells[x * maze->width + y].walls != 0) {
        // Push the current cell onto the stack
        stack[stackPtr++] = x * maze->width + y;

        // Mark the current cell as visited
        maze->cells[x * maze->width + y].walls = 0;

        // Get a list of unvisited neighbors
        int neighbors[4];
        int numNeighbors = 0;
        if (x > 0 && maze->cells[(x - 1) * maze->width + y].walls != 0) {
            neighbors[numNeighbors++] = (x - 1) * maze->width + y;
        }
        if (y > 0 && maze->cells[x * maze->width + (y - 1)].walls != 0) {
            neighbors[numNeighbors++] = x * maze->width + (y - 1);
        }
        if (x < maze->width - 1 && maze->cells[(x + 1) * maze->width + y].walls != 0) {
            neighbors[numNeighbors++] = (x + 1) * maze->width + y;
        }
        if (y < maze->height - 1 && maze->cells[x * maze->width + (y + 1)].walls != 0) {
            neighbors[numNeighbors++] = x * maze->width + (y + 1);
        }

        // If there are no unvisited neighbors, pop the current cell off the stack
        if (numNeighbors == 0) {
            stackPtr--;
            x = maze->cells[stack[stackPtr]].x;
            y = maze->cells[stack[stackPtr]].y;
        } else {
            // Randomly choose an unvisited neighbor
            int neighbor = neighbors[rand() % numNeighbors];

            // Remove the wall between the current cell and the neighbor
            if (neighbor == (x - 1) * maze->width + y) {
                maze->cells[x * maze->width + y].walls &= ~0b0001;
            } else if (neighbor == x * maze->width + (y - 1)) {
                maze->cells[x * maze->width + y].walls &= ~0b1000;
            } else if (neighbor == (x + 1) * maze->width + y) {
                maze->cells[neighbor].walls &= ~0b0001;
            } else if (neighbor == x * maze->width + (y + 1)) {
                maze->cells[neighbor].walls &= ~0b1000;
            }

            // Move to the neighbor
            x = maze->cells[neighbor].x;
            y = maze->cells[neighbor].y;
        }
    }
}

// Print a maze
void printMaze(Maze *maze) {
    for (int i = 0; i < maze->width; i++) {
        for (int j = 0; j < maze->height; j++) {
            printf("%c", maze->cells[i * maze->width + j].walls & 0b1000 ? '+' : ' ');
        }
        printf("+\n");
        for (int j = 0; j < maze->height; j++) {
            printf("%c", maze->cells[i * maze->width + j].walls & 0b0100 ? '|' : ' ');
        }
        printf("|\n");
    }
    for (int i = 0; i < maze->width; i++) {
        printf("+");
    }
    printf("+\n");
}

// Solve a maze
int solveMaze(Maze *maze, int startX, int startY, int endX, int endY) {
    // Create a queue to keep track of cells to visit
    int queue[maze->width * maze->height];
    int queuePtr = 0;

    // Enqueue the starting cell
    queue[queuePtr++] = startX * maze->width + startY;

    // Loop until the queue is empty or the end cell has been found
    while (queuePtr > 0) {
        // Dequeue the next cell
        int x = queue[queuePtr - 1] / maze->width;
        int y = queue[queuePtr - 1] % maze->width;
        queuePtr--;

        // Mark the cell as visited
        maze->cells[x * maze->width + y].walls |= 0b10000000;

        // Check if the end cell has been found
        if (x == endX && y == endY) {
            return 1;
        }

        // Get a list of unvisited neighbors
        int neighbors[4];
        int numNeighbors = 0;
        if (x > 0 && maze->cells[(x - 1) * maze->width + y].walls & 0b10000000 == 0) {
            neighbors[numNeighbors++] = (x - 1) * maze->width + y;
        }
        if (y > 0 && maze->cells[x * maze->width + (y - 1)].walls & 0b10000000 == 0) {
            neighbors[numNeighbors++] = x * maze->width + (y - 1);
        }
        if (x < maze->width - 1 && maze->cells[(x + 1) * maze->width + y].walls & 0b10000000 == 0) {
            neighbors[numNeighbors++] = (x + 1) * maze->width + y;
        }
        if (y < maze->height - 1 && maze->cells[x * maze->width + (y + 1)].walls & 0b10000000 == 0) {
            neighbors[numNeighbors++] = x * maze->width + (y + 1);
        }

        // Enqueue the unvisited neighbors
        for (int i = 0; i < numNeighbors; i++) {
            queue[queuePtr++] = neighbors[i];
        }
    }

    // The end cell was not found
    return 0;
}

int main() {
    // Create a maze
    Maze *maze = createMaze(10, 10);

    // Generate the maze
    generateMaze(maze);

    // Solve the maze
    if (solveMaze(maze, 0, 0, maze->width - 1, maze->height - 1)) {
        printf("Maze solved!\n");
    } else {
        printf("Maze not solvable!\n");
    }

    // Print the maze
    printMaze(maze);

    // Destroy the maze
    destroyMaze(maze);

    return 0;
}
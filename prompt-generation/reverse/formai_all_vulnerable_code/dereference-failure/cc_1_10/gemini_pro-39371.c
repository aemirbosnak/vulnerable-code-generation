//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the maze
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the possible directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Define the cell states
#define UNVISITED 0
#define VISITED 1

// Define the maze structure
typedef struct {
    int width;
    int height;
    int** cells;
} Maze;

// Create a new maze
Maze* create_maze(int width, int height) {
    Maze* maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->cells = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        maze->cells[i] = malloc(sizeof(int) * width);
    }

    // Initialize the cells to unvisited
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->cells[i][j] = UNVISITED;
        }
    }

    return maze;
}

// Free the memory allocated for the maze
void free_maze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->cells[i]);
    }
    free(maze->cells);
    free(maze);
}

// Print the maze to the console
void print_maze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->cells[i][j] == UNVISITED) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Generate a random direction
int random_direction() {
    return rand() % 4;
}

// Get a random unvisited neighbor of the given cell
int* get_random_unvisited_neighbor(Maze* maze, int x, int y) {
    int directions[] = {NORTH, EAST, SOUTH, WEST};
    int num_directions = 4;

    // Shuffle the directions array
    for (int i = 0; i < num_directions; i++) {
        int j = rand() % num_directions;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Iterate over the directions until we find an unvisited neighbor
    for (int i = 0; i < num_directions; i++) {
        int direction = directions[i];
        int nx = x;
        int ny = y;
        switch (direction) {
            case NORTH:
                ny--;
                break;
            case EAST:
                nx++;
                break;
            case SOUTH:
                ny++;
                break;
            case WEST:
                nx--;
                break;
        }

        if (nx >= 0 && nx < maze->width && ny >= 0 && ny < maze->height && maze->cells[ny][nx] == UNVISITED) {
            int* neighbor = malloc(sizeof(int) * 2);
            neighbor[0] = nx;
            neighbor[1] = ny;
            return neighbor;
        }
    }

    return NULL;
}

// Generate a maze using the recursive backtracker algorithm
Maze* generate_maze(int width, int height) {
    // Create a new maze
    Maze* maze = create_maze(width, height);

    // Start at a random cell
    int x = rand() % width;
    int y = rand() % height;

    // Mark the current cell as visited
    maze->cells[y][x] = VISITED;

    // While there are still unvisited cells
    while (1) {
        // Get a random unvisited neighbor of the current cell
        int* neighbor = get_random_unvisited_neighbor(maze, x, y);

        // If there is no unvisited neighbor, backtrack
        if (neighbor == NULL) {
            // Find the first unvisited cell in the stack
            int found = 0;
            for (int i = height - 1; i >= 0; i--) {
                for (int j = width - 1; j >= 0; j--) {
                    if (maze->cells[i][j] == UNVISITED) {
                        x = j;
                        y = i;
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }

            // If there are no more unvisited cells, the maze is complete
            if (!found) {
                break;
            }
        } else {
            // Visit the neighbor
            x = neighbor[0];
            y = neighbor[1];
            free(neighbor);
            maze->cells[y][x] = VISITED;

            // Carve a path between the current cell and the neighbor
            int direction = random_direction();
            switch (direction) {
                case NORTH:
                    maze->cells[y + 1][x] = VISITED;
                    break;
                case EAST:
                    maze->cells[y][x + 1] = VISITED;
                    break;
                case SOUTH:
                    maze->cells[y - 1][x] = VISITED;
                    break;
                case WEST:
                    maze->cells[y][x - 1] = VISITED;
                    break;
            }
        }
    }

    return maze;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a maze
    Maze* maze = generate_maze(MAZE_WIDTH, MAZE_HEIGHT);

    // Print the maze to the console
    print_maze(maze);

    // Free the memory allocated for the maze
    free_maze(maze);

    return 0;
}
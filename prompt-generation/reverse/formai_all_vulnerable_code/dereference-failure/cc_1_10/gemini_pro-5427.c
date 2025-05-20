//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

// Define the maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Define the maze directions
typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} Direction;

// Define the maze cell types
typedef enum {
    WALL,
    OPEN,
    VISITED
} CellType;

// Define the maze structure
typedef struct {
    CellType cells[MAZE_WIDTH][MAZE_HEIGHT];
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} Maze;

// Create a new maze
Maze* create_maze()
{
    Maze* maze = malloc(sizeof(Maze));

    // Initialize the maze cells to walls
    for (int x = 0; x < MAZE_WIDTH; x++) {
        for (int y = 0; y < MAZE_HEIGHT; y++) {
            maze->cells[x][y] = WALL;
        }
    }

    // Set the start and end positions
    maze->start_x = 0;
    maze->start_y = 0;
    maze->end_x = MAZE_WIDTH - 1;
    maze->end_y = MAZE_HEIGHT - 1;

    // Return the maze
    return maze;
}

// Print the maze to the console
void print_maze(Maze* maze)
{
    // Print the top border
    printf("+");
    for (int x = 0; x < MAZE_WIDTH; x++) {
        printf("---+");
    }
    printf("\n");

    // Print the maze cells
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        printf("|");
        for (int x = 0; x < MAZE_WIDTH; x++) {
            switch (maze->cells[x][y]) {
                case WALL:
                    printf("   |");
                    break;
                case OPEN:
                    printf("   |");
                    break;
                case VISITED:
                    printf(" X |");
                    break;
            }
        }
        printf("\n");

        // Print the bottom border
        printf("+");
        for (int x = 0; x < MAZE_WIDTH; x++) {
            printf("---+");
        }
        printf("\n");
    }
}

// Find a path through the maze using a depth-first search
int find_path(Maze* maze, int x, int y)
{
    // Check if we have reached the end of the maze
    if (x == maze->end_x && y == maze->end_y) {
        return 1;
    }

    // Mark the current cell as visited
    maze->cells[x][y] = VISITED;

    // Try all possible directions
    for (Direction direction = NORTH; direction <= WEST; direction++) {
        // Get the coordinates of the next cell
        int next_x = x;
        int next_y = y;

        switch (direction) {
            case NORTH:
                next_y--;
                break;
            case EAST:
                next_x++;
                break;
            case SOUTH:
                next_y++;
                break;
            case WEST:
                next_x--;
                break;
        }

        // Check if the next cell is valid and not visited
        if (next_x >= 0 && next_x < MAZE_WIDTH && next_y >= 0 && next_y < MAZE_HEIGHT && maze->cells[next_x][next_y] != WALL && maze->cells[next_x][next_y] != VISITED) {
            // Recursively call find_path on the next cell
            if (find_path(maze, next_x, next_y)) {
                return 1;
            }
        }
    }

    // If we have not found a path, mark the current cell as open again
    maze->cells[x][y] = OPEN;

    // Return 0 to indicate that no path was found
    return 0;
}


int main()
{
    // Create a new maze
    Maze* maze = create_maze();

    // Print the maze to the console
    print_maze(maze);

    // Find a path through the maze
    int success = find_path(maze, maze->start_x, maze->start_y);

    // Print the result
    if (success) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    // Free the maze
    free(maze);

    return 0;
}
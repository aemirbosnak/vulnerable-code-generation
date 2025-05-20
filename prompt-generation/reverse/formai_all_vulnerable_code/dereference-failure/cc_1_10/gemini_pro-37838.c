//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The maze structure
typedef struct maze {
    int width;
    int height;
    int **cells;
} maze;

// Create a new maze
maze *create_maze(int width, int height) {
    maze *m = malloc(sizeof(maze));
    m->width = width;
    m->height = height;
    m->cells = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        m->cells[i] = malloc(sizeof(int) * width);
    }
    return m;
}

// Free the memory allocated for a maze
void free_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->cells[i]);
    }
    free(m->cells);
    free(m);
}

// Print a maze to the console
void print_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%d ", m->cells[i][j]);
        }
        printf("\n");
    }
}

// Generate a random maze
maze *generate_maze(int width, int height) {
    maze *m = create_maze(width, height);

    // Initialize the maze cells to 0
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            m->cells[i][j] = 0;
        }
    }

    // Create a stack to store the cells that have been visited
    int stack[width * height];
    int top = 0;

    // Start at the top-left corner of the maze
    int x = 0;
    int y = 0;

    // While there are still cells to visit
    while (top > 0 || x != width - 1 || y != height - 1) {
        // If the current cell has not been visited
        if (m->cells[y][x] == 0) {
            // Mark the current cell as visited
            m->cells[y][x] = 1;

            // Push the current cell onto the stack
            stack[top++] = y * width + x;

            // Randomly choose a direction to move
            int direction = rand() % 4;

            // Move in the chosen direction
            switch (direction) {
                case 0:  // Up
                    y--;
                    break;
                case 1:  // Right
                    x++;
                    break;
                case 2:  // Down
                    y++;
                    break;
                case 3:  // Left
                    x--;
                    break;
            }
        } else {
            // If the current cell has been visited
            // Pop the previous cell from the stack
            top--;
            y = stack[top] / width;
            x = stack[top] % width;
        }
    }

    // Return the generated maze
    return m;
}

// Solve a maze
int solve_maze(maze *m) {
    // Start at the top-left corner of the maze
    int x = 0;
    int y = 0;

    // While we haven't reached the bottom-right corner of the maze
    while (x != m->width - 1 || y != m->height - 1) {
        // If the current cell is a wall
        if (m->cells[y][x] == 0) {
            // Return 0 to indicate that the maze is unsolvable
            return 0;
        } else {
            // If the current cell is not a wall
            // Mark the current cell as visited
            m->cells[y][x] = 2;

            // Check if we have reached the bottom-right corner of the maze
            if (x == m->width - 1 && y == m->height - 1) {
                // Return 1 to indicate that the maze is solvable
                return 1;
            }

            // Randomly choose a direction to move
            int direction = rand() % 4;

            // Move in the chosen direction
            switch (direction) {
                case 0:  // Up
                    y--;
                    break;
                case 1:  // Right
                    x++;
                    break;
                case 2:  // Down
                    y++;
                    break;
                case 3:  // Left
                    x--;
                    break;
            }
        }
    }

    // Return 0 to indicate that the maze is unsolvable
    return 0;
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a maze
    maze *m = generate_maze(10, 10);

    // Print the maze to the console
    print_maze(m);

    // Solve the maze
    int solved = solve_maze(m);

    // Print whether the maze was solved or not
    if (solved) {
        printf("The maze was solved!\n");
    } else {
        printf("The maze was not solved.\n");
    }

    // Free the memory allocated for the maze
    free_maze(m);

    return 0;
}
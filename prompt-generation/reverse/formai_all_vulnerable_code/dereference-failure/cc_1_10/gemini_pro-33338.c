//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: cheerful
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Forward declarations
int** createMaze(int width, int height);
void printMaze(int** maze, int width, int height);
void freeMaze(int** maze, int width, int height);

int main() {
    // Cheerful greetings!
    printf("Hello there, maze adventurer! 🎉\n\n");

    // Let's get some maze dimensions from you!
    int width, height;
    printf("How wide should your maze be? (Enter an integer): ");
    scanf("%d", &width);
    printf("And how tall should it be? (Enter an integer): ");
    scanf("%d", &height);

    // Let's create a brand-new, sparkly clean maze! ✨
    srand(time(NULL)); // Seed the random number generator with the current time
    int** maze = createMaze(width, height);

    // Time to show off our masterpiece! 🤩
    printf("\nYour spectacular maze:\n");
    printMaze(maze, width, height);

    // Don't forget to tidy up after ourselves! 🧹
    freeMaze(maze, width, height);

    // We're all done! Thanks for joining us on this maze-making adventure! 🌈
    printf("\nHave a splendid day, maze explorer!");

    return 0;
}

// Creates a maze of the specified width and height.
int** createMaze(int width, int height) {
    // Initialize the maze with walls everywhere
    int** maze = malloc(height * sizeof(int*));
    for (int i = 0; i < height; i++) {
        maze[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            maze[i][j] = 1;
        }
    }

    // Now let's carve out some paths!
    int x = 1, y = 1; // Starting position
    while (x != width - 2 || y != height - 2) {
        // Choose a random direction to move in
        int direction = rand() % 4;
        switch (direction) {
            case 0: // Up
                if (y > 1 && maze[y - 2][x] == 1) {
                    maze[y - 2][x] = 0;
                    maze[y - 1][x] = 0;
                    y -= 2;
                }
                break;
            case 1: // Right
                if (x < width - 2 && maze[y][x + 2] == 1) {
                    maze[y][x + 2] = 0;
                    maze[y][x + 1] = 0;
                    x += 2;
                }
                break;
            case 2: // Down
                if (y < height - 2 && maze[y + 2][x] == 1) {
                    maze[y + 2][x] = 0;
                    maze[y + 1][x] = 0;
                    y += 2;
                }
                break;
            case 3: // Left
                if (x > 1 && maze[y][x - 2] == 1) {
                    maze[y][x - 2] = 0;
                    maze[y][x - 1] = 0;
                    x -= 2;
                }
                break;
        }
    }

    return maze;
}

// Prints the maze to the console.
void printMaze(int** maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == 1) {
                printf("■"); // Wall
            } else {
                printf("  "); // Open space
            }
        }
        printf("\n");
    }
}

// Frees the memory allocated for the maze.
void freeMaze(int** maze, int width, int height) {
    for (int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
}
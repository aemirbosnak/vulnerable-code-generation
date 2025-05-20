//Gemma-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: minimalist
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 10
#define WALL_CHAR '#'
#define EMPTY_CHAR '.'
#define PLAYER_CHAR 'P'

void generateMaze(int **maze, int size) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            maze[i][j] = EMPTY_CHAR + rand() % 2;
        }
    }

    // Create walls
    maze[0][0] = maze[0][size - 1] = WALL_CHAR;
    maze[size - 1][0] = maze[size - 1][size - 1] = WALL_CHAR;

    // Connect rooms
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (maze[i][j] == EMPTY_CHAR) {
                int direction = rand() % 4;
                switch (direction) {
                    case 0:
                        maze[i - 1][j] = WALL_CHAR;
                        break;
                    case 1:
                        maze[i][j + 1] = WALL_CHAR;
                        break;
                    case 2:
                        maze[i + 1][j] = WALL_CHAR;
                        break;
                    case 3:
                        maze[i][j - 1] = WALL_CHAR;
                        break;
                }
            }
        }
    }
}

int main() {
    int **maze = NULL;
    int size = MAP_SIZE;

    maze = (int **)malloc(size * size * sizeof(int));
    generateMaze(maze, size);

    // Draw the maze
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    // Place the player
    maze[1][1] = PLAYER_CHAR;

    // Draw the player
    printf("%c ", maze[1][1]);

    return 0;
}
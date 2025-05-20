//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int width;
    int height;
    char **grid;
} Maze;

Maze *createMaze(int width, int height) {
    Maze *maze = (Maze *)malloc(sizeof(Maze));
    if (!maze) return NULL;

    maze->width = width;
    maze->height = height;
    maze->grid = (char **)malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze->grid[i] = (char *)malloc(width * sizeof(char));
    }

    // Fill the maze with walls
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze->grid[i][j] = WALL;
        }
    }

    return maze;
}

void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void generateMaze(Maze *maze, int x, int y) {
    int directions[4][2] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    for (int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        int temp[2] = {directions[i][0], directions[i][1]};
        directions[i][0] = directions[randomIndex][0];
        directions[i][1] = directions[randomIndex][1];
        directions[randomIndex][0] = temp[0];
        directions[randomIndex][1] = temp[1];
    }

    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (newX > 0 && newX < maze->width && newY > 0 && newY < maze->height &&
            maze->grid[newY][newX] == WALL) {
            maze->grid[newY][newX] = PATH;
            maze->grid[y + directions[i][1] / 2][x + directions[i][0] / 2] = PATH;
            generateMaze(maze, newX, newY);
        }
    }
}

void displayMaze(Maze *maze) {
    printf("\nMaze:\n");
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

void placeStartAndEnd(Maze *maze) {
    maze->grid[1][1] = START;
    maze->grid[maze->height - 2][maze->width - 2] = END;
}

int main() {
    srand(time(NULL));

    int width = 81; // Must be odd
    int height = 21; // Must be odd

    Maze *maze = createMaze(width, height);
    if (!maze) {
        printf("Failed to create maze.\n");
        return 1;
    }

    maze->grid[1][1] = PATH;
    generateMaze(maze, 1, 1);
    placeStartAndEnd(maze);
    displayMaze(maze);

    freeMaze(maze);
    return 0;
}
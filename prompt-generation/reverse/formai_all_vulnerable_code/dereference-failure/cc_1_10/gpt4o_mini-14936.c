//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

typedef struct {
    int width;
    int height;
    char **grid;
} Maze;

void initializeMaze(Maze *maze, int width, int height) {
    maze->width = width;
    maze->height = height;
    maze->grid = malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(width * sizeof(char));
        for (int j = 0; j < width; j++) {
            maze->grid[i][j] = WALL;
        }
    }
}

void freeMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
}

void carvePath(Maze *maze, int x, int y) {
    // Define the possible moves: (dx, dy)
    int directions[4][2] = {{2, 0}, {-2, 0}, {0, 2}, {0, -2}};
      
    // Shuffle directions
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;
        int tempX = directions[i][0];
        int tempY = directions[i][1];
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = tempX;
        directions[j][1] = tempY;
    }

    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];
        
        if (newX > 0 && newX < maze->width && newY > 0 && newY < maze->height && maze->grid[newY][newX] == WALL) {
            maze->grid[y + directions[i][1] / 2][x + directions[i][0] / 2] = PATH;
            maze->grid[newY][newX] = PATH;
            carvePath(maze, newX, newY);
        }
    }
}

void generateMaze(Maze *maze) {
    srand(time(0));
    // Start carving from (1,1)
    maze->grid[1][1] = PATH;
    carvePath(maze, 1, 1);
}

void printMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%c", maze->grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int width = 21;
    int height = 21;
    
    // Check for a valid size
    if (width % 2 == 0) width++;
    if (height % 2 == 0) height++;
    
    Maze maze;
    initializeMaze(&maze, width, height);
    generateMaze(&maze);
    
    // Set start and end points
    maze.grid[1][1] = START;
    maze.grid[height - 2][width - 2] = END;

    printMaze(&maze);
    freeMaze(&maze);
    return 0;
}
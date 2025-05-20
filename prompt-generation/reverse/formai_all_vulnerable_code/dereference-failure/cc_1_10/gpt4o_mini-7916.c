//GPT-4o-mini DATASET v1.0 Category: Procedurally Generated Maze ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WALL '#'
#define PATH ' '
#define START 'S'
#define END 'E'

typedef struct {
    int x, y;
} Position;

typedef struct {
    int width, height;
    char **grid;
} Maze;

Maze* createMaze(int width, int height);
void destroyMaze(Maze* maze);
void generateMaze(Maze* maze, int startX, int startY);
void printMaze(Maze* maze);
void carvePath(Maze* maze, int x, int y);
int isValidMove(Maze* maze, int x, int y);
void shuffleDirections(Position* directions);
void placeStartAndEnd(Maze* maze);

int main() {
    srand(time(NULL));
    int width = 21; // Should be odd
    int height = 21; // Should be odd

    Maze* maze = createMaze(width, height);
    generateMaze(maze, 1, 1);
    placeStartAndEnd(maze);
    printMaze(maze);
    destroyMaze(maze);

    return 0;
}

Maze* createMaze(int width, int height) {
    Maze* maze = (Maze*)malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;

    maze->grid = (char**)malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++) {
        maze->grid[i] = (char*)malloc(width * sizeof(char));
    }

    // Fill grid with walls
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            maze->grid[y][x] = WALL;
        }
    }

    return maze;
}

void destroyMaze(Maze* maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void generateMaze(Maze* maze, int startX, int startY) {
    carvePath(maze, startX, startY);
}

void carvePath(Maze* maze, int x, int y) {
    Position directions[4] = {
        {0, 2}, {2, 0}, {0, -2}, {-2, 0} // Right, Down, Up, Left
    };

    shuffleDirections(directions);

    for (int i = 0; i < 4; i++) {
        Position direction = directions[i];
        int newX = x + direction.x;
        int newY = y + direction.y;

        if (isValidMove(maze, newX, newY)) {
            maze->grid[newY][newX] = PATH; // Carve path
            maze->grid[y + direction.y / 2][x + direction.x / 2] = PATH; // Carve between
            carvePath(maze, newX, newY);
        }
    }
}

int isValidMove(Maze* maze, int x, int y) {
    if (x > 0 && x < maze->width && y > 0 && y < maze->height) {
        return maze->grid[y][x] == WALL;
    }
    return 0;
}

void shuffleDirections(Position* directions) {
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        Position temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
}

void placeStartAndEnd(Maze* maze) {
    maze->grid[1][0] = START; // Starting point
    maze->grid[maze->height - 2][maze->width - 1] = END; // Ending point
}

void printMaze(Maze* maze) {
    for (int y = 0; y < maze->height; y++) {
        for (int x = 0; x < maze->width; x++) {
            putchar(maze->grid[y][x]);
        }
        putchar('\n');
    }
}
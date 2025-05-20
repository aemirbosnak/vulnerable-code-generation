//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point *start;
    Point *end;
    int **grid;
    int width;
    int height;
} Maze;

Maze *createMaze(int width, int height) {
    Maze *maze = malloc(sizeof(Maze));
    maze->width = width;
    maze->height = height;
    maze->grid = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        maze->grid[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++) {
            maze->grid[i][j] = 0;
        }
    }
    return maze;
}

void destroyMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        free(maze->grid[i]);
    }
    free(maze->grid);
    free(maze);
}

void printMaze(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            printf("%d ", maze->grid[i][j]);
        }
        printf("\n");
    }
}

Point *findStart(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->grid[i][j] == 0) {
                return &(Point){j, i};
            }
        }
    }
    return NULL;
}

Point *findEnd(Maze *maze) {
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (maze->grid[i][j] == 2) {
                return &(Point){j, i};
            }
        }
    }
    return NULL;
}

int isWall(Maze *maze, Point *point) {
    return maze->grid[point->y][point->x] == 1;
}

int isVisited(Maze *maze, Point *point) {
    return maze->grid[point->y][point->x] == 3;
}

void markVisited(Maze *maze, Point *point) {
    maze->grid[point->y][point->x] = 3;
}

int isEnd(Maze *maze, Point *point) {
    return maze->grid[point->y][point->x] == 2;
}

int findPath(Maze *maze, Point *start, Point *end) {
    int steps = 0;
    Point *current = start;
    while (!isEnd(maze, current)) {
        if (!isVisited(maze, current)) {
            markVisited(maze, current);
            steps++;
        }
        if (!isWall(maze, current) && !isVisited(maze, current)) {
            maze->grid[current->y][current->x] = 3;
            steps++;
        }
        if (current->x < maze->width - 1 && !isWall(maze, &(Point){current->x + 1, current->y}) && !isVisited(maze, &(Point){current->x + 1, current->y})) {
            current->x++;
        } else if (current->y < maze->height - 1 && !isWall(maze, &(Point){current->x, current->y + 1}) && !isVisited(maze, &(Point){current->x, current->y + 1})) {
            current->y++;
        } else if (current->x > 0 && !isWall(maze, &(Point){current->x - 1, current->y}) && !isVisited(maze, &(Point){current->x - 1, current->y})) {
            current->x--;
        } else if (current->y > 0 && !isWall(maze, &(Point){current->x, current->y - 1}) && !isVisited(maze, &(Point){current->x, current->y - 1})) {
            current->y--;
        } else {
            return -1;
        }
    }
    return steps;
}

int main() {
    srand(time(NULL));
    int width = 10;
    int height = 10;
    Maze *maze = createMaze(width, height);
    for (int i = 0; i < maze->height; i++) {
        for (int j = 0; j < maze->width; j++) {
            if (rand() % 2 == 0) {
                maze->grid[i][j] = 1;
            }
        }
    }
    maze->grid[0][0] = 0;
    maze->grid[width - 1][height - 1] = 2;
    Point *start = findStart(maze);
    Point *end = findEnd(maze);
    int steps = findPath(maze, start, end);
    if (steps == -1) {
        printf("No path found.\n");
    } else {
        printf("Path found in %d steps.\n", steps);
    }
    printMaze(maze);
    destroyMaze(maze);
    return 0;
}
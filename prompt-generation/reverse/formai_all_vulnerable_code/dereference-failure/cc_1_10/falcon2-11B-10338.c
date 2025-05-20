//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    int x;
    int y;
} Coordinate;

typedef struct {
    Coordinate start;
    Coordinate end;
    int rows;
    int cols;
    int **maze;
} Maze;

typedef struct {
    Coordinate current;
    int level;
    bool visited;
} Node;

void printMaze(Maze *maze) {
    printf("Maze:\n");
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%3d", maze->maze[i][j]);
        }
        printf("\n");
    }
}

void initializeMaze(Maze *maze, int startX, int startY, int endX, int endY) {
    maze->rows = MAX_ROWS;
    maze->cols = MAX_COLS;
    maze->maze = malloc(maze->rows * sizeof(int*));
    for (int i = 0; i < maze->rows; i++) {
        maze->maze[i] = malloc(maze->cols * sizeof(int));
        for (int j = 0; j < maze->cols; j++) {
            maze->maze[i][j] = 1;
        }
    }

    maze->start.x = startX;
    maze->start.y = startY;
    maze->end.x = endX;
    maze->end.y = endY;
}

void dfs(Maze *maze, Node *node, int *level) {
    node->visited = true;
    maze->maze[node->current.x][node->current.y] = 0;

    if (node->current.x == maze->end.x && node->current.y == maze->end.y) {
        *level = node->level;
    } else {
        int dx = -1, dy = 0, d = 0;
        int nextX, nextY;

        for (int i = 0; i < 4; i++) {
            nextX = node->current.x + dx;
            nextY = node->current.y + dy;

            if (nextX >= 0 && nextX < maze->rows && nextY >= 0 && nextY < maze->cols && maze->maze[nextX][nextY] == 0) {
                d = i;
                break;
            }
        }

        node->current.x += dx;
        node->current.y += dy;
        dfs(maze, node, level);
        node->current.x -= dx;
        node->current.y -= dy;
    }
}

void findPath(Maze *maze) {
    Node node;
    initializeMaze(maze, maze->start.x, maze->start.y, maze->end.x, maze->end.y);
    node.current = maze->start;
    node.level = 0;
    node.visited = false;

    dfs(maze, &node, &node.level);

    printf("Path length: %d\n", node.level);
    printf("Path: ");
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            if (maze->maze[i][j] == 1) {
                printf("%d ", i * maze->cols + j + 1);
            }
        }
        printf("\n");
    }
}

int main() {
    Maze maze;
    initializeMaze(&maze, 1, 1, 1, 1);
    findPath(&maze);
    return 0;
}
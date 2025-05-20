//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int x;
    int y;
    int visited;
    struct Node *next;
} Node;

typedef struct Maze {
    int rows;
    int cols;
    Node **maze;
} Maze;

void printMaze(Maze *maze) {
    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            printf("%d ", maze->maze[i][j].visited);
        }
        printf("\n");
    }
}

void initializeMaze(Maze *maze, int rows, int cols) {
    maze->rows = rows;
    maze->cols = cols;
    maze->maze = (Node **)malloc(rows * sizeof(Node *));
    for (int i = 0; i < rows; i++) {
        maze->maze[i] = (Node *)malloc(cols * sizeof(Node));
        for (int j = 0; j < cols; j++) {
            maze->maze[i][j].next = NULL;
            maze->maze[i][j].visited = 0;
        }
    }
}

void generateMaze(Maze *maze) {
    srand(time(NULL));

    Node *current = maze->maze[0][0].next;
    Node *next;
    int i, j;

    for (i = 0; i < maze->rows; i++) {
        for (j = 0; j < maze->cols; j++) {
            if (current->visited == 0) {
                next = current->next;
                current->visited = 1;
                maze->maze[i][j].next = current;

                while (next!= NULL && next->visited == 0) {
                    next = next->next;
                }
                current = next;
            }
        }
    }
}

int main() {
    int rows = 10, cols = 10;
    Maze maze;
    initializeMaze(&maze, rows, cols);
    generateMaze(&maze);
    printMaze(&maze);
    free(maze.maze);
    return 0;
}
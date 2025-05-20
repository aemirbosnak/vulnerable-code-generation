//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 30
#define MAX_COLS 30
#define INITIAL_ROWS 1
#define INITIAL_COLS 1
#define MAX_VISITED_ROWS 1000
#define MAX_VISITED_COLS 1000

typedef struct {
    int row;
    int col;
} Coordinate;

typedef struct {
    int row;
    int col;
    int parentRow;
    int parentCol;
    int visited;
} Node;

void initializeMaze(Node** maze, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            maze[i][j].row = i;
            maze[i][j].col = j;
            maze[i][j].parentRow = -1;
            maze[i][j].parentCol = -1;
            maze[i][j].visited = 0;
        }
    }
}

void generateMaze(Node** maze, int rows, int cols) {
    int i, j;
    Node* startNode = &maze[INITIAL_ROWS][INITIAL_COLS];
    startNode->visited = 1;
    Node* currentNode = startNode;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (currentNode->visited == 0) {
                break;
            } else {
                currentNode = &maze[currentNode->row][currentNode->col];
                currentNode->visited = 1;
                generateMaze(maze, rows, cols);
            }
        }
    }
}

void printMaze(Node** maze, int rows, int cols) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (maze[i][j].visited) {
                printf(" * ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Node** maze = (Node**)malloc(MAX_ROWS * sizeof(Node*));
    int rows = MAX_ROWS;
    int cols = MAX_COLS;

    srand(time(NULL));

    initializeMaze(maze, rows, cols);
    generateMaze(maze, rows, cols);
    printMaze(maze, rows, cols);

    free(maze);

    return 0;
}
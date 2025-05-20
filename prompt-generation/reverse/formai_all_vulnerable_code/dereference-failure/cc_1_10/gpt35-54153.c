//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '#', '.', '.', '#'},
    {'#', '.', '#', '.', '#', '.', '.', '#'},
    {'#', '.', '#', '.', '.', '.', '.', '#'},
    {'#', '.', '.', '#', '.', '#', '.', '#'},
    {'#', '.', '#', '.', '.', '#', '.', '#'},
    {'#', '.', '#', '#', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#'}
};

typedef struct Node {
    int row;
    int col;
    struct Node* next;
} Node;

Node* createNode(int row, int col, Node* next) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->next = next;
    return node;
}

Node* push(Node* top, int row, int col) {
    return createNode(row, col, top);
}

Node* pop(Node* top) {
    Node* node = top->next;
    free(top);
    return node;
}

bool isWall(int row, int col) {
    return maze[row][col] == '#';
}

bool isVisited(int row, int col, bool visited[][COLS]) {
    return visited[row][col] == true;
}

bool isOutside(int row, int col) {
    return row < 0 || row == ROWS || col < 0 || col == COLS;
}

Node* solveMaze(int startRow, int startCol, int endRow, int endCol) {
    Node* path = NULL;
    bool visited[ROWS][COLS] = { false };
    Node* top = push(NULL, startRow, startCol);
    visited[startRow][startCol] = true;

    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    while (top != NULL) {
        int row = top->row;
        int col = top->col;

        if (row == endRow && col == endCol) {
            path = top;
            break;
        }

        bool deadEnd = true;
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];

            if (!isWall(newRow, newCol) && !isVisited(newRow, newCol, visited) && !isOutside(newRow, newCol)) {
                top = push(top, newRow, newCol);
                visited[newRow][newCol] = true;
                deadEnd = false;
            }
        }

        if (deadEnd) {
            top = pop(top);
        }
    }

    if (path != NULL) {
        printf("Path from (%d, %d) to (%d, %d):\n", startRow, startCol, endRow, endCol);
        while (path != NULL) {
            printf("(%d,%d) ", path->row, path->col);
            path = path->next;
        }
        printf("\n");
    } else {
        printf("No path found from (%d, %d) to (%d, %d).\n", startRow, startCol, endRow, endCol);
    }

    return path;
}

int main() {
    solveMaze(1, 1, 6, 6);
    return 0;
}
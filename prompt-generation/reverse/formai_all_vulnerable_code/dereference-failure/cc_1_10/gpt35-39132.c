//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

struct Node {
    int row;
    int col;
    struct Node* parent;
};

int ROWS[] = {-1, 0, 0, 1};
int COLS[] = {0, -1, 1, 0};

bool isValid(int row, int col) {
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}

bool isSafe(int mat[][COL], int row, int col,
            bool visited[][COL]) {
    return (mat[row][col] && !visited[row][col]);
}

void printPath(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printPath(node->parent);
    printf("(%d,%d) -> ", node->row, node->col);
}

void BFS(int mat[][COL], int srcRow, int srcCol,
         int dstRow, int dstCol) {
    bool visited[ROW][COL];
    memset(visited, false, sizeof(visited));
    visited[srcRow][srcCol] = true;
    struct Node* queue = (struct Node*)malloc(sizeof(struct Node));
    queue->row = srcRow;
    queue->col = srcCol;
    queue->parent = NULL;
    while (queue != NULL) {
        struct Node* current = queue;
        queue = queue->parent;
        int row = current->row;
        int col = current->col;
        if (row == dstRow && col == dstCol) {
            printPath(current);
            return;
        }
        for (int i = 0; i < 4; i++) {
            int adjRow = row + ROWS[i];
            int adjCol = col + COLS[i];
            if (isValid(adjRow, adjCol) && isSafe(mat, adjRow, adjCol, visited)) {
                visited[adjRow][adjCol] = true;
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->row = adjRow;
                newNode->col = adjCol;
                newNode->parent = current;
                current->parent = newNode;
                newNode->parent = current;
                queue = newNode;
            }
        }
    }
}

int main() {
    int mat[ROW][COL] = {
        {1, 1, 1, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {0, 0, 1, 1, 0}
    };
    int srcRow = 0;
    int srcCol = 0;
    int dstRow = 2;
    int dstCol = 4;
    printf("Path: ");
    BFS(mat, srcRow, srcCol, dstRow, dstCol);
    printf("\b\b\b   \n");
    return 0;
}
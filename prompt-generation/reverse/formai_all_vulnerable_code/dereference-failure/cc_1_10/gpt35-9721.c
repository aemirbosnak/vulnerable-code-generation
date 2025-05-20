//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

int visited[ROW][COL];
int maze[ROW][COL] = {
    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

typedef struct node {
    int row, col, distance;
} Node;

void push(Node** queue, int* tail, int row, int col, int distance) {
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->row = row;
    temp->col = col;
    temp->distance = distance;

    (*queue)[(*tail)++] = *temp;
    free(temp);
}

Node pop(Node** queue, int* head) {
    return (*queue)[(*head)++];
}

void printPath(int (*path)[ROW][COL], int row, int col) {
    if (row == 0 && col == 0) {
        printf("(%d, %d) ", row, col);
        return;
    }
    int prevRow = (*path)[row][col] / 100;
    int prevCol = (*path)[row][col] % 100;

    printPath(path, prevRow, prevCol);
    printf("(%d, %d) ", row, col);
}

void breathFirstSearch(int (*path)[ROW][COL], int* distance) {
    Node* queue = (Node*) malloc(sizeof(Node) * ROW * COL);
    int head = 0, tail = 0;
    push(&queue, &tail, 0, 0, 0);
    visited[0][0] = 1;

    while (head != tail) {
        Node currNode = pop(&queue, &head);
        int currRow = currNode.row;
        int currCol = currNode.col;

        if (currRow == ROW - 1 && currCol == COL - 1) {
            printf("Shortest Distance: %d\n", currNode.distance);
            printPath(&path, currRow, currCol);
            return;
        }

        if (currRow - 1 >= 0 && maze[currRow - 1][currCol] == 0 && !visited[currRow - 1][currCol]) {
            visited[currRow - 1][currCol] = 1;
            push(&queue, &tail, currRow - 1, currCol, currNode.distance + 1);
            (*path)[currRow - 1][currCol] = currRow * 100 + currCol;
        }

        if (currRow + 1 < ROW && maze[currRow + 1][currCol] == 0 && !visited[currRow + 1][currCol]) {
            visited[currRow + 1][currCol] = 1;
            push(&queue, &tail, currRow + 1, currCol, currNode.distance + 1);
            (*path)[currRow + 1][currCol] = currRow * 100 + currCol;
        }

        if (currCol - 1 >= 0 && maze[currRow][currCol - 1] == 0 && !visited[currRow][currCol - 1]) {
            visited[currRow][currCol - 1] = 1;
            push(&queue, &tail, currRow, currCol - 1, currNode.distance + 1);
            (*path)[currRow][currCol - 1] = currRow * 100 + currCol;
        }

        if (currCol + 1 < COL && maze[currRow][currCol + 1] == 0 && !visited[currRow][currCol + 1]) {
            visited[currRow][currCol + 1] = 1;
            push(&queue, &tail, currRow, currCol + 1, currNode.distance + 1);
            (*path)[currRow][currCol + 1] = currRow * 100 + currCol;
        }
    }
}

int main() {
    int path[ROW][COL] = {0};
    int dis = -1;
    breathFirstSearch(&path, &dis);

    if (dis == -1) {
        printf("No path found");
    }

    return 0;
}
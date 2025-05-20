//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/*
 * This program implements the Breadth-First Search (BFS) algorithm for pathfinding in a maze
 * using a queue data structure. The maze is represented as a matrix of 0s and 1s where 0s 
 * represent walls and 1s represent free spaces. The BFS algorithm finds the shortest path 
 * from a start point to an end point in the maze.
 *
 * Author: Chatbot
 * Date: June 2021
 */

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {
    {1, 0, 0, 0, 1, 1, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
    {0, 0, 0, 0, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 0},
    {0, 0, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 1, 1, 0, 1, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 0, 0, 1, 0, 0, 1}
};

int visited[MAX_ROWS][MAX_COLS] = {0};
int parent[MAX_ROWS][MAX_COLS][2] = {0};
int start_row, start_col, end_row, end_col;

// Queue data structure
struct queue {
    int data[MAX_ROWS * MAX_COLS][2];
    int front;
    int rear;
};

void enqueue(struct queue *q, int row, int col) {
    q->data[q->rear][0] = row;
    q->data[q->rear][1] = col;
    q->rear++;
}

int* dequeue(struct queue *q) {
    int *front = q->data[q->front];
    q->front++;
    return front;
}

int is_empty(struct queue *q) {
    return q->front == q->rear;
}

void find_path(int row, int col) {
    if (row == start_row && col == start_col) {
        printf("(%d,%d)", row, col);
        return;
    }
    find_path(parent[row][col][0], parent[row][col][1]);
    printf(" -> (%d,%d)", row, col);
}

void bfs(struct queue *q) {
    while (!is_empty(q)) {
        int *node = dequeue(q);
        int row = node[0];
        int col = node[1];
        free(node);

        if (row == end_row && col == end_col) {
            printf("Found path: ");
            find_path(row, col);
            printf("\n");
            return;
        }

        visited[row][col] = 1;

        // Generate neighbors
        int neighbors[4][2] = { {row-1,col}, {row+1,col}, {row,col-1}, {row,col+1} };

        for (int i = 0; i < 4; i++) {
            int r = neighbors[i][0];
            int c = neighbors[i][1];
            if (r < 0 || r >= MAX_ROWS || c < 0 || c >= MAX_COLS) {
                continue;
            }
            if (visited[r][c]) {
                continue;
            }
            if (maze[r][c] == 0) {
                continue;
            }
            visited[r][c] = 1;
            parent[r][c][0] = row;
            parent[r][c][1] = col;
            enqueue(q, r, c);
        }
    }
    printf("No path found.\n");
}

int main() {
    start_row = 0;
    start_col = 0;
    end_row = 9;
    end_col = 9;

    struct queue *q = malloc(sizeof(struct queue));
    q->front = 0;
    q->rear = 0;

    enqueue(q, start_row, start_col);
    visited[start_row][start_col] = 1;

    bfs(q);

    free(q);
    return 0;
}
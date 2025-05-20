//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

struct Point {
    int x, y;
};

struct Node {
    struct Point point;
    struct Node *prev;
};

bool is_valid(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == 0;
}

void print_path(struct Node *node) {
    if (node == NULL) {
        return;
    }
    print_path(node->prev);
    printf("(%d,%d) ", node->point.x, node->point.y);
}

void find_path(int start_row, int start_col, int end_row, int end_col) {
    struct Node *queue = malloc(sizeof(struct Node));
    queue->point.x = start_row;
    queue->point.y = start_col;
    queue->prev = NULL;

    int front = 0, rear = 1;
    struct Node *tmp;
    while (front < rear) {
        struct Point p = queue[front].point;
        
        if (p.x == end_row && p.y == end_col) {
            print_path(&queue[front]);
            return;
        }

        // move up
        if (is_valid(p.x-1, p.y)) {
            tmp = malloc(sizeof(struct Node));
            tmp->point.x = p.x-1;
            tmp->point.y = p.y;
            tmp->prev = &queue[front];
            queue = realloc(queue, ++rear * sizeof(struct Node));
            queue[rear-1] = *tmp;
            free(tmp);
        }

        // move down
        if (is_valid(p.x+1, p.y)) {
            tmp = malloc(sizeof(struct Node));
            tmp->point.x = p.x+1;
            tmp->point.y = p.y;
            tmp->prev = &queue[front];
            queue = realloc(queue, ++rear * sizeof(struct Node));
            queue[rear-1] = *tmp;
            free(tmp);
        }

        // move left
        if (is_valid(p.x, p.y-1)) {
            tmp = malloc(sizeof(struct Node));
            tmp->point.x = p.x;
            tmp->point.y = p.y-1;
            tmp->prev = &queue[front];
            queue = realloc(queue, ++rear * sizeof(struct Node));
            queue[rear-1] = *tmp;
            free(tmp);
        }

        // move right
        if (is_valid(p.x, p.y+1)) {
            tmp = malloc(sizeof(struct Node));
            tmp->point.x = p.x;
            tmp->point.y = p.y+1;
            tmp->prev = &queue[front];
            queue = realloc(queue, ++rear * sizeof(struct Node));
            queue[rear-1] = *tmp;
            free(tmp);
        }

        front++;
    }

    printf("No path found\n");
}

int main() {
    find_path(1, 1, 8, 8);
    return 0;
}
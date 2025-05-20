//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 15

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct Node {
    int row;
    int col;
    int distance;
    struct Node* next;
};

struct Queue {
    int size;
    struct Node* first;
    struct Node* last;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->size = 0;
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

void enqueue(struct Queue* queue, int row, int col, int distance) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->row = row;
    node->col = col;
    node->distance = distance;
    node->next = NULL;
    if (queue->size == 0) {
        queue->first = node;
        queue->last = node;
    } else {
        queue->last->next = node;
        queue->last = node;
    }
    queue->size++;
}

struct Node* dequeue(struct Queue* queue) {
    struct Node* node = queue->first;
    queue->first = queue->first->next;
    queue->size--;
    if (queue->size == 0) {
        queue->last = NULL;
    }
    return node;
}

int isGoal(int row, int col) {
    return row == ROWS - 1 && col == COLS - 1;
}

int isValid(int row, int col) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        return 0;
    }
    return maze[row][col] == 0;
}

int bfs() {
    int minDistance = -1;
    struct Queue* queue = createQueue();
    enqueue(queue, 0, 0, 0);
    while (queue->size > 0) {
        struct Node* node = dequeue(queue);
        int row = node->row;
        int col = node->col;
        int distance = node->distance;
        if (isGoal(row, col)) {
            minDistance = distance;
            break;
        }
        if (isValid(row - 1, col)) {
            enqueue(queue, row - 1, col, distance + 1);
            maze[row - 1][col] = 2;
        }
        if (isValid(row + 1, col)) {
            enqueue(queue, row + 1, col, distance + 1);
            maze[row + 1][col] = 2;
        }
        if (isValid(row, col - 1)) {
            enqueue(queue, row, col - 1, distance + 1);
            maze[row][col - 1] = 2;
        }
        if (isValid(row, col + 1)) {
            enqueue(queue, row, col + 1, distance + 1);
            maze[row][col + 1] = 2;
        }
        free(node);
    }
    return minDistance;
}

void printMaze() {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int distance = bfs();
    if (distance != -1) {
        printf("The shortest distance to the end is: %d\n", distance);
        printMaze();
    } else {
        printf("There is no path to the end.\n");
    }
    return 0;
}
//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point point;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

int isEmpty(Queue* queue) {
    return (queue->head == NULL);
}

void enqueue(Queue* queue, Point point) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->point = point;
    node->next = NULL;
    if (queue->head == NULL) {
        queue->head = node;
        queue->tail = node;
    } else {
        queue->tail->next = node;
        queue->tail = node;
    }
}

Point dequeue(Queue* queue) {
    Point point;
    Node* temp;
    point = queue->head->point;
    temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    return point;
}

int BFS(int rows, int cols, int grid[][cols], Point start, Point end) {
    int* visited = (int*) calloc(rows * cols, sizeof(int));
    Queue queue;
    Point curr;
    int numSteps = 0;

    initQueue(&queue);
    enqueue(&queue, start);

    while (!isEmpty(&queue)) {
        curr = dequeue(&queue);
        visited[curr.y * cols + curr.x] = 1;

        if (curr.x == end.x && curr.y == end.y) {
            free(visited);
            return numSteps;
        }

        numSteps++;
        if (curr.x > 0 && grid[curr.y][curr.x - 1] != 1 && !visited[curr.y * cols + curr.x - 1]) {
            Point next = {curr.x - 1, curr.y};
            enqueue(&queue, next);
        }
        if (curr.x < cols - 1 && grid[curr.y][curr.x + 1] != 1 && !visited[curr.y * cols + curr.x + 1]) {
            Point next = {curr.x + 1, curr.y};
            enqueue(&queue, next);
        }
        if (curr.y > 0 && grid[curr.y - 1][curr.x] != 1 && !visited[(curr.y - 1) * cols + curr.x]) {
            Point next = {curr.x, curr.y - 1};
            enqueue(&queue, next);
        }
        if (curr.y < rows - 1 && grid[curr.y + 1][curr.x] != 1 && !visited[(curr.y + 1) * cols + curr.x]) {
            Point next = {curr.x, curr.y + 1};
            enqueue(&queue, next);
        }
    }

    free(visited);
    return -1;
}

int main() {
    int rows = 7, cols = 8, grid[7][8] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };
    Point start = {0, 0};
    Point end = {7, 6};
    printf("Number of steps: %d\n", BFS(rows, cols, grid, start, end));
    return 0;
}
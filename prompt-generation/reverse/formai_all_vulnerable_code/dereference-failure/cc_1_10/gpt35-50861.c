//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 1, 1, 1, 0, 0},
    {1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
    int row;
    int col;
    int dist;
} node_t;

typedef struct {
    int size;
    int front;
    int rear;
    node_t *nodes;
} queue_t;

queue_t* queue_init(int size) {
    queue_t *q = malloc(sizeof(queue_t));
    q->size = size;
    q->front = 0;
    q->rear = 0;
    q->nodes = malloc(sizeof(node_t) * size);
    return q;
}

void queue_destroy(queue_t *q) {
    free(q->nodes);
    free(q);
}

void queue_push(queue_t *q, int row, int col, int dist) {
    pthread_mutex_lock(&mutex);
    q->nodes[q->rear].row = row;
    q->nodes[q->rear].col = col;
    q->nodes[q->rear].dist = dist;
    q->rear = (q->rear + 1) % q->size;
    pthread_mutex_unlock(&mutex);
}

node_t* queue_pop(queue_t *q) {
    pthread_mutex_lock(&mutex);
    if (q->front == q->rear) {
        pthread_mutex_unlock(&mutex);
        return NULL;
    }
    node_t *node = &q->nodes[q->front];
    q->front = (q->front + 1) % q->size;
    pthread_mutex_unlock(&mutex);
    return node;
}

int in_bounds(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

int is_wall(int row, int col) {
    return maze[row][col] == 1;
}

void* find_path(void *q_ptr) {
    queue_t *q = (queue_t*) q_ptr;
    while (1) {
        node_t *current = queue_pop(q);
        if (!current) break;
        int row = current->row;
        int col = current->col;
        int dist = current->dist;
        if (maze[row][col] == 2) {
            printf("Shortest path found: %d\n", dist);
            queue_destroy(q);
            pthread_exit(NULL);
        }
        if (maze[row][col] != 0) continue;
        maze[row][col] = dist;
        for (int i = -1; i <= 1; i += 2) {
            if (in_bounds(row + i, col) && !is_wall(row + i, col)) {
                queue_push(q, row + i, col, dist + 1);
            }
            if (in_bounds(row, col + i) && !is_wall(row, col + i)) {
                queue_push(q, row, col + i, dist + 1);
            }
        }
    }
    return NULL;
}

int main() {
    queue_t *q = queue_init(ROWS * COLS);
    printf("Start searching...\n");
    queue_push(q, 0, 0, 1);
    pthread_t threads[4];
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, &find_path, (void*) q);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            printf("%d ", maze[row][col]);
        }
        printf("\n");
    }
    return 0;
}
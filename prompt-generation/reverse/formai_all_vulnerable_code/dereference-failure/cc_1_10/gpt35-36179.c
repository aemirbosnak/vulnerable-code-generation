//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 20

typedef struct node {
    int x;
    int y;
    struct node *parent;
} Node;

typedef struct queue {
    Node *data[ROWS * COLS];
    int head;
    int tail;
} Queue;

Queue *init_queue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->head = 0;
    queue->tail = 0;
    return queue;
}

void enqueue(Queue *queue, Node *node) {
    queue->data[queue->tail++] = node;
}

Node *dequeue(Queue *queue) {
    return queue->data[queue->head++];
}

int is_empty(Queue *queue) {
    return queue->head == queue->tail;
}

int maze[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};

int bfs(int start_x, int start_y, int end_x, int end_y) {
    Queue *queue = init_queue();
    Node *start = malloc(sizeof(Node));
    start->x = start_x;
    start->y = start_y;
    start->parent = NULL;
    enqueue(queue, start);
    maze[start_x][start_y] = 1;

    while (!is_empty(queue)) {
        Node *current = dequeue(queue);
        if (current->x == end_x && current->y == end_y) {
            Node *node = current;
            while (node) {
                maze[node->x][node->y] = 2;
                node = node->parent;
            }
            return 1;
        }
        Node *next;
        if (current->x > 0 && maze[current->x-1][current->y] == 0) { // Left
            next = malloc(sizeof(Node));
            next->x = current->x-1;
            next->y = current->y;
            next->parent = current;
            enqueue(queue, next);
            maze[next->x][next->y] = 1;
        }
        if (current->y > 0 && maze[current->x][current->y-1] == 0) { // Up
            next = malloc(sizeof(Node));
            next->x = current->x;
            next->y = current->y-1;
            next->parent = current;
            enqueue(queue, next);
            maze[next->x][next->y] = 1;
        }
        if (current->x < ROWS-1 && maze[current->x+1][current->y] == 0) { // Right
            next = malloc(sizeof(Node));
            next->x = current->x+1;
            next->y = current->y;
            next->parent = current;
            enqueue(queue, next);
            maze[next->x][next->y] = 1;
        }
        if (current->y < COLS-1 && maze[current->x][current->y+1] == 0) { // Down
            next = malloc(sizeof(Node));
            next->x = current->x;
            next->y = current->y+1;
            next->parent = current;
            enqueue(queue, next);
            maze[next->x][next->y] = 1;
        }
    }
    return 0;
}

int main() {
    int start_x = 3;
    int start_y = 3;
    int end_x = 7;
    int end_y = 18;

    int found = bfs(start_x, start_y, end_x, end_y);
    if (found) {
        printf("Path found!\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (maze[i][j] == 2) {
                    printf("* ");
                } else {
                    printf("%d ", maze[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("Path not found!\n");
    }
    return 0;
}
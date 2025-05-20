//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define WALL 'X'

char maze[ROWS][COLS] = {
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X             X             X",
    "X XXXXXXXXX XXX XXXXXXXXX X",
    "X XXXXXXXXX XXX XXXXXXXXX X",
    "X XXXXXXXXX XXX XXXXXXXXX X",
    "X                           X",
    "X XXXXXXXXX X XXXXXXXXX XXX",
    "X XXXXXXXXX X XXXXXXXXX XXX",
    "X           X X           X",
    "XXXX XXXX XX X XX XXXX XXXX",
    "XXXX XXXX XX X XX XXXX XXXX",
    "X           X X           X",
    "X XXXXXXXXX X XXXXXXXXX X",
    "X XXXXXXXXX X XXXXXXXXX X",
    "X                           X",
    "X XXXXXXXXX XXX XXXXXXXXX X",
    "X XXXXXXXXX XXX XXXXXXXXX X",
    "X             X             X",
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
};

typedef struct {
    int x;
    int y;
} Point;

typedef struct Node {
    Point p;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

int isQueueEmpty(Queue* q) {
    return (q->head == NULL);
}

void enqueue(Queue* q, Point p) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->p = p;
    new_node->next = NULL;

    if (isQueueEmpty(q)) {
        q->head = new_node;
        q->tail = new_node;
    }
    else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

void dequeue(Queue* q) {
    if (!isQueueEmpty(q)) {
        Node* temp = q->head;
        q->head = q->head->next;

        if (q->head == NULL) {
            q->tail = NULL;
        }

        free(temp);
    }
}

Point peek(Queue* q) {
    return q->head->p;
}

int bfs(Point start, Point end) {
    int visited[ROWS][COLS] = {0};
    int distance[ROWS][COLS] = {0};
    Queue q;
    initQueue(&q);

    enqueue(&q, start);
    visited[start.x][start.y] = 1;

    while (!isQueueEmpty(&q)) {
        Point current = peek(&q);
        dequeue(&q);

        if (current.x == end.x && current.y == end.y) {
            return distance[current.x][current.y];
        }

        if (current.x - 1 >= 0 && visited[current.x - 1][current.y] == 0 && maze[current.x - 1][current.y] != WALL) {
            Point next = {current.x - 1, current.y};
            enqueue(&q, next);
            visited[next.x][next.y] = 1;
            distance[next.x][next.y] = distance[current.x][current.y] + 1;
        }

        if (current.x + 1 < ROWS && visited[current.x + 1][current.y] == 0 && maze[current.x + 1][current.y] != WALL) {
            Point next = {current.x + 1, current.y};
            enqueue(&q, next);
            visited[next.x][next.y] = 1;
            distance[next.x][next.y] = distance[current.x][current.y] + 1;
        }

        if (current.y - 1 >= 0 && visited[current.x][current.y - 1] == 0 && maze[current.x][current.y - 1] != WALL) {
            Point next = {current.x, current.y - 1};
            enqueue(&q, next);
            visited[next.x][next.y] = 1;
            distance[next.x][next.y] = distance[current.x][current.y] + 1;
        }

        if (current.y + 1 < COLS && visited[current.x][current.y + 1] == 0 && maze[current.x][current.y + 1] != WALL) {
            Point next = {current.x, current.y + 1};
            enqueue(&q, next);
            visited[next.x][next.y] = 1;
            distance[next.x][next.y] = distance[current.x][current.y] + 1;
        }
    }

    return -1;
}

int main() {
    Point start = {1, 1};
    Point end = {ROWS - 2, COLS - 2};
    int distance = bfs(start, end);

    if (distance == -1) {
        printf("No path found.\n");
    }
    else {
        printf("Path found! Distance: %d\n", distance);
    }

    return 0;
}
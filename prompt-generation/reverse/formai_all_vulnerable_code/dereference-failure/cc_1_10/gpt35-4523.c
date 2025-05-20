//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

typedef struct node {
    int x;
    int y;
    struct node *ptr;
} Node;

typedef struct queue {
    Node *front;
    Node *rear;
} Queue;

int visited[ROW][COL];
int parent[ROW][COL];

void init(Queue *Q) {
    Q->front = NULL;
    Q->rear = NULL;
}

int is_empty(Queue *Q) {
    return (Q->front == NULL);
}

void enqueue(Queue *Q, int x, int y) {
    Node *N = (Node*)malloc(sizeof(Node));
    N->x = x;
    N->y = y;
    N->ptr = NULL;
    if (Q->rear == NULL) {
        Q->front = N;
        Q->rear = N;
    } else {
        Q->rear->ptr = N;
        Q->rear = N;
    }
}

Node* dequeue(Queue *Q) {
    if (is_empty(Q))
        return NULL;

    Node *temp = Q->front;
    Q->front = Q->front->ptr;
    if (Q->front == NULL)
        Q->rear = NULL;

    temp->ptr = NULL;
    return temp;
}

void print_path(int src_x, int src_y, int dest_x, int dest_y) {
    if (dest_x == src_x && dest_y == src_y) {
        printf("(%d, %d)\n", src_x, src_y);
        return;
    }

    print_path(src_x, src_y, parent[dest_x][dest_y]/100, parent[dest_x][dest_y]%100);
    printf("(%d, %d)\n", dest_x, dest_y);
}

void BFS(int mat[][COL], int src_x, int src_y, int dest_x, int dest_y) {
    Queue Q;
    init(&Q);
    visited[src_x][src_y] = 1;
    enqueue(&Q, src_x, src_y);

    while (!is_empty(&Q)) {
        Node *curr = dequeue(&Q);
        int x = curr->x;
        int y = curr->y;
        if (x == dest_x && y == dest_y) {
            print_path(src_x, src_y, dest_x, dest_y);
            return;
        }
        if (x-1 >= 0 && mat[x-1][y] && !visited[x-1][y]) {
            visited[x-1][y] = 1;
            parent[x-1][y] = x*100+y;
            enqueue(&Q, x-1, y);
        }
        if (x+1 < ROW && mat[x+1][y] && !visited[x+1][y]) {
            visited[x+1][y] = 1;
            parent[x+1][y] = x*100+y;
            enqueue(&Q, x+1, y);
        }
        if (y-1 >= 0 && mat[x][y-1] && !visited[x][y-1]) {
            visited[x][y-1] = 1;
            parent[x][y-1] = x*100+y;
            enqueue(&Q, x, y-1);
        }
        if (y+1 < COL && mat[x][y+1] && !visited[x][y+1]) {
            visited[x][y+1] = 1;
            parent[x][y+1] = x*100+y;
            enqueue(&Q, x, y+1);
        }
        free(curr);
    }
}

int main() {
    int mat[ROW][COL] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
                          {1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
                          {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
                          {1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
                          {1, 1, 0, 1, 0, 0, 1, 0, 0, 0},
                          {1, 1, 0, 1, 1, 1, 1, 0, 1, 1},
                          {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
                          {1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
                          {1, 1, 1, 1, 1, 0, 1, 1, 1, 1}};

    int src_x = 0, src_y = 0, dest_x = 3, dest_y = 7;
    BFS(mat, src_x, src_y, dest_x, dest_y);

    return 0;
}
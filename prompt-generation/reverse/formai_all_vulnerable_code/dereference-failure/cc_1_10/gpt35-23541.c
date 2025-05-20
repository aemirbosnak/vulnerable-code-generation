//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define ROW 7 // number of rows in maze
#define COL 7 // number of columns in maze

int maze[ROW][COL] = { // maze layout
    {1, 1, 1, 0, 1, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0, 1, 1},
    {1, 1, 0, 0, 1, 1, 1},
    {0, 0, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1}
};

int visited[ROW][COL] = { // keep track of visited cells
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0}
};

int start_row = 0; // starting row
int start_col = 0; // starting column
int end_row = ROW - 1; // ending row
int end_col = COL - 1; // ending column

typedef struct queue_node { // queue node struct
    int row;
    int col;
    struct queue_node *next;
} QueueNode;

typedef struct queue { // queue struct
    QueueNode *head;
    QueueNode *tail;
} Queue;

void enqueue(Queue *q, int row, int col) { // enqueue operation for queue
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;
    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
}

void dequeue(Queue *q) { // dequeue operation for queue
    if (q->head == NULL) {
        return;
    }
    QueueNode *temp = q->head;
    q->head = q->head->next;
    free(temp);
}

int is_queue_empty(Queue *q) { // check if queue is empty
    if (q->head == NULL) {
        return 1;
    }
    return 0;
}

int is_valid_move(int row, int col) { // check if move is valid
    if (row < 0 || row >= ROW) { // check if row is out of bounds
        return 0;
    }
    if (col < 0 || col >= COL) { // check if column is out of bounds
        return 0;
    }
    if (visited[row][col] == 1) { // check if cell has already been visited
        return 0;
    }
    if (maze[row][col] == 0) { // check if cell is a wall
        return 0;
    }
    return 1;
}

void find_route() { // find the route using bfs algorithm
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    visited[start_row][start_col] = 1;
    enqueue(&q, start_row, start_col);
    while (!is_queue_empty(&q)) {
        int row = q.head->row;
        int col = q.head->col;
        dequeue(&q);
        if (row == end_row && col == end_col) { // check if end has been reached
            return;
        }
        if (is_valid_move(row+1, col)) { // check if down is a valid move
            visited[row+1][col] = 1;
            enqueue(&q, row+1, col);
        }
        if (is_valid_move(row-1, col)) { // check if up is a valid move
            visited[row-1][col] = 1;
            enqueue(&q, row-1, col);
        }
        if (is_valid_move(row, col+1)) { // check if right is a valid move
            visited[row][col+1] = 1;
            enqueue(&q, row, col+1);
        }
        if (is_valid_move(row, col-1)) { // check if left is a valid move
            visited[row][col-1] = 1;
            enqueue(&q, row, col-1);
        }
    }
}

void print_route() { // print the route
    int row = end_row;
    int col = end_col;
    printf("Route:\n");
    while (row != start_row || col != start_col) {
        if (row+1 < ROW && visited[row+1][col] == 1) { // check if down was visited
            row = row+1;
            printf("(%d,%d)\n", row, col);
        }
        else if (row-1 >= 0 && visited[row-1][col] == 1) { // check if up was visited
            row = row-1;
            printf("(%d,%d)\n", row, col);
        }
        else if (col+1 < COL && visited[row][col+1] == 1) { // check if right was visited
            col = col+1;
            printf("(%d,%d)\n", row, col);
        }
        else if (col-1 >= 0 && visited[row][col-1] == 1) { // check if left was visited
            col = col-1;
            printf("(%d,%d)\n", row, col);
        }
    }
    printf("(%d,%d)\n", start_row, start_col);
}

int main() {
    find_route();
    print_route();
    return 0;
}
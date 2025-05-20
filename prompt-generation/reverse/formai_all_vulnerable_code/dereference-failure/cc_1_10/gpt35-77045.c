//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 10
#define MAX_COLS 10

int maze[MAX_ROWS][MAX_COLS] = {
    {0, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
};

typedef struct {
    int row;
    int col;
} Point;

typedef struct Node {
    Point point;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

Queue* create_queue();
void push(Queue* queue, Point point);
Point pop(Queue* queue);
int is_empty(Queue* queue);

void bfs(int sx, int sy, int tx, int ty);

int main() {
    int sx = 1, sy = 1;    // starting point
    int tx = 8, ty = 8;    // target point
    
    // find the shortest route from (sx, sy) to (tx, ty) using breadth-first search algorithm
    bfs(sx, sy, tx, ty);
    
    return 0;
}

Queue* create_queue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void push(Queue* queue, Point point) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->point = point;
    new_node->next = NULL;
    if (queue->tail == NULL) {
        queue->head = new_node;
        queue->tail = new_node;
    } else {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

Point pop(Queue* queue) {
    Point point = queue->head->point;
    Node* temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    return point;
}

int is_empty(Queue* queue) {
    return queue->head == NULL;
}

void bfs(int sx, int sy, int tx, int ty) {
    int visited[MAX_ROWS][MAX_COLS] = {0};
    int distance[MAX_ROWS][MAX_COLS];
    Point from[MAX_ROWS][MAX_COLS];
    Queue* queue = create_queue();
    
    Point start = { sx, sy };
    Point target = { tx, ty };
    push(queue, start);
    visited[sx][sy] = 1;
    distance[sx][sy] = 0;
    from[sx][sy] = start;
    
    while (!is_empty(queue)) {
        Point current = pop(queue);
        int row = current.row;
        int col = current.col;
        
        // if the target is reached, stop search
        if (row == tx && col == ty) {
            printf("The shortest route from (%d, %d) to (%d, %d) is:\n", sx, sy, tx, ty);
            while (!(row == sx && col == sy)) {
                Point prev = from[row][col];
                printf("(%d, %d) <- ", row, col);
                row = prev.row;
                col = prev.col;
            }
            printf("(%d, %d)\n", sx, sy);
            printf("The minimum distance is %d\n", distance[tx][ty]);
            return;
        }
        
        // check each unvisited neighboring cell
        if (row > 0 && maze[row-1][col] == 0 && !visited[row-1][col]) {  // up
            Point neighbor = { row-1, col };
            push(queue, neighbor);
            visited[row-1][col] = 1;
            distance[row-1][col] = distance[row][col] + 1;
            from[row-1][col] = current;
        }
        if (row < MAX_ROWS-1 && maze[row+1][col] == 0 && !visited[row+1][col]) {  // down
            Point neighbor = { row+1, col };
            push(queue, neighbor);
            visited[row+1][col] = 1;
            distance[row+1][col] = distance[row][col] + 1;
            from[row+1][col] = current;
        }
        if (col > 0 && maze[row][col-1] == 0 && !visited[row][col-1]) {  // left
            Point neighbor = { row, col-1 };
            push(queue, neighbor);
            visited[row][col-1] = 1;
            distance[row][col-1] = distance[row][col] + 1;
            from[row][col-1] = current;
        }
        if (col < MAX_COLS-1 && maze[row][col+1] == 0 && !visited[row][col+1]) {  // right
            Point neighbor = { row, col+1 };
            push(queue, neighbor);
            visited[row][col+1] = 1;
            distance[row][col+1] = distance[row][col] + 1;
            from[row][col+1] = current;
        }
    }
    
    // if the target is not reached
    printf("No route found from (%d, %d) to (%d, %d)\n", sx, sy, tx, ty);
}
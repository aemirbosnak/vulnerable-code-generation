//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

#define ROW 5
#define COL 5

int grid[ROW][COL];
int visited[ROW][COL];

// Define a struct to hold the x, y coordinates of a cell
typedef struct {
    int x;
    int y;
} Point;

// Define a queue to hold points
struct Queue {
    Point* arr[ROW*COL];
    int front, rear;
};

// Create a new queue
struct Queue* newQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Add a point to the queue
void enqueue(struct Queue* queue, Point* point) {
    queue->arr[++queue->rear] = point;
    if(queue->front == -1) {
        queue->front++;
    }
}

// Remove a point from the queue
Point* dequeue(struct Queue* queue) {
    Point* point = queue->arr[queue->front];
    if(queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front++;
    }
    return point;
}

// Check if a given point is valid
int isValid(int x, int y) {
    if(x < 0 || x >= ROW || y < 0 || y >= COL) {
        return 0;
    }
    if(grid[x][y] == 1) {
        return 0;
    }
    if(visited[x][y] == 1) {
        return 0;
    }
    return 1;
}

// Find the shortest path between two points on the grid
void findPath(Point* start, Point* end) {
    struct Queue* queue = newQueue();
    visited[start->x][start->y] = 1;
    enqueue(queue, start);
    while(!isEmpty(queue)) {
        Point* curr = dequeue(queue);
        if(curr->x == end->x && curr->y == end->y) {
            printf("Path found!\n");
            return;
        }
        Point up = {curr->x-1, curr->y};
        Point down = {curr->x+1, curr->y};
        Point left = {curr->x, curr->y-1};
        Point right = {curr->x, curr->y+1};
        if(isValid(up.x, up.y)) {
            visited[up.x][up.y] = 1;
            enqueue(queue, &up);
        }
        if(isValid(down.x, down.y)) {
            visited[down.x][down.y] = 1;
            enqueue(queue, &down);
        }
        if(isValid(left.x, left.y)) {
            visited[left.x][left.y] = 1;
            enqueue(queue, &left);
        }
        if(isValid(right.x, right.y)) {
            visited[right.x][right.y] = 1;
            enqueue(queue, &right);
        }
    }
    printf("No path found.\n");
}

// Initialize the grid and visited arrays
void initialize() {
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            grid[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][1] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
}

int main() {
    initialize();
    Point start = {0, 0};
    Point end = {4, 4};
    findPath(&start, &end);
    return 0;
}
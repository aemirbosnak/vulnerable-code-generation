//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROW 10
#define COL 10

// Define the structure for BFS queue
typedef struct {
    int x, y;  // Store coordinates of the cell
} Point;

// Direction vectors for moving in 4 directions (up, down, left, right)
int rowNum[] = {-1, 1, 0, 0};
int colNum[] = {0, 0, -1, 1};

// A queue structure for BFS
typedef struct {
    Point *points;
    int front, rear, size;
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->points = (Point*)malloc(capacity * sizeof(Point));
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    return queue;
}

// Queue operations
bool isFull(Queue* queue) {
    return (queue->size == ROW * COL);
}

bool isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Point p) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % (ROW * COL);
    queue->points[queue->rear] = p;
    queue->size++;
}

Point dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        Point p = {-1, -1}; // Return invalid point
        return p;
    }
    Point p = queue->points[queue->front];
    queue->front = (queue->front + 1) % (ROW * COL);
    queue->size--;
    return p;
}

// Function to check if a cell is valid for movement
bool isValid(int row, int col, int maze[ROW][COL], bool visited[ROW][COL]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && maze[row][col] == 0 && !visited[row][col]);
}

// Function to perform BFS and find the shortest path
void bfs(int maze[ROW][COL], Point start, Point end) {
    if (maze[start.x][start.y] == 1 || maze[end.x][end.y] == 1) {
        printf("No path exists from start to end.\n");
        return;
    }

    bool visited[ROW][COL];
    memset(visited, false, sizeof(visited));

    Queue* queue = createQueue(ROW * COL);
    enqueue(queue, start);
    visited[start.x][start.y] = true;

    while (!isEmpty(queue)) {
        Point current = dequeue(queue);
        printf("Visiting: (%d, %d)\n", current.x, current.y);

        if (current.x == end.x && current.y == end.y) {
            printf("Reached destination: (%d, %d)\n", end.x, end.y);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = current.x + rowNum[i];
            int newCol = current.y + colNum[i];

            if (isValid(newRow, newCol, maze, visited)) {
                visited[newRow][newCol] = true;
                Point next = {newRow, newCol};
                enqueue(queue, next);
            }
        }
    }
  
    printf("No path found to destination.\n");
}

// Main function to set up the maze and test BFS
int main() {
    int maze[ROW][COL] = {
        {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 1, 1, 0, 0}
    };

    Point start = {0, 0}; // Starting point
    Point end = {9, 9};   // Destination point

    printf("Starting BFS from (%d, %d) to (%d, %d)\n", start.x, start.y, end.x, end.y);
    bfs(maze, start, end);

    return 0;
}
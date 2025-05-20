//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

// Directions for movement: up, down, left, right
int rowDir[] = {-1, 1, 0, 0};
int colDir[] = {0, 0, -1, 1};

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point* points;
    int front, rear, capacity;
} Queue;

// Function to create a queue
Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = q->rear = 0;
    q->points = (Point*)malloc(capacity * sizeof(Point));
    return q;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

// Add an element to the queue
void enqueue(Queue* q, Point pt) {
    q->points[q->rear++] = pt;
}

// Remove an element from the queue
Point dequeue(Queue* q) {
    return q->points[q->front++];
}

// Check if a cell is valid and open
bool isValid(int row, int col, int grid[ROW][COL], bool visited[ROW][COL]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && grid[row][col] == 0 && !visited[row][col]);
}

// Function to implement BFS for pathfinding
bool bfs(int grid[ROW][COL], Point start, Point destination) {
    bool visited[ROW][COL] = {false};
    Queue* q = createQueue(ROW * COL);
    
    visited[start.x][start.y] = true;
    enqueue(q, start);

    while (!isEmpty(q)) {
        Point current = dequeue(q);

        if (current.x == destination.x && current.y == destination.y) {
            free(q->points);
            free(q);
            return true; // Path found
        }

        for (int i = 0; i < 4; i++) {
            int adjX = current.x + rowDir[i];
            int adjY = current.y + colDir[i];

            if (isValid(adjX, adjY, grid, visited)) {
                visited[adjX][adjY] = true;
                Point newPoint = {adjX, adjY};
                enqueue(q, newPoint);
            }
        }
    }

    free(q->points);
    free(q);
    return false; // No path
}

// Main function to visualize the peaceful pathfinding
int main() {
    int grid[ROW][COL] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}
    };

    Point start = {0, 0};      // Starting point
    Point destination = {4, 4}; // Destination point

    printf("Searching for the peaceful path...\n");

    if (bfs(grid, start, destination)) {
        printf("A harmonious path exists from (%d, %d) to (%d, %d).\n", start.x, start.y, destination.x, destination.y);
    } else {
        printf("Alas, there is no path in this serene landscape.\n");
    }

    return 0;
}
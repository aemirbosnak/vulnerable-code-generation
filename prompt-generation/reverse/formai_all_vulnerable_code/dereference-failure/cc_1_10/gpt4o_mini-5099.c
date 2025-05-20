//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 9
#define COL 10

// A structure to represent a cell in the grid
typedef struct {
    int x;
    int y;
} Cell;

// A structure to represent the queue
typedef struct {
    Cell *cells;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to create a queue of given capacity
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = 0;
    queue->cells = (Cell*)malloc(queue->capacity * sizeof(Cell));
    return queue;
}

// Queue functions
bool isQueueFull(Queue* queue) {
    return (queue->rear == queue->capacity);
}

bool isQueueEmpty(Queue* queue) {
    return (queue->front == queue->rear);
}

void enqueue(Queue* queue, Cell cell) {
    if (!isQueueFull(queue)) {
        queue->cells[queue->rear++] = cell;
    }
}

Cell dequeue(Queue* queue) {
    if (!isQueueEmpty(queue)) {
        return queue->cells[queue->front++];
    }
    Cell empty = {-1, -1};
    return empty;
}

// Directions for movement: up, down, left, right
int rowNum[] = {-1, 1, 0, 0};
int colNum[] = {0, 0, -1, 1};

// Function to check if a cell is valid
bool isValid(int row, int col, int grid[ROW][COL], bool visited[ROW][COL]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && grid[row][col] == 1 && !visited[row][col]);
}

// Function to perform BFS for pathfinding
bool bfs(int grid[ROW][COL], Cell start, Cell end) {
    if (grid[start.x][start.y] == 0 || grid[end.x][end.y] == 0) {
        return false;
    }

    bool visited[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            visited[i][j] = false;
        }
    }

    visited[start.x][start.y] = true;

    Queue* queue = createQueue(ROW * COL);
    enqueue(queue, start);

    while (!isQueueEmpty(queue)) {
        Cell current = dequeue(queue);

        // Check if we reached the destination
        if (current.x == end.x && current.y == end.y) {
            free(queue->cells);
            free(queue);
            return true;
        }

        // Explore neighbors
        for (int i = 0; i < 4; i++) {
            int newRow = current.x + rowNum[i];
            int newCol = current.y + colNum[i];
            if (isValid(newRow, newCol, grid, visited)) {
                visited[newRow][newCol] = true;
                Cell nextCell = {newRow, newCol};
                enqueue(queue, nextCell);
            }
        }
    }

    free(queue->cells);
    free(queue);
    return false;
}

// Main function
int main() {
    // Define the grid (1 represents traversable cells, 0 represents obstacles)
    int grid[ROW][COL] = {
        {1, 0, 1, 1, 1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0, 1, 1},
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    Cell start = {0, 0};
    Cell end = {8, 9};

    if (bfs(grid, start, end)) {
        printf("Path exists from start to end.\n");
    } else {
        printf("No path exists from start to end.\n");
    }

    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 10
#define COL 10

// Define structure to represent a cell in the grid
typedef struct {
    int x, y;
} Cell;

// A structure to represent the queue for BFS
typedef struct {
    Cell* cells;
    int front;
    int rear;
    int size;
} Queue;

// Function to create a new queue
Queue* createQueue(int size) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->size = size;
    queue->front = 0;
    queue->rear = 0;
    queue->cells = (Cell*)malloc(size * sizeof(Cell));
    return queue;
}

// Function to enqueue a cell
void enqueue(Queue* queue, Cell cell) {
    if (queue->rear < queue->size) {
        queue->cells[queue->rear++] = cell;
    }
}

// Function to dequeue a cell
Cell dequeue(Queue* queue) {
    if (queue->front < queue->rear) {
        return queue->cells[queue->front++];
    }
    Cell emptyCell = {-1, -1};
    return emptyCell;
}

// Check if a cell is valid to visit
bool isValid(int row, int col, bool visited[ROW][COL], int grid[ROW][COL]) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL && 
            !visited[row][col] && grid[row][col] == 1);
}

// Function to perform BFS
void bfs(int grid[ROW][COL], Cell start, Cell end) {
    bool visited[ROW][COL] = {false};
    Queue* queue = createQueue(ROW * COL);
    
    enqueue(queue, start);
    visited[start.x][start.y] = true;

    while (queue->front < queue->rear) {
        Cell current = dequeue(queue);
        
        // Check if we have reached the destination
        if (current.x == end.x && current.y == end.y) {
            printf("Path found from (%d, %d) to (%d, %d)\n", start.x, start.y, end.x, end.y);
            free(queue->cells);
            free(queue);
            return;
        }

        // Directions: right, left, down, up
        int rowDir[] = {0, 0, 1, -1};
        int colDir[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int newRow = current.x + rowDir[i];
            int newCol = current.y + colDir[i];

            if (isValid(newRow, newCol, visited, grid)) {
                visited[newRow][newCol] = true;
                Cell nextCell = {newRow, newCol};
                enqueue(queue, nextCell);
            }
        }
    }
    
    printf("No path found from (%d, %d) to (%d, %d)\n", start.x, start.y, end.x, end.y);
    
    free(queue->cells);
    free(queue);
}

int main() {
    int grid[ROW][COL] = {
        {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1, 1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 0, 0, 0, 1}
    };

    Cell start = {0, 0}; // Starting point
    Cell end = {9, 9};   // Ending point

    bfs(grid, start, end);

    return 0;
}
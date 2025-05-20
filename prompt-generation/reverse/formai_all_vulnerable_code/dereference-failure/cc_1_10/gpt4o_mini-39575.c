//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 5 // Size of the puzzle grid

// Directions for movements
int rowDirs[] = {-1, 1, 0, 0}; // Up, Down
int colDirs[] = {0, 0, -1, 1}; // Left, Right

// Structure to represent a cell in the grid
typedef struct {
    int x;
    int y;
    int cost;
} Cell;

// Priority queue for A* algorithm
typedef struct {
    Cell* cells;
    int size;
} PriorityQueue;

// Function to create a priority queue
PriorityQueue* createQueue(int capacity) {
    PriorityQueue* q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    q->cells = (Cell*)malloc(capacity * sizeof(Cell));
    q->size = 0;
    return q;
}

// Function to insert into the priority queue
void enqueue(PriorityQueue* q, int x, int y, int cost) {
    Cell newCell = {x, y, cost};
    q->cells[q->size++] = newCell;
}

// Function to extract min from priority queue
Cell dequeue(PriorityQueue* q) {
    int minIndex = 0;
    for (int i = 1; i < q->size; i++) {
        if (q->cells[i].cost < q->cells[minIndex].cost) {
            minIndex = i;
        }
    }
    Cell minCell = q->cells[minIndex];
    q->cells[minIndex] = q->cells[q->size - 1];
    q->size--;
    return minCell;
}

// Check if the position is valid
bool isValid(int x, int y, bool visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && !visited[x][y]);
}

// A* Pathfinding algorithm
void aStar(int grid[N][N], int startX, int startY, int targetX, int targetY) {
    // Visited array to track paths
    bool visited[N][N] = {false};
    int gCost[N][N] = {INT_MAX}; // Cost from start node
    int fCost[N][N]; // Total cost = gCost + hCost
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fCost[i][j] = INT_MAX;
        }
    }

    gCost[startX][startY] = 0;
    fCost[startX][startY] = 0; // Starting point

    PriorityQueue* queue = createQueue(N * N);
    enqueue(queue, startX, startY, fCost[startX][startY]);

    while (queue->size > 0) {
        Cell current = dequeue(queue);
        int x = current.x;
        int y = current.y;

        if (x == targetX && y == targetY) {
            printf("Path found to (%d, %d)!\n", targetX, targetY);
            return;
        }
        
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int newX = x + rowDirs[i];
            int newY = y + colDirs[i];
            if (isValid(newX, newY, visited) && grid[newX][newY] == 0) {
                int tentative_gCost = gCost[x][y] + 1; // Assume cost of moving to adjacent cell is 1

                if (tentative_gCost < gCost[newX][newY]) {
                    gCost[newX][newY] = tentative_gCost;
                    int hCost = abs(newX - targetX) + abs(newY - targetY); // Manhattan distance
                    fCost[newX][newY] = gCost[newX][newY] + hCost;

                    if (!visited[newX][newY]) {
                        enqueue(queue, newX, newY, fCost[newX][newY]);
                    }
                }
            }
        }
    }

    printf("No path found to (%d, %d).\n", targetX, targetY);
    free(queue->cells);
    free(queue);
}

// Main function to test the A* implementation
int main() {
    int grid[N][N] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int startX = 0, startY = 0;   // Starting position
    int targetX = 4, targetY = 4;  // Target position

    aStar(grid, startX, startY, targetX, targetY);
    return 0;
}
//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 10 // Size of the grid

// Define directions for 8 possible moves (N, NE, E, SE, S, SW, W, NW)
int rowMoves[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int colMoves[] = {0, 1, 1, 1, 0, -1, -1, -1};

// Structure to represent a cell in the grid
typedef struct {
    int x, y;
    int cost; // Cost to reach this cell from starting point
    int heuristic; // Heuristic cost from this cell to target
    int f; // Total cost
} Cell;

// Priority queue to hold cells for A* algorithm
typedef struct {
    Cell *cells;
    int size;
    int capacity;
} PriorityQueue;

// Function to initialize a priority queue
PriorityQueue* createQueue(int capacity) {
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    queue->cells = (Cell *)malloc(capacity * sizeof(Cell));
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

// Function to insert a cell into the priority queue
void enqueue(PriorityQueue *pq, Cell cell) {
    if (pq->size < pq->capacity) {
        pq->cells[pq->size++] = cell;
        // Maintain the min-heap property
        for (int i = pq->size - 1; i > 0; i--) {
            if (pq->cells[i].f < pq->cells[(i - 1) / 2].f) {
                Cell temp = pq->cells[i];
                pq->cells[i] = pq->cells[(i - 1) / 2];
                pq->cells[(i - 1) / 2] = temp;
            } else {
                break;
            }
        }
    }
}

// Function to remove and return the cell with minimum f cost
Cell dequeue(PriorityQueue *pq) {
    if (pq->size == 0) {
        Cell dummy = {-1, -1, -1, -1, -1};
        return dummy;
    }
    Cell minCell = pq->cells[0];
    pq->cells[0] = pq->cells[--pq->size];
    
    // Maintain the min-heap property
    for (int i = 0; i < pq->size;) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int smallest = i;

        if (leftChild < pq->size && pq->cells[leftChild].f < pq->cells[smallest].f) {
            smallest = leftChild;
        }
        if (rightChild < pq->size && pq->cells[rightChild].f < pq->cells[smallest].f) {
            smallest = rightChild;
        }
        if (smallest != i) {
            Cell temp = pq->cells[i];
            pq->cells[i] = pq->cells[smallest];
            pq->cells[smallest] = temp;
            i = smallest;
        } else {
            break;
        }
    }
    return minCell;
}

// Function to check if the given coordinates are valid
bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Function to calculate the heuristic (Manhattan distance)
int calculateHeuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// A* Pathfinding algorithm
void astar(int grid[N][N], int startX, int startY, int goalX, int goalY) {
    bool closedSet[N][N] = {false};
    PriorityQueue *openSet = createQueue(N * N);
    
    Cell start = {startX, startY, 0, calculateHeuristic(startX, startY, goalX, goalY), 0};
    start.f = start.cost + start.heuristic;
    enqueue(openSet, start);

    while (openSet->size != 0) {
        Cell current = dequeue(openSet);

        if (current.x == goalX && current.y == goalY) {
            printf("Path found to goal (%d, %d) with minimal cost %d\n", goalX, goalY, current.cost);
            free(openSet->cells);
            free(openSet);
            return;
        }

        closedSet[current.x][current.y] = true;

        // Explore neighbors
        for (int i = 0; i < 8; i++) {
            int newX = current.x + rowMoves[i];
            int newY = current.y + colMoves[i];

            if (isValid(newX, newY) && !closedSet[newX][newY] && grid[newX][newY] == 0) {
                Cell neighbor = {newX, newY, current.cost + 1, calculateHeuristic(newX, newY, goalX, goalY), 0};
                neighbor.f = neighbor.cost + neighbor.heuristic;
                enqueue(openSet, neighbor);
            }
        }
    }

    printf("No path found to goal (%d, %d)\n", goalX, goalY);
    free(openSet->cells);
    free(openSet);
}

int main() {
    int grid[N][N] = {
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 1, 1, 0}
    };

    int startX = 0, startY = 0; // Starting point
    int goalX = 9, goalY = 9; // Goal point

    printf("Starting A* Pathfinding from (%d, %d) to (%d, %d)...\n", startX, startY, goalX, goalY);
    astar(grid, startX, startY, goalX, goalY);
    return 0;
}
//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a cell in the grid
struct Cell {
    int row;
    int col;
    bool visited;
    bool blocked;
};

// Priority Queue for storing cells
struct PriorityQueue {
    int size;
    int capacity;
    struct Cell *cells;
};

// Initializes a new priority queue with given capacity
struct PriorityQueue create_pq(int capacity) {
    struct PriorityQueue pq;
    pq.size = 0;
    pq.capacity = capacity;
    pq.cells = malloc(sizeof(struct Cell) * capacity);
    return pq;
}

// Returns true if the priority queue is empty
bool is_pq_empty(struct PriorityQueue *pq) {
    return pq->size == 0;
}

// Swaps two cells in the priority queue
void swap_cells(struct Cell *a, struct Cell *b) {
    struct Cell tmp = *a;
    *a = *b;
    *b = tmp;
}

// Inserts a new cell in the priority queue (min-heap)
void insert_cell(struct PriorityQueue *pq, struct Cell cell) {
    if (pq->size < pq->capacity) {
        pq->cells[pq->size] = cell;
        int current = pq->size;
        int parent = (current - 1) / 2;
        while (current > 0 && pq->cells[current].row + pq->cells[current].col < pq->cells[parent].row + pq->cells[parent].col) {
            swap_cells(&pq->cells[current], &pq->cells[parent]);
            current = parent;
            parent = (current - 1) / 2;
        }
        pq->size++;
    }
}

// Removes and returns the cell with minimal distance from the start
struct Cell extract_min(struct PriorityQueue *pq) {
    struct Cell result = pq->cells[0];
    pq->size--;
    pq->cells[0] = pq->cells[pq->size];
    int current = 0;
    int left_child = current * 2 + 1;
    int right_child = current * 2 + 2;
    while (left_child < pq->size) {
        int min_child = left_child;
        if (right_child < pq->size && pq->cells[right_child].row + pq->cells[right_child].col < pq->cells[left_child].row + pq->cells[left_child].col) {
            min_child = right_child;
        }
        if (pq->cells[current].row + pq->cells[current].col <= pq->cells[min_child].row + pq->cells[min_child].col) {
            break;
        }
        swap_cells(&pq->cells[current], &pq->cells[min_child]);
        current = min_child;
        left_child = current * 2 + 1;
        right_child = current * 2 + 2;
    }
    return result;
}

// Returns true if the given position is a valid index in the grid
bool is_valid_position(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

// Returns true if a path exists from start to end using A* search
bool path_exists(struct Cell **grid, int rows, int cols, struct Cell start, struct Cell end) {
    // Initialize the priority queue and add the start cell
    struct PriorityQueue pq = create_pq(rows * cols);
    start.visited = true;
    insert_cell(&pq, start);

    while (!is_pq_empty(&pq)) {
        // Get the cell with smallest distance from the start and mark it visited
        struct Cell current = extract_min(&pq);
        current.visited = true;
        if (current.row == end.row && current.col == end.col) {
            // The end has been reached, a path exists
            return true;
        }

        // Check all neighbours and add them to the queue if they are not blocked and have not been visited
        int row_offsets[] = {-1, 0, 1, 0};
        int col_offsets[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int new_row = current.row + row_offsets[i];
            int new_col = current.col + col_offsets[i];
            if (is_valid_position(new_row, new_col, rows, cols)) {
                struct Cell neighbour = grid[new_row][new_col];
                if (!neighbour.blocked && !neighbour.visited) {
                    neighbour.visited = true;
                    // Calculate the distance and heuristic for this cell
                    int distance = current.row + current.col + 1;
                    int heuristic = abs(new_row - end.row) + abs(new_col - end.col);
                    // Add the cell to the priority queue with the combined score as priority
                    neighbour.row = new_row;
                    neighbour.col = new_col;
                    insert_cell(&pq, neighbour);
                }
            }
        }
    }

    // No path exists
    return false;
}

// Example usage
int main() {
    // Initialize the grid (5*5), with all cells initially unvisited and unblocked
    struct Cell **grid = malloc(sizeof(struct Cell*) * 5);
    for (int i = 0; i < 5; i++) {
        grid[i] = malloc(sizeof(struct Cell) * 5);
        for (int j = 0; j < 5; j++) {
            struct Cell cell = {i, j, false, false};
            grid[i][j] = cell;
        }
    }

    // Block some cells
    grid[2][2].blocked = true;
    grid[1][2].blocked = true;

    // Define the start and end cells
    struct Cell start = {0, 0, false, false};
    struct Cell end = {4, 4, false, false};

    // Find a path from start to end
    if (path_exists(grid, 5, 5, start, end)) {
        printf("A path exists from (%d,%d) to (%d,%d)\n", start.row, start.col, end.row, end.col);
    } else {
        printf("No path exists from (%d,%d) to (%d,%d)\n", start.row, start.col, end.row, end.col);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < 5; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for the grid
typedef struct {
    int rows;
    int columns;
    bool **grid;
} grid_t;

// Function to print the grid
void print_grid(grid_t* grid) {
    int row, column;
    for (row = 0; row < grid->rows; row++) {
        for (column = 0; column < grid->columns; column++) {
            if (grid->grid[row][column])
                printf("X");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// Function to initialize the grid
void init_grid(grid_t* grid, int rows, int columns) {
    grid->rows = rows;
    grid->columns = columns;
    grid->grid = (bool**)malloc(rows * sizeof(bool*));
    for (int i = 0; i < rows; i++) {
        grid->grid[i] = (bool*)malloc(columns * sizeof(bool));
        for (int j = 0; j < columns; j++) {
            grid->grid[i][j] = false;
        }
    }
}

// Function to perform Dijkstra's algorithm for pathfinding
bool dijkstra(grid_t* grid, int start_row, int start_column, int goal_row, int goal_column) {
    // Define the structure for the priority queue
    typedef struct {
        int row;
        int column;
        int distance;
    } vertex_t;

    // Define the structure for the heap
    typedef struct {
        vertex_t *vertex;
        int size;
        int capacity;
    } heap_t;

    // Initialize the heap
    heap_t heap;
    heap.size = 0;
    heap.capacity = 100;
    heap.vertex = (vertex_t*)malloc(heap.capacity * sizeof(vertex_t));

    // Initialize the distance array
    int **distance = (int**)malloc(grid->rows * sizeof(int*));
    for (int i = 0; i < grid->rows; i++) {
        distance[i] = (int*)malloc(grid->columns * sizeof(int));
        for (int j = 0; j < grid->columns; j++) {
            distance[i][j] = 1000000;
        }
    }

    // Mark the start node as visited
    distance[start_row][start_column] = 0;
    heap.vertex[heap.size++] = (vertex_t){start_row, start_column, 0};
    heap.size++;

    // Perform Dijkstra's algorithm
    while (heap.size > 0) {
        // Get the vertex with the minimum distance from the heap
        vertex_t min_vertex = heap.vertex[0];
        int min_index = 0;
        for (int i = 1; i < heap.size; i++) {
            if (heap.vertex[i].distance < min_vertex.distance) {
                min_vertex = heap.vertex[i];
                min_index = i;
            }
        }

        // Pop the minimum vertex from the heap
        heap.vertex[min_index] = heap.vertex[heap.size - 1];
        heap.size--;

        // Check if the current vertex is the goal vertex
        if (min_vertex.row == goal_row && min_vertex.column == goal_column) {
            // Reconstruct the path
            int current_row = goal_row;
            int current_column = goal_column;
            while (current_row!= start_row || current_column!= start_column) {
                if (current_row > start_row)
                    printf("S");
                else
                    printf("N");

                if (current_column > start_column)
                    printf("E");
                else
                    printf("W");

                current_row -= 1;
                current_column -= 1;
            }
            printf("G\n");
            return true;
        }

        // Mark the neighboring vertices as visited
        int row = min_vertex.row;
        int column = min_vertex.column;
        if (row > 0 && grid->grid[row - 1][column]) {
            if (distance[row - 1][column] > distance[row][column] + 1) {
                distance[row - 1][column] = distance[row][column] + 1;
                heap.vertex[heap.size++] = (vertex_t){row - 1, column, distance[row - 1][column]};
                heap.size++;
            }
        }
        if (row < grid->rows - 1 && grid->grid[row + 1][column]) {
            if (distance[row + 1][column] > distance[row][column] + 1) {
                distance[row + 1][column] = distance[row][column] + 1;
                heap.vertex[heap.size++] = (vertex_t){row + 1, column, distance[row + 1][column]};
                heap.size++;
            }
        }
        if (column > 0 && grid->grid[row][column - 1]) {
            if (distance[row][column - 1] > distance[row][column] + 1) {
                distance[row][column - 1] = distance[row][column] + 1;
                heap.vertex[heap.size++] = (vertex_t){row, column - 1, distance[row][column - 1]};
                heap.size++;
            }
        }
        if (column < grid->columns - 1 && grid->grid[row][column + 1]) {
            if (distance[row][column + 1] > distance[row][column] + 1) {
                distance[row][column + 1] = distance[row][column] + 1;
                heap.vertex[heap.size++] = (vertex_t){row, column + 1, distance[row][column + 1]};
                heap.size++;
            }
        }
    }
    return false;
}

int main() {
    // Define the size of the grid
    int rows = 5;
    int columns = 5;

    // Initialize the grid
    grid_t grid;
    init_grid(&grid, rows, columns);

    // Set the start and goal nodes
    int start_row = 3;
    int start_column = 3;
    int goal_row = 0;
    int goal_column = 4;

    // Print the grid
    printf("Grid:\n");
    print_grid(&grid);

    // Perform Dijkstra's algorithm
    if (dijkstra(&grid, start_row, start_column, goal_row, goal_column)) {
        printf("Path found\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}
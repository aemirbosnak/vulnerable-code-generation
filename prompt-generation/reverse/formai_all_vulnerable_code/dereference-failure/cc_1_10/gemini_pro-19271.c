//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the grid dimensions
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Define the start and end points
int start_x = 0;
int start_y = 0;
int end_x = 9;
int end_y = 9;

// Define the grid
int grid[GRID_WIDTH][GRID_HEIGHT] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Define the directions
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

// Define the queue
struct Queue {
    int x;
    int y;
    struct Queue *next;
};

struct Queue *head = NULL;
struct Queue *tail = NULL;

// Function to enqueue a cell
void enqueue(int x, int y) {
    struct Queue *new_cell = (struct Queue *) malloc(sizeof(struct Queue));
    new_cell->x = x;
    new_cell->y = y;
    new_cell->next = NULL;

    if (head == NULL) {
        head = new_cell;
        tail = new_cell;
    } else {
        tail->next = new_cell;
        tail = new_cell;
    }
}

// Function to dequeue a cell
struct Queue *dequeue() {
    struct Queue *cell = head;

    if (head != NULL) {
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
    }

    return cell;
}

// Function to check if a cell is valid
int is_valid(int x, int y) {
    return (x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT && grid[x][y] == 0);
}

// Function to find the path
int find_path() {
    // Initialize the queue
    enqueue(start_x, start_y);

    // While the queue is not empty
    while (head != NULL) {
        // Dequeue the first cell
        struct Queue *cell = dequeue();

        // If the cell is the end point
        if (cell->x == end_x && cell->y == end_y) {
            return 1;
        }

        // For each direction
        for (int i = 0; i < 4; i++) {
            // Get the next cell
            int next_x = cell->x + dx[i];
            int next_y = cell->y + dy[i];

            // If the next cell is valid
            if (is_valid(next_x, next_y)) {
                // Enqueue the next cell
                enqueue(next_x, next_y);
            }
        }
    }

    // If the queue is empty, no path was found
    return 0;
}

// Function to print the grid
void print_grid() {
    for (int i = 0; i < GRID_HEIGHT; i++) {
        for (int j = 0; j < GRID_WIDTH; j++) {
            printf("%d ", grid[j][i]);
        }
        printf("\n");
    }
}

int main() {
    // Find the path
    int found = find_path();

    // Print the result
    if (found) {
        printf("Path found!\n");
    } else {
        printf("No path found!\n");
    }

    // Print the grid
    print_grid();

    return 0;
}
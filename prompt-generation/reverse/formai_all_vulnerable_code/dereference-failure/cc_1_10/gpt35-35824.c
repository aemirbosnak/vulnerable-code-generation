//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: creative
/* Welcome to our custom pathfinding algorithm.
 * This algorithm is designed to find the shortest path between two points on a grid.
 * The grid consists of squares that can either be empty or filled with obstacles.
 * Our algorithm uses Dijkstra's shortest path algorithm to find the shortest path.
 * However, before running Dijkstra, we first run a pre-processing step to remove unnecessary nodes.
 * This helps speed up the algorithm and reduce memory usage.
 * Let's get started!
 */

#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of our grid
#define MAX_SIZE 1000

// Define constants for different types of squares on the grid
#define EMPTY 0
#define OBSTACLE 1

// Define a struct to hold a coordinate on the grid
typedef struct {
    int x;
    int y;
} Coord;

// Define a struct to hold information about a square on the grid
typedef struct {
    Coord coord;
    int type;
    int dist;
    Coord parent;
} Square;

// Define a queue data structure for breadth-first search
typedef struct {
    int front;
    int rear;
    int size;
    Coord* elements;
} Queue;

// Define a function to add an element to the queue
void enqueue(Queue* queue, Coord element) {
    if (queue->size == MAX_SIZE) {
        printf("Error: queue is full\n");
        exit(EXIT_FAILURE);
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->elements[queue->rear] = element;
    queue->size++;
}

// Define a function to remove an element from the queue
Coord dequeue(Queue* queue) {
    if (queue->size == 0) {
        printf("Error: queue is empty\n");
        exit(EXIT_FAILURE);
    }
    Coord element = queue->elements[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return element;
}

// Define a function to check if a coordinate is within the bounds of the grid
int is_valid_coord(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Define a function to check if a square is an obstacle
int is_obstacle(Square* square) {
    return square->type == OBSTACLE;
}

// Define a function to calculate the distance between two coordinates
int distance(Coord a, Coord b) {
    int dx = abs(a.x - b.x);
    int dy = abs(a.y - b.y);
    return dx + dy;
}

// Define a function to update a square's distance and parent
void update_square(Square* square, int dist, Coord parent) {
    square->dist = dist;
    square->parent = parent;
}

// Define a function to check if a square has been visited
int is_visited(Square* square) {
    return square->dist != -1;
}

// Define a function to remove unnecessary nodes from the grid
void preprocess_grid(Square* grid, int rows, int cols, Coord start, Coord end) {
    // Create a queue for breadth-first search
    Queue queue = {0, -1, 0, malloc(sizeof(Coord) * MAX_SIZE)};

    // Mark the start square as visited and add it to the queue
    Square* start_square = &grid[start.x * cols + start.y];
    update_square(start_square, 0, start);
    enqueue(&queue, start);

    // Run breadth-first search to find reachable squares
    while (queue.size > 0) {
        Coord current = dequeue(&queue);
        Square* current_square = &grid[current.x * cols + current.y];

        // Check neighboring squares
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }

                int next_x = current.x + dx;
                int next_y = current.y + dy;

                if (is_valid_coord(next_x, next_y, rows, cols)) {
                    Square* next_square = &grid[next_x * cols + next_y];

                    if (!is_visited(next_square) && !is_obstacle(next_square)) {
                        update_square(next_square, current_square->dist + 1, current);
                        enqueue(&queue, (Coord){next_x, next_y});
                    }
                }
            }
        }
    }

    // Reset all squares to unvisited
    for (int i = 0; i < rows * cols; i++) {
        grid[i].dist = -1;
    }

    // Mark the end square as visited and add it to the queue
    Square* end_square = &grid[end.x * cols + end.y];
    update_square(end_square, 0, end);
    enqueue(&queue, end);

    // Run breadth-first search to find squares that can reach the end square
    while (queue.size > 0) {
        Coord current = dequeue(&queue);
        Square* current_square = &grid[current.x * cols + current.y];

        // Check neighboring squares
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }

                int next_x = current.x + dx;
                int next_y = current.y + dy;

                if (is_valid_coord(next_x, next_y, rows, cols)) {
                    Square* next_square = &grid[next_x * cols + next_y];

                    if (!is_visited(next_square) && !is_obstacle(next_square)) {
                        update_square(next_square, current_square->dist + 1, current);
                        enqueue(&queue, (Coord){next_x, next_y});
                    }
                }
            }
        }
    }

    // Remove unreachable squares from the grid
    for (int i = 0; i < rows * cols; i++) {
        Square* square = &grid[i];
        if (!is_visited(square)) {
            square->type = OBSTACLE;
        }
    }

    // Free the queue's memory
    free(queue.elements);
}

// Define a function to find the shortest path between two points
void find_shortest_path(Square* grid, int rows, int cols, Coord start, Coord end) {
    // Create a queue for breadth-first search
    Queue queue = {0, -1, 0, malloc(sizeof(Coord) * MAX_SIZE)};

    // Mark the start square as visited and add it to the queue
    Square* start_square = &grid[start.x * cols + start.y];
    update_square(start_square, 0, start);
    enqueue(&queue, start);

    // Run Dijkstra's shortest path algorithm
    while (queue.size > 0) {
        Coord current = dequeue(&queue);
        Square* current_square = &grid[current.x * cols + current.y];

        // Check neighboring squares
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }

                int next_x = current.x + dx;
                int next_y = current.y + dy;

                if (is_valid_coord(next_x, next_y, rows, cols)) {
                    Square* next_square = &grid[next_x * cols + next_y];
                    int new_dist = current_square->dist + distance(current, next_square->coord);

                    if (!is_obstacle(next_square) && (next_square->dist == -1 || new_dist < next_square->dist)) {
                        update_square(next_square, new_dist, current);
                        enqueue(&queue, (Coord){next_x, next_y});
                    }
                }
            }
        }
    }

    // Print the shortest path
    Square* end_square = &grid[end.x * cols + end.y];
    if (end_square->dist == -1) {
        printf("No path found\n");
    } else {
        printf("Shortest path length: %d\n", end_square->dist);
        while (end_square->coord.x != start.x || end_square->coord.y != start.y) {
            printf("(%d, %d) ", end_square->coord.x, end_square->coord.y);
            end_square = &grid[end_square->parent.x * cols + end_square->parent.y];
        }
        printf("(%d, %d)\n", end_square->coord.x, end_square->coord.y);
    }

    // Free the queue's memory
    free(queue.elements);
}

int main() {
    // Define the size and contents of the grid
    int rows = 10;
    int cols = 10;
    Square grid[MAX_SIZE] = {
        {{0, 0}, EMPTY, -1},
        {{0, 1}, EMPTY, -1},
        {{0, 2}, OBSTACLE, -1},
        {{0, 3}, EMPTY, -1},
        {{0, 4}, EMPTY, -1},
        {{1, 0}, OBSTACLE, -1},
        {{1, 1}, EMPTY, -1},
        {{1, 2}, EMPTY, -1},
        {{1, 3}, EMPTY, -1},
        {{1, 4}, OBSTACLE, -1},
        {{2, 0}, OBSTACLE, -1},
        {{2, 1}, EMPTY, -1},
        {{2, 2}, OBSTACLE, -1},
        {{2, 3}, EMPTY, -1},
        {{2, 4}, EMPTY, -1},
        {{3, 0}, OBSTACLE, -1},
        {{3, 1}, EMPTY, -1},
        {{3, 2}, EMPTY, -1},
        {{3, 3}, EMPTY, -1},
        {{3, 4}, OBSTACLE, -1},
        {{4, 0}, EMPTY, -1},
        {{4, 1}, EMPTY, -1},
        {{4, 2}, OBSTACLE, -1},
        {{4, 3}, EMPTY, -1},
        {{4, 4}, EMPTY, -1},
    };

    // Define the start and end points
    Coord start = {0, 0};
    Coord end = {4, 4};

    // Preprocess the grid to remove unnecessary nodes
    preprocess_grid(grid, rows, cols, start, end);

    // Find the shortest path between the start and end points
    find_shortest_path(grid, rows, cols, start, end);

    return 0;
}
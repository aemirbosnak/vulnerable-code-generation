//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Dimensions of the maze
#define WIDTH 10
#define HEIGHT 10

// The maze itself
char maze[HEIGHT][WIDTH] = {
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#' },
    { '#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#' },
    { '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#' },
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#' },
    { '#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#' },
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
};

// The starting and ending positions
int start_x = 1;
int start_y = 1;
int end_x = 8;
int end_y = 8;

// A queue to store the cells to be visited
typedef struct Queue {
    int x;
    int y;
    struct Queue* next;
} Queue;

// Function to create a new queue
Queue* create_queue() {
    return NULL;
}

// Function to add a new cell to the queue
void enqueue(Queue** queue, int x, int y) {
    Queue* new_cell = malloc(sizeof(Queue));
    new_cell->x = x;
    new_cell->y = y;
    new_cell->next = NULL;

    if (*queue == NULL) {
        *queue = new_cell;
    } else {
        Queue* last_cell = *queue;
        while (last_cell->next != NULL) {
            last_cell = last_cell->next;
        }
        last_cell->next = new_cell;
    }
}

// Function to remove the first cell from the queue
Queue* dequeue(Queue** queue) {
    if (*queue == NULL) {
        return NULL;
    }

    Queue* first_cell = *queue;
    *queue = (*queue)->next;
    return first_cell;
}

// Function to check if a cell is valid
bool is_valid(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[y][x] != '#';
}

// Function to find the path through the maze
void find_path(int start_x, int start_y, int end_x, int end_y) {
    // Create a queue to store the cells to be visited
    Queue* queue = create_queue();

    // Add the starting cell to the queue
    enqueue(&queue, start_x, start_y);

    // Mark the starting cell as visited
    maze[start_y][start_x] = 'S';

    // While the queue is not empty
    while (queue != NULL) {
        // Get the first cell from the queue
        Queue* current_cell = dequeue(&queue);

        // Check if the cell is the ending cell
        if (current_cell->x == end_x && current_cell->y == end_y) {
            // Found the path!
            printf("Path found!\n");

            // Print the path
            int x = current_cell->x;
            int y = current_cell->y;
            while (x != start_x || y != start_y) {
                printf("(%d, %d) -> ", x, y);

                // Move to the next cell in the path
                if (maze[y][x-1] == 'P') {
                    x--;
                } else if (maze[y-1][x] == 'P') {
                    y--;
                } else if (maze[y][x+1] == 'P') {
                    x++;
                } else if (maze[y+1][x] == 'P') {
                    y++;
                }
            }
            printf("(%d, %d)\n", start_x, start_y);

            // Free the queue
            while (queue != NULL) {
                Queue* next_cell = dequeue(&queue);
                free(current_cell);
                current_cell = next_cell;
            }
            return;
        }

        // Try to move north
        if (is_valid(current_cell->x, current_cell->y-1)) {
            enqueue(&queue, current_cell->x, current_cell->y-1);
            maze[current_cell->y-1][current_cell->x] = 'P';
        }

        // Try to move east
        if (is_valid(current_cell->x+1, current_cell->y)) {
            enqueue(&queue, current_cell->x+1, current_cell->y);
            maze[current_cell->y][current_cell->x+1] = 'P';
        }

        // Try to move south
        if (is_valid(current_cell->x, current_cell->y+1)) {
            enqueue(&queue, current_cell->x, current_cell->y+1);
            maze[current_cell->y+1][current_cell->x] = 'P';
        }

        // Try to move west
        if (is_valid(current_cell->x-1, current_cell->y)) {
            enqueue(&queue, current_cell->x-1, current_cell->y);
            maze[current_cell->y][current_cell->x-1] = 'P';
        }

        // Free the current cell
        free(current_cell);
    }

    // No path found
    printf("No path found!\n");
}

// Main function
int main() {
    // Find the path through the maze
    find_path(start_x, start_y, end_x, end_y);

    return 0;
}
//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// The maze is represented as a 2D array of characters.
char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// The start and end positions are represented as coordinates.
int start_x = 1;
int start_y = 1;
int end_x = MAZE_WIDTH - 2;
int end_y = MAZE_HEIGHT - 2;

// A queue is used to store the positions that need to be explored.
typedef struct queue_node {
    int x;
    int y;
    struct queue_node *next;
} queue_node;

queue_node *queue_head = NULL;
queue_node *queue_tail = NULL;

// Enqueue a position into the queue.
void enqueue(int x, int y) {
    queue_node *new_node = malloc(sizeof(queue_node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;

    if (queue_head == NULL) {
        queue_head = new_node;
        queue_tail = new_node;
    } else {
        queue_tail->next = new_node;
        queue_tail = new_node;
    }
}

// Dequeue a position from the queue.
void dequeue() {
    if (queue_head != NULL) {
        queue_node *old_head = queue_head;
        queue_head = queue_head->next;
        free(old_head);
    }
}

// Check if a position is valid.
int is_valid_position(int x, int y) {
    return x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[y][x] == '.' && maze[y][x] != '#';
}

// Check if a position is the end position.
int is_end_position(int x, int y) {
    return x == end_x && y == end_y;
}

// Find a path from the start position to the end position.
int find_path() {
    // Initialize the queue with the start position.
    enqueue(start_x, start_y);

    // While the queue is not empty, explore the next position.
    while (queue_head != NULL) {
        // Dequeue the next position.
        int x = queue_head->x;
        int y = queue_head->y;
        dequeue();

        // Check if the position is the end position.
        if (is_end_position(x, y)) {
            return 1;
        }

        // Check if the position is valid.
        if (is_valid_position(x, y)) {
            // Mark the position as visited.
            maze[y][x] = '#';

            // Enqueue the adjacent positions.
            enqueue(x - 1, y);
            enqueue(x + 1, y);
            enqueue(x, y - 1);
            enqueue(x, y + 1);
        }
    }

    // No path was found.
    return 0;
}

// Print the maze.
void print_maze() {
    for (int y = 0; y < MAZE_HEIGHT; y++) {
        for (int x = 0; x < MAZE_WIDTH; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

int main() {
    // Find a path from the start position to the end position.
    int found_path = find_path();

    // Print the maze with the path.
    print_maze();

    // Free the queue.
    while (queue_head != NULL) {
        dequeue();
    }

    return 0;
}
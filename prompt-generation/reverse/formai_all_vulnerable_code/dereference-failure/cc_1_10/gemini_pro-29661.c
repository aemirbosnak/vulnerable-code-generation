//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// The map is represented as a 2D array of characters.
// Each character represents a different type of terrain.
// '.' represents an open space.
// '#' represents a wall.
// 'S' represents the starting position.
// 'E' represents the ending position.
char map[HEIGHT][WIDTH] = {
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '#', '#', '#', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '.', '.', '#', '#', '.'},
    {'.', '#', '.', '#', '.', '#', '.', '#', '#', '.'},
    {'.', '#', '.', '#', '.', '#', '.', '#', '#', '.'},
    {'.', '#', '.', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
};

// The starting position is at (0, 0).
int start_x = 0;
int start_y = 0;

// The ending position is at (9, 9).
int end_x = 9;
int end_y = 9;

// A queue is used to store the positions that have been visited.
typedef struct QueueNode {
    int x;
    int y;
    struct QueueNode *next;
} QueueNode;

QueueNode *head = NULL;
QueueNode *tail = NULL;

// Enqueue a position into the queue.
void enqueue(int x, int y) {
    QueueNode *new_node = malloc(sizeof(QueueNode));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        tail->next = new_node;
    }
    tail = new_node;
}

// Dequeue a position from the queue.
QueueNode *dequeue() {
    if (head == NULL) {
        return NULL;
    }
    QueueNode *first_node = head;
    head = head->next;
    if (head == NULL) {
        tail = NULL;
    }
    return first_node;
}

// Check if a position is valid.
int is_valid(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && map[y][x] != '#';
}

// Find the shortest path from the starting position to the ending position using a breadth-first search.
int find_path() {
    // Enqueue the starting position.
    enqueue(start_x, start_y);

    // While the queue is not empty, dequeue a position and check if it is the ending position.
    while (head != NULL) {
        QueueNode *node = dequeue();
        int x = node->x;
        int y = node->y;
        if (x == end_x && y == end_y) {
            return 1;
        }

        // Check the positions adjacent to the current position.
        if (is_valid(x - 1, y)) {
            enqueue(x - 1, y);
        }
        if (is_valid(x + 1, y)) {
            enqueue(x + 1, y);
        }
        if (is_valid(x, y - 1)) {
            enqueue(x, y - 1);
        }
        if (is_valid(x, y + 1)) {
            enqueue(x, y + 1);
        }
    }

    // No path was found.
    return 0;
}

// Print the map.
void print_map() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", map[y][x]);
        }
        printf("\n");
    }
}

// Main function.
int main() {
    // Find the shortest path.
    int path_found = find_path();

    if (path_found) {
        printf("Path found!\n");
        print_map();
    } else {
        printf("No path found.\n");
    }

    return 0;
}
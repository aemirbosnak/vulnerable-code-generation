//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// The map is a 2D array of characters representing the terrain.
// '.' - Open space
// '#' - Wall
// 'S' - Start
// 'E' - End
char map[10][10] = {
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '#', '.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '#', '#', '#', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '.', '#', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '#', '#', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '#', '.', '.', '#', '.'},
    {'.', '#', '.', '#', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '#', '#', '#', '#', '#', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'}
};

// The start and end coordinates.
int start_x = 1;
int start_y = 1;
int end_x = 8;
int end_y = 8;

// A queue of coordinates to be visited.
struct queue {
    int x;
    int y;
    struct queue *next;
};

// Enqueue a coordinate.
void enqueue(struct queue **head, int x, int y) {
    struct queue *new_node = malloc(sizeof(struct queue));
    new_node->x = x;
    new_node->y = y;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct queue *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Dequeue a coordinate.
struct queue *dequeue(struct queue **head) {
    if (*head == NULL) {
        return NULL;
    }

    struct queue *temp = *head;
    *head = (*head)->next;
    return temp;
}

// Check if a coordinate is valid.
bool is_valid(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10 && map[x][y] != '#';
}

// Find the path from the start to the end.
bool find_path() {
    // Create a queue of coordinates to be visited.
    struct queue *queue = NULL;

    // Enqueue the start coordinate.
    enqueue(&queue, start_x, start_y);

    // While the queue is not empty, dequeue a coordinate and check if it is the end coordinate.
    while (queue != NULL) {
        struct queue *current = dequeue(&queue);

        // Check if the current coordinate is the end coordinate.
        if (current->x == end_x && current->y == end_y) {
            return true;
        }

        // Check if the current coordinate is a valid coordinate.
        if (is_valid(current->x - 1, current->y)) {
            enqueue(&queue, current->x - 1, current->y);
        }
        if (is_valid(current->x + 1, current->y)) {
            enqueue(&queue, current->x + 1, current->y);
        }
        if (is_valid(current->x, current->y - 1)) {
            enqueue(&queue, current->x, current->y - 1);
        }
        if (is_valid(current->x, current->y + 1)) {
            enqueue(&queue, current->x, current->y + 1);
        }
    }

    // No path found.
    return false;
}

// Print the map.
void print_map() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

// Main function.
int main() {
    // Find the path.
    bool path_found = find_path();

    // Print the map.
    print_map();

    // Print the result.
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}
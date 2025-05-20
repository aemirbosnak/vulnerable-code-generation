//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH  10
#define MAZE_HEIGHT 10

// The maze itself, 0 represents an empty space and 1 represents a wall
int maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// The starting and ending positions of the maze
int start_x = 1;
int start_y = 1;
int end_x = MAZE_WIDTH - 2;
int end_y = MAZE_HEIGHT - 2;

// A queue to store the positions that need to be checked
struct queue {
    int x;
    int y;
    struct queue *next;
};

// A function to create a new queue node
struct queue *new_queue_node(int x, int y) {
    struct queue *node = malloc(sizeof(struct queue));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

// A function to enqueue a new position to the queue
void enqueue(struct queue **head, int x, int y) {
    struct queue *node = new_queue_node(x, y);
    if (*head == NULL) {
        *head = node;
    } else {
        struct queue *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// A function to dequeue a position from the queue
struct queue *dequeue(struct queue **head) {
    if (*head == NULL) {
        return NULL;
    } else {
        struct queue *node = *head;
        *head = (*head)->next;
        return node;
    }
}

// A function to check if a position is valid and not a wall
int is_valid(int x, int y) {
    return (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[y][x] == 0);
}

// A function to find the shortest path through the maze using BFS
int find_shortest_path() {
    // Create a queue to store the positions that need to be checked
    struct queue *queue = NULL;

    // Enqueue the starting position to the queue
    enqueue(&queue, start_x, start_y);

    // Create a 2D array to store the distances from the starting position to each position
    int distances[MAZE_HEIGHT][MAZE_WIDTH];

    // Initialize all distances to -1
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            distances[i][j] = -1;
        }
    }

    // Set the distance of the starting position to 0
    distances[start_y][start_x] = 0;

    // While the queue is not empty
    while (queue != NULL) {
        // Dequeue the next position from the queue
        struct queue *node = dequeue(&queue);

        // Check if the position is the ending position
        if (node->x == end_x && node->y == end_y) {
            return distances[node->y][node->x];
        }

        // Check all four adjacent positions (up, down, left, right)
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int x = node->x + dx[i];
            int y = node->y + dy[i];

            // If the position is valid and not a wall
            if (is_valid(x, y)) {
                // If the distance to the position is not set yet
                if (distances[y][x] == -1) {
                    // Set the distance to the position to the distance to the current position plus 1
                    distances[y][x] = distances[node->y][node->x] + 1;

                    // Enqueue the position to the queue
                    enqueue(&queue, x, y);
                }
            }
        }
    }

    // If no path was found, return -1
    return -1;
}

// A function to print the maze with the shortest path highlighted
void print_maze() {
    int shortest_path = find_shortest_path();

    // Create a 2D array to store the maze with the shortest path highlighted
    char maze_with_path[MAZE_HEIGHT][MAZE_WIDTH];

    // Copy the maze to the new array
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze_with_path[i][j] = maze[i][j];
        }
    }

    // If a path was found, highlight it
    if (shortest_path != -1) {
        int x = end_x;
        int y = end_y;

        while (x != start_x || y != start_y) {
            maze_with_path[y][x] = '*';

            // Check all four adjacent positions (up, down, left, right) to find the next position in the path
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            for (int i = 0; i < 4; i++) {
                int next_x = x + dx[i];
                int next_y = y + dy[i];

                if (is_valid(next_x, next_y) && maze_with_path[next_y][next_x] == '*') {
                    x = next_x;
                    y = next_y;
                    break;
                }
            }
        }
    }

    // Print the maze with the shortest path highlighted
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            printf("%c", maze_with_path[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // Generate a random maze
    for (int i = 1; i < MAZE_HEIGHT - 1; i++) {
        for (int j = 1; j < MAZE_WIDTH - 1; j++) {
            if (rand() % 2 == 0) {
                maze[i][j] = 1;
            }
        }
    }

    // Print the maze
    print_maze();

    return 0;
}
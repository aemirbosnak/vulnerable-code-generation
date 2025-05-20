//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Maze dimensions and starting point
#define WIDTH 10
#define HEIGHT 10
int start_row = 0, start_col = 0;

// The maze
int maze[WIDTH][HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Position struct
typedef struct {
    int row;
    int col;
} Position;

// Thread data struct
typedef struct {
    Position start;      // Starting position
    Position end;        // Ending position
    int *path;          // Path found
    int *path_len;     // Length of the path
} ThreadData;

// Thread function
void *find_path(void *data) {
    ThreadData *thread_data = (ThreadData *)data;

    // Initialize stack for depth-first search
    int stack_size = WIDTH * HEIGHT;
    Position *stack = malloc(stack_size * sizeof(Position));
    int top = 0;

    // Push the starting position onto the stack
    stack[top++] = thread_data->start;

    // While the stack is not empty
    while (top > 0) {
        // Pop the top position from the stack
        Position current = stack[--top];

        // Check if the current position is the ending position
        if (current.row == thread_data->end.row && current.col == thread_data->end.col) {
            // Path found!
            *thread_data->path_len = top;
            for (int i = 0; i < top; i++) {
                thread_data->path[i] = (stack[i].row * WIDTH) + stack[i].col;
            }
            break;
        }

        // Mark the current position as visited
        maze[current.row][current.col] = 2;

        // Push the neighbors of the current position onto the stack
        if (current.row > 0 && maze[current.row - 1][current.col] == 0) {
            stack[top++] = (Position){current.row - 1, current.col};
        }
        if (current.col > 0 && maze[current.row][current.col - 1] == 0) {
            stack[top++] = (Position){current.row, current.col - 1};
        }
        if (current.row < HEIGHT - 1 && maze[current.row + 1][current.col] == 0) {
            stack[top++] = (Position){current.row + 1, current.col};
        }
        if (current.col < WIDTH - 1 && maze[current.row][current.col + 1] == 0) {
            stack[top++] = (Position){current.row, current.col + 1};
        }
    }

    // Free the stack
    free(stack);

    return NULL;
}

int main() {
    // Ending point
    int end_row = HEIGHT - 1, end_col = WIDTH - 1;

    // Allocate memory for the path
    int path_len;
    int *path = malloc(WIDTH * HEIGHT * sizeof(int));

    // Create thread data
    ThreadData thread_data = {
        .start = {start_row, start_col},
        .end = {end_row, end_col},
        .path = path,
        .path_len = &path_len
    };

    // Create thread
    pthread_t thread;
    pthread_create(&thread, NULL, find_path, &thread_data);

    // Join thread
    pthread_join(thread, NULL);

    // Print the path if found
    if (path_len > 0) {
        printf("Path found: ");
        for (int i = 0; i < path_len; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("No path found.\n");
    }

    // Free the path
    free(path);

    return 0;
}
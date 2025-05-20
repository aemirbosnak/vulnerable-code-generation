//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// The maze structure represents the actual maze.
typedef struct maze {
    int width; // The width of the maze.
    int height; // The height of the maze.
    int **cells; // The 2D array representing the maze cells.
} maze;

// The stack structure represents the stack of positions used to find the route.
typedef struct stack {
    int top; // The index of the top of the stack.
    int size; // The size of the stack.
    int *array; // The array representing the stack.
} stack;

// Create a new maze with the given width and height.
maze *create_maze(int width, int height) {
    maze *m = (maze *)malloc(sizeof(maze));
    m->width = width;
    m->height = height;
    m->cells = (int **)malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++) {
        m->cells[i] = (int *)malloc(sizeof(int) * width);
    }
    return m;
}

// Free the memory allocated for the maze.
void free_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->cells[i]);
    }
    free(m->cells);
    free(m);
}

// Create a new stack with the given size.
stack *create_stack(int size) {
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->size = size;
    s->array = (int *)malloc(sizeof(int) * size);
    return s;
}

// Free the memory allocated for the stack.
void free_stack(stack *s) {
    free(s->array);
    free(s);
}

// Push an element onto the stack.
void push(stack *s, int element) {
    if (s->top == s->size - 1) {
        printf("Error: Stack overflow.\n");
        return;
    }
    s->array[++s->top] = element;
}

// Pop an element from the stack.
int pop(stack *s) {
    if (s->top == -1) {
        printf("Error: Stack underflow.\n");
        return -1;
    }
    return s->array[s->top--];
}

// Check if the given position is valid.
int is_valid_position(maze *m, int x, int y) {
    return x >= 0 && x < m->width && y >= 0 && y < m->height && m->cells[y][x] == 0;
}

// Find a route through the maze using a depth-first search.
int find_route(maze *m, int start_x, int start_y, int end_x, int end_y) {
    // Create a stack to store the positions that have been visited.
    stack *s = create_stack(m->width * m->height);

    // Push the starting position onto the stack.
    push(s, start_x);
    push(s, start_y);

    // While the stack is not empty, pop the next position and check if it is the end position.
    while (s->top != -1) {
        // Pop the next position from the stack.
        int x = pop(s);
        int y = pop(s);

        // Check if the popped position is the end position.
        if (x == end_x && y == end_y) {
            // Free the stack.
            free_stack(s);

            // Return true to indicate that a route has been found.
            return 1;
        }

        // Check if the popped position is a valid position.
        if (!is_valid_position(m, x, y)) {
            continue;
        }

        // Mark the popped position as visited.
        m->cells[y][x] = 1;

        // Push the neighboring positions onto the stack.
        push(s, x - 1);
        push(s, y);
        push(s, x + 1);
        push(s, y);
        push(s, x);
        push(s, y - 1);
        push(s, x);
        push(s, y + 1);
    }

    // Free the stack.
    free_stack(s);

    // Return false to indicate that a route has not been found.
    return 0;
}

// Print the maze to the console.
void print_maze(maze *m) {
    for (int i = 0; i < m->height; i++) {
        for (int j = 0; j < m->width; j++) {
            printf("%d ", m->cells[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Create a maze with a width of 10 and a height of 10.
    maze *m = create_maze(10, 10);

    // Set the starting and ending positions.
    int start_x = 0;
    int start_y = 0;
    int end_x = 9;
    int end_y = 9;

    // Find a route through the maze.
    int route_found = find_route(m, start_x, start_y, end_x, end_y);

    // Print the maze to the console.
    print_maze(m);

    // Free the memory allocated for the maze.
    free_maze(m);

    return 0;
}
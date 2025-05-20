//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10  // Assuming a 10x10 maze

// Maze representation using a 2D array
int maze[MAZE_SIZE][MAZE_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Directions for moving in the maze
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// Stack to store the path while exploring the maze
typedef struct StackNode {
    int row;
    int col;
    enum Direction direction;
    struct StackNode* next;
} StackNode;

// Push a node onto the stack
void push(StackNode** stack, int row, int col, enum Direction direction) {
    StackNode* new_node = (StackNode*)malloc(sizeof(StackNode));
    new_node->row = row;
    new_node->col = col;
    new_node->direction = direction;
    new_node->next = *stack;
    *stack = new_node;
}

// Pop a node from the stack
void pop(StackNode** stack) {
    if (*stack != NULL) {
        StackNode* temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

// Check if a given cell is valid
int is_valid(int row, int col) {
    return (row >= 0 && row < MAZE_SIZE) && (col >= 0 && col < MAZE_SIZE) && (maze[row][col] == 0);
}

// Find a path through the maze using Depth-First Search (DFS)
int find_path(int start_row, int start_col, int end_row, int end_col) {
    // Stack to store the current path
    StackNode* stack = NULL;

    // Initialize the starting position
    push(&stack, start_row, start_col, RIGHT);

    // While there are still positions to explore
    while (stack != NULL) {
        // Get the current position
        StackNode* current = stack;

        // Check if we have reached the end
        if (current->row == end_row && current->col == end_col) {
            return 1;  // Path found
        }

        // Try all possible moves from the current position
        for (enum Direction direction = UP; direction <= LEFT; direction++) {
            int new_row = current->row;
            int new_col = current->col;

            // Move in the specified direction
            switch (direction) {
                case UP:
                    new_row--;
                    break;
                case RIGHT:
                    new_col++;
                    break;
                case DOWN:
                    new_row++;
                    break;
                case LEFT:
                    new_col--;
                    break;
            }

            // Check if the new position is valid
            if (is_valid(new_row, new_col)) {
                // Push the new position onto the stack
                push(&stack, new_row, new_col, direction);
            }
        }

        // If none of the moves were valid, pop the current position from the stack
        if (current->direction == LEFT) {
            pop(&stack);
        } else {
            current->direction++;
        }
    }

    // No path found
    return 0;
}

// Main function
int main() {
    // Starting and ending positions
    int start_row = 1;
    int start_col = 1;
    int end_row = 8;
    int end_col = 8;

    // Find a path through the maze
    int path_found = find_path(start_row, start_col, end_row, end_col);

    // Print the result
    if (path_found) {
        printf("Path found\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}
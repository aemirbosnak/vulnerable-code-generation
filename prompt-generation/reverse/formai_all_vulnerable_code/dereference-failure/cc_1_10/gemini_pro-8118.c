//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create a 2D array to represent the maze
char maze[10][10] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

// Create a stack to keep track of the path taken
typedef struct node {
    int x;
    int y;
    struct node *next;
} node;

node *top = NULL;

// Push a node onto the stack
void push(int x, int y) {
    node *new_node = malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->next = top;
    top = new_node;
}

// Pop a node from the stack
node *pop() {
    if (top == NULL) {
        return NULL;
    }
    node *popped_node = top;
    top = top->next;
    return popped_node;
}

// Check if a cell is valid
bool is_valid(int x, int y) {
    if (x < 0 || x >= 10 || y < 0 || y >= 10) {
        return false;
    }
    if (maze[x][y] == '#') {
        return false;
    }
    return true;
}

// Find the path through the maze
bool find_path(int x, int y) {
    // Check if we have reached the end of the maze
    if (x == 9 && y == 9) {
        return true;
    }

    // Push the current cell onto the stack
    push(x, y);

    // Mark the current cell as visited
    maze[x][y] = 'v';

    // Check if we can move in any direction
    if (is_valid(x + 1, y)) {
        // Move right
        if (find_path(x + 1, y)) {
            return true;
        }
    }
    if (is_valid(x - 1, y)) {
        // Move left
        if (find_path(x - 1, y)) {
            return true;
        }
    }
    if (is_valid(x, y + 1)) {
        // Move down
        if (find_path(x, y + 1)) {
            return true;
        }
    }
    if (is_valid(x, y - 1)) {
        // Move up
        if (find_path(x, y - 1)) {
            return true;
        }
    }

    // If we cannot move in any direction, pop the current cell from the stack and backtrack
    node *popped_node = pop();
    maze[popped_node->x][popped_node->y] = ' ';
    free(popped_node);

    return false;
}

// Print the path through the maze
void print_path() {
    // Create a new maze to store the path
    char path[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            path[i][j] = maze[i][j];
        }
    }

    // Mark the path with asterisks
    node *current_node = top;
    while (current_node != NULL) {
        path[current_node->x][current_node->y] = '*';
        current_node = current_node->next;
    }

    // Print the path
    printf("The path through the maze is:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", path[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Find the path through the maze
    bool found_path = find_path(1, 1);

    // Print the path through the maze
    if (found_path) {
        print_path();
    } else {
        printf("No path found.\n");
    }

    return 0;
}
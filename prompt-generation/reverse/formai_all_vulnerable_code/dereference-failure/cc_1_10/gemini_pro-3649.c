//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the directions we can move in
#define UP    0
#define RIGHT 1
#define DOWN  2
#define LEFT  3

// Define the size of the maze
#define WIDTH  20
#define HEIGHT 20

char maze[HEIGHT][WIDTH];

// Define a stack to keep track of our path
struct stack {
    int x, y;
    struct stack *next;
};

struct stack *stack = NULL;

// Push a new element onto the stack
void push(int x, int y) {
    struct stack *new_element = malloc(sizeof(struct stack));
    new_element->x = x;
    new_element->y = y;
    new_element->next = stack;
    stack = new_element;
}

// Pop an element from the stack
void pop(void) {
    if (stack != NULL) {
        struct stack *next = stack->next;
        free(stack);
        stack = next;
    }
}

// Is the given cell a valid move?
int is_valid_move(int x, int y) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) {
        return 0;  // Out of bounds
    }
    if (maze[y][x] == '#') {
        return 0;  // Wall
    }
    return 1;  // Valid move
}

// Generate a random valid move
int random_valid_move(int x, int y) {
    int directions[] = {UP, RIGHT, DOWN, LEFT};
    int num_directions = 4;

    // Remove any invalid directions
    for (int i = 0; i < num_directions; i++) {
        int new_x = x;
        int new_y = y;
        switch (directions[i]) {
            case UP:
                new_y--;
                break;
            case RIGHT:
                new_x++;
                break;
            case DOWN:
                new_y++;
                break;
            case LEFT:
                new_x--;
                break;
        }
        if (!is_valid_move(new_x, new_y)) {
            directions[i] = directions[num_directions - 1];
            num_directions--;
            i--;
        }
    }

    // Choose a random valid direction
    int random_index = rand() % num_directions;
    return directions[random_index];
}

// Generate the maze using a recursive backtracking algorithm
void generate_maze(int x, int y) {
    maze[y][x] = ' ';  // Mark the current cell as visited

    // While there are still unvisited cells
    while (1) {
        // Choose a random valid move
        int direction = random_valid_move(x, y);

        // If there are no valid moves, backtrack
        if (direction == -1) {
            pop();  // Remove the current cell from the stack
            if (stack == NULL) {  // If the stack is empty, we're done
                return;
            }
            x = stack->x;  // Get the coordinates of the previous cell
            y = stack->y;
            continue;
        }

        // Move in the chosen direction
        switch (direction) {
            case UP:
                y--;
                break;
            case RIGHT:
                x++;
                break;
            case DOWN:
                y++;
                break;
            case LEFT:
                x--;
                break;
        }

        // Push the current cell onto the stack
        push(x, y);
    }
}

// Print the maze to the screen
void print_maze(void) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Generate the maze
    generate_maze(0, 0);

    // Print the maze
    print_maze();

    return 0;
}
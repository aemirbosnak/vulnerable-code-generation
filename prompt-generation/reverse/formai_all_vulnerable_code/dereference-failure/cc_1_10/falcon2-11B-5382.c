//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROWS 30
#define MAX_COLS 30

// Define the directions for moving around the maze
enum directions {
    UP,
    RIGHT,
    DOWN,
    LEFT
};

// Define the state of a node in the maze
struct node {
    enum directions direction;
    int row;
    int col;
    struct node *next;
};

// Define a function to create a new node in the maze
struct node* create_node(enum directions direction, int row, int col) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->direction = direction;
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;
    return new_node;
}

// Define a function to print the maze
void print_maze(struct node *start, int rows, int cols) {
    struct node *current = start;
    int row = 0;
    int col = 0;
    while (current!= NULL) {
        switch (current->direction) {
            case UP:
                printf(" %c", 'A' + row);
                row--;
                break;
            case RIGHT:
                printf(" %c", 'A' + col);
                col++;
                break;
            case DOWN:
                printf(" %c", 'A' + row);
                row++;
                break;
            case LEFT:
                printf(" %c", 'A' + col);
                col--;
                break;
            default:
                printf(" %c", 'A' + row);
                row++;
                col++;
        }
        printf(" ");
        current = current->next;
    }
    printf("\n");
}

// Define a function to find the shortest path through the maze
void find_shortest_path(struct node *start, int rows, int cols) {
    struct node *current = start;
    struct node *prev = start;
    bool *visited = calloc(rows * cols, sizeof(bool));
    int steps = 0;
    while (current!= NULL) {
        visited[current->row * cols + current->col] = true;
        printf("Current: %c %d %d\n", 'A' + current->row, current->col, current->direction);
        switch (current->direction) {
            case UP:
                if (!visited[current->row - 1 * cols + current->col]) {
                    prev = current;
                    current = current->next;
                } else if (prev->direction == DOWN) {
                    printf("Shortest path found!\n");
                    break;
                } else {
                    printf("Cannot move up, try again.\n");
                    current = prev;
                    steps--;
                }
                break;
            case RIGHT:
                if (!visited[current->row * cols + current->col + 1]) {
                    prev = current;
                    current = current->next;
                } else if (prev->direction == LEFT) {
                    printf("Shortest path found!\n");
                    break;
                } else {
                    printf("Cannot move right, try again.\n");
                    current = prev;
                    steps--;
                }
                break;
            case DOWN:
                if (!visited[current->row + 1 * cols + current->col]) {
                    prev = current;
                    current = current->next;
                } else if (prev->direction == UP) {
                    printf("Shortest path found!\n");
                    break;
                } else {
                    printf("Cannot move down, try again.\n");
                    current = prev;
                    steps--;
                }
                break;
            case LEFT:
                if (!visited[current->row * cols - 1 + current->col]) {
                    prev = current;
                    current = current->next;
                } else if (prev->direction == RIGHT) {
                    printf("Shortest path found!\n");
                    break;
                } else {
                    printf("Cannot move left, try again.\n");
                    current = prev;
                    steps--;
                }
                break;
        }
        if (current == NULL) {
            printf("No path found.\n");
            break;
        }
        steps++;
    }
    free(visited);
}

int main() {
    // Create the start node
    struct node *start = create_node(UP, 0, 0);

    // Create the maze
    int rows = MAX_ROWS;
    int cols = MAX_COLS;
    struct node *current = start;
    struct node *prev = start;
    while (current!= NULL) {
        struct node *new_node = create_node(RIGHT, current->row, current->col);
        current->next = new_node;
        current = new_node;
        current->next = prev;
        prev = current;
        current = current->next;
    }

    // Print the maze
    printf("Maze: \n");
    print_maze(start, rows, cols);

    // Find the shortest path
    find_shortest_path(start, rows, cols);

    return 0;
}
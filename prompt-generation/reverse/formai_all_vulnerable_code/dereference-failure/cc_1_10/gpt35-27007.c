//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define maze dimensions
#define ROWS 10
#define COLS 10

// Define the maze
int maze[ROWS][COLS] = {
        {0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

// Define a node for the queue
struct node {
    int row;
    int col;
    struct node* next;
};

// Define a function to check if position is valid
int isValid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS || maze[row][col] == 1) {
        return 0;
    }
    return 1;
}

// Define a function to add a node to the queue
void enqueue(struct node** head, struct node** tail, int row, int col) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = *tail = new_node;
    } else {
        (*tail)->next = new_node;
        *tail = (*tail)->next;
    }
}

// Define a function to remove a node from the queue
struct node* dequeue(struct node** head) {
    struct node* temp = *head;
    if (*head == NULL) {
        return NULL;
    } else {
        *head = (*head)->next;
    }
    return temp;
}

// Define the main function for the program
int main () {
    // Define the starting and ending positions
    int start_row = 0;
    int start_col = 0;
    int end_row = ROWS - 1;
    int end_col = COLS - 1;

    // Define the queue
    struct node* head = NULL;
    struct node* tail = NULL;

    // Enqueue the starting position
    enqueue(&head, &tail, start_row, start_col);

    // Define the visited array
    int visited[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            visited[row][col] = 0;
        }
    }

    // Mark the starting position as visited
    visited[start_row][start_col] = 1;

    // Define the path array
    int path[ROWS][COLS];
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            path[row][col] = -1;
        }
    }

    // Define the current node
    struct node* current = NULL;

    // Define the row and col offsets
    int offset_row[4] = {-1, 0, 1, 0};
    int offset_col[4] = {0, 1, 0, -1};

    // BFS algorithm
    while (head != NULL) {
        // Dequeue the current node
        current = dequeue(&head);

        // Check if current node is the ending position
        if (current->row == end_row && current->col == end_col) {
            break;
        }

        // Explore the neighbours
        for (int i = 0; i < 4; i++) {
            int new_row = current->row + offset_row[i];
            int new_col = current->col + offset_col[i];

            // Check if the new position is valid and not visited
            if (isValid(new_row, new_col) && visited[new_row][new_col] == 0) {
                // Enqueue the new position
                enqueue(&head, &tail, new_row, new_col);

                // Mark the new position as visited
                visited[new_row][new_col] = 1;

                // Assign the path value
                path[new_row][new_col] = i;
            }
        }
    }

    // Print the path
    if (path[end_row][end_col] == -1) {
        printf("No path found!\n");
    } else {
        int row = end_row;
        int col = end_col;
        int prev_row, prev_col, tmp;

        while (row != start_row || col != start_col) {
            tmp = path[row][col];
            prev_row = row - offset_row[tmp];
            prev_col = col - offset_col[tmp];
            maze[row][col] = 2;
            row = prev_row;
            col = prev_col;
        }
        maze[start_row][start_col] = 2;
        printf("The path is:\n");
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                switch (maze[row][col]) {
                    case 0:
                        printf(" ");
                        break;
                    case 1:
                        printf("#");
                        break;
                    case 2:
                        printf(".");
                        break;
                    default:
                        printf("?");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
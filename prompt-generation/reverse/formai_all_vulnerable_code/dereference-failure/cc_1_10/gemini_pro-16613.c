//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

// The maze
char maze[ROWS][COLS] = {
    { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' },
    { '1', '0', '0', '0', '0', '0', '0', '1', '0', '1' },
    { '1', '1', '1', '0', '1', '1', '0', '1', '0', '1' },
    { '1', '0', '0', '0', '0', '0', '0', '0', '0', '1' },
    { '1', '1', '1', '1', '1', '1', '1', '1', '0', '1' },
    { '1', '0', '0', '0', '0', '0', '0', '0', '0', '1' },
    { '1', '0', '1', '1', '1', '1', '1', '1', '0', '1' },
    { '1', '0', '0', '0', '0', '0', '0', '0', '0', '1' },
    { '1', '1', '1', '1', '1', '1', '1', '1', '1', '1' }
};

// The visited array
int visited[ROWS][COLS];

// The queue
struct queue {
    int row;
    int col;
    struct queue *next;
};

// The enqueue function
void enqueue(struct queue **head, int row, int col) {
    struct queue *new_node = (struct queue *)malloc(sizeof(struct queue));
    new_node->row = row;
    new_node->col = col;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct queue *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// The dequeue function
struct queue *dequeue(struct queue **head) {
    if (*head == NULL) {
        return NULL;
    } else {
        struct queue *temp = *head;
        *head = (*head)->next;
        return temp;
    }
}

// The is_valid_move function
int is_valid_move(int row, int col) {
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] != '1' && !visited[row][col]);
}

// The find_path function
int find_path(int start_row, int start_col, int end_row, int end_col) {
    // Initialize the queue
    struct queue *head = NULL;

    // Enqueue the starting cell
    enqueue(&head, start_row, start_col);

    // Mark the starting cell as visited
    visited[start_row][start_col] = 1;

    // While the queue is not empty
    while (head != NULL) {
        // Dequeue the next cell
        struct queue *current = dequeue(&head);

        // If the current cell is the end cell, return true
        if (current->row == end_row && current->col == end_col) {
            return 1;
        }

        // Otherwise, check all the adjacent cells
        if (is_valid_move(current->row - 1, current->col)) {
            enqueue(&head, current->row - 1, current->col);
            visited[current->row - 1][current->col] = 1;
        }
        if (is_valid_move(current->row + 1, current->col)) {
            enqueue(&head, current->row + 1, current->col);
            visited[current->row + 1][current->col] = 1;
        }
        if (is_valid_move(current->row, current->col - 1)) {
            enqueue(&head, current->row, current->col - 1);
            visited[current->row][current->col - 1] = 1;
        }
        if (is_valid_move(current->row, current->col + 1)) {
            enqueue(&head, current->row, current->col + 1);
            visited[current->row][current->col + 1] = 1;
        }
    }

    // If the queue is empty and the end cell has not been reached, return false
    return 0;
}

// The main function
int main() {
    // Get the starting and ending cells
    int start_row, start_col, end_row, end_col;
    printf("Enter the starting cell (row, col): ");
    scanf("%d %d", &start_row, &start_col);
    printf("Enter the ending cell (row, col): ");
    scanf("%d %d", &end_row, &end_col);

    // Find the path
    int path_found = find_path(start_row, start_col, end_row, end_col);

    // Print the result
    if (path_found) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}
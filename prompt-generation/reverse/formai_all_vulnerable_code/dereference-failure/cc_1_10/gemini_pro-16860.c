//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// The maze represented as a 2D array of integers
int maze[MAZE_WIDTH][MAZE_HEIGHT] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// The starting position of the maze solver
int start_row = 1;
int start_col = 1;

// The ending position of the maze solver
int end_row = 8;
int end_col = 8;

// A stack to store the current path of the maze solver
struct stack {
    int row;
    int col;
    struct stack *next;
};

// Pushes a new element onto the stack
void push(struct stack **head, int row, int col) {
  struct stack *new_element = malloc(sizeof(struct stack));
  new_element->row = row;
  new_element->col = col;
  new_element->next = *head;
  *head = new_element;
}

// Pops the top element from the stack
void pop(struct stack **head) {
  if (*head == NULL) {
    return;
  }
  struct stack *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// Checks if the given position is valid
bool is_valid_position(int row, int col) {
  return row >= 0 && row < MAZE_HEIGHT && col >= 0 && col < MAZE_WIDTH && maze[row][col] == 0;
}

// Checks if the given position is the end of the maze
bool is_end_position(int row, int col) {
  return row == end_row && col == end_col;
}

// Finds a path through the maze using a depth-first search
bool find_path(struct stack **head, int row, int col) {
  // Push the current position onto the stack
  push(head, row, col);

  // Check if the current position is the end of the maze
  if (is_end_position(row, col)) {
    return true;
  }

  // Explore all possible moves from the current position
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      // Skip the current position
      if (i == 0 && j == 0) {
        continue;
      }

      // Check if the move is valid
      int new_row = row + i;
      int new_col = col + j;
      if (is_valid_position(new_row, new_col)) {

        // Move the maze solver to the new position
        if (find_path(head, new_row, new_col)) {
          return true;
        }
      }
    }
  }

  // No path was found from the current position, so pop it from the stack
  pop(head);
  return false;
}

int main() {
  // Create a stack to store the path of the maze solver
  struct stack *head = NULL;

  // Find a path through the maze
  bool path_found = find_path(&head, start_row, start_col);

  // Print the path if a path was found
  if (path_found) {
    printf("Path found:\n");

    struct stack *curr = head;
    while (curr != NULL) {
      printf("(%d, %d)\n", curr->row, curr->col);
      curr = curr->next;
    }

  } else {
    printf("No path found.\n");
  }

  // Free the stack
  while (head != NULL) {
    pop(&head);
  }

  return 0;
}
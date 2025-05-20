//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAZE_SIZE 10

// The maze is represented as a 2D array of characters.
char maze[MAZE_SIZE][MAZE_SIZE] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
  {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
  {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// The starting position of the maze.
int start_x = 1;
int start_y = 1;

// The ending position of the maze.
int end_x = MAZE_SIZE - 2;
int end_y = MAZE_SIZE - 2;

// A stack to store the path through the maze.
struct stack {
  int x;
  int y;
  struct stack *next;
};

// A function to push a position onto the stack.
void push(struct stack **head, int x, int y) {
  struct stack *new_node = malloc(sizeof(struct stack));
  new_node->x = x;
  new_node->y = y;
  new_node->next = *head;
  *head = new_node;
}

// A function to pop a position from the stack.
void pop(struct stack **head) {
  if (*head == NULL) {
    return;
  }
  struct stack *temp = *head;
  *head = (*head)->next;
  free(temp);
}

// A function to check if a position is valid.
bool is_valid(int x, int y) {
  return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && maze[x][y] != '#';
}

// A function to find the path through the maze.
bool find_path(struct stack **head, int x, int y) {
  // If we have reached the end of the maze, return true.
  if (x == end_x && y == end_y) {
    return true;
  }
  // Push the current position onto the stack.
  push(head, x, y);
  // Mark the current position as visited.
  maze[x][y] = 'v';
  // Try all four directions.
  if (is_valid(x + 1, y) && find_path(head, x + 1, y)) {
    return true;
  }
  if (is_valid(x - 1, y) && find_path(head, x - 1, y)) {
    return true;
  }
  if (is_valid(x, y + 1) && find_path(head, x, y + 1)) {
    return true;
  }
  if (is_valid(x, y - 1) && find_path(head, x, y - 1)) {
    return true;
  }
  // If we cannot move in any direction, pop the current position from the stack.
  pop(head);
  // Unmark the current position as visited.
  maze[x][y] = ' ';
  // Return false to indicate that we have not found a path.
  return false;
}

// A function to print the maze.
void print_maze() {
  for (int i = 0; i < MAZE_SIZE; i++) {
    for (int j = 0; j < MAZE_SIZE; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Create a stack to store the path through the maze.
  struct stack *head = NULL;
  // Find the path through the maze.
  bool found = find_path(&head, start_x, start_y);
  // Print the maze.
  print_maze();
  // Free the stack.
  while (head != NULL) {
    pop(&head);
  }
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_WIDTH  10
#define MAZE_HEIGHT 10

// The maze represented as a 2D array of characters.
char maze[MAZE_WIDTH][MAZE_HEIGHT] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
  {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
};

// The starting and ending positions of the maze.
int start_x = 1;
int start_y = 1;
int end_x = MAZE_WIDTH - 2;
int end_y = MAZE_HEIGHT - 2;

// A queue of positions to visit.
struct queue_node {
  int x;
  int y;
  struct queue_node *next;
};
struct queue_node *queue_head = NULL;
struct queue_node *queue_tail = NULL;

// A stack of positions to backtrack from.
struct stack_node {
  int x;
  int y;
  struct stack_node *next;
};
struct stack_node *stack_head = NULL;

// A function to add a position to the queue.
void queue_push(int x, int y) {
  struct queue_node *new_node = malloc(sizeof(struct queue_node));
  new_node->x = x;
  new_node->y = y;
  new_node->next = NULL;

  if (queue_head == NULL) {
    queue_head = new_node;
    queue_tail = new_node;
  } else {
    queue_tail->next = new_node;
    queue_tail = new_node;
  }
}

// A function to remove a position from the queue.
struct queue_node *queue_pop() {
  if (queue_head == NULL) {
    return NULL;
  }

  struct queue_node *old_head = queue_head;
  queue_head = queue_head->next;

  if (queue_head == NULL) {
    queue_tail = NULL;
  }

  return old_head;
}

// A function to add a position to the stack.
void stack_push(int x, int y) {
  struct stack_node *new_node = malloc(sizeof(struct stack_node));
  new_node->x = x;
  new_node->y = y;
  new_node->next = NULL;

  if (stack_head == NULL) {
    stack_head = new_node;
  } else {
    new_node->next = stack_head;
    stack_head = new_node;
  }
}

// A function to remove a position from the stack.
struct stack_node *stack_pop() {
  if (stack_head == NULL) {
    return NULL;
  }

  struct stack_node *old_head = stack_head;
  stack_head = stack_head->next;

  return old_head;
}

// A function to check if a position is valid.
int is_valid_position(int x, int y) {
  return x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[x][y] != '#';
}

// A function to find a path through the maze using depth-first search.
int find_path_dfs() {
  // Push the starting position onto the stack.
  stack_push(start_x, start_y);

  while (stack_head != NULL) {
    // Pop the top position from the stack.
    struct stack_node *current_node = stack_pop();
    int x = current_node->x;
    int y = current_node->y;

    // Check if the current position is the ending position.
    if (x == end_x && y == end_y) {
      return 1;
    }

    // Check if the current position is a valid position.
    if (!is_valid_position(x, y)) {
      continue;
    }

    // Mark the current position as visited.
    maze[x][y] = 'V';

    // Push the adjacent positions onto the stack.
    if (is_valid_position(x - 1, y)) {
      stack_push(x - 1, y);
    }
    if (is_valid_position(x + 1, y)) {
      stack_push(x + 1, y);
    }
    if (is_valid_position(x, y - 1)) {
      stack_push(x, y - 1);
    }
    if (is_valid_position(x, y + 1)) {
      stack_push(x, y + 1);
    }
  }

  // No path was found.
  return 0;
}

// A function to find a path through the maze using breadth-first search.
int find_path_bfs() {
  // Push the starting position onto the queue.
  queue_push(start_x, start_y);

  while (queue_head != NULL) {
    // Pop the front position from the queue.
    struct queue_node *current_node = queue_pop();
    int x = current_node->x;
    int y = current_node->y;

    // Check if the current position is the ending position.
    if (x == end_x && y == end_y) {
      return 1;
    }

    // Check if the current position is a valid position.
    if (!is_valid_position(x, y)) {
      continue;
    }

    // Mark the current position as visited.
    maze[x][y] = 'V';

    // Push the adjacent positions onto the queue.
    if (is_valid_position(x - 1, y)) {
      queue_push(x - 1, y);
    }
    if (is_valid_position(x + 1, y)) {
      queue_push(x + 1, y);
    }
    if (is_valid_position(x, y - 1)) {
      queue_push(x, y - 1);
    }
    if (is_valid_position(x, y + 1)) {
      queue_push(x, y + 1);
    }
  }

  // No path was found.
  return 0;
}

// A function to print the maze.
void print_maze() {
  for (int y = 0; y < MAZE_HEIGHT; ++y) {
    for (int x = 0; x < MAZE_WIDTH; ++x) {
      printf("%c", maze[x][y]);
    }
    printf("\n");
  }
}

int main() {
  // Find a path through the maze using depth-first search.
  int path_found = find_path_dfs();

  // Print the maze.
  print_maze();

  if (path_found) {
    printf("Path found using depth-first search.\n");
  } else {
    printf("No path found using depth-first search.\n");
  }

  // Reset the maze.
  for (int y = 0; y < MAZE_HEIGHT; ++y) {
    for (int x = 0; x < MAZE_WIDTH; ++x) {
      maze[x][y] = '.';
    }
  }

  // Find a path through the maze using breadth-first search.
  path_found = find_path_bfs();

  // Print the maze.
  print_maze();

  if (path_found) {
    printf("Path found using breadth-first search.\n");
  } else {
    printf("No path found using breadth-first search.\n");
  }

  return 0;
}
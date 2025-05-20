//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Maze dimensions
#define MAZE_WIDTH 10
#define MAZE_HEIGHT 10

// Maze data structure
char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
  {'#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#'},
  {'#', ' ', '#', ' ', '#', '#', ' ', '#', ' ', '#'},
  {'#', ' ', '#', ' ', '#', ' ', ' ', '#', ' ', '#'},
  {'#', ' ', '#', ' ', '#', ' ', '#', '#', ' ', '#'},
  {'#', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
  {'#', ' ', '#', '#', '#', '#', '#', '#', ' ', '#'},
  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

// Start and end points
int start_x = 1;
int start_y = 1;
int end_x = 8;
int end_y = 8;

// Queue for BFS
typedef struct queue {
  int x;
  int y;
  struct queue *next;
} queue;

// Push a new element to the queue
void push(queue **head, int x, int y) {
  queue *new_element = (queue *)malloc(sizeof(queue));
  new_element->x = x;
  new_element->y = y;
  new_element->next = NULL;

  if (*head == NULL) {
    *head = new_element;
  } else {
    queue *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_element;
  }
}

// Pop the first element from the queue
void pop(queue **head) {
  if (*head != NULL) {
    queue *next_element = (*head)->next;
    free(*head);
    *head = next_element;
  }
}

// Check if the given coordinates are valid
int is_valid(int x, int y) {
  return (x >= 0 && x < MAZE_WIDTH && y >= 0 && y < MAZE_HEIGHT && maze[y][x] != '#');
}

// Find the shortest path from the start to the end point using BFS
int find_path() {
  // Initialize the queue
  queue *head = NULL;

  // Push the start point to the queue
  push(&head, start_x, start_y);

  // Mark the start point as visited
  maze[start_y][start_x] = 'V';

  // Loop until the queue is empty or the end point is found
  while (head != NULL) {
    // Pop the first element from the queue
    queue *current = head;
    int x = current->x;
    int y = current->y;
    pop(&head);

    // Check if the end point is found
    if (x == end_x && y == end_y) {
      return 1;
    }

    // Check if the current point is a valid move
    if (is_valid(x + 1, y)) {
      // Push the right neighbor to the queue
      push(&head, x + 1, y);
      // Mark the right neighbor as visited
      maze[y][x + 1] = 'V';
    }

    if (is_valid(x - 1, y)) {
      // Push the left neighbor to the queue
      push(&head, x - 1, y);
      // Mark the left neighbor as visited
      maze[y][x - 1] = 'V';
    }

    if (is_valid(x, y + 1)) {
      // Push the down neighbor to the queue
      push(&head, x, y + 1);
      // Mark the down neighbor as visited
      maze[y + 1][x] = 'V';
    }

    if (is_valid(x, y - 1)) {
      // Push the up neighbor to the queue
      push(&head, x, y - 1);
      // Mark the up neighbor as visited
      maze[y - 1][x] = 'V';
    }
  }

  // No path found
  return 0;
}

// Print the maze
void print_maze() {
  for (int i = 0; i < MAZE_HEIGHT; i++) {
    for (int j = 0; j < MAZE_WIDTH; j++) {
      printf("%c", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Find the shortest path
  int path_found = find_path();

  // Print the result
  if (path_found) {
    printf("Path found!\n");
    print_maze();
  } else {
    printf("No path found\n");
  }

  return 0;
}
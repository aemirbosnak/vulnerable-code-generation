//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20

// A node in the maze
typedef struct node {
  int x, y;
  struct node *neighbors[4];
} node;

// The maze itself
node *maze[WIDTH][HEIGHT];

// A stack of nodes to visit
node *stack[WIDTH * HEIGHT];
int stack_size = 0;

// Create a new node at the given coordinates
node *create_node(int x, int y) {
  node *n = malloc(sizeof(node));
  n->x = x;
  n->y = y;
  for (int i = 0; i < 4; i++) {
    n->neighbors[i] = NULL;
  }
  return n;
}

// Add a node to the stack
void push(node *n) {
  stack[stack_size++] = n;
}

// Remove a node from the stack
node *pop() {
  return stack[--stack_size];
}

// Check if a node is in the stack
int in_stack(node *n) {
  for (int i = 0; i < stack_size; i++) {
    if (stack[i] == n) {
      return 1;
    }
  }
  return 0;
}

// Check if a node is in the maze
int in_maze(node *n) {
  return n->x >= 0 && n->x < WIDTH && n->y >= 0 && n->y < HEIGHT;
}

// Check if a node has any unvisited neighbors
int has_unvisited_neighbors(node *n) {
  for (int i = 0; i < 4; i++) {
    if (n->neighbors[i] == NULL) {
      return 1;
    }
  }
  return 0;
}

// Get a random unvisited neighbor of a node
node *get_random_unvisited_neighbor(node *n) {
  int neighbors[4];
  int num_neighbors = 0;
  for (int i = 0; i < 4; i++) {
    if (n->neighbors[i] == NULL) {
      neighbors[num_neighbors++] = i;
    }
  }
  return n->neighbors[neighbors[rand() % num_neighbors]];
}

// Generate the maze
void generate_maze() {
  // Create the starting node
  node *start = create_node(0, 0);
  push(start);

  // While there are still unvisited nodes
  while (stack_size > 0) {
    // Get the current node
    node *current = pop();

    // If the current node has any unvisited neighbors
    if (has_unvisited_neighbors(current)) {
      // Get a random unvisited neighbor
      node *neighbor = get_random_unvisited_neighbor(current);

      // Connect the current node to the neighbor
      current->neighbors[neighbor->x - current->x + 1] = neighbor;
      neighbor->neighbors[current->x - neighbor->x + 1] = current;

      // Push the neighbor onto the stack
      push(neighbor);
    }
  }
}

// Print the maze to the console
void print_maze() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      node *n = maze[x][y];
      if (n == NULL) {
        printf("#");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the maze
  generate_maze();

  // Print the maze to the console
  print_maze();

  return 0;
}
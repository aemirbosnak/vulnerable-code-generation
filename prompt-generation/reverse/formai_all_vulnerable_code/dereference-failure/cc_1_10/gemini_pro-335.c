//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Map dimensions
#define WIDTH 10
#define HEIGHT 10

// Map data
int map[WIDTH][HEIGHT] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// Pathfinding algorithm
typedef struct {
  int x;
  int y;
} Node;

typedef struct {
  Node* nodes;
  int size;
  int capacity;
} Queue;

Queue* queue_init(int capacity) {
  Queue* queue = malloc(sizeof(Queue));
  queue->nodes = malloc(sizeof(Node) * capacity);
  queue->size = 0;
  queue->capacity = capacity;
  return queue;
}

void queue_push(Queue* queue, Node node) {
  if (queue->size == queue->capacity) {
    queue->capacity *= 2;
    queue->nodes = realloc(queue->nodes, sizeof(Node) * queue->capacity);
  }
  queue->nodes[queue->size++] = node;
}

Node queue_pop(Queue* queue) {
  if (queue->size == 0) {
    printf("Error: Queue is empty.\n");
    exit(1);
  }
  return queue->nodes[--queue->size];
}

Node* find_path(int start_x, int start_y, int end_x, int end_y) {
  Queue* queue = queue_init(WIDTH * HEIGHT);
  Node start = {start_x, start_y};
  queue_push(queue, start);

  while (queue->size > 0) {
    Node current = queue_pop(queue);

    // Check if we have reached the destination
    if (current.x == end_x && current.y == end_y) {
      return &current;
    }

    // Check if we can move up
    if (current.y > 0 && map[current.x][current.y - 1] == 0) {
      Node up = {current.x, current.y - 1};
      queue_push(queue, up);
    }

    // Check if we can move right
    if (current.x < WIDTH - 1 && map[current.x + 1][current.y] == 0) {
      Node right = {current.x + 1, current.y};
      queue_push(queue, right);
    }

    // Check if we can move down
    if (current.y < HEIGHT - 1 && map[current.x][current.y + 1] == 0) {
      Node down = {current.x, current.y + 1};
      queue_push(queue, down);
    }

    // Check if we can move left
    if (current.x > 0 && map[current.x - 1][current.y] == 0) {
      Node left = {current.x - 1, current.y};
      queue_push(queue, left);
    }
  }

  // No path found
  return NULL;
}

// Print the map with the path
void print_map(Node* path) {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      if (path != NULL && path->x == x && path->y == y) {
        printf("X"); // Path
      } else if (map[x][y] == 1) {
        printf("#"); // Wall
      } else {
        printf(" "); // Open space
      }
    }
    printf("\n");
  }
}

int main() {
  // Start and end points
  int start_x = 1;
  int start_y = 1;
  int end_x = 8;
  int end_y = 8;

  // Find the path
  Node* path = find_path(start_x, start_y, end_x, end_y);

  // Print the map with the path
  print_map(path);

  return 0;
}
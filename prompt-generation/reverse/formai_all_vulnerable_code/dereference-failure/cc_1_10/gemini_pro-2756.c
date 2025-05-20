//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the maze
int maze[10][10] = {
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

// Define the starting and ending points
int start_x = 1;
int start_y = 1;
int end_x = 8;
int end_y = 8;

// Define the directions
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

// Define the queue
struct queue {
  int x;
  int y;
  struct queue *next;
};

// Create a new queue element
struct queue *create_queue_element(int x, int y) {
  struct queue *new_element = (struct queue *)malloc(sizeof(struct queue));
  new_element->x = x;
  new_element->y = y;
  new_element->next = NULL;
  return new_element;
}

// Enqueue an element
void enqueue(struct queue **head, struct queue *element) {
  if (*head == NULL) {
    *head = element;
  } else {
    struct queue *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = element;
  }
}

// Dequeue an element
struct queue *dequeue(struct queue **head) {
  if (*head == NULL) {
    return NULL;
  }
  struct queue *element = *head;
  *head = (*head)->next;
  return element;
}

// Check if the queue is empty
int is_queue_empty(struct queue *head) {
  return head == NULL;
}

// Find the shortest path from the starting point to the ending point
int find_shortest_path() {
  // Create the queue
  struct queue *queue = NULL;

  // Enqueue the starting point
  enqueue(&queue, create_queue_element(start_x, start_y));

  // Mark the starting point as visited
  maze[start_x][start_y] = 2;

  // While the queue is not empty
  while (!is_queue_empty(queue)) {
    // Dequeue the first element from the queue
    struct queue *element = dequeue(&queue);

    // Check if the element is the ending point
    if (element->x == end_x && element->y == end_y) {
      // Free the queue
      while (!is_queue_empty(queue)) {
        free(dequeue(&queue));
      }
      return 1;
    }

    // Try all four directions
    for (int i = 0; i < 4; i++) {
      int new_x = element->x + dx[i];
      int new_y = element->y + dy[i];

      // Check if the new position is valid and not visited
      if (new_x >= 0 && new_x < 10 && new_y >= 0 && new_y < 10 && maze[new_x][new_y] == 0) {
        // Enqueue the new position
        enqueue(&queue, create_queue_element(new_x, new_y));

        // Mark the new position as visited
        maze[new_x][new_y] = 2;
      }
    }

    // Free the element
    free(element);
  }

  // Free the queue
  while (!is_queue_empty(queue)) {
    free(dequeue(&queue));
  }

  // No path found
  return 0;
}

// Print the maze
void print_maze() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", maze[i][j]);
    }
    printf("\n");
  }
}

int main() {
  // Find the shortest path
  int found = find_shortest_path();

  // Print the result
  if (found) {
    printf("Path found!\n");
  } else {
    printf("No path found!\n");
  }

  // Print the maze
  print_maze();

  return 0;
}
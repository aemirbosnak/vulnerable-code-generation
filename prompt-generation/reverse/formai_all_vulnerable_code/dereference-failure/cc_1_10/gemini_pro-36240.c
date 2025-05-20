//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the grid size
#define GRID_WIDTH 10
#define GRID_HEIGHT 10

// Define the start and end points
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

// Define the grid
int grid[GRID_WIDTH][GRID_HEIGHT] = {
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
  { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 },
  { 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 1, 1, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 0, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 1, 0, 1 },
  { 1, 0, 1, 0, 1, 0, 1, 0, 0, 1 },
  { 1, 0, 1, 0, 0, 0, 1, 0, 1, 1 },
  { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

// Define the directions
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// Define the queue
typedef struct queue {
  int x;
  int y;
  struct queue* next;
} queue;

// Create a new queue
queue* create_queue() {
  queue* q = (queue*)malloc(sizeof(queue));
  q->x = -1;
  q->y = -1;
  q->next = NULL;
  return q;
}

// Enqueue a new element
void enqueue(queue** q, int x, int y) {
  queue* new_element = (queue*)malloc(sizeof(queue));
  new_element->x = x;
  new_element->y = y;
  new_element->next = NULL;
  if (*q == NULL) {
    *q = new_element;
  } else {
    queue* temp = *q;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = new_element;
  }
}

// Dequeue an element
int dequeue(queue** q, int* x, int* y) {
  if (*q == NULL) {
    return 0;
  }
  *x = (*q)->x;
  *y = (*q)->y;
  *q = (*q)->next;
  return 1;
}

// Check if the queue is empty
int is_queue_empty(queue* q) {
  return q == NULL;
}

// Find the shortest path from the start to the end point using BFS
int find_shortest_path(int grid[GRID_WIDTH][GRID_HEIGHT], int start_x, int start_y, int end_x, int end_y) {
  // Create a queue to store the nodes to be visited
  queue* q = create_queue();

  // Enqueue the start node
  enqueue(&q, start_x, start_y);

  // Create a visited array to keep track of the nodes that have been visited
  int visited[GRID_WIDTH][GRID_HEIGHT] = { 0 };

  // Create a distance array to store the distance from the start node to each node
  int distance[GRID_WIDTH][GRID_HEIGHT] = { 0 };

  // Set the distance of the start node to 0
  distance[start_x][start_y] = 0;

  // While the queue is not empty
  while (!is_queue_empty(q)) {
    // Dequeue the first node from the queue
    int x, y;
    dequeue(&q, &x, &y);

    // If the current node is the end node, return the distance
    if (x == end_x && y == end_y) {
      return distance[x][y];
    }

    // For each of the four directions
    for (int i = 0; i < 4; i++) {
      // Get the next node in the current direction
      int nx = x + dx[i];
      int ny = y + dy[i];

      // If the next node is within the grid and has not been visited
      if (nx >= 0 && nx < GRID_WIDTH && ny >= 0 && ny < GRID_HEIGHT && !visited[nx][ny] && grid[nx][ny] == 0) {
        // Enqueue the next node
        enqueue(&q, nx, ny);

        // Set the distance of the next node to the distance of the current node plus 1
        distance[nx][ny] = distance[x][y] + 1;

        // Mark the next node as visited
        visited[nx][ny] = 1;
      }
    }
  }

  // Return -1 if the end node is not reachable
  return -1;
}

// Print the grid
void print_grid(int grid[GRID_WIDTH][GRID_HEIGHT]) {
  for (int i = 0; i < GRID_WIDTH; i++) {
    for (int j = 0; j < GRID_HEIGHT; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Find the shortest path from the start to the end point
  int shortest_path = find_shortest_path(grid, START_X, START_Y, END_X, END_Y);

  // Print the shortest path
  printf("The shortest path from (%d, %d) to (%d, %d) is %d\n", START_X, START_Y, END_X, END_Y, shortest_path);

  // Print the grid
  printf("The grid is:\n");
  print_grid(grid);

  return 0;
}
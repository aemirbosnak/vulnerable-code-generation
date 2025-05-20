//GEMINI-pro DATASET v1.0 Category: Percolation Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Grid dimensions
#define GRID_WIDTH 20
#define GRID_HEIGHT 20

// Probability of a site being open
#define P 0.5

// Data structures
typedef struct {
  int x;
  int y;
} Site;

typedef struct {
  Site *sites;
  int size;
  int capacity;
} Queue;

// Function prototypes
Queue *create_queue(int capacity);
void destroy_queue(Queue *queue);
int is_empty_queue(Queue *queue);
void enqueue(Queue *queue, Site site);
Site dequeue(Queue *queue);
int is_open_site(int x, int y);
int is_in_bounds(int x, int y);
void print_grid(int **grid);
int simulate_percolation();

// Main function
int main() {
  // Initialize random number generator
  srand(time(NULL));

  // Simulate percolation
  int num_simulations = 1000;
  int num_percolating = 0;
  for (int i = 0; i < num_simulations; i++) {
    if (simulate_percolation()) {
      num_percolating++;
    }
  }

  // Print results
  printf("Probability of percolation: %f\n", (float)num_percolating / num_simulations);

  return 0;
}

// Create a queue
Queue *create_queue(int capacity) {
  Queue *queue = malloc(sizeof(Queue));
  queue->sites = malloc(sizeof(Site) * capacity);
  queue->size = 0;
  queue->capacity = capacity;
  return queue;
}

// Destroy a queue
void destroy_queue(Queue *queue) {
  free(queue->sites);
  free(queue);
}

// Check if a queue is empty
int is_empty_queue(Queue *queue) {
  return queue->size == 0;
}

// Enqueue a site
void enqueue(Queue *queue, Site site) {
  if (queue->size == queue->capacity) {
    queue->capacity *= 2;
    queue->sites = realloc(queue->sites, sizeof(Site) * queue->capacity);
  }
  queue->sites[queue->size++] = site;
}

// Dequeue a site
Site dequeue(Queue *queue) {
  if (is_empty_queue(queue)) {
    printf("Error: cannot dequeue from an empty queue.\n");
    exit(1);
  }
  return queue->sites[--queue->size];
}

// Check if a site is open
int is_open_site(int x, int y) {
  return rand() < P;
}

// Check if a site is in bounds
int is_in_bounds(int x, int y) {
  return x >= 0 && x < GRID_WIDTH && y >= 0 && y < GRID_HEIGHT;
}

// Print the grid
void print_grid(int **grid) {
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      printf("%d ", grid[y][x]);
    }
    printf("\n");
  }
}

// Simulate percolation
int simulate_percolation() {
  // Create a grid of sites
  int **grid = malloc(sizeof(int *) * GRID_HEIGHT);
  for (int i = 0; i < GRID_HEIGHT; i++) {
    grid[i] = malloc(sizeof(int) * GRID_WIDTH);
  }

  // Initialize the grid
  for (int y = 0; y < GRID_HEIGHT; y++) {
    for (int x = 0; x < GRID_WIDTH; x++) {
      grid[y][x] = is_open_site(x, y);
    }
  }

  // Create a queue of sites to visit
  Queue *queue = create_queue(GRID_WIDTH * GRID_HEIGHT);

  // Add the top row of sites to the queue
  for (int x = 0; x < GRID_WIDTH; x++) {
    if (grid[0][x]) {
      enqueue(queue, (Site){ .x = x, .y = 0 });
    }
  }

  // Perform breadth-first search to find all connected open sites
  while (!is_empty_queue(queue)) {
    // Get the next site to visit
    Site site = dequeue(queue);

    // Check if the site has already been visited
    if (!grid[site.y][site.x]) {
      continue;
    }

    // Mark the site as visited
    grid[site.y][site.x] = 0;

    // Add all adjacent open sites to the queue
    for (int dy = -1; dy <= 1; dy++) {
      for (int dx = -1; dx <= 1; dx++) {
        int x = site.x + dx;
        int y = site.y + dy;
        if (is_in_bounds(x, y) && grid[y][x]) {
          enqueue(queue, (Site){ .x = x, .y = y });
        }
      }
    }
  }

  // Check if there is a path of open sites from the top row to the bottom row
  for (int x = 0; x < GRID_WIDTH; x++) {
    if (grid[GRID_HEIGHT - 1][x]) {
      return 1;
    }
  }

  // Destroy the grid and the queue
  for (int i = 0; i < GRID_HEIGHT; i++) {
    free(grid[i]);
  }
  free(grid);
  destroy_queue(queue);

  return 0;
}
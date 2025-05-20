//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Map parameters
#define MAP_WIDTH 50
#define MAP_HEIGHT 50

// Node structure
typedef struct node {
  int x;
  int y;
  int f;
  int g;
  int h;
  struct node *parent;
} node;

// Map structure
typedef struct map {
  char **cells;
  int width;
  int height;
} map;

// Function to create a new map
map *create_map(int width, int height) {
  map *new_map = (map *)malloc(sizeof(map));
  new_map->cells = (char **)malloc(sizeof(char *) * height);
  for (int i = 0; i < height; i++) {
    new_map->cells[i] = (char *)malloc(sizeof(char) * width);
  }
  new_map->width = width;
  new_map->height = height;
  return new_map;
}

// Function to destroy a map
void destroy_map(map *map) {
  for (int i = 0; i < map->height; i++) {
    free(map->cells[i]);
  }
  free(map->cells);
  free(map);
}

// Function to set a cell in the map to a value
void set_cell(map *map, int x, int y, char value) {
  map->cells[y][x] = value;
}

// Function to get a cell from the map
char get_cell(map *map, int x, int y) {
  return map->cells[y][x];
}

// Function to print the map
void print_map(map *map) {
  for (int i = 0; i < map->height; i++) {
    for (int j = 0; j < map->width; j++) {
      printf("%c", map->cells[i][j]);
    }
    printf("\n");
  }
}

// Function to create a new node
node *create_node(int x, int y, int f, int g, int h, node *parent) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->x = x;
  new_node->y = y;
  new_node->f = f;
  new_node->g = g;
  new_node->h = h;
  new_node->parent = parent;
  return new_node;
}

// Function to destroy a node
void destroy_node(node *node) {
  free(node);
}

// Function to calculate the f-score of a node
int calculate_f_score(node *node) {
  return node->g + node->h;
}

// Function to compare two nodes based on their f-score
int compare_nodes(const void *a, const void *b) {
  node *node1 = (node *)a;
  node *node2 = (node *)b;
  return node1->f - node2->f;
}

// Function to find the path from the start node to the end node
node *find_path(map *map, node *start_node, node *end_node) {
  // Create a priority queue to store the nodes
  node **priority_queue = (node **)malloc(sizeof(node *) * MAP_WIDTH * MAP_HEIGHT);
  int priority_queue_size = 0;

  // Add the start node to the priority queue
  priority_queue[priority_queue_size++] = start_node;

  // While the priority queue is not empty
  while (priority_queue_size > 0) {
    // Get the node with the lowest f-score from the priority queue
    node *current_node = priority_queue[0];
    for (int i = 1; i < priority_queue_size; i++) {
      if (compare_nodes(current_node, priority_queue[i]) > 0) {
        current_node = priority_queue[i];
      }
    }

    // Remove the node from the priority queue
    for (int i = 0; i < priority_queue_size; i++) {
      if (priority_queue[i] == current_node) {
        priority_queue[i] = priority_queue[priority_queue_size - 1];
        priority_queue_size--;
        break;
      }
    }

    // If the current node is the end node, return the path
    if (current_node->x == end_node->x && current_node->y == end_node->y) {
      return current_node;
    }

    // For each neighbor of the current node
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        if (i == 0 && j == 0) {
          continue;
        }

        int neighbor_x = current_node->x + i;
        int neighbor_y = current_node->y + j;

        // If the neighbor is within the bounds of the map
        if (neighbor_x >= 0 && neighbor_x < map->width && neighbor_y >= 0 && neighbor_y < map->height) {
          // If the neighbor is not an obstacle
          if (get_cell(map, neighbor_x, neighbor_y) != 'X') {
            // Calculate the g-score of the neighbor
            int neighbor_g = current_node->g + 1;

            // Calculate the h-score of the neighbor
            int neighbor_h = abs(neighbor_x - end_node->x) + abs(neighbor_y - end_node->y);

            // Calculate the f-score of the neighbor
            int neighbor_f = calculate_f_score(create_node(neighbor_x, neighbor_y, neighbor_f, neighbor_g, neighbor_h, current_node));

            // Add the neighbor to the priority queue
            priority_queue[priority_queue_size++] = create_node(neighbor_x, neighbor_y, neighbor_f, neighbor_g, neighbor_h, current_node);
          }
        }
      }
    }
  }

  // If the path was not found, return NULL
  return NULL;
}

// Function to print the path from the start node to the end node
void print_path(node *path) {
  while (path != NULL) {
    printf("(%d, %d)\n", path->x, path->y);
    path = path->parent;
  }
}

// Main function
int main() {
  // Create a map
  map *map = create_map(MAP_WIDTH, MAP_HEIGHT);

  // Set the obstacles in the map
  for (int i = 0; i < MAP_WIDTH; i++) {
    set_cell(map, i, 0, 'X');
    set_cell(map, i, MAP_HEIGHT - 1, 'X');
  }
  for (int i = 0; i < MAP_HEIGHT; i++) {
    set_cell(map, 0, i, 'X');
    set_cell(map, MAP_WIDTH - 1, i, 'X');
  }

  // Print the map
  print_map(map);

  // Get the start and end nodes
  node *start_node = create_node(1, 1, 0, 0, 0, NULL);
  node *end_node = create_node(MAP_WIDTH - 2, MAP_HEIGHT - 2, 0, 0, 0, NULL);

  // Find the path from the start node to the end node
  node *path = find_path(map, start_node, end_node);

  // Print the path
  print_path(path);

  // Destroy the path
  destroy_node(path);

  // Destroy the start and end nodes
  destroy_node(start_node);
  destroy_node(end_node);

  // Destroy the map
  destroy_map(map);

  return 0;
}
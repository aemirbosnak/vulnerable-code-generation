//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: relaxed
/*
  A* Pathfinding Algorithm Example Program
  Author: [Your Name]
  Date: [Current Date]
*/

#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

// Define the grid/map with start and goal points
char map[ROWS][COLS] = {
  {'S', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', '.'},
  {'.', '.', '.', '.', '.', '.', '.', 'G'}
};

// Define the structure for each node in the search tree
typedef struct node {
  int row, col;
  int f, g, h;
  struct node *parent;
} Node;

// Function to find the Manhattan distance between two points
int manhattan_distance(int row1, int col1, int row2, int col2) {
  return abs(row1 - row2) + abs(col1 - col2);
}

// Function to find the lowest f cost node in the open list
int lowest_f_cost(Node *open_list[], int open_list_size) {
  int lowest_index = 0;

  for (int i = 1; i < open_list_size; i++) {
    if (open_list[i]->f < open_list[lowest_index]->f) {
      lowest_index = i;
    }
  }

  return lowest_index;
}

// Function to check if the given row and column are within the grid
bool is_valid(int row, int col) {
  return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

// Function to check if the given node is the goal node
bool is_goal(Node *node, int goal_row, int goal_col) {
  return node->row == goal_row && node->col == goal_col;
}

// Main function for A* Pathfinding Algorithm
Node* a_star(int start_row, int start_col, int goal_row, int goal_col) {
  // Initialize the start and goal nodes
  Node *start = (Node*) malloc(sizeof(Node));
  start->row = start_row;
  start->col = start_col;
  start->f = 0;
  start->g = 0;
  start->h = manhattan_distance(start_row, start_col, goal_row, goal_col);
  start->parent = NULL;

  Node *goal = (Node*) malloc(sizeof(Node));
  goal->row = goal_row;
  goal->col = goal_col;
  goal->f = 0;
  goal->g = 0;
  goal->h = 0;
  goal->parent = NULL;

  // Initialize the open and closed lists
  Node *open_list[ROWS*COLS] = {start};
  int open_list_size = 1;

  Node *closed_list[ROWS*COLS] = {NULL};
  int closed_list_size = 0;

  while (open_list_size > 0) {
    // Find the node with the lowest f cost in the open list
    int current_index = lowest_f_cost(open_list, open_list_size);
    Node *current = open_list[current_index];

    // Check if the current node is the goal
    if (is_goal(current, goal_row, goal_col)) {
      return current;
    }

    // Move the current node from the open to the closed list
    open_list[current_index] = open_list[open_list_size - 1];
    open_list_size--;

    closed_list[closed_list_size] = current;
    closed_list_size++;

    // Generate the adjacent nodes
    Node *neighbors[8];
    int num_neighbors = 0;

    for (int row = current->row - 1; row <= current->row + 1; row++) {
      for (int col = current->col - 1; col <= current->col + 1; col++) {
        // Don't generate a neighbor for the current node
        if (row == current->row && col == current->col) {
          continue;
        }

        // Check if the neighbor is within the grid
        if (is_valid(row, col)) {
          // Don't generate a neighbor for an obstacle in the map
          if (map[row][col] != '.') {
            continue;
          }

          // Create the neighbor node
          Node *neighbor = (Node*) malloc(sizeof(Node));
          neighbor->row = row;
          neighbor->col = col;
          neighbor->parent = current;

          // Calculate the g, h, and f costs for the neighbor node
          neighbor->g = current->g + 1;
          neighbor->h = manhattan_distance(row, col, goal_row, goal_col);
          neighbor->f = neighbor->g + neighbor->h;

          // Add the neighbor to the list of neighbors
          neighbors[num_neighbors] = neighbor;
          num_neighbors++;
        }
      }
    }

    // Check each neighbor in the list of neighbors
    for (int i = 0; i < num_neighbors; i++) {
      Node *neighbor = neighbors[i];

      // Check if the neighbor is in the closed list
      bool is_in_closed_list = false;
      for (int j = 0; j < closed_list_size; j++) {
        if (neighbor->row == closed_list[j]->row && neighbor->col == closed_list[j]->col) {
          is_in_closed_list = true;
          break;
        }
      }
      if (is_in_closed_list) {
        continue;
      }

      // Calculate the tentative g score for this neighbor
      int tentative_g_score = current->g + 1;

      // Check if the neighbor is already in the open list
      bool is_in_open_list = false;
      for (int j = 0; j < open_list_size; j++) {
        if (neighbor->row == open_list[j]->row && neighbor->col == open_list[j]->col) {
          is_in_open_list = true;
          break;
        }
      }

      // Add the neighbor to the open list if it's not already there
      if (!is_in_open_list) {
        open_list[open_list_size] = neighbor;
        open_list_size++;
      } else if (tentative_g_score >= neighbor->g) {
        // This is not a better path
        continue;
      }

      // Set the parent and g score of the neighbor to the current node and tentative g score
      neighbor->parent = current;
      neighbor->g = tentative_g_score;

      // Calculate the f score of the neighbor and update it in the list
      neighbor->f = neighbor->g + neighbor->h;

    }
  }

  // Return NULL if no path was found
  return NULL;
}

// Function to print the found path on the map
void print_path(Node *node) {
  if (node->parent != NULL) {
    print_path(node->parent);
  }

  printf("(%d,%d) ", node->row, node->col);
}

int main() {
  // Define the start and goal coordinates
  int start_row = 0;
  int start_col = 0;
  int goal_row = ROWS - 1;
  int goal_col = COLS - 1;

  Node *result = a_star(start_row, start_col, goal_row, goal_col);

  if (result != NULL) {
    printf("Path found: ");
    print_path(result);
    printf("\n");
  } else {
    printf("No path found.\n");
  }

  return 0;
}
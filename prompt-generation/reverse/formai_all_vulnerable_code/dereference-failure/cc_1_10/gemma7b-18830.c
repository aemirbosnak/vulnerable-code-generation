//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_WIDTH 5
#define MAZE_HEIGHT 5
#define MAZE_START_X 2
#define MAZE_START_Y 2
#define MAZE_GOAL_X 3
#define MAZE_GOAL_Y 3

#define EMPTY_SPACE '.'
#define WALL 'W'
#define PATH 'P'

typedef struct Node {
  int x, y;
  struct Node* next;
} Node;

Node* createNode(int x, int y) {
  Node* node = malloc(sizeof(struct Node));
  node->x = x;
  node->y = y;
  node->next = NULL;
  return node;
}

int main() {
  // Create the maze
  char maze[MAZE_HEIGHT][MAZE_WIDTH] = {
    {WALL, WALL, EMPTY_SPACE, WALL, WALL},
    {WALL, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, WALL},
    {WALL, EMPTY_SPACE, PATH, EMPTY_SPACE, WALL},
    {WALL, EMPTY_SPACE, EMPTY_SPACE, EMPTY_SPACE, WALL},
    {WALL, WALL, EMPTY_SPACE, WALL, WALL}
  };

  // Initialize the start and goal positions
  int start_x = MAZE_START_X;
  int start_y = MAZE_START_Y;
  int goal_x = MAZE_GOAL_X;
  int goal_y = MAZE_GOAL_Y;

  // Create the linked list of nodes
  Node* head = createNode(start_x, start_y);

  // Traverse the maze
  while (head) {
    // Check if the node is the goal
    if (head->x == goal_x && head->y == goal_y) {
      printf("You have reached the goal!\n");
      break;
    }

    // Move in a random direction
    int direction = rand() % 4;

    // North
    if (direction == 0 && maze[head->y - 1][head->x] != WALL) {
      head->next = createNode(head->x, head->y - 1);
      head = head->next;
    }

    // South
    else if (direction == 1 && maze[head->y + 1][head->x] != WALL) {
      head->next = createNode(head->x, head->y + 1);
      head = head->next;
    }

    // East
    else if (direction == 2 && maze[head->y][head->x + 1] != WALL) {
      head->next = createNode(head->x + 1, head->y);
      head = head->next;
    }

    // West
    else if (direction == 3 && maze[head->y][head->x - 1] != WALL) {
      head->next = createNode(head->x - 1, head->y);
      head = head->next;
    }
  }

  // If the goal is not reached, print an error message
  if (head == NULL) {
    printf("You have reached a dead end.\n");
  }

  return 0;
}
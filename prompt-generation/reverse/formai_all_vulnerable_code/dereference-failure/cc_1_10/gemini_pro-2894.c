//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

char maze[MAZE_SIZE][MAZE_SIZE] = {
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 0, 1},
  {1, 0, 1, 0, 1, 0, 1, 0, 1, 1},
  {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
  {1, 0, 1, 1, 1, 1, 1, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

struct point {
  int x;
  int y;
};

struct stack {
  struct point *points;
  int top;
  int size;
};

struct stack *stack_create(int size) {
  struct stack *stack = malloc(sizeof(struct stack));
  stack->points = malloc(sizeof(struct point) * size);
  stack->top = -1;
  stack->size = size;
  return stack;
}

void stack_push(struct stack *stack, struct point point) {
  if (stack->top == stack->size - 1) {
    printf("Error: Stack is full.\n");
    return;
  }
  stack->points[++stack->top] = point;
}

struct point stack_pop(struct stack *stack) {
  if (stack->top == -1) {
    printf("Error: Stack is empty.\n");
    return (struct point) {-1, -1};
  }
  return stack->points[stack->top--];
}

int is_valid_move(int x, int y) {
  if (x < 0 || x >= MAZE_SIZE || y < 0 || y >= MAZE_SIZE) {
    return 0;
  }
  return maze[x][y] == 0;
}

int find_path(int start_x, int start_y, int end_x, int end_y) {
  struct stack *stack = stack_create(MAZE_SIZE * MAZE_SIZE);
  struct point start_point = {start_x, start_y};
  stack_push(stack, start_point);

  while (stack->top != -1) {
    struct point current_point = stack_pop(stack);

    if (current_point.x == end_x && current_point.y == end_y) {
      return 1;
    }

    if (is_valid_move(current_point.x + 1, current_point.y)) {
      struct point next_point = {current_point.x + 1, current_point.y};
      stack_push(stack, next_point);
    }

    if (is_valid_move(current_point.x - 1, current_point.y)) {
      struct point next_point = {current_point.x - 1, current_point.y};
      stack_push(stack, next_point);
    }

    if (is_valid_move(current_point.x, current_point.y + 1)) {
      struct point next_point = {current_point.x, current_point.y + 1};
      stack_push(stack, next_point);
    }

    if (is_valid_move(current_point.x, current_point.y - 1)) {
      struct point next_point = {current_point.x, current_point.y - 1};
      stack_push(stack, next_point);
    }
  }

  return 0;
}

int main() {
  if (find_path(START_X, START_Y, END_X, END_Y)) {
    printf("Path found!\n");
  } else {
    printf("No path found.\n");
  }

  return 0;
}
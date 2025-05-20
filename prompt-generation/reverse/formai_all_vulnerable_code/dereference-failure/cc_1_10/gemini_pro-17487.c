//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The maze is represented as a 2D array of characters.
char maze[10][10] = {
  { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '#', '#', '#', '#', '#', '#', '.', '#' },
  { '#', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
  { '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '#', '#', '#', '#', '#', '#', '#', '.', '#' },
  { '#', '.', '.', '.', '.', '.', '.', '.', '.', '#' },
  { '#', '.', '#', '#', '#', '#', '#', '#', '.', '#' },
  { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' }
};

// The player's position is represented as a structure with two members: x and y.
typedef struct {
  int x;
  int y;
} Player;

// The stack is used to store the player's previous positions.
typedef struct {
  Player* items[100];
  int top;
} Stack;

// Create a new stack.
Stack* create_stack() {
  Stack* stack = malloc(sizeof(Stack));
  stack->top = 0;
  return stack;
}

// Push an item onto the stack.
void push(Stack* stack, Player* player) {
  stack->items[stack->top++] = player;
}

// Pop an item from the stack.
Player* pop(Stack* stack) {
  return stack->items[--stack->top];
}

// Check if the stack is empty.
int is_empty(Stack* stack) {
  return stack->top == 0;
}

// Create a new player.
Player* create_player(int x, int y) {
  Player* player = malloc(sizeof(Player));
  player->x = x;
  player->y = y;
  return player;
}

// Check if the player is at the exit of the maze.
int is_exit(Player* player) {
  return player->x == 9 && player->y == 9;
}

// Check if the player can move in a given direction.
int can_move(Player* player, int dx, int dy) {
  return maze[player->x + dx][player->y + dy] == '.' || maze[player->x + dx][player->y + dy] == 'E';
}

// Move the player in a given direction.
void move(Player* player, int dx, int dy) {
  player->x += dx;
  player->y += dy;
}

// Find a solution to the maze using a depth-first search.
Player* find_solution(Player* player) {
  // Create a stack to store the player's previous positions.
  Stack* stack = create_stack();

  // Push the player's initial position onto the stack.
  push(stack, player);

  // While the stack is not empty,
  while (!is_empty(stack)) {
    // Pop the player's current position from the stack.
    player = pop(stack);

    // If the player is at the exit of the maze,
    if (is_exit(player)) {
      // Return the player's current position.
      return player;
    }

    // Try to move the player in each of the four directions.
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        // If the player can move in the given direction,
        if (can_move(player, dx, dy)) {
          // Move the player in the given direction.
          move(player, dx, dy);

          // Push the player's new position onto the stack.
          push(stack, player);
        }
      }
    }
  }

  // If the stack is empty, then there is no solution to the maze.
  return NULL;
}

// Print the maze.
void print_maze(Player* player) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (player->x == i && player->y == j) {
        printf("O");
      } else {
        printf("%c", maze[i][j]);
      }
    }
    printf("\n");
  }
}

// Main function.
int main() {
  // Create a new player.
  Player* player = create_player(1, 1);

  // Find a solution to the maze.
  Player* solution = find_solution(player);

  // If a solution was found,
  if (solution) {
    // Print the solution.
    print_maze(solution);
  } else {
    // Otherwise, print a message indicating that there is no solution.
    printf("No solution found.\n");
  }

  return 0;
}
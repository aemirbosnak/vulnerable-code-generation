//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define ROBOT_START_X 0
#define ROBOT_START_Y 0

// The robot's current position
int robot_x = ROBOT_START_X;
int robot_y = ROBOT_START_Y;

// The board
char board[BOARD_SIZE][BOARD_SIZE];

// The robot's movement instructions
char* instructions;

// The robot's movement function
void move_robot(char instruction) {
  switch (instruction) {
    case 'N':
      robot_y--;
      break;
    case 'S':
      robot_y++;
      break;
    case 'E':
      robot_x++;
      break;
    case 'W':
      robot_x--;
      break;
  }
}

// The robot's main function
int main() {
  // Initialize the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = '.';
    }
  }

  // Set the robot's starting position
  board[robot_x][robot_y] = 'R';

  // Get the robot's movement instructions
  printf("Enter the robot's movement instructions: ");
  scanf("%s", instructions);

  // Move the robot
  for (int i = 0; i < strlen(instructions); i++) {
    move_robot(instructions[i]);
  }

  // Print the board
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }

  return 0;
}
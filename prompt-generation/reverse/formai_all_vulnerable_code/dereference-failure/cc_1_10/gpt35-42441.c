//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

/*Defining constants and variables*/
#define LENGTH 5
#define WIDTH 5
#define MAX_BATTERY_LEVEL 100
#define MOVE_COST 5
#define TURN_COST 3

int battery_level = MAX_BATTERY_LEVEL;
int current_row_position = 0;
int current_column_position = 0;
int target_row_position;
int target_column_position;
int distance_to_target;
int path_length = 0;
char direction = 'N';

/*Function to display grid*/
void display_grid(char grid[LENGTH][WIDTH]) {
  printf("\nCurrent Grid:\n");
  for(int i=0; i<LENGTH; i++) {
    for(int j=0; j<WIDTH; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("\n");
  }
}

/*Function to move the vehicle*/
void move(char grid[LENGTH][WIDTH]) {
  if(distance_to_target == 0) {
    printf("\nVehicle has reached the target position!\n");
    exit(0);
  }
  if(distance_to_target > 0 && battery_level >= MOVE_COST) {
    printf("\nVehicle is moving...\n");
    switch(direction) {
      case 'N':
        current_row_position--;
        break;
      case 'S':
        current_row_position++;
        break;
      case 'E':
        current_column_position++;
        break;
      case 'W':
        current_column_position--;
        break;
    }
    path_length++;
    battery_level -= MOVE_COST;
    distance_to_target--;
    grid[current_row_position][current_column_position] = 'V';
    display_grid(grid);
  } else {
    printf("\nVehicle cannot move due to low battery level. Please charge the vehicle or change target position.\n");
    exit(0);
  }
}

/*Function to turn the vehicle*/
void turn_left() {
  if(battery_level >= TURN_COST) {
    printf("\nVehicle is turning left...\n");
    switch(direction) {
      case 'N':
        direction = 'W';
        break;
      case 'S':
        direction = 'E';
        break;
      case 'E':
        direction = 'N';
        break;
      case 'W':
        direction = 'S';
        break;
    }
    battery_level -= TURN_COST;
  } else {
    printf("\nVehicle cannot turn due to low battery level. Please charge the vehicle or change target position.\n");
    exit(0);
  }
}

/*Function to charge the vehicle*/
void charge_vehicle() {
  printf("\nVehicle is charging...\n");
  battery_level = MAX_BATTERY_LEVEL;
  printf("\nVehicle is fully charged now.\n");
}

int main() {
  char grid[LENGTH][WIDTH] = {
    {'V', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.'}
  };
  display_grid(grid);
  printf("\nEnter target position row number (0-4): ");
  scanf("%d", &target_row_position);
  printf("Enter target position column number (0-4): ");
  scanf("%d", &target_column_position);
  distance_to_target = abs(target_row_position-current_row_position) + abs(target_column_position-current_column_position);
  while(distance_to_target > 0 && battery_level >= MOVE_COST) {
    printf("\nDistance to target: %d\nBattery level: %d\nPath length: %d\nDirection facing: %c\n", distance_to_target, battery_level, path_length, direction);
    printf("\nEnter move option (m for move, l for turn left, c for charge): ");
    char move_option;
    scanf(" %c", &move_option);
    switch(move_option) {
      case 'm':
        move(grid);
        break;
      case 'l':
        turn_left();
        break;
      case 'c':
        charge_vehicle();
        break;
      default:
        printf("\nInvalid option entered. Please enter valid option.\n");
        break;
    }
  }
  printf("\nVehicle has stopped due to low battery or target reached.\n");
  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROBOT_X_MAX 1000
#define ROBOT_Y_MAX 1000

typedef struct {
  int x;
  int y;
  int facing;  // 0 = north, 1 = east, 2 = south, 3 = west
} robot;

robot *create_robot(int x, int y, int facing) {
  robot *new_robot = malloc(sizeof(robot));
  new_robot->x = x;
  new_robot->y = y;
  new_robot->facing = facing;
  return new_robot;
}

void destroy_robot(robot *r) {
  free(r);
}

void move_robot(robot *r, int direction, int distance) {
  switch (direction) {
    case 0:  // north
      r->y += distance;
      break;
    case 1:  // east
      r->x += distance;
      break;
    case 2:  // south
      r->y -= distance;
      break;
    case 3:  // west
      r->x -= distance;
      break;
  }
}

void turn_robot(robot *r, int direction) {
  r->facing = (r->facing + direction + 4) % 4;
}

int main() {
  srand(time(NULL));

  // Create a robot
  robot *r = create_robot(ROBOT_X_MAX / 2, ROBOT_Y_MAX / 2, 0);

  // Move the robot around randomly
  for (int i = 0; i < 1000; i++) {
    int direction = rand() % 4;
    int distance = rand() % 100;
    move_robot(r, direction, distance);
  }

  // Print the robot's final position
  printf("The robot is at (%d, %d)\n", r->x, r->y);

  // Destroy the robot
  destroy_robot(r);

  return 0;
}
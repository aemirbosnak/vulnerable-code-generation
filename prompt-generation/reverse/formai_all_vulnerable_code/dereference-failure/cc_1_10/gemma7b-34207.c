//Gemma-7B DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROBOTS 10

typedef struct Robot {
  int x;
  int y;
  int direction;
  char name[20];
} Robot;

void moveRobot(Robot *robot) {
  switch (robot->direction) {
    case 0:
      robot->x++;
      break;
    case 1:
      robot->y++;
      break;
    case 2:
      robot->x--;
      break;
    case 3:
      robot->y--;
      break;
  }
}

int main() {
  int numRobots = 5;
  Robot *robots = (Robot *)malloc(numRobots * sizeof(Robot));

  for (int i = 0; i < numRobots; i++) {
    robots[i].x = rand() % 10;
    robots[i].y = rand() % 10;
    robots[i].direction = rand() % 4;
    robots[i].name[0] = 'R' + i;
  }

  time_t start = time(NULL);
  int timeLimit = 60;

  while (time(NULL) - start < timeLimit) {
    for (int i = 0; i < numRobots; i++) {
      moveRobot(&robots[i]);
    }

    sleep(1);
  }

  free(robots);

  return 0;
}
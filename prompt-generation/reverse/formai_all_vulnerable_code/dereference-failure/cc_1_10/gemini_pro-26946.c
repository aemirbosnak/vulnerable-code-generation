//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPEED_MAX 100
#define SPEED_MIN 0
#define DIRECTION_MAX 360
#define DIRECTION_MIN 0

typedef struct {
  int speed;
  int direction;
} remote_control_car;

void print_car_status(remote_control_car car) {
  printf("Speed: %d\n", car.speed);
  printf("Direction: %d\n", car.direction);
}

int main() {
  remote_control_car car = {0, 0};

  while (1) {
    char command[100];
    printf("Enter command (speed direction): ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    }

    int speed = atoi(strtok(command, " "));
    int direction = atoi(strtok(NULL, " "));

    if (speed < SPEED_MIN || speed > SPEED_MAX) {
      printf("Invalid speed: %d\n", speed);
      continue;
    }

    if (direction < DIRECTION_MIN || direction > DIRECTION_MAX) {
      printf("Invalid direction: %d\n", direction);
      continue;
    }

    car.speed = speed;
    car.direction = direction;

    printf("Car status:\n");
    print_car_status(car);
  }

  printf("Goodbye!\n");
  return 0;
}
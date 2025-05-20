//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 100
#define MAX_TURN_RADIUS 50

typedef struct {
  int speed;
  int turn_radius;
  int direction;
} Car;

void init_car(Car *car) {
  car->speed = 0;
  car->turn_radius = 0;
  car->direction = 0;
}

void accelerate(Car *car, int amount) {
  car->speed += amount;
  if (car->speed > MAX_SPEED) {
    car->speed = MAX_SPEED;
  }
}

void decelerate(Car *car, int amount) {
  car->speed -= amount;
  if (car->speed < 0) {
    car->speed = 0;
  }
}

void turn_left(Car *car, int amount) {
  car->turn_radius -= amount;
  if (car->turn_radius < -MAX_TURN_RADIUS) {
    car->turn_radius = -MAX_TURN_RADIUS;
  }
}

void turn_right(Car *car, int amount) {
  car->turn_radius += amount;
  if (car->turn_radius > MAX_TURN_RADIUS) {
    car->turn_radius = MAX_TURN_RADIUS;
  }
}

void update_car(Car *car) {
  // Update the car's position based on its speed and turn radius.
  car->direction += car->turn_radius;
  car->direction %= 360;
}

void print_car(Car *car) {
  printf("Car speed: %d\n", car->speed);
  printf("Car turn radius: %d\n", car->turn_radius);
  printf("Car direction: %d\n", car->direction);
}

int main() {
  // Create a new car.
  Car car;
  init_car(&car);

  // Simulate the car driving around a track.
  while (1) {
    // Get input from the user.
    char input[100];
    fgets(input, 100, stdin);

    // Parse the input.
    char *command = strtok(input, " ");
    int amount = atoi(strtok(NULL, " "));

    // Execute the command.
    if (strcmp(command, "accelerate") == 0) {
      accelerate(&car, amount);
    } else if (strcmp(command, "decelerate") == 0) {
      decelerate(&car, amount);
    } else if (strcmp(command, "turn_left") == 0) {
      turn_left(&car, amount);
    } else if (strcmp(command, "turn_right") == 0) {
      turn_right(&car, amount);
    } else if (strcmp(command, "print") == 0) {
      print_car(&car);
    } else if (strcmp(command, "quit") == 0) {
      break;
    }

    // Update the car's position.
    update_car(&car);
  }

  return 0;
}
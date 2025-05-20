//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Get the number of cars from the user
int get_num_cars() {
  int num_cars;
  printf("How many cars do you want to simulate? ");
  scanf("%d", &num_cars);
  return num_cars;
}

// Create the cars
struct car {
  int id;
  int speed;
  int lane;
  int position;
};

struct car *create_cars(int num_cars) {
  struct car *cars = malloc(sizeof(struct car) * num_cars);
  for (int i = 0; i < num_cars; i++) {
    cars[i].id = i;
    cars[i].speed = rand() % 100;
    cars[i].lane = rand() % 3;
    cars[i].position = rand() % 1000;
  }
  return cars;
}

// Update the state of the cars
void update_cars(struct car *cars, int num_cars) {
  for (int i = 0; i < num_cars; i++) {
    // Update the speed of the car
    cars[i].speed += (rand() % 10) - 5;
    if (cars[i].speed < 0) {
      cars[i].speed = 0;
    }
    if (cars[i].speed > 100) {
      cars[i].speed = 100;
    }

    // Update the lane of the car
    cars[i].lane += (rand() % 3) - 1;
    if (cars[i].lane < 0) {
      cars[i].lane = 0;
    }
    if (cars[i].lane > 2) {
      cars[i].lane = 2;
    }

    // Update the position of the car
    cars[i].position += cars[i].speed;
    if (cars[i].position < 0) {
      cars[i].position = 0;
    }
    if (cars[i].position > 1000) {
      cars[i].position = 1000;
    }
  }
}

// Draw the cars on the screen
void draw_cars(struct car *cars, int num_cars) {
  for (int i = 0; i < num_cars; i++) {
    printf("[Car %d] Speed: %d, Lane: %d, Position: %d\n", cars[i].id, cars[i].speed, cars[i].lane, cars[i].position);
  }
}

// Main function
int main() {
  // Get the number of cars from the user
  int num_cars = get_num_cars();

  // Create the cars
  struct car *cars = create_cars(num_cars);

  // Update the state of the cars
  update_cars(cars, num_cars);

  // Draw the cars on the screen
  draw_cars(cars, num_cars);

  return 0;
}
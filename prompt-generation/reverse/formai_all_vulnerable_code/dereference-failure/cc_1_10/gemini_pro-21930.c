//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CARS 100
#define MAX_ROAD_LENGTH 100

// A car has a position, a speed, and a direction.
struct car {
  int position;
  int speed;
  int direction;
};

// The road is a 1D array of cells, each of which can contain a car.
struct road {
  struct car *cells[MAX_ROAD_LENGTH];
};

// Create a new road.
struct road *create_road() {
  struct road *road = malloc(sizeof(struct road));
  for (int i = 0; i < MAX_ROAD_LENGTH; i++) {
    road->cells[i] = NULL;
  }
  return road;
}

// Free the memory allocated for a road.
void free_road(struct road *road) {
  for (int i = 0; i < MAX_ROAD_LENGTH; i++) {
    free(road->cells[i]);
  }
  free(road);
}

// Create a new car.
struct car *create_car(int position, int speed, int direction) {
  struct car *car = malloc(sizeof(struct car));
  car->position = position;
  car->speed = speed;
  car->direction = direction;
  return car;
}

// Free the memory allocated for a car.
void free_car(struct car *car) {
  free(car);
}

// Add a car to the road.
void add_car_to_road(struct road *road, struct car *car) {
  road->cells[car->position] = car;
}

// Remove a car from the road.
void remove_car_from_road(struct road *road, struct car *car) {
  road->cells[car->position] = NULL;
}

// Move a car forward one cell.
void move_car_forward(struct road *road, struct car *car) {
  car->position += car->direction * car->speed;
  if (car->position < 0) {
    car->position = MAX_ROAD_LENGTH - 1;
  } else if (car->position >= MAX_ROAD_LENGTH) {
    car->position = 0;
  }
}

// Update the positions of all the cars on the road.
void update_road(struct road *road) {
  for (int i = 0; i < MAX_CARS; i++) {
    struct car *car = road->cells[i];
    if (car != NULL) {
      move_car_forward(road, car);
    }
  }
}

// Print the road to the terminal.
void print_road(struct road *road) {
  for (int i = 0; i < MAX_ROAD_LENGTH; i++) {
    struct car *car = road->cells[i];
    if (car != NULL) {
      printf("%d ", car->position);
    } else {
      printf("- ");
    }
  }
  printf("\n");
}

int main() {
  // Create a new road.
  struct road *road = create_road();

  // Add some cars to the road.
  for (int i = 0; i < MAX_CARS; i++) {
    struct car *car = create_car(rand() % MAX_ROAD_LENGTH, rand() % 10, rand() % 2);
    add_car_to_road(road, car);
  }

  // Update the road for a number of iterations.
  for (int i = 0; i < 1000; i++) {
    update_road(road);
    print_road(road);
  }

  // Free the memory allocated for the road and the cars.
  free_road(road);
  return 0;
}
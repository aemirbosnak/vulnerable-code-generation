//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ROAD_SIZE 100
#define CAR_SIZE 5
#define MAX_SPEED 10
#define MIN_SPEED 1

typedef struct car {
  int speed;
  int position;
  char *name;
} car;

car *create_car(char *name) {
  car *new_car = malloc(sizeof(car));
  new_car->speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
  new_car->position = rand() % ROAD_SIZE;
  new_car->name = strdup(name);
  return new_car;
}

void destroy_car(car *car) {
  free(car->name);
  free(car);
}

void move_car(car *car) {
  car->position += car->speed;
  if (car->position >= ROAD_SIZE) {
    car->position -= ROAD_SIZE;
  }
}

void print_road(car **cars, int num_cars) {
  for (int i = 0; i < ROAD_SIZE; i++) {
    int found_car = 0;
    for (int j = 0; j < num_cars; j++) {
      if (cars[j]->position == i) {
        printf("%s ", cars[j]->name);
        found_car = 1;
        break;
      }
    }
    if (!found_car) {
      printf("  ");
    }
  }
  printf("\n");
}

int main() {
  srand(time(NULL));

  int num_cars = 10;
  car **cars = malloc(sizeof(car *) * num_cars);
  for (int i = 0; i < num_cars; i++) {
    char name[10];
    sprintf(name, "Car %d", i);
    cars[i] = create_car(name);
  }

  while (1) {
    system("clear");
    printf("Peaceful Traffic Flow Simulation\n");
    print_road(cars, num_cars);
    for (int i = 0; i < num_cars; i++) {
      move_car(cars[i]);
    }
    usleep(100000);
  }

  for (int i = 0; i < num_cars; i++) {
    destroy_car(cars[i]);
  }
  free(cars);

  return 0;
}
//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 10

typedef struct Car {
  int x, y;
  int dir;
  int speed;
} Car;

void update_cars(Car *cars, int num_cars) {
  for (int i = 0; i < num_cars; i++) {
    switch (cars[i].dir) {
      case 0:
        cars[i].x++;
        break;
      case 1:
        cars[i].y++;
        break;
      case 2:
        cars[i].x--;
        break;
      case 3:
        cars[i].y--;
        break;
    }

    if (cars[i].x < 0 || cars[i].x >= 10) {
      cars[i].dir = (cars[i].dir + 1) % 4;
    }

    if (cars[i].y < 0 || cars[i].y >= 10) {
      cars[i].dir = (cars[i].dir + 1) % 4;
    }
  }
}

void draw_road(int x, int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (i == 0 || i == x - 1) {
        printf("%c", '-');
      } else if (j == 0 || j == y - 1) {
        printf("%c", '|');
      } else {
        printf("%c", '.');
      }
    }

    printf("\n");
  }
}

int main() {
  srand(time(NULL));

  int num_cars = rand() % MAX_CARS;
  Car *cars = malloc(num_cars * sizeof(Car));

  for (int i = 0; i < num_cars; i++) {
    cars[i].x = rand() % 10;
    cars[i].y = rand() % 10;
    cars[i].dir = rand() % 4;
    cars[i].speed = rand() % 5;
  }

  update_cars(cars, num_cars);
  draw_road(11, 11);

  for (int i = 0; i < num_cars; i++) {
    printf("Car %d: (%d, %d), Direction: %d, Speed: %d\n", i + 1, cars[i].x, cars[i].y, cars[i].dir, cars[i].speed);
  }

  free(cars);

  return 0;
}
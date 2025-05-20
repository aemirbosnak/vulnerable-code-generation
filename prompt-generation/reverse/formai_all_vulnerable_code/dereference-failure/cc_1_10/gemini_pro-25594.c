//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_INTERSECTIONS 5
#define NUM_VEHICLES 20
#define MAX_SPEED 10
#define MIN_SPEED 5

typedef struct {
  int x, y;
} Point;

typedef struct {
  Point pos;
  int speed;
  bool is_stopped;
} Vehicle;

typedef struct {
  int num_vehicles;
  Vehicle* vehicles;
} Intersection;

Intersection* intersections[NUM_INTERSECTIONS];

void init_intersections() {
  for (int i = 0; i < NUM_INTERSECTIONS; i++) {
    intersections[i] = malloc(sizeof(Intersection));
    intersections[i]->num_vehicles = 0;
    intersections[i]->vehicles = malloc(sizeof(Vehicle) * NUM_VEHICLES);
  }
}

void init_vehicles() {
  for (int i = 0; i < NUM_VEHICLES; i++) {
    Vehicle* vehicle = &intersections[i]->vehicles[i];
    vehicle->pos.x = rand() % 100;
    vehicle->pos.y = rand() % 100;
    vehicle->speed = rand() % (MAX_SPEED - MIN_SPEED) + MIN_SPEED;
    vehicle->is_stopped = false;
  }
}

void update_vehicles() {
  for (int i = 0; i < NUM_INTERSECTIONS; i++) {
    for (int j = 0; j < intersections[i]->num_vehicles; j++) {
      Vehicle* vehicle = &intersections[i]->vehicles[j];
      if (!vehicle->is_stopped) {
        vehicle->pos.x += vehicle->speed;
        vehicle->pos.y += vehicle->speed;
        if (vehicle->pos.x < 0 || vehicle->pos.x > 100 || vehicle->pos.y < 0 || vehicle->pos.y > 100) {
          vehicle->is_stopped = true;
        }
      }
    }
  }
}

void check_collisions() {
  for (int i = 0; i < NUM_INTERSECTIONS; i++) {
    for (int j = 0; j < intersections[i]->num_vehicles; j++) {
      Vehicle* vehicle1 = &intersections[i]->vehicles[j];
      for (int k = j + 1; k < intersections[i]->num_vehicles; k++) {
        Vehicle* vehicle2 = &intersections[i]->vehicles[k];
        if (vehicle1->is_stopped && vehicle2->is_stopped) {
          continue;
        }
        if (vehicle1->pos.x == vehicle2->pos.x && vehicle1->pos.y == vehicle2->pos.y) {
          vehicle1->is_stopped = true;
          vehicle2->is_stopped = true;
        }
      }
    }
  }
}

void print_intersections() {
  for (int i = 0; i < NUM_INTERSECTIONS; i++) {
    printf("Intersection %d:\n", i);
    for (int j = 0; j < intersections[i]->num_vehicles; j++) {
      Vehicle* vehicle = &intersections[i]->vehicles[j];
      printf("  Vehicle %d: (%d, %d)\n", j, vehicle->pos.x, vehicle->pos.y);
    }
  }
}

int main() {
  srand(time(NULL));
  init_intersections();
  init_vehicles();
  for (int i = 0; i < 1000; i++) {
    update_vehicles();
    check_collisions();
    print_intersections();
  }
  return 0;
}
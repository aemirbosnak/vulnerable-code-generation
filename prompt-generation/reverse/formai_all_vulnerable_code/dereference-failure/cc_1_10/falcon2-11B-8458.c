//Falcon2-11B DATASET v1.0 Category: Elevator Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for passenger
typedef struct Passenger {
  int floor;
  char name[50];
} Passenger;

// Structure for floors
typedef struct Floors {
  int num;
  int max_capacity;
  int passengers;
  Passenger* passengers_array;
} Floors;

// Function to move passenger
void move_passenger(Floors* floor) {
  int random_floor = rand() % floor->num + 1;
  Passenger* passenger = malloc(sizeof(Passenger));
  printf("Passenger %s wants to go to floor %d\n", floor->passengers_array[floor->passengers - 1].name, random_floor);
  floor->passengers += 1;
  floor->passengers_array[floor->passengers - 1].floor = random_floor;
  printf("Passenger %s is on floor %d\n", floor->passengers_array[floor->passengers - 1].name, random_floor);
}

// Function to print the elevator status
void print_status(Floors* floor) {
  int i;
  printf("Current floor: %d\n", floor->num);
  for(i = 0; i < floor->passengers; i++) {
    printf("Passenger %s is on floor %d\n", floor->passengers_array[i].name, floor->passengers_array[i].floor);
  }
  printf("Passenger count: %d\n", floor->passengers);
}

// Function to initialize elevator
void init_elevator(Floors* floor) {
  floor->num = 3;
  floor->max_capacity = 5;
  floor->passengers = 0;
  floor->passengers_array = malloc(floor->max_capacity * sizeof(Passenger));
  for(int i = 0; i < floor->max_capacity; i++) {
    Passenger* p = malloc(sizeof(Passenger));
    p->floor = i + 1;
    strcpy(p->name, "Passenger ");
    strcat(p->name, " ");
    strcat(p->name, "on floor ");
    strcat(p->name, (i + 1));
    strcat(p->name, " ");
    strcat(p->name, "is waiting");
    floor->passengers_array[i] = *p;
  }
}

// Function to simulate elevator
void simulate_elevator(Floors* floor) {
  int num_passengers;
  scanf("%d", &num_passengers);
  for(int i = 0; i < num_passengers; i++) {
    move_passenger(floor);
  }
  print_status(floor);
}

int main() {
  srand(time(NULL));
  Floors elevator = {
    3,
    5,
    0,
    NULL
  };
  init_elevator(&elevator);
  simulate_elevator(&elevator);
  return 0;
}
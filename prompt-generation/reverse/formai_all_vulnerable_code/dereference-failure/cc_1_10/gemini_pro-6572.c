//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

struct Baggage {
  int id;
  int weight;
  char *destination;
};

struct Flight {
  int id;
  char *destination;
  int num_bags;
  struct Baggage *bags[MAX_BAGS];
};

struct Airport {
  struct Flight *flights[MAX_FLIGHTS];
  int num_flights;
};

void initialize_airport(struct Airport *airport) {
  srand(time(NULL));
  for (int i = 0; i < MAX_FLIGHTS; i++) {
    airport->flights[i] = malloc(sizeof(struct Flight));
    airport->flights[i]->id = i;
    airport->flights[i]->destination = malloc(10);
    sprintf(airport->flights[i]->destination, "Flight %d", i);
    airport->flights[i]->num_bags = rand() % MAX_BAGS;
    for (int j = 0; j < airport->flights[i]->num_bags; j++) {
      airport->flights[i]->bags[j] = malloc(sizeof(struct Baggage));
      airport->flights[i]->bags[j]->id = j;
      airport->flights[i]->bags[j]->weight = rand() % 50;
      airport->flights[i]->bags[j]->destination = malloc(10);
      sprintf(airport->flights[i]->bags[j]->destination, "Bag %d", j);
    }
  }
  airport->num_flights = MAX_FLIGHTS;
}

void print_airport(struct Airport *airport) {
  for (int i = 0; i < airport->num_flights; i++) {
    printf("Flight %d: %s\n", airport->flights[i]->id, airport->flights[i]->destination);
    for (int j = 0; j < airport->flights[i]->num_bags; j++) {
      printf("\tBag %d: %s (%d lbs)\n", airport->flights[i]->bags[j]->id, airport->flights[i]->bags[j]->destination, airport->flights[i]->bags[j]->weight);
    }
  }
}

int main() {
  struct Airport airport;
  initialize_airport(&airport);
  print_airport(&airport);
  return 0;
}
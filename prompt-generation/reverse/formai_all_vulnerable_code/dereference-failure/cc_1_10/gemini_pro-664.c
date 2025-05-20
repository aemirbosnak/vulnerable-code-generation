//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

typedef struct {
  int id;
  char *flight_number;
  int num_bags;
  int *bag_ids;
} flight_t;

typedef struct {
  int id;
  char *destination;
  int num_flights;
  flight_t *flights;
} terminal_t;

terminal_t *terminals;
int num_terminals;

void create_terminals(int n) {
  terminals = malloc(sizeof(terminal_t) * n);
  for (int i = 0; i < n; i++) {
    terminals[i].id = i;
    terminals[i].destination = malloc(sizeof(char) * 10);
    sprintf(terminals[i].destination, "Terminal %d", i + 1);
    terminals[i].num_flights = 0;
    terminals[i].flights = NULL;
  }
  num_terminals = n;
}

void create_flights(int n) {
  for (int i = 0; i < num_terminals; i++) {
    terminals[i].flights = malloc(sizeof(flight_t) * n);
    for (int j = 0; j < n; j++) {
      terminals[i].flights[j].id = j;
      terminals[i].flights[j].flight_number = malloc(sizeof(char) * 10);
      sprintf(terminals[i].flights[j].flight_number, "Flight %d", j + 1);
      terminals[i].flights[j].num_bags = 0;
      terminals[i].flights[j].bag_ids = NULL;
    }
    terminals[i].num_flights = n;
  }
}

void create_bags(int n) {
  for (int i = 0; i < num_terminals; i++) {
    for (int j = 0; j < terminals[i].num_flights; j++) {
      terminals[i].flights[j].bag_ids = malloc(sizeof(int) * n);
      for (int k = 0; k < n; k++) {
        terminals[i].flights[j].bag_ids[k] = k;
      }
      terminals[i].flights[j].num_bags = n;
    }
  }
}

void print_terminals() {
  for (int i = 0; i < num_terminals; i++) {
    printf("Terminal %d: %s\n", terminals[i].id, terminals[i].destination);
    for (int j = 0; j < terminals[i].num_flights; j++) {
      printf("  Flight %d: %s\n", terminals[i].flights[j].id, terminals[i].flights[j].flight_number);
      for (int k = 0; k < terminals[i].flights[j].num_bags; k++) {
        printf("    Bag %d: %d\n", k, terminals[i].flights[j].bag_ids[k]);
      }
    }
  }
}

int main() {
  srand(time(NULL));

  int num_terminals = 3;
  int num_flights = 5;
  int num_bags = 10;

  create_terminals(num_terminals);
  create_flights(num_flights);
  create_bags(num_bags);

  print_terminals();

  return 0;
}
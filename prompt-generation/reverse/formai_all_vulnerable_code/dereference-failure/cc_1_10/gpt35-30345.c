//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_BAGS 10
#define MAX_LUGGAGE_WEIGHT 50.0
#define MAX_TRUCK_WEIGHT 1000.0

struct Baggage {
  int id;
  double weight;
};

struct LuggageTruck {
  int num_bags;
  double weight;
};

struct BaggageList {
  int count;
  struct Baggage *bags[NUM_BAGS];
};

void print_baggage(struct Baggage *bag) {
  printf("Bag #%d: %lf kg\n", bag->id, bag->weight);
}

void print_luggage_truck(struct LuggageTruck *truck) {
  printf("Luggage Truck: %d bags, %lf kg\n", truck->num_bags, truck->weight);
}

void print_baggage_list(struct BaggageList *list) {
  printf("Baggage List: %d bags\n", list->count);
  for (int i = 0; i < list->count; ++i) {
    print_baggage(list->bags[i]);
  }
}

double get_total_weight(struct BaggageList *list) {
  double total_weight = 0.0;
  for (int i = 0; i < list->count; ++i) {
    total_weight += list->bags[i]->weight;
  }
  return total_weight;
}

int main() {
  struct BaggageList checked_baggage;
  checked_baggage.count = 0;

  for (int i = 0; i < NUM_BAGS; ++i) {
    struct Baggage *bag = malloc(sizeof(struct Baggage));
    bag->id = i + 1;
    bag->weight = (double) rand() / RAND_MAX * MAX_LUGGAGE_WEIGHT;
    checked_baggage.bags[i] = bag;
    checked_baggage.count++;
  }

  printf("Initial Baggage:\n");
  print_baggage_list(&checked_baggage);

  struct LuggageTruck outgoing_truck;
  outgoing_truck.num_bags = 0;
  outgoing_truck.weight = 0.0;

  while (checked_baggage.count > 0) {
    struct Baggage *bag = checked_baggage.bags[0];
    if (outgoing_truck.num_bags == NUM_BAGS || outgoing_truck.weight + bag->weight > MAX_TRUCK_WEIGHT) {
      print_luggage_truck(&outgoing_truck);
      outgoing_truck.num_bags = 0;
      outgoing_truck.weight = 0.0;
    }
    outgoing_truck.num_bags++;
    outgoing_truck.weight += bag->weight;
    printf("Bag #%d loaded onto Luggage Truck.\n", bag->id);
    for (int i = 1; i < checked_baggage.count; ++i) {
      checked_baggage.bags[i - 1] = checked_baggage.bags[i];
    }
    checked_baggage.count--;
    free(bag);
  }

  if (outgoing_truck.num_bags > 0) {
    print_luggage_truck(&outgoing_truck);
  }

  return 0;
}
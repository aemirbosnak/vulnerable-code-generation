//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BAGS 100
#define MAX_CONVEYORS 10

typedef struct {
  int id;
  int weight;
  int destination;
} Bag;

typedef struct {
  int id;
  int length;
  int speed;
  Bag *bags[MAX_BAGS];
  int num_bags;
} Conveyor;

Conveyor conveyors[MAX_CONVEYORS];
int num_conveyors = 0;

void add_conveyor(int id, int length, int speed) {
  conveyors[num_conveyors].id = id;
  conveyors[num_conveyors].length = length;
  conveyors[num_conveyors].speed = speed;
  conveyors[num_conveyors].num_bags = 0;
  num_conveyors++;
}

void add_bag(int weight, int destination) {
  Bag bag;
  bag.id = rand() % 1000;
  bag.weight = weight;
  bag.destination = destination;

  int i;
  for (i = 0; i < num_conveyors; i++) {
    if (conveyors[i].num_bags < MAX_BAGS) {
      conveyors[i].bags[conveyors[i].num_bags++] = &bag;
      break;
    }
  }
}

void move_bags() {
  int i, j;
  for (i = 0; i < num_conveyors; i++) {
    for (j = 0; j < conveyors[i].num_bags; j++) {
      Bag *bag = conveyors[i].bags[j];
      bag->destination--;
      if (bag->destination == 0) {
        // Bag has reached its destination
        conveyors[i].num_bags--;
        memmove(&conveyors[i].bags[j], &conveyors[i].bags[j + 1], sizeof(Bag *) * (conveyors[i].num_bags - j));
        j--;
      }
    }
  }
}

void print_conveyors() {
  int i, j;
  for (i = 0; i < num_conveyors; i++) {
    printf("Conveyor %d: ", conveyors[i].id);
    for (j = 0; j < conveyors[i].num_bags; j++) {
      Bag *bag = conveyors[i].bags[j];
      printf("(%d, %d, %d) ", bag->id, bag->weight, bag->destination);
    }
    printf("\n");
  }
}

int main() {
  // Initialize the conveyors
  add_conveyor(1, 100, 1);
  add_conveyor(2, 200, 2);
  add_conveyor(3, 300, 3);

  // Add some bags
  add_bag(10, 10);
  add_bag(20, 20);
  add_bag(30, 30);

  // Move the bags
  move_bags();

  // Print the conveyors
  print_conveyors();

  return 0;
}
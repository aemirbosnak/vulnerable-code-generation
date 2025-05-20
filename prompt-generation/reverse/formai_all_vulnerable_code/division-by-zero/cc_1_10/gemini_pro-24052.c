//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define some post-apocalyptic constants
#define RUST_LEVEL 10
#define SCAVENGE_RADIUS 5
#define SALVAGE_CHANCE 0.5

// define some post-apocalyptic functions
int scavenge(int radius);
int salvage(int rust_level);

// main function
int main() {
  // initialize random number generator
  srand(time(NULL));

  // declare variables
  int rust_level;
  int scavenged_items;
  int salvaged_items;

  // get the initial rust level
  rust_level = RUST_LEVEL;

  // scavenge for items
  scavenged_items = scavenge(SCAVENGE_RADIUS);

  // salvage the scavenged items
  salvaged_items = salvage(rust_level);

  // print the results
  printf("You scavenged %d items.\n", scavenged_items);
  printf("You salvaged %d items.\n", salvaged_items);

  return 0;
}

// scavenge for items
int scavenge(int radius) {
  // declare variables
  int items_found;

  // calculate the number of items found
  items_found = rand() % radius;

  // return the number of items found
  return items_found;
}

// salvage the scavenged items
int salvage(int rust_level) {
  // declare variables
  int items_salvaged;

  // calculate the number of items salvaged
  items_salvaged = rand() % (RUST_LEVEL - rust_level);

  // return the number of items salvaged
  return items_salvaged;
}
//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h> // For malloc(), free()

// Our intrepid spaceship
typedef struct {
  void *memoryPool;
  int currentSpace;
  int maxCapacity;
} Spaceship;

// Star Trek-inspired resource allocation
void allocateMemory(Spaceship *ship, int amount) {
  if (ship->currentSpace + amount > ship->maxCapacity) {
    printf("Warp Core Breach! Insufficient RAM allocation: %d bytes requested, %d bytes available.\n", amount, ship->maxCapacity - ship->currentSpace);
    exit(1); // Abandon ship!
  }
  ship->memoryPool = realloc(ship->memoryPool, ship->currentSpace + amount);
  ship->currentSpace += amount;
}

// Phaser fire: Deallocate memory
void deallocateMemory(Spaceship *ship, int amount) {
  if (amount > ship->currentSpace) {
    printf("Phasers set to stun: Invalid deallocation request: %d bytes requested, %d bytes allocated.\n", amount, ship->currentSpace);
  }
  ship->currentSpace -= amount;
  ship->memoryPool = realloc(ship->memoryPool, ship->currentSpace);
}

// Warp to the RAM frontier: Initialize spaceship
Spaceship *launchSpaceship(int capacity) {
  Spaceship *ship = malloc(sizeof(Spaceship));
  ship->memoryPool = malloc(capacity);
  ship->currentSpace = 0;
  ship->maxCapacity = capacity;
  return ship;
}

// Spacewalk: Traverse memory
void memoryCheck(Spaceship *ship) {
  printf("Current RAM allocation: %d / %d bytes\n", ship->currentSpace, ship->maxCapacity);
  for (int i = 0; i < ship->currentSpace; i++) {
    printf("%c", ((char *)ship->memoryPool)[i]);
  }
  printf("\n");
}

int main() {
  // Set sail for the unknown
  Spaceship *ship = launchSpaceship(10000);

  // Allocate some RAM for our intergalactic crew
  allocateMemory(ship, 2000);
  printf("Captain's log: Allocated 2000 bytes of memory.\n");
  memoryCheck(ship);

  // Deallocate RAM as we beam crew members back aboard
  deallocateMemory(ship, 1000);
  printf("First Officer's report: Deallocated 1000 bytes of memory.\n");
  memoryCheck(ship);

  // Oops, we hit an asteroid field!
  allocateMemory(ship, 3000);
  printf("Engineering report: Warp Core Breach! Insufficient RAM allocation.\n");
  memoryCheck(ship); // Memory leak!

  // Time to self-destruct, but first...
  deallocateMemory(ship, 4000);
  printf("Science Officer's report: Deallocated 4000 bytes of memory.\n");
  memoryCheck(ship); // Still a leak...

  // The ship is doomed!
  printf("Sacrifice to the Borg! RAM leak detected.\n");
  exit(1);
}
//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house structure
typedef struct HauntedHouse {
  char name[20];
  int rooms;
  struct HauntedHouse* next;
} HauntedHouse;

// Function to create a haunted house
HauntedHouse* createHauntedHouse(char* name, int rooms) {
  HauntedHouse* house = malloc(sizeof(HauntedHouse));
  strcpy(house->name, name);
  house->rooms = rooms;
  house->next = NULL;
  return house;
}

// Function to add a room to a haunted house
void addRoom(HauntedHouse* house, int rooms) {
  house->rooms += rooms;
}

// Function to simulate a haunted house
void simulateHauntedHouse(HauntedHouse* house) {
  // Randomly select a room in the house
  int room = rand() % house->rooms;

  // Display the room number
  printf("You are in room %d.\n", room);

  // Check if the room is haunted
  if (room % 2 == 0) {
    // Simulate a ghostly presence
    printf("You feel a cold hand brush against your skin.\n");
  }
}

int main() {
  // Create a haunted house
  HauntedHouse* house = createHauntedHouse("The Thorn Mansion", 5);

  // Add rooms to the house
  addRoom(house, 3);
  addRoom(house, 2);
  addRoom(house, 4);

  // Simulate the haunted house
  simulateHauntedHouse(house);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms in the haunted house.
#define MAX_ROOMS 10

// Define the maximum number of exits per room.
#define MAX_EXITS 4

// Define the data structure for a room.
typedef struct room {
  int number;                // The room number.
  int num_exits;             // The number of exits from the room.
  int exits[MAX_EXITS];      // The exit numbers.
  char *description;         // A description of the room.
  struct room *next;          // A pointer to the next room in the list.
} room;

// Define the data structure for the haunted house.
typedef struct haunted_house {
  int num_rooms;             // The number of rooms in the haunted house.
  room *rooms;               // An array of rooms.
} haunted_house;

// Create a new haunted house.
haunted_house *create_haunted_house() {
  // Allocate memory for the haunted house.
  haunted_house *house = malloc(sizeof(haunted_house));

  // Set the number of rooms in the haunted house.
  house->num_rooms = rand() % MAX_ROOMS + 1;

  // Allocate memory for the rooms in the haunted house.
  house->rooms = malloc(sizeof(room) * house->num_rooms);

  // Create the rooms in the haunted house.
  for (int i = 0; i < house->num_rooms; i++) {
    // Set the room number.
    house->rooms[i].number = i + 1;

    // Set the number of exits from the room.
    house->rooms[i].num_exits = rand() % MAX_EXITS + 1;

    // Set the exits from the room.
    for (int j = 0; j < house->rooms[i].num_exits; j++) {
      house->rooms[i].exits[j] = rand() % house->num_rooms + 1;
    }

    // Set the description of the room.
    house->rooms[i].description = malloc(100);
    sprintf(house->rooms[i].description, "Room %d", house->rooms[i].number);

    // Set the next pointer for the room.
    house->rooms[i].next = NULL;
  }

  // Return the haunted house.
  return house;
}

// Destroy a haunted house.
void destroy_haunted_house(haunted_house *house) {
  // Free the memory for the rooms in the haunted house.
  for (int i = 0; i < house->num_rooms; i++) {
    free(house->rooms[i].description);
  }

  // Free the memory for the haunted house.
  free(house->rooms);
  free(house);
}

// Print the haunted house.
void print_haunted_house(haunted_house *house) {
  // Print the number of rooms in the haunted house.
  printf("The haunted house has %d rooms.\n", house->num_rooms);

  // Print the rooms in the haunted house.
  for (int i = 0; i < house->num_rooms; i++) {
    // Print the room number.
    printf("Room %d:\n", house->rooms[i].number);

    // Print the number of exits from the room.
    printf("  Number of exits: %d\n", house->rooms[i].num_exits);

    // Print the exits from the room.
    printf("  Exits: ");
    for (int j = 0; j < house->rooms[i].num_exits; j++) {
      printf("%d ", house->rooms[i].exits[j]);
    }
    printf("\n");

    // Print the description of the room.
    printf("  Description: %s\n", house->rooms[i].description);
  }
}

// Main function.
int main() {
  // Seed the random number generator.
  srand(time(NULL));

  // Create a haunted house.
  haunted_house *house = create_haunted_house();

  // Print the haunted house.
  print_haunted_house(house);

  // Destroy the haunted house.
  destroy_haunted_house(house);

  return 0;
}
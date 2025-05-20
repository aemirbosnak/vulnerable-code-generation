//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store the haunted house
typedef struct {
  int numRooms;        // Number of rooms in the house
  int **rooms;         // Array of pointers to rooms
  int *visited;        // Array of visited flags for each room
  int *scaryFactor;    // Array of scary factors for each room
} HauntedHouse;

// Function to create a new haunted house
HauntedHouse *createHauntedHouse(int numRooms) {
  // Allocate memory for the haunted house
  HauntedHouse *house = malloc(sizeof(HauntedHouse));
  if (house == NULL) {
    return NULL;
  }

  // Initialize the haunted house
  house->numRooms = numRooms;
  house->rooms = malloc(sizeof(int *) * numRooms);
  house->visited = malloc(sizeof(int) * numRooms);
  house->scaryFactor = malloc(sizeof(int) * numRooms);
  for (int i = 0; i < numRooms; i++) {
    house->rooms[i] = malloc(sizeof(int) * numRooms);
    house->visited[i] = 0;
    house->scaryFactor[i] = rand() % 10 + 1;
  }

  // Return the haunted house
  return house;
}

// Function to destroy a haunted house
void destroyHauntedHouse(HauntedHouse *house) {
  // Free the memory allocated for the haunted house
  for (int i = 0; i < house->numRooms; i++) {
    free(house->rooms[i]);
  }
  free(house->rooms);
  free(house->visited);
  free(house->scaryFactor);
  free(house);
}

// Function to print the haunted house
void printHauntedHouse(HauntedHouse *house) {
  // Print the number of rooms in the house
  printf("The haunted house has %d rooms.\n", house->numRooms);

  // Print the rooms in the house
  for (int i = 0; i < house->numRooms; i++) {
    printf("Room %d:\n", i + 1);
    for (int j = 0; j < house->numRooms; j++) {
      printf("%d ", house->rooms[i][j]);
    }
    printf("\n");
  }
}

// Function to explore the haunted house
void exploreHauntedHouse(HauntedHouse *house) {
  // Initialize the current room
  int currentRoom = 0;

  // Loop until all rooms have been visited
  while (currentRoom < house->numRooms) {
    // Mark the current room as visited
    house->visited[currentRoom] = 1;

    // Print the current room
    printf("You are now in room %d.\n", currentRoom + 1);

    // Get the scary factor of the current room
    int scaryFactor = house->scaryFactor[currentRoom];

    // Print the scary factor of the current room
    printf("The scary factor of this room is %d.\n", scaryFactor);

    // Get the possible next rooms
    int *nextRooms = malloc(sizeof(int) * house->numRooms);
    int numNextRooms = 0;
    for (int i = 0; i < house->numRooms; i++) {
      if (house->rooms[currentRoom][i] == 1 && !house->visited[i]) {
        nextRooms[numNextRooms++] = i;
      }
    }

    // Get the next room to explore
    int nextRoom = -1;
    if (numNextRooms > 0) {
      nextRoom = nextRooms[rand() % numNextRooms];
    }

    // Free the memory allocated for the possible next rooms
    free(nextRooms);

    // Move to the next room
    currentRoom = nextRoom;
  }

  // Print a message indicating that all rooms have been visited
  printf("You have explored all rooms in the haunted house.\n");
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a new haunted house
  HauntedHouse *house = createHauntedHouse(10);

  // Print the haunted house
  printHauntedHouse(house);

  // Explore the haunted house
  exploreHauntedHouse(house);

  // Destroy the haunted house
  destroyHauntedHouse(house);

  return 0;
}
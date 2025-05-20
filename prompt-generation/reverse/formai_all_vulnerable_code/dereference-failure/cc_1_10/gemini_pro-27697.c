//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms in the haunted house
#define NUM_ROOMS 10

// Define the maximum number of objects in each room
#define MAX_OBJECTS 5

// Define the maximum number of adjectives
#define MAX_ADJECTIVES 10

// Define the maximum number of nouns
#define MAX_NOUNS 10

// Define the data structure for a room
typedef struct room {
  char* name;
  char* description;
  int num_objects;
  char* objects[MAX_OBJECTS];
} room;

// Define the data structure for a haunted house
typedef struct haunted_house {
  room* rooms[NUM_ROOMS];
} haunted_house;

// Define the array of adjectives
char* adjectives[MAX_ADJECTIVES] = {
  "dark", "spooky", "creepy", "eerie", "sinister", "ominous", "foreboding", "menacing", "threatening", "horrifying"
};

// Define the array of nouns
char* nouns[MAX_NOUNS] = {
  "house", "mansion", "castle", "dungeon", "crypt", "tomb", "graveyard", "cemetery", "ruins", "wilderness"
};

// Create a new haunted house
haunted_house* create_haunted_house() {
  // Allocate memory for the haunted house
  haunted_house* house = malloc(sizeof(haunted_house));

  // Create the rooms
  for (int i = 0; i < NUM_ROOMS; i++) {
    // Allocate memory for the room
    room* room = malloc(sizeof(room));

    // Generate the room's name
    room->name = malloc(16);
    sprintf(room->name, "Room %d", i + 1);

    // Generate the room's description
    room->description = malloc(256);
    sprintf(room->description, "This is %s %s.", adjectives[rand() % MAX_ADJECTIVES], nouns[rand() % MAX_NOUNS]);

    // Generate the room's objects
    room->num_objects = rand() % MAX_OBJECTS;
    for (int j = 0; j < room->num_objects; j++) {
      // Allocate memory for the object
      room->objects[j] = malloc(16);

      // Generate the object's name
      sprintf(room->objects[j], "Object %d", j + 1);
    }

    // Add the room to the haunted house
    house->rooms[i] = room;
  }

  // Return the haunted house
  return house;
}

// Destroy a haunted house
void destroy_haunted_house(haunted_house* house) {
  // Destroy the rooms
  for (int i = 0; i < NUM_ROOMS; i++) {
    // Destroy the room's name
    free(house->rooms[i]->name);

    // Destroy the room's description
    free(house->rooms[i]->description);

    // Destroy the room's objects
    for (int j = 0; j < house->rooms[i]->num_objects; j++) {
      // Destroy the object's name
      free(house->rooms[i]->objects[j]);
    }

    // Destroy the room
    free(house->rooms[i]);
  }

  // Destroy the haunted house
  free(house);
}

// Print a haunted house
void print_haunted_house(haunted_house* house) {
  // Print the haunted house's name
  printf("Haunted House:\n");

  // Print the rooms
  for (int i = 0; i < NUM_ROOMS; i++) {
    // Print the room's name
    printf("  %s\n", house->rooms[i]->name);

    // Print the room's description
    printf("    %s\n", house->rooms[i]->description);

    // Print the room's objects
    for (int j = 0; j < house->rooms[i]->num_objects; j++) {
      // Print the object's name
      printf("    %s\n", house->rooms[i]->objects[j]);
    }
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create a haunted house
  haunted_house* house = create_haunted_house();

  // Print the haunted house
  print_haunted_house(house);

  // Destroy the haunted house
  destroy_haunted_house(house);

  return 0;
}
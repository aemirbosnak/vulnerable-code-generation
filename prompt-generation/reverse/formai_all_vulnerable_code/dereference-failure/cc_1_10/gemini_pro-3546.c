//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of rooms in the haunted house
#define NUM_ROOMS 10

// Define the maximum number of objects in a room
#define MAX_OBJECTS 5

// Define the maximum number of characters in a string
#define MAX_STRING_LENGTH 100

// Define the types of objects that can be found in a room
typedef enum {
  OBJECT_TYPE_DOOR,
  OBJECT_TYPE_WINDOW,
  OBJECT_TYPE_CHAIR,
  OBJECT_TYPE_TABLE,
  OBJECT_TYPE_BED
} object_type_t;

// Define the structure of an object
typedef struct {
  object_type_t type;
  char *name;
  char *description;
} object_t;

// Define the structure of a room
typedef struct {
  int number;
  char *name;
  char *description;
  object_t *objects[MAX_OBJECTS];
  int num_objects;
} room_t;

// Define the structure of the haunted house
typedef struct {
  room_t *rooms[NUM_ROOMS];
  int num_rooms;
} haunted_house_t;

// Create a new haunted house
haunted_house_t *create_haunted_house() {
  // Allocate memory for the haunted house
  haunted_house_t *haunted_house = malloc(sizeof(haunted_house_t));

  // Set the number of rooms in the haunted house
  haunted_house->num_rooms = NUM_ROOMS;

  // Create the rooms in the haunted house
  for (int i = 0; i < NUM_ROOMS; i++) {
    // Allocate memory for the room
    room_t *room = malloc(sizeof(room_t));

    // Set the room number
    room->number = i + 1;

    // Set the room name
    room->name = malloc(MAX_STRING_LENGTH);
    sprintf(room->name, "Room %d", i + 1);

    // Set the room description
    room->description = malloc(MAX_STRING_LENGTH);
    sprintf(room->description, "This is room %d.", i + 1);

    // Set the number of objects in the room
    room->num_objects = 0;

    // Add the room to the haunted house
    haunted_house->rooms[i] = room;
  }

  // Return the haunted house
  return haunted_house;
}

// Destroy a haunted house
void destroy_haunted_house(haunted_house_t *haunted_house) {
  // Destroy the rooms in the haunted house
  for (int i = 0; i < NUM_ROOMS; i++) {
    // Destroy the objects in the room
    for (int j = 0; j < haunted_house->rooms[i]->num_objects; j++) {
      free(haunted_house->rooms[i]->objects[j]->name);
      free(haunted_house->rooms[i]->objects[j]->description);
      free(haunted_house->rooms[i]->objects[j]);
    }

    // Destroy the room
    free(haunted_house->rooms[i]->name);
    free(haunted_house->rooms[i]->description);
    free(haunted_house->rooms[i]);
  }

  // Destroy the haunted house
  free(haunted_house);
}

// Print the haunted house
void print_haunted_house(haunted_house_t *haunted_house) {
  // Print the haunted house name
  printf("Haunted House:\n");

  // Print the rooms in the haunted house
  for (int i = 0; i < NUM_ROOMS; i++) {
    // Print the room number
    printf("Room %d:\n", haunted_house->rooms[i]->number);

    // Print the room name
    printf("  Name: %s\n", haunted_house->rooms[i]->name);

    // Print the room description
    printf("  Description: %s\n", haunted_house->rooms[i]->description);

    // Print the objects in the room
    printf("  Objects:\n");
    for (int j = 0; j < haunted_house->rooms[i]->num_objects; j++) {
      // Print the object name
      printf("    Name: %s\n", haunted_house->rooms[i]->objects[j]->name);

      // Print the object description
      printf("    Description: %s\n", haunted_house->rooms[i]->objects[j]->description);
    }
  }
}

// Main function
int main() {
  // Create a new haunted house
  haunted_house_t *haunted_house = create_haunted_house();

  // Print the haunted house
  print_haunted_house(haunted_house);

  // Destroy the haunted house
  destroy_haunted_house(haunted_house);

  return 0;
}
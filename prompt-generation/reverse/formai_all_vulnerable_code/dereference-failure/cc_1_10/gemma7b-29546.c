//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of rooms
#define MAX_ROOMS 10

// Define the room structure
typedef struct Room {
  int x, y;
  struct Room* next;
} Room;

// Generate a random room
Room* generate_room() {
  // Allocate a new room
  Room* room = malloc(sizeof(Room));

  // Set the room's coordinates
  room->x = rand() % MAX_ROOMS;
  room->y = rand() % MAX_ROOMS;

  // Set the room's next pointer
  room->next = NULL;

  // Return the new room
  return room;
}

// Create a labyrinth
void create_labyrinth(int size) {
  // Generate the rooms
  Room* head = generate_room();
  Room* current = head;

  // Connect the rooms
  for (int i = 1; i < size; i++) {
    current->next = generate_room();
    current = current->next;
  }

  // Print the labyrinth
  for (current = head; current; current = current->next) {
    printf("(%d, %d)\n", current->x, current->y);
  }
}

int main() {
  // Create a labyrinth
  create_labyrinth(5);

  return 0;
}
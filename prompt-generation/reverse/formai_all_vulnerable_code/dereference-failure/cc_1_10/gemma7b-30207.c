//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum number of rooms
#define MAX_ROOMS 20

// Define the room structure
typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
} Room;

// Generate a random room
Room* generate_room() {
  Room* room = malloc(sizeof(Room));
  room->x = rand() % MAX_ROOMS;
  room->y = rand() % MAX_ROOMS;
  room->north = NULL;
  room->south = NULL;
  room->east = NULL;
  room->west = NULL;
  return room;
}

// Connect rooms
void connect_rooms(Room* room1, Room* room2) {
  room1->east = room2;
  room2->west = room1;
}

// Create the dungeon
Room* create_dungeon() {
  // Generate the first room
  Room* start = generate_room();

  // Generate the remaining rooms
  for (int i = 0; i < MAX_ROOMS - 1; i++) {
    Room* room = generate_room();
    connect_rooms(start, room);
    start = room;
  }

  return start;
}

int main() {
  // Create the dungeon
  Room* dungeon = create_dungeon();

  // Traverse the dungeon
  Room* current_room = dungeon;
  while (current_room) {
    printf("You are in room (%d, %d).\n", current_room->x, current_room->y);

    // Go north, south, east, west
    if (current_room->north) {
      printf("You can go north to room (%d, %d).\n", current_room->north->x, current_room->north->y);
    }
    if (current_room->south) {
      printf("You can go south to room (%d, %d).\n", current_room->south->x, current_room->south->y);
    }
    if (current_room->east) {
      printf("You can go east to room (%d, %d).\n", current_room->east->x, current_room->east->y);
    }
    if (current_room->west) {
      printf("You can go west to room (%d, %d).\n", current_room->west->x, current_room->west->y);
    }

    // Move in a direction
    int direction = scanf("Enter direction (n/s/e/w): ");

    // Go in the chosen direction
    switch (direction) {
      case 'n':
        current_room = current_room->north;
        break;
      case 's':
        current_room = current_room->south;
        break;
      case 'e':
        current_room = current_room->east;
        break;
      case 'w':
        current_room = current_room->west;
        break;
    }
  }

  return 0;
}
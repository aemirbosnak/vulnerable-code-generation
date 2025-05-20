//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ROOMS 10
#define MAX_ROOM_SIZE 10

// Room struct
typedef struct {
  int x, y; // Coordinates
  int size; // Size of room
  int num_doors; // Number of doors
  int* doors; // Array of door indices
} Room;

// Door struct
typedef struct {
  int room1, room2; // Indices of the two rooms connected by the door
} Door;

// Array of rooms
Room rooms[NUM_ROOMS];

// Array of doors
Door doors[NUM_ROOMS * MAX_ROOM_SIZE];

// Function to generate a random room
Room generate_room() {
  Room room;
  room.x = rand() % 100;
  room.y = rand() % 100;
  room.size = rand() % MAX_ROOM_SIZE + 1;
  room.num_doors = rand() % room.size + 1;
  room.doors = malloc(room.num_doors * sizeof(int));
  for (int i = 0; i < room.num_doors; i++) {
    room.doors[i] = rand() % NUM_ROOMS;
  }
  return room;
}

// Function to generate a random door
Door generate_door() {
  Door door;
  door.room1 = rand() % NUM_ROOMS;
  door.room2 = rand() % NUM_ROOMS;
  return door;
}

// Function to initialize the haunted house
void initialize_haunted_house() {
  // Generate rooms
  for (int i = 0; i < NUM_ROOMS; i++) {
    rooms[i] = generate_room();
  }

  // Generate doors
  for (int i = 0; i < NUM_ROOMS * MAX_ROOM_SIZE; i++) {
    doors[i] = generate_door();
  }
}

// Function to print the haunted house
void print_haunted_house() {
  for (int i = 0; i < NUM_ROOMS; i++) {
    printf("Room %d: (%d, %d), size %d, num_doors %d\n", i, rooms[i].x, rooms[i].y, rooms[i].size, rooms[i].num_doors);
    for (int j = 0; j < rooms[i].num_doors; j++) {
      printf("  Door %d: (%d, %d)\n", j, doors[rooms[i].doors[j]].room1, doors[rooms[i].doors[j]].room2);
    }
  }
}

// Main function
int main() {
  // Initialize the random seed
  srand(time(NULL));

  // Initialize the haunted house
  initialize_haunted_house();

  // Print the haunted house
  print_haunted_house();

  return 0;
}
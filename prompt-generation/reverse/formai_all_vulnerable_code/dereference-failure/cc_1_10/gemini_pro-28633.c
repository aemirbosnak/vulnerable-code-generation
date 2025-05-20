//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Hotel management system
// This program manages the rooms of a hotel.
// It allows the user to add, remove, and modify rooms.

// The room structure
typedef struct room {
  int number;
  char type;
  bool occupied;
} room;

// The hotel structure
typedef struct hotel {
  int num_rooms;
  room *rooms;
} hotel;

// Function prototypes
void add_room(hotel *h);
void remove_room(hotel *h);
void modify_room(hotel *h);
void print_hotel(hotel *h);

// Main function
int main() {
  // Create a hotel
  hotel h;
  h.num_rooms = 0;
  h.rooms = NULL;

  // Add some rooms to the hotel
  add_room(&h);
  add_room(&h);
  add_room(&h);

  // Print the hotel
  print_hotel(&h);

  // Remove a room from the hotel
  remove_room(&h);

  // Print the hotel
  print_hotel(&h);

  // Modify a room in the hotel
  modify_room(&h);

  // Print the hotel
  print_hotel(&h);

  return 0;
}

// Function to add a room to the hotel
void add_room(hotel *h) {
  // Increase the number of rooms
  h->num_rooms++;

  // Reallocate memory for the rooms
  h->rooms = (room *)realloc(h->rooms, sizeof(room) * h->num_rooms);

  // Get the room details
  printf("Enter the room number: ");
  scanf("%d", &h->rooms[h->num_rooms - 1].number);
  printf("Enter the room type (S, D, Q, K): ");
  scanf(" %c", &h->rooms[h->num_rooms - 1].type);
  h->rooms[h->num_rooms - 1].occupied = false;
}

// Function to remove a room from the hotel
void remove_room(hotel *h) {
  int room_number;

  // Get the room number to remove
  printf("Enter the room number to remove: ");
  scanf("%d", &room_number);

  // Find the room in the list
  int i;
  for (i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].number == room_number) {
      break;
    }
  }

  // If the room was found, remove it
  if (i < h->num_rooms) {
    // Shift the remaining rooms down
    for (int j = i; j < h->num_rooms - 1; j++) {
      h->rooms[j] = h->rooms[j + 1];
    }

    // Decrease the number of rooms
    h->num_rooms--;

    // Reallocate memory for the rooms
    h->rooms = (room *)realloc(h->rooms, sizeof(room) * h->num_rooms);
  } else {
    printf("Room not found.\n");
  }
}

// Function to modify a room in the hotel
void modify_room(hotel *h) {
  int room_number;
  char new_type;
  bool new_occupied;

  // Get the room number to modify
  printf("Enter the room number to modify: ");
  scanf("%d", &room_number);

  // Find the room in the list
  int i;
  for (i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].number == room_number) {
      break;
    }
  }

  // If the room was found, modify it
  if (i < h->num_rooms) {
    // Get the new room details
    printf("Enter the new room type (S, D, Q, K): ");
    scanf(" %c", &new_type);
    printf("Enter the new room occupancy (true/false): ");
    scanf("%d", &new_occupied);

    // Set the new room details
    h->rooms[i].type = new_type;
    h->rooms[i].occupied = new_occupied;
  } else {
    printf("Room not found.\n");
  }
}

// Function to print the hotel
void print_hotel(hotel *h) {
  printf("Hotel Rooms:\n");
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d: %c, ", h->rooms[i].number, h->rooms[i].type);
    if (h->rooms[i].occupied) {
      printf("Occupied\n");
    } else {
      printf("Available\n");
    }
  }
}
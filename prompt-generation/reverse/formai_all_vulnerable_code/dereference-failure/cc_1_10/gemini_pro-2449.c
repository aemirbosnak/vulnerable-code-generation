//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms
#define MAX_ROOMS 100

// Define the maximum length of a string
#define MAX_STRING_LENGTH 100

// Define the room types
typedef enum {
  SINGLE,
  DOUBLE,
  SUITE
} room_type;

// Define the room status
typedef enum {
  VACANT,
  OCCUPIED,
  RESERVED
} room_status;

// Define the room struct
typedef struct {
  int room_number;
  room_type type;
  room_status status;
  char guest_name[MAX_STRING_LENGTH];
  char check_in_date[MAX_STRING_LENGTH];
  char check_out_date[MAX_STRING_LENGTH];
} room;

// Define the hotel struct
typedef struct {
  room rooms[MAX_ROOMS];
  int num_rooms;
} hotel;

// Create a new hotel
hotel *create_hotel() {
  hotel *h = malloc(sizeof(hotel));
  h->num_rooms = 0;
  return h;
}

// Add a room to the hotel
void add_room(hotel *h, room *r) {
  h->rooms[h->num_rooms] = *r;
  h->num_rooms++;
}

// Find a room by room number
room *find_room_by_number(hotel *h, int room_number) {
  for (int i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].room_number == room_number) {
      return &h->rooms[i];
    }
  }
  return NULL;
}

// Print the hotel information
void print_hotel_info(hotel *h) {
  printf("Hotel Information\n");
  printf("-----------------\n");
  printf("Number of rooms: %d\n", h->num_rooms);
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d:\n", h->rooms[i].room_number);
    printf("  Type: %s\n", h->rooms[i].type == SINGLE ? "Single" : h->rooms[i].type == DOUBLE ? "Double" : "Suite");
    printf("  Status: %s\n", h->rooms[i].status == VACANT ? "Vacant" : h->rooms[i].status == OCCUPIED ? "Occupied" : "Reserved");
    if (h->rooms[i].status == OCCUPIED || h->rooms[i].status == RESERVED) {
      printf("  Guest name: %s\n", h->rooms[i].guest_name);
      printf("  Check-in date: %s\n", h->rooms[i].check_in_date);
      printf("  Check-out date: %s\n", h->rooms[i].check_out_date);
    }
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel *h = create_hotel();

  // Add some rooms to the hotel
  room r1 = {1, SINGLE, VACANT, "", "", ""};
  add_room(h, &r1);
  room r2 = {2, DOUBLE, VACANT, "", "", ""};
  add_room(h, &r2);
  room r3 = {3, SUITE, OCCUPIED, "John Doe", "2023-03-01", "2023-03-07"};
  add_room(h, &r3);

  // Print the hotel information
  print_hotel_info(h);

  return 0;
}
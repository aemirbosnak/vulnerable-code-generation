//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the room types
typedef enum {
  STANDARD,
  DELUXE,
  SUITE
} room_type;

// Define the room status
typedef enum {
  VACANT,
  OCCUPIED,
  RESERVED
} room_status;

// Define the room structure
typedef struct {
  int room_number;
  room_type type;
  room_status status;
  char *guest_name;
  int check_in_date;
  int check_out_date;
} room;

// Define the hotel structure
typedef struct {
  room rooms[MAX_ROOMS];
  int num_rooms;
} hotel;

// Create a new hotel
hotel *create_hotel() {
  hotel *h = (hotel *)malloc(sizeof(hotel));
  h->num_rooms = 0;
  return h;
}

// Add a new room to the hotel
void add_room(hotel *h, int room_number, room_type type) {
  if (h->num_rooms >= MAX_ROOMS) {
    printf("Error: Hotel is full\n");
    return;
  }

  h->rooms[h->num_rooms].room_number = room_number;
  h->rooms[h->num_rooms].type = type;
  h->rooms[h->num_rooms].status = VACANT;
  h->rooms[h->num_rooms].guest_name = NULL;
  h->rooms[h->num_rooms].check_in_date = 0;
  h->rooms[h->num_rooms].check_out_date = 0;

  h->num_rooms++;
}

// Check in a guest
int check_in_guest(hotel *h, int room_number, char *guest_name, int check_in_date, int check_out_date) {
  // Find the room
  int i;
  for (i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].room_number == room_number) {
      break;
    }
  }

  // Check if the room is available
  if (h->rooms[i].status != VACANT) {
    printf("Error: Room is not available\n");
    return -1;
  }

  // Check in the guest
  h->rooms[i].status = OCCUPIED;
  h->rooms[i].guest_name = strdup(guest_name);
  h->rooms[i].check_in_date = check_in_date;
  h->rooms[i].check_out_date = check_out_date;

  return 0;
}

// Check out a guest
int check_out_guest(hotel *h, int room_number) {
  // Find the room
  int i;
  for (i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].room_number == room_number) {
      break;
    }
  }

  // Check if the room is occupied
  if (h->rooms[i].status != OCCUPIED) {
    printf("Error: Room is not occupied\n");
    return -1;
  }

  // Check out the guest
  h->rooms[i].status = VACANT;
  free(h->rooms[i].guest_name);
  h->rooms[i].check_in_date = 0;
  h->rooms[i].check_out_date = 0;

  return 0;
}

// Print the hotel status
void print_hotel_status(hotel *h) {
  int i;
  for (i = 0; i < h->num_rooms; i++) {
    printf("Room %d:\n", h->rooms[i].room_number);
    printf("  Type: %s\n", h->rooms[i].type == STANDARD ? "Standard" : h->rooms[i].type == DELUXE ? "Deluxe" : "Suite");
    printf("  Status: %s\n", h->rooms[i].status == VACANT ? "Vacant" : h->rooms[i].status == OCCUPIED ? "Occupied" : "Reserved");
    if (h->rooms[i].status == OCCUPIED) {
      printf("  Guest: %s\n", h->rooms[i].guest_name);
      printf("  Check-in date: %d\n", h->rooms[i].check_in_date);
      printf("  Check-out date: %d\n", h->rooms[i].check_out_date);
    }
  }
}

// Free the hotel
void free_hotel(hotel *h) {
  int i;
  for (i = 0; i < h->num_rooms; i++) {
    free(h->rooms[i].guest_name);
  }
  free(h);
}

int main() {
  // Create a new hotel
  hotel *h = create_hotel();

  // Add some rooms to the hotel
  add_room(h, 101, STANDARD);
  add_room(h, 102, DELUXE);
  add_room(h, 103, SUITE);

  // Check in a guest
  check_in_guest(h, 101, "John Doe", 20230301, 20230303);

  // Print the hotel status
  print_hotel_status(h);

  // Check out a guest
  check_out_guest(h, 101);

  // Print the hotel status again
  print_hotel_status(h);

  // Free the hotel
  free_hotel(h);

  return 0;
}
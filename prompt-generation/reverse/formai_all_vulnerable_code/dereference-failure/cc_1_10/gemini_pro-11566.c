//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 1000

// Define the room types
typedef enum {
  SINGLE,
  DOUBLE,
  SUITE
} room_type;

// Define the guest status
typedef enum {
  CHECKED_IN,
  CHECKED_OUT
} guest_status;

// Define the room struct
typedef struct {
  int room_number;
  room_type type;
  int capacity;
  float price;
  guest_status status;
} room;

// Define the guest struct
typedef struct {
  int guest_id;
  char *name;
  char *address;
  char *phone_number;
  room *room;
  guest_status status;
} guest;

// Define the hotel struct
typedef struct {
  room rooms[MAX_ROOMS];
  guest guests[MAX_GUESTS];
  int num_rooms;
  int num_guests;
} hotel;

// Create a new hotel
hotel *create_hotel() {
  hotel *h = malloc(sizeof(hotel));
  h->num_rooms = 0;
  h->num_guests = 0;
  return h;
}

// Add a new room to the hotel
void add_room(hotel *h, room *r) {
  h->rooms[h->num_rooms++] = *r;
}

// Add a new guest to the hotel
void add_guest(hotel *h, guest *g) {
  h->guests[h->num_guests++] = *g;
}

// Check in a guest
void check_in_guest(hotel *h, guest *g) {
  g->status = CHECKED_IN;
  g->room->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(hotel *h, guest *g) {
  g->status = CHECKED_OUT;
  g->room->status = CHECKED_OUT;
}

// Print the hotel information
void print_hotel_info(hotel *h) {
  printf("Hotel Information:\n");
  printf("Number of rooms: %d\n", h->num_rooms);
  printf("Number of guests: %d\n", h->num_guests);
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d:\n", h->rooms[i].room_number);
    printf("Type: %d\n", h->rooms[i].type);
    printf("Capacity: %d\n", h->rooms[i].capacity);
    printf("Price: %.2f\n", h->rooms[i].price);
    printf("Status: %d\n", h->rooms[i].status);
  }
  for (int i = 0; i < h->num_guests; i++) {
    printf("Guest %d:\n", h->guests[i].guest_id);
    printf("Name: %s\n", h->guests[i].name);
    printf("Address: %s\n", h->guests[i].address);
    printf("Phone number: %s\n", h->guests[i].phone_number);
    printf("Room: %d\n", h->guests[i].room->room_number);
    printf("Status: %d\n", h->guests[i].status);
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel *h = create_hotel();

  // Add some rooms to the hotel
  room r1 = {1, SINGLE, 1, 100.0, CHECKED_OUT};
  add_room(h, &r1);
  room r2 = {2, DOUBLE, 2, 150.0, CHECKED_OUT};
  add_room(h, &r2);
  room r3 = {3, SUITE, 4, 200.0, CHECKED_OUT};
  add_room(h, &r3);

  // Add some guests to the hotel
  guest g1 = {1, "John Doe", "123 Main Street", "555-1212", &r1, CHECKED_OUT};
  add_guest(h, &g1);
  guest g2 = {2, "Jane Doe", "456 Elm Street", "555-1213", &r2, CHECKED_OUT};
  add_guest(h, &g2);
  guest g3 = {3, "John Smith", "789 Oak Street", "555-1214", &r3, CHECKED_OUT};
  add_guest(h, &g3);

  // Check in some guests
  check_in_guest(h, &g1);
  check_in_guest(h, &g2);

  // Print the hotel information
  print_hotel_info(h);

  return 0;
}
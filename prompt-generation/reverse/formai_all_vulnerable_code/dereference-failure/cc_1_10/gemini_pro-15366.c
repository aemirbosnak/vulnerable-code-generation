//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: realistic
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

// Define the room structure
typedef struct {
  int room_number;
  room_type type;
  float price;
  guest_status status;
} room;

// Define the guest structure
typedef struct {
  int guest_id;
  char *name;
  char *address;
  char *phone;
  room *room;
} guest;

// Define the hotel structure
typedef struct {
  room rooms[MAX_ROOMS];
  guest guests[MAX_GUESTS];
  int num_rooms;
  int num_guests;
} hotel;

// Create a new hotel
hotel *create_hotel() {
  hotel *h = (hotel *)malloc(sizeof(hotel));
  h->num_rooms = 0;
  h->num_guests = 0;
  return h;
}

// Add a new room to the hotel
void add_room(hotel *h, int room_number, room_type type, float price) {
  room r;
  r.room_number = room_number;
  r.type = type;
  r.price = price;
  r.status = CHECKED_OUT;
  h->rooms[h->num_rooms++] = r;
}

// Add a new guest to the hotel
void add_guest(hotel *h, int guest_id, char *name, char *address, char *phone, room *room) {
  guest g;
  g.guest_id = guest_id;
  g.name = strdup(name);
  g.address = strdup(address);
  g.phone = strdup(phone);
  g.room = room;
  h->guests[h->num_guests++] = g;
}

// Check in a guest
void check_in_guest(hotel *h, guest *g) {
  g->room->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(hotel *h, guest *g) {
  g->room->status = CHECKED_OUT;
}

// Print the hotel information
void print_hotel(hotel *h) {
  int i;

  printf("Hotel Information\n");
  printf("Number of Rooms: %d\n", h->num_rooms);
  printf("Number of Guests: %d\n", h->num_guests);

  printf("\nRooms:\n");
  for (i = 0; i < h->num_rooms; i++) {
    printf("Room %d: Type %d, Price %.2f, Status %d\n", h->rooms[i].room_number, h->rooms[i].type, h->rooms[i].price, h->rooms[i].status);
  }

  printf("\nGuests:\n");
  for (i = 0; i < h->num_guests; i++) {
    printf("Guest %d: %s, %s, %s, Room %d\n", h->guests[i].guest_id, h->guests[i].name, h->guests[i].address, h->guests[i].phone, h->guests[i].room->room_number);
  }
}

// Free the memory allocated for the hotel
void destroy_hotel(hotel *h) {
  int i;

  for (i = 0; i < h->num_guests; i++) {
    free(h->guests[i].name);
    free(h->guests[i].address);
    free(h->guests[i].phone);
  }

  free(h);
}

// Main function
int main() {
  hotel *h = create_hotel();

  // Add some rooms to the hotel
  add_room(h, 101, SINGLE, 100.00);
  add_room(h, 102, DOUBLE, 150.00);
  add_room(h, 103, SUITE, 200.00);

  // Add some guests to the hotel
  add_guest(h, 1, "John Doe", "123 Main Street", "555-1212", &h->rooms[0]);
  add_guest(h, 2, "Jane Doe", "456 Elm Street", "555-1213", &h->rooms[1]);
  add_guest(h, 3, "John Smith", "789 Oak Street", "555-1214", &h->rooms[2]);

  // Check in some guests
  check_in_guest(h, &h->guests[0]);
  check_in_guest(h, &h->guests[2]);

  // Print the hotel information
  print_hotel(h);

  // Destroy the hotel
  destroy_hotel(h);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: authentic
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
  int capacity;
  double price;
  guest_status status;
} room;

// Define the guest structure
typedef struct {
  int guest_id;
  char *name;
  char *email;
  char *phone;
  room *room;
  guest_status status;
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

// Find a room by its number
room *find_room_by_number(hotel *h, int room_number) {
  for (int i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].room_number == room_number) {
      return &h->rooms[i];
    }
  }
  return NULL;
}

// Find a guest by their ID
guest *find_guest_by_id(hotel *h, int guest_id) {
  for (int i = 0; i < h->num_guests; i++) {
    if (h->guests[i].guest_id == guest_id) {
      return &h->guests[i];
    }
  }
  return NULL;
}

// Check in a guest
void check_in_guest(hotel *h, guest *g, room *r) {
  g->status = CHECKED_IN;
  g->room = r;
  r->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(hotel *h, guest *g) {
  g->status = CHECKED_OUT;
  g->room->status = CHECKED_OUT;
}

// Print the hotel's information
void print_hotel(hotel *h) {
  printf("Hotel Information:\n");
  printf("Number of Rooms: %d\n", h->num_rooms);
  printf("Number of Guests: %d\n", h->num_guests);
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d:\n", h->rooms[i].room_number);
    printf("Type: %s\n", h->rooms[i].type == SINGLE ? "Single" : h->rooms[i].type == DOUBLE ? "Double" : "Suite");
    printf("Capacity: %d\n", h->rooms[i].capacity);
    printf("Price: %.2f\n", h->rooms[i].price);
    printf("Status: %s\n", h->rooms[i].status == CHECKED_IN ? "Checked In" : "Checked Out");
  }
  for (int i = 0; i < h->num_guests; i++) {
    printf("Guest %d:\n", h->guests[i].guest_id);
    printf("Name: %s\n", h->guests[i].name);
    printf("Email: %s\n", h->guests[i].email);
    printf("Phone: %s\n", h->guests[i].phone);
    printf("Room: %d\n", h->guests[i].room->room_number);
    printf("Status: %s\n", h->guests[i].status == CHECKED_IN ? "Checked In" : "Checked Out");
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel *h = create_hotel();

  // Add some rooms to the hotel
  room r1 = {1, SINGLE, 1, 100.0, CHECKED_OUT};
  room r2 = {2, DOUBLE, 2, 150.0, CHECKED_OUT};
  room r3 = {3, SUITE, 4, 200.0, CHECKED_OUT};
  add_room(h, &r1);
  add_room(h, &r2);
  add_room(h, &r3);

  // Add some guests to the hotel
  guest g1 = {1, "John Doe", "johndoe@example.com", "+1234567890", &r1, CHECKED_OUT};
  guest g2 = {2, "Jane Doe", "janedoe@example.com", "+1234567891", &r2, CHECKED_OUT};
  guest g3 = {3, "John Smith", "johnsmith@example.com", "+1234567892", &r3, CHECKED_OUT};
  add_guest(h, &g1);
  add_guest(h, &g2);
  add_guest(h, &g3);

  // Check in a guest
  check_in_guest(h, &g1, &r1);

  // Print the hotel's information
  print_hotel(h);

  return 0;
}
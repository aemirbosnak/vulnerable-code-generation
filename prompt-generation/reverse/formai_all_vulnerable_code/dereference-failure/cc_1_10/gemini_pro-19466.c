//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 1000

// Define the room types
typedef enum {
  STANDARD,
  DELUXE,
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
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  room_type room_type;
  int room_number;
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
void add_room(hotel *h, room r) {
  h->rooms[h->num_rooms++] = r;
}

// Add a new guest to the hotel
void add_guest(hotel *h, guest g) {
  h->guests[h->num_guests++] = g;
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

// Find a guest by guest ID
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
  r->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(hotel *h, guest *g, room *r) {
  g->status = CHECKED_OUT;
  r->status = CHECKED_OUT;
}

// Print the hotel information
void print_hotel_info(hotel *h) {
  printf("Hotel Information\n");
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
    printf("Phone: %s\n", h->guests[i].phone);
    printf("Email: %s\n", h->guests[i].email);
    printf("Room type: %d\n", h->guests[i].room_type);
    printf("Room number: %d\n", h->guests[i].room_number);
    printf("Status: %d\n", h->guests[i].status);
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel *h = create_hotel();

  // Add some rooms to the hotel
  room r1 = {101, STANDARD, 2, 100.00, CHECKED_OUT};
  add_room(h, r1);
  room r2 = {102, DELUXE, 4, 150.00, CHECKED_OUT};
  add_room(h, r2);
  room r3 = {103, SUITE, 6, 200.00, CHECKED_OUT};
  add_room(h, r3);

  // Add some guests to the hotel
  guest g1 = {1001, "John Doe", "123 Main Street", "555-1212", "john.doe@example.com", STANDARD, 101, CHECKED_OUT};
  add_guest(h, g1);
  guest g2 = {1002, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@example.com", DELUXE, 102, CHECKED_OUT};
  add_guest(h, g2);
  guest g3 = {1003, "Bob Smith", "789 Oak Street", "555-1214", "bob.smith@example.com", SUITE, 103, CHECKED_OUT};
  add_guest(h, g3);

  // Check in some guests
  check_in_guest(h, &g1, &r1);
  check_in_guest(h, &g2, &r2);
  check_in_guest(h, &g3, &r3);

  // Print the hotel information
  print_hotel_info(h);

  return 0;
}
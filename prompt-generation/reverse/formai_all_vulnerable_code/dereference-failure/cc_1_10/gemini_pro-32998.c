//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: rigorous
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
  char first_name[50];
  char last_name[50];
  char email[50];
  char phone_number[50];
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
hotel* create_hotel() {
  hotel* h = malloc(sizeof(hotel));
  h->num_rooms = 0;
  h->num_guests = 0;
  return h;
}

// Add a new room to the hotel
void add_room(hotel* h, room r) {
  h->rooms[h->num_rooms] = r;
  h->num_rooms++;
}

// Add a new guest to the hotel
void add_guest(hotel* h, guest g) {
  h->guests[h->num_guests] = g;
  h->num_guests++;
}

// Check in a guest
void check_in_guest(hotel* h, guest* g) {
  g->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(hotel* h, guest* g) {
  g->status = CHECKED_OUT;
}

// Print the hotel information
void print_hotel_info(hotel* h) {
  printf("Hotel Information\n");
  printf("Number of rooms: %d\n", h->num_rooms);
  printf("Number of guests: %d\n", h->num_guests);
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d: type %d, price %f, status %d\n", h->rooms[i].room_number, h->rooms[i].type, h->rooms[i].price, h->rooms[i].status);
  }
  for (int i = 0; i < h->num_guests; i++) {
    printf("Guest %d: %s %s, email %s, phone %s, room type %d, room number %d, status %d\n", h->guests[i].guest_id, h->guests[i].first_name, h->guests[i].last_name, h->guests[i].email, h->guests[i].phone_number, h->guests[i].room_type, h->guests[i].room_number, h->guests[i].status);
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel* h = create_hotel();

  // Add some rooms to the hotel
  room r1 = {1, SINGLE, 50.0, CHECKED_OUT};
  add_room(h, r1);
  room r2 = {2, DOUBLE, 100.0, CHECKED_OUT};
  add_room(h, r2);
  room r3 = {3, SUITE, 200.0, CHECKED_OUT};
  add_room(h, r3);

  // Add some guests to the hotel
  guest g1 = {1, "John", "Doe", "john.doe@example.com", "123-456-7890", SINGLE, 1, CHECKED_OUT};
  add_guest(h, g1);
  guest g2 = {2, "Jane", "Doe", "jane.doe@example.com", "123-456-7891", DOUBLE, 2, CHECKED_OUT};
  add_guest(h, g2);
  guest g3 = {3, "John", "Smith", "john.smith@example.com", "123-456-7892", SUITE, 3, CHECKED_OUT};
  add_guest(h, g3);

  // Check in some guests
  check_in_guest(h, &g1);
  check_in_guest(h, &g2);

  // Print the hotel information
  print_hotel_info(h);

  return 0;
}
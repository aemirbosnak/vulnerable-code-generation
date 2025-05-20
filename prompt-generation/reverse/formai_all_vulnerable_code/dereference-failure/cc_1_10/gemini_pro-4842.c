//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: happy
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
  int price;
  guest_status status;
} room;

// Define the guest structure
typedef struct {
  int guest_id;
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  room* room;
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
void add_room(hotel* h, room_type type, int price) {
  room* r = &h->rooms[h->num_rooms++];
  r->room_number = h->num_rooms;
  r->type = type;
  r->price = price;
  r->status = CHECKED_OUT;
}

// Add a new guest to the hotel
void add_guest(hotel* h, char* name, char* address, char* phone, char* email) {
  guest* g = &h->guests[h->num_guests++];
  g->guest_id = h->num_guests;
  strcpy(g->name, name);
  strcpy(g->address, address);
  strcpy(g->phone, phone);
  strcpy(g->email, email);
  g->room = NULL;
}

// Check in a guest
void check_in_guest(hotel* h, guest* g, room* r) {
  g->room = r;
  r->status = CHECKED_IN;
}

// Check out a guest
void check_out_guest(hotel* h, guest* g) {
  g->room->status = CHECKED_OUT;
  g->room = NULL;
}

// Print the hotel information
void print_hotel(hotel* h) {
  printf("Hotel Information:\n");
  printf("Number of rooms: %d\n", h->num_rooms);
  printf("Number of guests: %d\n", h->num_guests);
  printf("\nRooms:\n");
  for (int i = 0; i < h->num_rooms; i++) {
    room* r = &h->rooms[i];
    printf("Room %d: type %d, price %d, status %d\n", r->room_number, r->type, r->price, r->status);
  }
  printf("\nGuests:\n");
  for (int i = 0; i < h->num_guests; i++) {
    guest* g = &h->guests[i];
    printf("Guest %d: %s, %s, %s, %s, room %d\n", g->guest_id, g->name, g->address, g->phone, g->email, g->room ? g->room->room_number : -1);
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel* h = create_hotel();

  // Add some rooms to the hotel
  add_room(h, STANDARD, 100);
  add_room(h, DELUXE, 150);
  add_room(h, SUITE, 200);

  // Add some guests to the hotel
  add_guest(h, "John Doe", "123 Main Street", "123-456-7890", "john.doe@example.com");
  add_guest(h, "Jane Doe", "456 Elm Street", "123-456-7891", "jane.doe@example.com");
  add_guest(h, "Jack Doe", "789 Oak Street", "123-456-7892", "jack.doe@example.com");

  // Check in some guests
  check_in_guest(h, &h->guests[0], &h->rooms[0]);
  check_in_guest(h, &h->guests[1], &h->rooms[1]);

  // Print the hotel information
  print_hotel(h);

  // Check out some guests
  check_out_guest(h, &h->guests[0]);
  check_out_guest(h, &h->guests[1]);

  // Print the hotel information again
  print_hotel(h);

  return 0;
}
//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: systematic
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

// Define the guest struct
typedef struct {
  int id;
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  room_type room_type;
  int check_in_date;
  int check_out_date;
} guest;

// Define the hotel struct
typedef struct {
  guest guests[MAX_GUESTS];
  int num_guests;
  room_type rooms[MAX_ROOMS];
  int num_rooms;
} hotel;

// Create a new hotel
hotel* create_hotel() {
  hotel* h = malloc(sizeof(hotel));
  h->num_guests = 0;
  h->num_rooms = 0;
  return h;
}

// Add a new guest to the hotel
void add_guest(hotel* h, guest* g) {
  h->guests[h->num_guests] = *g;
  h->num_guests++;
}

// Add a new room to the hotel
void add_room(hotel* h, room_type room_type) {
  h->rooms[h->num_rooms] = room_type;
  h->num_rooms++;
}

// Find a guest by their ID
guest* find_guest_by_id(hotel* h, int id) {
  for (int i = 0; i < h->num_guests; i++) {
    if (h->guests[i].id == id) {
      return &h->guests[i];
    }
  }
  return NULL;
}

// Find a room by its type
room_type* find_room_by_type(hotel* h, room_type room_type) {
  for (int i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i] == room_type) {
      return &h->rooms[i];
    }
  }
  return NULL;
}

// Print the details of all guests
void print_guests(hotel* h) {
  for (int i = 0; i < h->num_guests; i++) {
    printf("Guest %d:\n", h->guests[i].id);
    printf("Name: %s\n", h->guests[i].name);
    printf("Address: %s\n", h->guests[i].address);
    printf("Phone: %s\n", h->guests[i].phone);
    printf("Email: %s\n", h->guests[i].email);
    printf("Room type: %d\n", h->guests[i].room_type);
    printf("Check-in date: %d\n", h->guests[i].check_in_date);
    printf("Check-out date: %d\n", h->guests[i].check_out_date);
    printf("\n");
  }
}

// Print the details of all rooms
void print_rooms(hotel* h) {
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d: %d\n", i, h->rooms[i]);
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel* h = create_hotel();

  // Add some guests to the hotel
  guest g1 = {1, "John Smith", "123 Main Street", "555-1212", "john.smith@example.com", SINGLE, 20230301, 20230305};
  add_guest(h, &g1);
  guest g2 = {2, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@example.com", DOUBLE, 20230302, 20230306};
  add_guest(h, &g2);
  guest g3 = {3, "Bill Johnson", "789 Oak Street", "555-1214", "bill.johnson@example.com", SUITE, 20230303, 20230307};
  add_guest(h, &g3);

  // Add some rooms to the hotel
  add_room(h, SINGLE);
  add_room(h, DOUBLE);
  add_room(h, SUITE);

  // Print the details of all guests
  print_guests(h);

  // Print the details of all rooms
  print_rooms(h);

  // Find a guest by their ID
  guest* g = find_guest_by_id(h, 2);
  if (g != NULL) {
    printf("Found guest: %s\n", g->name);
  } else {
    printf("Guest not found\n");
  }

  // Find a room by its type
  room_type* r = find_room_by_type(h, DOUBLE);
  if (r != NULL) {
    printf("Found room: %d\n", *r);
  } else {
    printf("Room not found\n");
  }

  return 0;
}
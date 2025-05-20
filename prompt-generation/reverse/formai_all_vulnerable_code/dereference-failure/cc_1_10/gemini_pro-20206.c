//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum number of guests per room
#define MAX_GUESTS 4

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

// Define the guest structure
typedef struct {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
} guest;

// Define the room structure
typedef struct {
  int room_number;
  room_type type;
  room_status status;
  guest guests[MAX_GUESTS];
} room;

// Define the hotel structure
typedef struct {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  room rooms[MAX_ROOMS];
} hotel;

// Create a new hotel
hotel *create_hotel(char *name, char *address, char *phone, char *email) {
  hotel *h = malloc(sizeof(hotel));
  strcpy(h->name, name);
  strcpy(h->address, address);
  strcpy(h->phone, phone);
  strcpy(h->email, email);
  return h;
}

// Add a new room to the hotel
void add_room(hotel *h, int room_number, room_type type) {
  room *r = &h->rooms[room_number - 1];
  r->room_number = room_number;
  r->type = type;
  r->status = VACANT;
}

// Check in a guest
void check_in(hotel *h, int room_number, guest *guest) {
  room *r = &h->rooms[room_number - 1];
  r->status = OCCUPIED;
  for (int i = 0; i < MAX_GUESTS; i++) {
    if (r->guests[i].name[0] == '\0') {
      r->guests[i] = *guest;
      break;
    }
  }
}

// Check out a guest
void check_out(hotel *h, int room_number) {
  room *r = &h->rooms[room_number - 1];
  r->status = VACANT;
  for (int i = 0; i < MAX_GUESTS; i++) {
    r->guests[i].name[0] = '\0';
  }
}

// Print the hotel information
void print_hotel(hotel *h) {
  printf("Hotel Name: %s\n", h->name);
  printf("Hotel Address: %s\n", h->address);
  printf("Hotel Phone: %s\n", h->phone);
  printf("Hotel Email: %s\n", h->email);
  printf("\n");
  for (int i = 0; i < MAX_ROOMS; i++) {
    room *r = &h->rooms[i];
    printf("Room Number: %d\n", r->room_number);
    printf("Room Type: %s\n", r->type == STANDARD ? "Standard" : r->type == DELUXE ? "Deluxe" : "Suite");
    printf("Room Status: %s\n", r->status == VACANT ? "Vacant" : r->status == OCCUPIED ? "Occupied" : "Reserved");
    printf("Guests:\n");
    for (int j = 0; j < MAX_GUESTS; j++) {
      guest *g = &r->guests[j];
      if (g->name[0] != '\0') {
        printf("  - %s\n", g->name);
      }
    }
    printf("\n");
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel *h = create_hotel("The Grand Hotel", "123 Main Street", "555-1212", "info@thegrandhotel.com");

  // Add some rooms to the hotel
  add_room(h, 1, STANDARD);
  add_room(h, 2, STANDARD);
  add_room(h, 3, DELUXE);
  add_room(h, 4, DELUXE);
  add_room(h, 5, SUITE);

  // Check in some guests
  guest guest1 = {"John Smith", "123 Elm Street", "555-1212", "john.smith@email.com"};
  check_in(h, 1, &guest1);
  guest guest2 = {"Jane Doe", "456 Oak Street", "555-1212", "jane.doe@email.com"};
  check_in(h, 2, &guest2);

  // Check out a guest
  check_out(h, 1);

  // Print the hotel information
  print_hotel(h);

  return 0;
}
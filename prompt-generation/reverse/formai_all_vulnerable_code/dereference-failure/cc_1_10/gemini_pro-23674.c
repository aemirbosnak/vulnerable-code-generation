//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms and guests
#define MAX_ROOMS 100
#define MAX_GUESTS 100

// Define the room types
enum room_type {
  SINGLE,
  DOUBLE,
  SUITE
};

// Define the guest status
enum guest_status {
  CHECKED_IN,
  CHECKED_OUT
};

// Define the room struct
typedef struct room {
  int room_number;
  enum room_type type;
  float price;
  enum guest_status status;
} room;

// Define the guest struct
typedef struct guest {
  int guest_id;
  char name[50];
  char address[100];
  char phone_number[20];
  char email_address[50];
  enum guest_status status;
} guest;

// Define the hotel struct
typedef struct hotel {
  room rooms[MAX_ROOMS];
  guest guests[MAX_GUESTS];
  int num_rooms;
  int num_guests;
} hotel;

// Create a new hotel
hotel* create_hotel() {
  hotel* h = (hotel*)malloc(sizeof(hotel));
  h->num_rooms = 0;
  h->num_guests = 0;
  return h;
}

// Add a new room to the hotel
void add_room(hotel* h, int room_number, enum room_type type, float price) {
  h->rooms[h->num_rooms].room_number = room_number;
  h->rooms[h->num_rooms].type = type;
  h->rooms[h->num_rooms].price = price;
  h->rooms[h->num_rooms].status = CHECKED_OUT;
  h->num_rooms++;
}

// Add a new guest to the hotel
void add_guest(hotel* h, int guest_id, char* name, char* address, char* phone_number, char* email_address) {
  h->guests[h->num_guests].guest_id = guest_id;
  strcpy(h->guests[h->num_guests].name, name);
  strcpy(h->guests[h->num_guests].address, address);
  strcpy(h->guests[h->num_guests].phone_number, phone_number);
  strcpy(h->guests[h->num_guests].email_address, email_address);
  h->guests[h->num_guests].status = CHECKED_IN;
  h->num_guests++;
}

// Check in a guest
void check_in_guest(hotel* h, int guest_id, int room_number) {
  for (int i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].room_number == room_number) {
      h->rooms[i].status = CHECKED_IN;
      for (int j = 0; j < h->num_guests; j++) {
        if (h->guests[j].guest_id == guest_id) {
          h->guests[j].status = CHECKED_IN;
          break;
        }
      }
      break;
    }
  }
}

// Check out a guest
void check_out_guest(hotel* h, int guest_id, int room_number) {
  for (int i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].room_number == room_number) {
      h->rooms[i].status = CHECKED_OUT;
      for (int j = 0; j < h->num_guests; j++) {
        if (h->guests[j].guest_id == guest_id) {
          h->guests[j].status = CHECKED_OUT;
          break;
        }
      }
      break;
    }
  }
}

// Print the hotel information
void print_hotel(hotel* h) {
  printf("Hotel Information:\n");
  printf("Number of rooms: %d\n", h->num_rooms);
  printf("Number of guests: %d\n", h->num_guests);
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d:\n", h->rooms[i].room_number);
    printf("Type: %d\n", h->rooms[i].type);
    printf("Price: %.2f\n", h->rooms[i].price);
    printf("Status: %d\n", h->rooms[i].status);
  }
  for (int i = 0; i < h->num_guests; i++) {
    printf("Guest %d:\n", h->guests[i].guest_id);
    printf("Name: %s\n", h->guests[i].name);
    printf("Address: %s\n", h->guests[i].address);
    printf("Phone number: %s\n", h->guests[i].phone_number);
    printf("Email address: %s\n", h->guests[i].email_address);
    printf("Status: %d\n", h->guests[i].status);
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel* h = create_hotel();

  // Add some rooms to the hotel
  add_room(h, 101, SINGLE, 100.00);
  add_room(h, 102, DOUBLE, 150.00);
  add_room(h, 103, SUITE, 200.00);

  // Add some guests to the hotel
  add_guest(h, 1, "John Smith", "123 Main Street", "555-1212", "john.smith@email.com");
  add_guest(h, 2, "Jane Doe", "456 Elm Street", "555-1213", "jane.doe@email.com");
  add_guest(h, 3, "Bill Jones", "789 Oak Street", "555-1214", "bill.jones@email.com");

  // Check in some guests
  check_in_guest(h, 1, 101);
  check_in_guest(h, 2, 102);

  // Check out some guests
  check_out_guest(h, 1, 101);
  check_out_guest(h, 2, 102);

  // Print the hotel information
  print_hotel(h);

  return 0;
}
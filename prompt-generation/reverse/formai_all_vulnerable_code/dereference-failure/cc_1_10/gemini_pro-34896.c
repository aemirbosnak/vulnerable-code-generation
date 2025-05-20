//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the room types
enum room_type {
  SINGLE,
  DOUBLE,
  SUITE
};

// Define the room status
enum room_status {
  VACANT,
  OCCUPIED,
  RESERVED
};

// Define the guest data
struct guest {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
};

// Define the room data
struct room {
  int room_number;
  enum room_type room_type;
  enum room_status room_status;
  struct guest guest;
};

// Define the hotel data
struct hotel {
  struct room rooms[MAX_ROOMS];
  int num_rooms;
};

// Function to create a new hotel
struct hotel *create_hotel() {
  // Allocate memory for the hotel
  struct hotel *hotel = malloc(sizeof(struct hotel));

  // Initialize the hotel data
  hotel->num_rooms = 0;

  // Return the hotel
  return hotel;
}

// Function to add a new room to the hotel
void add_room(struct hotel *hotel, int room_number, enum room_type room_type) {
  // Check if the hotel is full
  if (hotel->num_rooms >= MAX_ROOMS) {
    printf("Error: The hotel is full.\n");
    return;
  }

  // Add the new room to the hotel
  hotel->rooms[hotel->num_rooms].room_number = room_number;
  hotel->rooms[hotel->num_rooms].room_type = room_type;
  hotel->rooms[hotel->num_rooms].room_status = VACANT;

  // Increment the number of rooms in the hotel
  hotel->num_rooms++;
}

// Function to check in a guest
void check_in(struct hotel *hotel, int room_number, struct guest guest) {
  // Check if the room is vacant
  if (hotel->rooms[room_number - 1].room_status != VACANT) {
    printf("Error: The room is not vacant.\n");
    return;
  }

  // Check in the guest
  hotel->rooms[room_number - 1].room_status = OCCUPIED;
  hotel->rooms[room_number - 1].guest = guest;
}

// Function to check out a guest
void check_out(struct hotel *hotel, int room_number) {
  // Check if the room is occupied
  if (hotel->rooms[room_number - 1].room_status != OCCUPIED) {
    printf("Error: The room is not occupied.\n");
    return;
  }

  // Check out the guest
  hotel->rooms[room_number - 1].room_status = VACANT;
}

// Function to print the hotel data
void print_hotel(struct hotel *hotel) {
  // Print the hotel data
  printf("Hotel Data:\n");
  printf("Number of rooms: %d\n", hotel->num_rooms);
  for (int i = 0; i < hotel->num_rooms; i++) {
    printf("Room %d:\n", hotel->rooms[i].room_number);
    printf("  Room type: %s\n", hotel->rooms[i].room_type == SINGLE ? "Single" : hotel->rooms[i].room_type == DOUBLE ? "Double" : "Suite");
    printf("  Room status: %s\n", hotel->rooms[i].room_status == VACANT ? "Vacant" : hotel->rooms[i].room_status == OCCUPIED ? "Occupied" : "Reserved");
    if (hotel->rooms[i].room_status == OCCUPIED) {
      printf("  Guest name: %s\n", hotel->rooms[i].guest.name);
      printf("  Guest address: %s\n", hotel->rooms[i].guest.address);
      printf("  Guest phone: %s\n", hotel->rooms[i].guest.phone);
      printf("  Guest email: %s\n", hotel->rooms[i].guest.email);
    }
  }
}

// Main function
int main() {
  // Create a new hotel
  struct hotel *hotel = create_hotel();

  // Add some rooms to the hotel
  add_room(hotel, 101, SINGLE);
  add_room(hotel, 102, DOUBLE);
  add_room(hotel, 103, SUITE);

  // Check in a guest
  struct guest guest = {"John Smith", "123 Main Street", "555-1212", "john.smith@email.com"};
  check_in(hotel, 101, guest);

  // Print the hotel data
  print_hotel(hotel);

  // Check out the guest
  check_out(hotel, 101);

  // Print the hotel data
  print_hotel(hotel);

  // Free the memory allocated for the hotel
  free(hotel);

  return 0;
}
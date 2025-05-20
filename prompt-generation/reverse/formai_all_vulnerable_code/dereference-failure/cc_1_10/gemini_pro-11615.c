//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the maximum number of guests per room
#define MAX_GUESTS 4

// Define the maximum length of a guest name
#define MAX_NAME_LENGTH 50

// Define the maximum length of a room type
#define MAX_ROOM_TYPE_LENGTH 20

// Define the maximum length of a date
#define MAX_DATE_LENGTH 11

// Define the room types
enum room_type {
  SINGLE,
  DOUBLE,
  SUITE
};

// Define the guest struct
typedef struct guest {
  char name[MAX_NAME_LENGTH];
  int age;
} guest_t;

// Define the room struct
typedef struct room {
  int room_number;
  enum room_type type;
  int capacity;
  int num_guests;
  guest_t guests[MAX_GUESTS];
} room_t;

// Define the hotel struct
typedef struct hotel {
  room_t rooms[MAX_ROOMS];
  int num_rooms;
} hotel_t;

// Create a new hotel
hotel_t* create_hotel() {
  hotel_t* hotel = malloc(sizeof(hotel_t));
  hotel->num_rooms = 0;
  return hotel;
}

// Add a new room to the hotel
void add_room(hotel_t* hotel, int room_number, enum room_type type, int capacity) {
  room_t* room = &hotel->rooms[hotel->num_rooms];
  room->room_number = room_number;
  room->type = type;
  room->capacity = capacity;
  room->num_guests = 0;
  hotel->num_rooms++;
}

// Check in a guest to a room
void check_in_guest(hotel_t* hotel, int room_number, guest_t guest) {
  room_t* room = &hotel->rooms[room_number];
  if (room->num_guests < room->capacity) {
    room->guests[room->num_guests] = guest;
    room->num_guests++;
  } else {
    printf("Room is full.\n");
  }
}

// Check out a guest from a room
void check_out_guest(hotel_t* hotel, int room_number, char* guest_name) {
  room_t* room = &hotel->rooms[room_number];
  for (int i = 0; i < room->num_guests; i++) {
    if (strcmp(room->guests[i].name, guest_name) == 0) {
      for (int j = i + 1; j < room->num_guests; j++) {
        room->guests[j - 1] = room->guests[j];
      }
      room->num_guests--;
      break;
    }
  }
}

// Print the hotel information
void print_hotel(hotel_t* hotel) {
  for (int i = 0; i < hotel->num_rooms; i++) {
    room_t* room = &hotel->rooms[i];
    printf("Room %d:\n", room->room_number);
    printf("Type: %s\n", room->type == SINGLE ? "Single" : room->type == DOUBLE ? "Double" : "Suite");
    printf("Capacity: %d\n", room->capacity);
    printf("Guests:\n");
    for (int j = 0; j < room->num_guests; j++) {
      guest_t* guest = &room->guests[j];
      printf("  %s (%d years old)\n", guest->name, guest->age);
    }
    printf("\n");
  }
}

// Free the hotel memory
void free_hotel(hotel_t* hotel) {
  free(hotel);
}

// Main function
int main() {
  // Create a new hotel
  hotel_t* hotel = create_hotel();

  // Add some rooms to the hotel
  add_room(hotel, 101, SINGLE, 1);
  add_room(hotel, 102, DOUBLE, 2);
  add_room(hotel, 103, SUITE, 4);

  // Check in some guests to the hotel
  guest_t guest1 = {"John Doe", 30};
  check_in_guest(hotel, 101, guest1);
  guest_t guest2 = {"Jane Doe", 25};
  check_in_guest(hotel, 102, guest2);
  guest_t guest3 = {"Bob Smith", 40};
  check_in_guest(hotel, 103, guest3);
  guest_t guest4 = {"Alice Smith", 35};
  check_in_guest(hotel, 103, guest4);

  // Print the hotel information
  print_hotel(hotel);

  // Check out a guest from the hotel
  check_out_guest(hotel, 101, "John Doe");

  // Print the hotel information again
  print_hotel(hotel);

  // Free the hotel memory
  free_hotel(hotel);

  return 0;
}
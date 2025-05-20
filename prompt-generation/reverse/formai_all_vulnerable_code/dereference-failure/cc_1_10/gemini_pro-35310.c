//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a hotel room
typedef struct Room {
  int room_number;
  int capacity;
  float price;
  int is_occupied;
} Room;

// Structure to represent a hotel guest
typedef struct Guest {
  int guest_id;
  char name[50];
  char address[100];
  char phone_number[20];
  char email[50];
} Guest;

// Function to create a new room
Room *create_room(int room_number, int capacity, float price) {
  Room *room = (Room *)malloc(sizeof(Room));
  room->room_number = room_number;
  room->capacity = capacity;
  room->price = price;
  room->is_occupied = 0;
  return room;
}

// Function to create a new guest
Guest *create_guest(int guest_id, char *name, char *address, char *phone_number, char *email) {
  Guest *guest = (Guest *)malloc(sizeof(Guest));
  guest->guest_id = guest_id;
  strcpy(guest->name, name);
  strcpy(guest->address, address);
  strcpy(guest->phone_number, phone_number);
  strcpy(guest->email, email);
  return guest;
}

// Function to check if a room is available
int is_room_available(Room *room) {
  return !room->is_occupied;
}

// Function to book a room
void book_room(Room *room, Guest *guest) {
  room->is_occupied = 1;
  printf("Room %d has been booked by guest %s.\n", room->room_number, guest->name);
}

// Function to check out a guest
void check_out(Room *room) {
  room->is_occupied = 0;
  printf("Guest has checked out of room %d.\n", room->room_number);
}

// Main function
int main() {
  // Create a hotel with 10 rooms
  Room *rooms[10];
  for (int i = 0; i < 10; i++) {
    rooms[i] = create_room(i + 1, 2, 100.0);
  }

  // Create a guest
  Guest *guest = create_guest(1, "John Doe", "123 Main Street", "555-1212", "john.doe@email.com");

  // Book a room for the guest
  book_room(rooms[0], guest);

  // Check out the guest
  check_out(rooms[0]);

  return 0;
}
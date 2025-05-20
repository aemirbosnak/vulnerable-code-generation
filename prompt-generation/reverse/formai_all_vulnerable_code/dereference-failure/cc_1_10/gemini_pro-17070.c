//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a hotel room
typedef struct room {
  int room_number;
  int capacity;
  int price;
  char *type;
  int is_occupied;
} room;

// Structure for a hotel
typedef struct hotel {
  char *name;
  int num_rooms;
  room *rooms;
} hotel;

// Function to create a new hotel
hotel *create_hotel(char *name, int num_rooms) {
  hotel *new_hotel = malloc(sizeof(hotel));
  new_hotel->name = name;
  new_hotel->num_rooms = num_rooms;
  new_hotel->rooms = malloc(sizeof(room) * num_rooms);
  return new_hotel;
}

// Function to add a new room to a hotel
void add_room(hotel *hotel, int room_number, int capacity, int price, char *type) {
  room *new_room = malloc(sizeof(room));
  new_room->room_number = room_number;
  new_room->capacity = capacity;
  new_room->price = price;
  new_room->type = type;
  new_room->is_occupied = 0;
  hotel->rooms[room_number - 1] = *new_room;
}

// Function to find a room in a hotel
room *find_room(hotel *hotel, int room_number) {
  for (int i = 0; i < hotel->num_rooms; i++) {
    if (hotel->rooms[i].room_number == room_number) {
      return &hotel->rooms[i];
    }
  }
  return NULL;
}

// Function to book a room in a hotel
int book_room(hotel *hotel, int room_number) {
  room *room = find_room(hotel, room_number);
  if (room == NULL) {
    return -1; // Room not found
  }
  if (room->is_occupied) {
    return -2; // Room is already occupied
  }
  room->is_occupied = 1;
  return 0; // Room booked successfully
}

// Function to check out a room in a hotel
int check_out_room(hotel *hotel, int room_number) {
  room *room = find_room(hotel, room_number);
  if (room == NULL) {
    return -1; // Room not found
  }
  if (!room->is_occupied) {
    return -2; // Room is already checked out
  }
  room->is_occupied = 0;
  return 0; // Room checked out successfully
}

// Function to print the details of a hotel
void print_hotel_details(hotel *hotel) {
  printf("Hotel Name: %s\n", hotel->name);
  printf("Number of Rooms: %d\n", hotel->num_rooms);
  for (int i = 0; i < hotel->num_rooms; i++) {
    printf("Room %d: %s, Capacity: %d, Price: %d, Is Occupied: %d\n",
           hotel->rooms[i].room_number, hotel->rooms[i].type, hotel->rooms[i].capacity,
           hotel->rooms[i].price, hotel->rooms[i].is_occupied);
  }
}

// Main function
int main() {
  // Create a new hotel
  hotel *hotel = create_hotel("Grand Hotel", 10);

  // Add some rooms to the hotel
  add_room(hotel, 1, 2, 100, "Standard");
  add_room(hotel, 2, 3, 150, "Deluxe");
  add_room(hotel, 3, 4, 200, "Suite");

  // Print the details of the hotel
  print_hotel_details(hotel);

  // Book a room in the hotel
  int result = book_room(hotel, 1);
  if (result == 0) {
    printf("Room 1 booked successfully\n");
  } else {
    printf("Error booking room\n");
  }

  // Check out a room in the hotel
  result = check_out_room(hotel, 1);
  if (result == 0) {
    printf("Room 1 checked out successfully\n");
  } else {
    printf("Error checking out room\n");
  }

  return 0;
}
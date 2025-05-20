//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the structure of a room
typedef struct room {
  int room_number;
  char *room_type;
  float room_price;
  int room_occupancy;
} room_t;

// Define the structure of the hotel
typedef struct hotel {
  char *hotel_name;
  int num_rooms;
  room_t rooms[MAX_ROOMS];
} hotel_t;

// Create a new hotel
hotel_t *create_hotel(char *hotel_name, int num_rooms) {
  hotel_t *hotel = malloc(sizeof(hotel_t));
  hotel->hotel_name = strdup(hotel_name);
  hotel->num_rooms = num_rooms;
  for (int i = 0; i < num_rooms; i++) {
    hotel->rooms[i].room_number = i + 1;
    hotel->rooms[i].room_type = "Standard";
    hotel->rooms[i].room_price = 100.0;
    hotel->rooms[i].room_occupancy = 0;
  }
  return hotel;
}

// Print the details of a hotel
void print_hotel(hotel_t *hotel) {
  printf("Hotel Name: %s\n", hotel->hotel_name);
  printf("Number of Rooms: %d\n", hotel->num_rooms);
  for (int i = 0; i < hotel->num_rooms; i++) {
    printf("Room Number: %d\n", hotel->rooms[i].room_number);
    printf("Room Type: %s\n", hotel->rooms[i].room_type);
    printf("Room Price: %.2f\n", hotel->rooms[i].room_price);
    printf("Room Occupancy: %d\n", hotel->rooms[i].room_occupancy);
    printf("\n");
  }
}

// Check in a guest into a room
void check_in(hotel_t *hotel, int room_number) {
  if (room_number < 1 || room_number > hotel->num_rooms) {
    printf("Invalid room number\n");
    return;
  }
  if (hotel->rooms[room_number - 1].room_occupancy == 1) {
    printf("Room is already occupied\n");
    return;
  }
  hotel->rooms[room_number - 1].room_occupancy = 1;
}

// Check out a guest from a room
void check_out(hotel_t *hotel, int room_number) {
  if (room_number < 1 || room_number > hotel->num_rooms) {
    printf("Invalid room number\n");
    return;
  }
  if (hotel->rooms[room_number - 1].room_occupancy == 0) {
    printf("Room is already empty\n");
    return;
  }
  hotel->rooms[room_number - 1].room_occupancy = 0;
}

// Main function
int main() {
  // Create a new hotel
  hotel_t *hotel = create_hotel("The Grand Budapest Hotel", 100);

  // Print the details of the hotel
  print_hotel(hotel);

  // Check in a guest into room 101
  check_in(hotel, 101);

  // Print the details of the hotel again
  print_hotel(hotel);

  // Check out a guest from room 101
  check_out(hotel, 101);

  // Print the details of the hotel again
  print_hotel(hotel);

  return 0;
}
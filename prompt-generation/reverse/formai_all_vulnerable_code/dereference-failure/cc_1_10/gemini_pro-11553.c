//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of rooms in the hotel
#define MAX_ROOMS 100

// Define the structure of a room
typedef struct room {
  int number;  // The room number
  int type;    // The room type (1 = single, 2 = double, 3 = suite)
  int status;  // The room status (0 = vacant, 1 = occupied)
  char *name;  // The name of the guest occupying the room
} room;

// Define the structure of the hotel
typedef struct hotel {
  room rooms[MAX_ROOMS];  // The array of rooms
  int num_rooms;         // The number of rooms in the hotel
} hotel;

// Create a new hotel
hotel *create_hotel(int num_rooms) {
  hotel *h = malloc(sizeof(hotel));
  h->num_rooms = num_rooms;

  // Initialize the rooms
  for (int i = 0; i < num_rooms; i++) {
    h->rooms[i].number = i + 1;
    h->rooms[i].type = 1;
    h->rooms[i].status = 0;
    h->rooms[i].name = NULL;
  }

  return h;
}

// Destroy a hotel
void destroy_hotel(hotel *h) {
  // Free the memory allocated for each room
  for (int i = 0; i < h->num_rooms; i++) {
    free(h->rooms[i].name);
  }

  // Free the memory allocated for the hotel
  free(h);
}

// Check in a guest
int check_in(hotel *h, int room_number, char *name) {
  // Check if the room is vacant
  if (h->rooms[room_number - 1].status != 0) {
    return -1;
  }

  // Check if the name is valid
  if (name == NULL || strlen(name) == 0) {
    return -2;
  }

  // Assign the room to the guest
  h->rooms[room_number - 1].status = 1;
  h->rooms[room_number - 1].name = strdup(name);

  return 0;
}

// Check out a guest
int check_out(hotel *h, int room_number) {
  // Check if the room is occupied
  if (h->rooms[room_number - 1].status != 1) {
    return -1;
  }

  // Clear the room
  h->rooms[room_number - 1].status = 0;
  free(h->rooms[room_number - 1].name);
  h->rooms[room_number - 1].name = NULL;

  return 0;
}

// Print the hotel status
void print_hotel_status(hotel *h) {
  printf("Room\tType\tStatus\tGuest Name\n");
  printf("----\t----\t------\t----------\n");
  for (int i = 0; i < h->num_rooms; i++) {
    printf("%d\t", h->rooms[i].number);
    switch (h->rooms[i].type) {
      case 1:
        printf("Single\t");
        break;
      case 2:
        printf("Double\t");
        break;
      case 3:
        printf("Suite\t");
        break;
    }
    switch (h->rooms[i].status) {
      case 0:
        printf("Vacant\t");
        break;
      case 1:
        printf("Occupied\t");
        break;
    }
    if (h->rooms[i].name != NULL) {
      printf("%s\n", h->rooms[i].name);
    } else {
      printf("-\n");
    }
  }
}

int main() {
  // Create a new hotel
  hotel *h = create_hotel(10);

  // Check in a guest
  check_in(h, 1, "John Smith");

  // Check out a guest
  check_out(h, 1);

  // Print the hotel status
  print_hotel_status(h);

  // Destroy the hotel
  destroy_hotel(h);

  return 0;
}
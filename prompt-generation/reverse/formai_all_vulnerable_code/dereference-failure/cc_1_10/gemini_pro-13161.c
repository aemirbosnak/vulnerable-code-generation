//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
  int number;
  char *type;
  int price;
  int occupied;
} room;

typedef struct hotel {
  char *name;
  int num_rooms;
  room *rooms;
} hotel;

// Function to create a new hotel
hotel *create_hotel(char *name, int num_rooms) {
  hotel *h = malloc(sizeof(hotel));
  h->name = strdup(name);
  h->num_rooms = num_rooms;
  h->rooms = malloc(sizeof(room) * num_rooms);
  for (int i = 0; i < num_rooms; i++) {
    h->rooms[i].number = i + 1;
    h->rooms[i].type = "Standard";
    h->rooms[i].price = 100;
    h->rooms[i].occupied = 0;
  }
  return h;
}

// Function to print the details of a hotel
void print_hotel(hotel *h) {
  printf("Hotel: %s\n", h->name);
  printf("Number of rooms: %d\n", h->num_rooms);
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d: %s, $%d\n", h->rooms[i].number, h->rooms[i].type, h->rooms[i].price);
  }
}

// Function to find an available room in a hotel
room *find_available_room(hotel *h) {
  for (int i = 0; i < h->num_rooms; i++) {
    if (h->rooms[i].occupied == 0) {
      return &h->rooms[i];
    }
  }
  return NULL;
}

// Function to book a room in a hotel
int book_room(hotel *h, room *r) {
  if (r->occupied == 0) {
    r->occupied = 1;
    return 0;
  } else {
    return -1;
  }
}

// Function to check out of a room in a hotel
int check_out_of_room(hotel *h, room *r) {
  if (r->occupied == 1) {
    r->occupied = 0;
    return 0;
  } else {
    return -1;
  }
}

int main() {
  // Create a new hotel
  hotel *h = create_hotel("The Prancing Pony", 10);

  // Print the details of the hotel
  print_hotel(h);

  // Find an available room in the hotel
  room *r = find_available_room(h);

  // Book the room
  if (r != NULL) {
    book_room(h, r);
    printf("Room %d booked successfully.\n", r->number);
  } else {
    printf("No available rooms.\n");
  }

  // Check out of the room
  check_out_of_room(h, r);

  // Print the details of the hotel
  print_hotel(h);

  return 0;
}